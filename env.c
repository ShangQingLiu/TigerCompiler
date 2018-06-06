#include "util.h"
#include "env.h"
#include <stdlib.h>

// Access 要怎么使用？？
E_enventry E_VarEntry(Tr_access access, Type_t ty)
{
	E_enventry varEntry = checked_malloc(sizeof(*varEntry));
	varEntry->kind = E_varEntry;
	varEntry->u.var.access = access;
	varEntry->u.var.ty = ty;
	return varEntry;
}

E_enventry E_FunEntry(Tr_level level, Temp_label label, Ty_tyList formals, Type_t result)
{
	E_enventry funEntry = checked_malloc(sizeof(*funEntry));
	funEntry->kind = E_funEntry;
	funEntry->u.fun.level = level;
	funEntry->u.fun.label = label;
	funEntry->u.fun.formals = formals;
	funEntry->u.fun.result = result;
	return funEntry;
}

// Create base environment of types
table_t E_base_tenv(void)
{
	table_t tenv = SymbolEmpty();
	SymbolEnter(tenv, Symbol("int"), NewTyInt());
	SymbolEnter(tenv, Symbol("string"), NewTyString());
	return tenv;
}

// Create base environment of functions
table_t E_base_venv(void)
{
	table_t venv = SymbolEmpty();
	// Create function environment entries
	E_enventry env_print = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		Ty_TyList(NewTyString(), NULL), NewTyVoid());
	E_enventry env_flush = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		NULL, NewTyVoid());
	E_enventry env_getchar = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		NULL, NewTyString());
	E_enventry env_ord = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		Ty_TyList(NewTyString(), NULL), NewTyInt());
	E_enventry env_chr = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		Ty_TyList(NewTyInt(), NULL), NewTyString());
	E_enventry env_size = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		Ty_TyList(NewTyString(), NULL), NewTyInt());
	E_enventry env_substring = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		Ty_TyList(NewTyString(), Ty_TyList(NewTyInt(),
					Ty_TyList(NewTyInt(), NULL))), NewTyString());
	E_enventry env_concat = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		Ty_TyList(NewTyString(), Ty_TyList(NewTyString(), NULL)), NewTyString());
	E_enventry env_not = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		Ty_TyList(NewTyInt(), NULL), NewTyInt());
	E_enventry env_exit = E_FunEntry(Tr_outermost(), Temp_newlabel(),
		Ty_TyList(NewTyInt(), NULL), NewTyVoid());
	// Add the functions to the environment
	SymbolEnter(venv, Symbol("print"), env_print);
	SymbolEnter(venv, Symbol("flush"), env_flush);
	SymbolEnter(venv, Symbol("getchar"), env_getchar);
	SymbolEnter(venv, Symbol("ord"), env_ord);
	SymbolEnter(venv, Symbol("chr"), env_chr);
	SymbolEnter(venv, Symbol("size"), env_size);
	SymbolEnter(venv, Symbol("substring"), env_substring);
	SymbolEnter(venv, Symbol("concat"), env_concat);
	SymbolEnter(venv, Symbol("not"), env_not);
	SymbolEnter(venv, Symbol("exit"), env_exit);
	return venv;
}
