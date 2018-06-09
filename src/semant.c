#include "semant.h"
#include "utils.h"
#include "errormsg.h"
#include "env.h"
#include <assert.h>
#include <stdlib.h>

/* prototypes for functions local to this module */
static struct expty transExp(Tr_level level, table_t venv, table_t tenv, Tr_exp breakk, exp_t a);
static struct expty transVar(Tr_level level, table_t venv, table_t tenv, Tr_exp breakk, var_t v);
static Tr_exp transDec(Tr_level level, table_t venv, table_t tenv, Tr_exp breakk, dec_t d);
static Type_t transTy(table_t tenv, ty_t t);
static struct expty expTy(Tr_exp exp, Type_t ty);
static Ty_tyList makeFormalTys(table_t tenv, fieldList_t params);
static Ty_fieldList makeFieldTys(table_t tenv, fieldList_t fields);
static U_boolList makeFormals(fieldList_t params);
static Type_t actual_ty(Type_t ty);
static Type_t S_look_ty(table_t tenv, symbol_t sym);
static int is_equal_ty(Type_t tType, Type_t eType);

// Combine a tree expression and its type
static struct expty expTy(Tr_exp exp, Type_t ty)
{
	struct expty e;
	e.exp = exp;
	e.ty = ty;
	return e;
}

// Resolve typename alias
static Type_t actual_ty(Type_t ty)
{
	if (ty->kind == Ty_name)
		return actual_ty(ty->u.name.ty);
	else
		return ty;
}

// Look up type from current environment
static Type_t S_look_ty(table_t tenv, symbol_t sym)
{
	Type_t t = SymbolLookup(tenv, sym);
	if (t)
		return actual_ty(t);
	else
		return NULL;
}

/*
???
 * Compares two type kinds and returns 1 if they are the same
 * or 0 otherwise.
 * The first argument is the type of the variable, etc.
 * The second argument is the type of the initialising expression.
 * This also handles the record and nil expression constraint.
 */
static int is_equal_ty(Type_t tType, Type_t eType)
{
	Type_t actualtType = actual_ty(tType);
	int tyKind = actualtType->kind;
	int eKind = eType->kind;
	return ( ((tyKind == Ty_record || tyKind == Ty_array) && actualtType == eType) ||
		(tyKind == Ty_record && eKind == Ty_nil) ||
		(tyKind != Ty_record && tyKind != Ty_array && tyKind == eKind) );
}

F_fragList SEM_transProg(exp_t exp)
{
	/* Set up the type and value environments */
	table_t tenv = E_base_tenv();
	table_t venv = E_base_venv();
	transExp(Tr_outermost(), venv, tenv, NULL, exp);
	return Tr_getResult();
}

// Translate expression 语义分析核心函数
static struct expty transExp(Tr_level level, table_t venv, table_t tenv, Tr_exp breakk, exp_t a)
{
	switch (a->kind) {
		case A_varExp:
		{
			return transVar(level, venv, tenv, breakk, a->u.var);
		}
		case A_nilExp:
		{
			return expTy(Tr_nilExp(), NewTyNil());
		}
		case A_intExp:
		{
			return expTy(Tr_intExp(a->u.intt), NewTyInt());
		}
		case A_stringExp:
		{
			return expTy(Tr_stringExp(a->u.string), NewTyString());
		}
		case A_callExp:
		{
			expList_t args = NULL;
			Ty_tyList formals;
			E_enventry x = SymbolLookup(venv, a->u.call.func);
			Tr_exp translation = Tr_noExp();
			Tr_expList argList = Tr_ExpList();
			if (x && x->kind == E_funEntry) {
				// check type of parameters
				formals = x->u.fun.formals;
				for (args = a->u.call.args; args && formals;
						args = args->tail, formals = formals->tail) {
					// Treat each parameter as expression
					struct expty arg = transExp(level, venv, tenv, breakk, args->head);
					if (!is_equal_ty(arg.ty, formals->head))
						EM_error(args->head->pos, "incorrect type %s; expected %s",
							Ty_ToString(arg.ty), Ty_ToString(formals->head));
					// Append to argument list
					Tr_ExpList_append(argList, arg.exp);
				}
				// Check we have the same number of arguments and formals
				if (args == NULL && formals != NULL)
					EM_error(a->pos, "not enough arguments");
				else if (args != NULL && formals == NULL)
					EM_error(a->pos, "too many arguments");
				translation = Tr_callExp(level, x->u.fun.level, x->u.fun.label, argList);
				return expTy(translation, actual_ty(x->u.fun.result));
			} else {
				EM_error(a->pos, "undefined function %s", SymbolName(a->u.call.func));
				return expTy(translation, NewTyInt());
			}
		}
		case A_opExp:
		{
			A_oper oper = a->u.op.oper;
			struct expty left = transExp(level, venv, tenv, breakk, a->u.op.left);
			struct expty right = transExp(level, venv, tenv, breakk, a->u.op.right);
			Tr_exp translation = Tr_noExp();
			switch (oper) {
				// All basic arithmatic operation operates on INT
				case A_plusOp:
				case A_minusOp:
				case A_timesOp:
				case A_divideOp:
					if (left.ty->kind != Ty_int)
						EM_error(a->u.op.left->pos, "%s expression given for LHS; Int expected",
							Ty_ToString(left.ty));
					if (right.ty->kind != Ty_int)
						EM_error(a->u.op.right->pos, "%s expression given for RHS; Int expected",
							Ty_ToString(right.ty));
					return expTy(Tr_arithExp(oper, left.exp, right.exp), NewTyInt());
				
				// Logic operations work for all types
				case A_eqOp:
				case A_neqOp:
					switch(left.ty->kind) {
						case Ty_int:
							if (is_equal_ty(right.ty, left.ty))
								translation = Tr_eqExp(oper, left.exp, right.exp);
							break;
						case Ty_string:
							if (is_equal_ty(right.ty, left.ty))
								translation = Tr_eqStringExp(oper, left.exp, right.exp);
							break;
						// Array and record are represented by reference
						case Ty_array:
						{
							if (right.ty->kind != left.ty->kind) {
								EM_error(a->u.op.right->pos,
									"%s expression given for RHS; expected %s",
									Ty_ToString(right.ty), Ty_ToString(left.ty));
							}
							translation = Tr_eqRef(oper, left.exp, right.exp);
							break;
						}
						case Ty_record:
						{
							if (right.ty->kind != Ty_record && right.ty->kind != Ty_nil) {
								EM_error(a->u.op.right->pos,
									"%s expression given for RHS; expected record or nil",
									Ty_ToString(right.ty));
							}
							translation = Tr_eqRef(oper, left.exp, right.exp);
							break;
						}
						default:
						{
							EM_error(a->u.op.right->pos, "unexpected %s expression in comparsion",
								Ty_ToString(right.ty));
						}
					}
					return expTy(translation, NewTyInt());
				
				// Only INT and STRING can be used in comparsion operations
				case A_ltOp:
				case A_leOp:
				case A_gtOp:
				case A_geOp:
				{
					if (right.ty->kind != left.ty->kind) {
						EM_error(a->u.op.right->pos,
							"%s expression given for RHS; expected %s",
							Ty_ToString(right.ty), Ty_ToString(left.ty));
					}
					switch(left.ty->kind) {
						case Ty_int:
							translation = Tr_relExp(oper, left.exp, right.exp); break;
						// 为什么字符串的比较不用操作？
						case Ty_string:
							translation = Tr_noExp(); break;
						default:
						{
							EM_error(a->u.op.right->pos, "unexpected type %s in comparsion",
								Ty_ToString(right.ty));
							translation = Tr_noExp();
						}
					}
					return expTy(translation, NewTyInt());
				}
			}
			assert(0 && "Invalid operator in expression");
			return expTy(Tr_noExp(), NewTyInt());
		}
		// recordExp 是用来给结构变量赋初值的吗
		case A_recordExp:
		{
			Type_t typ = S_look_ty(tenv, a->u.record.typ);
			if (!typ) {
				EM_error(a->pos, "undefined type");
				return expTy(Tr_noExp(), NewTyRecord(NULL));
			}
			if (typ->kind != Ty_record)
				EM_error(a->pos, "%s is not a record type", SymbolName(a->u.record.typ));
			Ty_fieldList fieldTys = typ->u.record;
			efieldList_t recList;
			Tr_expList list = Tr_ExpList();
			int n = 0;
			for (recList = a->u.record.fields; recList;
					recList = recList->tail, fieldTys = fieldTys->tail, n++) {
				struct expty e = transExp(level, venv, tenv, breakk, recList->head->exp);
				if (recList->head->name != fieldTys->head->name)
					EM_error(a->pos, "%s not a valid field name", recList->head->name);
				if (!is_equal_ty(fieldTys->head->ty, e.ty))
					EM_error(recList->head->exp->pos, "type error: given %s but expected %s",
						Ty_ToString(e.ty), Ty_ToString(fieldTys->head->ty));
				Tr_ExpList_prepend(list, e.exp);
			}
			return expTy(Tr_recordExp(n, list), typ);
		}
		case A_seqExp:
		{
			struct expty expr = expTy(Tr_noExp(), NewTyVoid()); /* empty seq case */
			expList_t seq;
			Tr_expList list = Tr_ExpList();
			for (seq = a->u.seq; seq; seq = seq->tail) {
				expr = transExp(level, venv, tenv, breakk, seq->head);
				Tr_ExpList_prepend(list, expr.exp); // last expr is result of expression
			}
			// At least one exp in the list.
			if (Tr_ExpList_empty(list))
				Tr_ExpList_prepend(list, expr.exp);
			return expTy(Tr_seqExp(list), expr.ty);
		}
		case A_assignExp:
		{
			struct expty var = transVar(level, venv, tenv, breakk, a->u.assign.var);
			struct expty exp = transExp(level, venv, tenv, breakk, a->u.assign.exp);
			if (!is_equal_ty(var.ty, exp.ty))
				EM_error(a->u.assign.exp->pos, "expression not of expected type %s",
					Ty_ToString(var.ty));
			return expTy(Tr_assignExp(var.exp, exp.exp), NewTyVoid());
		}
		case A_ifExp:
		{
			struct expty test, then, elsee;
			test = transExp(level, venv, tenv, breakk, a->u.iff.test);
			if (test.ty->kind != Ty_int)
				EM_error(a->u.iff.test->pos, "integer required");
			then = transExp(level, venv, tenv, breakk, a->u.iff.then);
			if (a->u.iff.elsee) {
				elsee = transExp(level, venv, tenv, breakk, a->u.iff.elsee);
				if (!is_equal_ty(then.ty, elsee.ty)) {
					EM_error(a->u.iff.elsee->pos, "if-then-else branches must return same type"); 
				}
				return expTy(Tr_ifExp(test.exp, then.exp, elsee.exp), then.ty);
			} else {
				if (then.ty->kind != Ty_void)
					EM_error(a->u.iff.then->pos, "must produce no value");
				return expTy(Tr_ifExp(test.exp, then.exp, NULL), NewTyVoid());
			}
		}
		case A_whileExp:
		{
			struct expty test = transExp(level, venv, tenv, breakk, a->u.whilee.test);
			if (test.ty->kind != Ty_int)
				EM_error(a->u.whilee.test->pos, "integer required");
			Tr_exp newBreakk = Tr_doneExp();
			struct expty body = transExp(level, venv, tenv, breakk, a->u.whilee.body);
			if (body.ty->kind != Ty_void)
				EM_error(a->u.whilee.body->pos, "must produce no value");
			return expTy(Tr_whileExp(test.exp, newBreakk, body.exp), NewTyVoid());
		}
		case A_forExp:
		{
			/* Convert a for loop into a let expression with a while loop */
			dec_t i = VarDec(a->pos, a->u.forr.var, NULL, a->u.forr.lo);
			dec_t limit = VarDec(a->pos, Symbol("limit"), NULL, a->u.forr.hi);
			dec_t test = VarDec(a->pos, Symbol("test"), NULL, IntExp(a->pos, 1));
			exp_t testExp = VarExp(a->pos, SimpleVar(a->pos, Symbol("test")));
			exp_t iExp = VarExp(a->pos, SimpleVar(a->pos, a->u.forr.var));
			exp_t limitExp = VarExp(a->pos, SimpleVar(a->pos, Symbol("limit")));
			exp_t increment = AssignExp(a->pos, 
				SimpleVar(a->pos, a->u.forr.var),
				OpExp(a->pos, A_plusOp, iExp, IntExp(a->pos, 1)));
			exp_t setFalse = AssignExp(a->pos, 
				SimpleVar(a->pos, Symbol("test")), IntExp(a->pos, 0));
			/* The let expression we pass to this function */
			exp_t letExp = LetExp(a->pos, 
				DecList(i, DecList(limit, DecList(test, NULL))),
				SeqExp(a->pos,
					ExpList(
						IfExp(a->pos,
							OpExp(a->pos, A_leOp, a->u.forr.lo, a->u.forr.hi),
							WhileExp(a->pos, testExp,
								SeqExp(a->pos, 
									ExpList(a->u.forr.body,
										ExpList(
											IfExp(a->pos, 
												OpExp(a->pos, A_ltOp, iExp, 
													limitExp),
												increment, setFalse), 
											NULL)))), 
							NULL),
						NULL)));
			struct expty e = transExp(level, venv, tenv, breakk, letExp);
			return e;
		}
		case A_breakExp:
		{
			Tr_exp translation = Tr_noExp();
			if (!breakk) {
				EM_error(a->pos, "illegal break expression; must be inside loop construct");
			} else {
				translation = Tr_breakExp(breakk);
			}
			return expTy(translation, NewTyVoid());
		}
		case A_letExp:
		{
			struct expty expr;
			decList_t d;
			Tr_expList list = Tr_ExpList();
			SymbolBeginScope(venv);
			SymbolBeginScope(tenv);
			for (d = a->u.let.decs; d; d = d->tail)
				Tr_ExpList_prepend(list, transDec(level, venv, tenv, breakk, d->head));
			expr = transExp(level, venv, tenv, breakk, a->u.let.body);
			Tr_ExpList_prepend(list, expr.exp); // need result of let at the beginning
			SymbolEndScope(venv);
			SymbolEndScope(tenv);
			return expTy(Tr_seqExp(list), expr.ty);
		}
		case A_arrayExp:
		{
			Type_t typ = S_look_ty(tenv, a->u.array.typ);
			if (!typ) {
				EM_error(a->pos, "undefined type");
				return expTy(Tr_noExp(), NewTyInt());
			} else {
				struct expty size = transExp(level, venv, tenv, breakk, a->u.array.size);
				struct expty init = transExp(level, venv, tenv, breakk, a->u.array.init);
				if (size.ty->kind != Ty_int)
					EM_error(a->u.array.size->pos,
						"type error: %s for size expression; int required",
						Ty_ToString(size.ty));
				if (!is_equal_ty(typ->u.array, init.ty))
					EM_error(a->u.array.init->pos, 
						"type error: %s for initialisation expression; %s required",
						Ty_ToString(init.ty), Ty_ToString(typ->u.array));
				return expTy(Tr_arrayExp(size.exp, init.exp), typ);
			}
		}
	}
	assert(0);
}

// Translate variable
static struct expty transVar(Tr_level level, table_t venv, table_t tenv, Tr_exp breakk, var_t v)
{
	switch(v->kind) {
		case A_simpleVar:
		{
			E_enventry x = SymbolLookup(venv, v->u.simple);
			Tr_exp translation = Tr_noExp();
			if (x && x->kind == E_varEntry) {
				translation = Tr_simpleVar(x->u.var.access, level);
				return expTy(translation, actual_ty(x->u.var.ty));
			} else {
				EM_error(v->pos, "undefined variable %s", SymbolName(v->u.simple));
				return expTy(translation, NewTyInt());
			}
		}
		case A_fieldVar:
		{
			struct expty e = transVar(level, venv, tenv, breakk, v->u.field.var);
			if (e.ty->kind != Ty_record) {
				EM_error(v->u.field.var->pos, "not a record type");
			} else {
				/* Cycle through record field type list looking for field we want */
				Ty_fieldList f;
				int fieldOffset = 0;
				for (f = e.ty->u.record; f; f = f->tail, fieldOffset++) {
					if (f->head->name == v->u.field.sym) {
						return expTy(Tr_fieldVar(e.exp, fieldOffset), actual_ty(f->head->ty));
					}
				}
				EM_error(v->pos, "no such field %s for record type", SymbolName(v->u.field.sym));
			}
			return expTy(Tr_noExp(), NewTyInt());
		}
		case A_subscriptVar:
		{
			struct expty e = transVar(level, venv, tenv, breakk, v->u.subscript.var);
			Tr_exp translation = Tr_noExp();
			if (e.ty->kind != Ty_array) {
				EM_error(v->u.subscript.var->pos, "not an array type");
				return expTy(translation, NewTyInt());
			} else {
				struct expty index = transExp(level, venv, tenv, breakk, v->u.subscript.exp);
				if (index.ty->kind != Ty_int) {
					EM_error(v->u.subscript.exp->pos, "integer required");
				} else {
					translation =  Tr_subscriptVar(e.exp, index.exp);
				}
				return expTy(translation, actual_ty(e.ty->u.array));
			}
		}
	}
	assert(0);
}

// Translate declaration
static Tr_exp transDec(Tr_level level, table_t venv, table_t tenv, Tr_exp breakk, dec_t d)
{
	switch (d->kind) {
		case A_functionDec:
		{
			fundecList_t funList;
			Ty_tyList formalTys;
			U_boolList formals;
			Type_t resultTy;
			/* "headers" first -- so we can deal with mutally recursive functions */
			for (funList = d->u.function; funList; funList = funList->tail) {
				resultTy = NULL;
				if (funList->head->result) {
					resultTy = SymbolLookup(tenv, funList->head->result);
					if (!resultTy) {
						EM_error(funList->head->pos, "undefined type for return type");
					}
				}
				if (!resultTy) resultTy = NewTyVoid();
				
				formalTys = makeFormalTys(tenv, funList->head->params);
				formals = makeFormals(funList->head->params);
				Temp_label funLabel = Temp_newlabel();
				Tr_level funLevel = Tr_newLevel(level, funLabel, formals);
				SymbolEnter(venv, funList->head->name,
					E_FunEntry(funLevel, funLabel, formalTys, resultTy));
			}
			/* Now process the function bodies */
			E_enventry funEntry = NULL;
			for (funList = d->u.function; funList; funList = funList->tail) {
				/* Get formal types list from funEntry */
				funEntry = SymbolLookup(venv, funList->head->name);
				SymbolBeginScope(venv);
				/* Add formal parameters to value environment
				 * using the type list in the function entry and the params field list in
				 * the function abstract declaration */
				Ty_tyList paramTys = funEntry->u.fun.formals;
				fieldList_t paramFields;
				
				// 这个access list到底是用来干嘛的？？？？
				Tr_accessList accessList = Tr_formals(funEntry->u.fun.level);
				for (paramFields = funList->head->params; paramFields;
						paramFields = paramFields->tail, paramTys = paramTys->tail,
						accessList = accessList->tail) {
					SymbolEnter(venv, paramFields->head->name,
						E_VarEntry(accessList->head, paramTys->head));
				}
				struct expty e = transExp(funEntry->u.fun.level, venv, tenv,
					breakk, funList->head->body);
				if (!is_equal_ty(funEntry->u.fun.result, e.ty))
					EM_error(funList->head->body->pos, "incorrect return type %s; expected %s",
						Ty_ToString(e.ty), Ty_ToString(funEntry->u.fun.result));
						
				// ????
				Tr_procEntryExit(funEntry->u.fun.level, e.exp, accessList);
				SymbolEndScope(venv);
			}
			return Tr_noExp();
		}
		case A_varDec:
		{
			struct expty e = transExp(level, venv, tenv, breakk, d->u.var.init);
			Tr_access access = Tr_allocLocal(level, TRUE);
			if (d->u.var.typ) {
				Type_t type = S_look_ty(tenv, d->u.var.typ);
				if (!type) {
					EM_error(d->pos, "undefined type %s", SymbolName(d->u.var.typ));
					type = NewTyVoid();
				}
				if (!is_equal_ty(type, e.ty))
					EM_error(d->pos, "type error: %s given, expected %s for expression",
						Ty_ToString(e.ty), SymbolName(d->u.var.typ));
				SymbolEnter(venv, d->u.var.var, E_VarEntry(access, type));
			} else {
				if (e.ty->kind == Ty_nil)
					EM_error(d->u.var.init->pos, "illegal use nil expression");
				SymbolEnter(venv, d->u.var.var, E_VarEntry(access, e.ty));
			}
			return Tr_assignExp(Tr_simpleVar(access, level), e.exp);
		}
		case A_typeDec:
		{
			nametyList_t nameList;
			bool isCyclic = TRUE; /* Illegal cycle in type list */
			/* "headers" first */
			for (nameList = d->u.type; nameList; nameList = nameList->tail)
				SymbolEnter(tenv, nameList->head->name, NewTyName(nameList->head->name, NULL));
			/* now we can process the (possibly mutually) recursive bodies */
			for (nameList = d->u.type; nameList; nameList = nameList->tail) {
				Type_t t = transTy(tenv, nameList->head->ty);
				if (isCyclic) {
					if (t->kind != Ty_name) isCyclic = FALSE;
				}
				/* Update type binding */
				Type_t nameTy = SymbolLookup(tenv, nameList->head->name);
				nameTy->u.name.ty = t;
			}
			if (isCyclic)
				EM_error(d->pos,
					"illegal type cycle: cycle must contain record, array or built-in type");
			return Tr_noExp();
		}
	}
	assert(0);
}

// Translate type
static Type_t transTy(table_t tenv, ty_t t)
{
	Type_t ty;
	switch (t->kind) {
		case A_nameTy:
		{
			ty = SymbolLookup(tenv, t->u.var);
			if (!ty) {
				EM_error(t->pos, "undefined type %s",
					SymbolName(t->u.var));
			}
			return ty;
		}
		case A_recordTy:
		{
			Ty_fieldList fieldTys = makeFieldTys(tenv, t->u.record);
			return NewTyRecord(fieldTys);
		}
		case A_arrayTy:
		{
			ty = SymbolLookup(tenv, t->u.var);
			if (!ty) {
				EM_error(t->pos, "undefined type %s",
					SymbolName(t->u.var));
			}
			return NewTyArray(ty);
		}
	}
	assert(0);
}


/*
 * To maintain the same order as in the params list passed in,
 * we keep a pointer to the last list in the list of parameters;
 * this is where we insert every parameter type (by constructing a
 * type list with the currenct type).
 */
static Ty_tyList makeFormalTys(table_t tenv, fieldList_t params)
{
	Ty_tyList paramTys = NULL;
	Ty_tyList tailList = paramTys;
	fieldList_t paramList;
	for (paramList = params; paramList; paramList = paramList->tail) {
		Type_t t = S_look_ty(tenv, paramList->head->typ);
		if (!t) {
			EM_error(paramList->head->pos, "undefined type %s",
				SymbolName(paramList->head->typ));
		} else {
			if (paramTys) {
				tailList->tail = NewTyList(t, NULL);
				tailList = tailList->tail;
			} else {
				paramTys = NewTyList(t, NULL);
				tailList = paramTys;
			}
		}
	}
	return paramTys;
}

/*
 * Creates a list of booleans signifying whether the parameter escapes
 * For the moment the escape field of each parameter is ignored and the list
 * will contain all true values i.e. all parameters escape into the frame.
 * This will be altered later.
 */
static U_boolList makeFormals(fieldList_t params)
{
	U_boolList formalsList = NULL, tailList = NULL;
	fieldList_t paramList;
	for (paramList = params; paramList; paramList = paramList->tail) {
		if (formalsList) {
			tailList->tail = U_BoolList(TRUE, NULL);
			tailList = tailList->tail;
		} else {
			formalsList = U_BoolList(TRUE, NULL);
			tailList = formalsList;
		}
	}
	return formalsList;
}



static Ty_fieldList makeFieldTys(table_t tenv, fieldList_t fields)
{
	Ty_fieldList fieldTys = NULL;
	Ty_fieldList tailList = fieldTys;
	fieldList_t fieldList;
	for (fieldList = fields; fieldList; fieldList = fieldList->tail) {
		Type_t t = SymbolLookup(tenv, fieldList->head->typ);
		if (!t) {
			EM_error(fieldList->head->pos, "undefined type %s",
				SymbolName(fieldList->head->typ));
		} else {
			Ty_field f = NewTyField(fieldList->head->name, t);
			if (fieldTys) {
				tailList->tail = NewFieldList(f, NULL);
				tailList = tailList->tail;
			} else {
				fieldTys = NewFieldList(f, NULL);
				tailList = fieldTys;
			}
		}
	}
	return fieldTys;
}



