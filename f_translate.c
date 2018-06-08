/*
 * Translate module for translating abstract syntax tree
 * to IR form.
 * Created by Craig McL on 4/5/2012
 */
#include <stdlib.h>
#include "translate.h"
#include "tree.h"

typedef struct Tr_node_ *Tr_node;

struct Tr_level_ {
	Tr_level parent;
	Temp_label name;
	F_frame frame;
	Tr_accessList formals;
};

struct Tr_access_ {
	Tr_level level;
	F_access access;
};

struct Cx {
	patchList trues;
	patchList falses;
	T_stm stm;
};

struct Tr_exp_ {
	enum {Tr_ex, Tr_nx, Tr_cx} kind;
	union {
		T_exp ex;
		T_stm nx;
		struct Cx cx;
	} u;
};

struct Tr_expList_ {
	Tr_node head; /* points to first element in list */
	Tr_node tail; /* points to last element in list */
};

struct Tr_node_ {
	Tr_exp expr;
	Tr_node next;
};

struct patchList_ {
	Temp_label *head;
	patchList tail;
};

/* Frag list */
static F_fragList fragList = NULL;

static Tr_accessList makeFormalAccessList(Tr_level level);
static Tr_access Tr_Access(Tr_level level, F_access access);

/*
 * Function returns a tree expression list
 * with the same ordering of elements as the argument list.
 * (i.e. this function preserves ordering)
 */
static T_expList Tr_ExpList_convert(Tr_expList list);

/* Return address of static link */
static Tr_exp Tr_StaticLink(Tr_level funLevel, Tr_level level); 

static Tr_exp Tr_Ex(T_exp ex);
static Tr_exp Tr_Nx(T_stm nx);
static Tr_exp Tr_Cx(patchList trues, patchList falses, T_stm stm);

static T_exp unEx(Tr_exp e);
static T_stm unNx(Tr_exp e);
static struct Cx unCx(Tr_exp e);

static patchList PatchList(Temp_label *head, patchList tail);
static void doPatch(patchList pList, Temp_label label);
static patchList joinPatch(patchList fList, patchList sList);

static Tr_exp Tr_ifExpNoElse(Tr_exp test, Tr_exp then);
static Tr_exp Tr_ifExpWithElse(Tr_exp test, Tr_exp then, Tr_exp elsee);

static Tr_level outer = NULL;
Tr_level Tr_outermost(void)
{
	if (!outer)
		outer = Tr_newLevel(NULL, Temp_newlabel(), NULL);
	return outer;
}

static Tr_accessList makeFormalAccessList(Tr_level level)
{
	return NULL;
}

static Tr_exp Tr_Ex(T_exp ex)
{
	return NULL;
}

static Tr_exp Tr_Nx(T_stm nx)
{
	return NULL;
}

static Tr_exp Tr_Cx(patchList trues, patchList falses, T_stm stm)
{
	return NULL;
}

static void doPatch(patchList pList, Temp_label label)
{
}

static patchList joinPatch(patchList fList, patchList sList)
{
	return NULL;
}

static T_exp unEx(Tr_exp e)
{
	return NULL;
}

static T_stm unNx(Tr_exp e)
{
	return NULL;
}

static struct Cx unCx(Tr_exp e)
{
	return NULL;
}

static patchList PatchList(Temp_label *head, patchList tail)
{
	return NULL;
}

static Tr_access Tr_Access(Tr_level level, F_access access)
{
	return NULL;
}

static Tr_exp Tr_StaticLink(Tr_level funLevel, Tr_level level)
{
	return NULL;
}

/*
 * Adds an extra formal parameter onto the list passed to
 * the frame constructor. This parameter represents the static link
 */
Tr_level Tr_newLevel(Tr_level parent, Temp_label name, U_boolList formals)
{
	return NULL;
}

Tr_access Tr_allocLocal(Tr_level level, bool escape)
{
	return NULL;
}

Tr_accessList Tr_formals(Tr_level level)
{
	return NULL;
}

Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail)
{
	return NULL;
}

Tr_expList Tr_ExpList(void)
{
	return NULL;
}

void Tr_ExpList_append(Tr_expList list, Tr_exp expr)
{
	
}

void Tr_ExpList_prepend(Tr_expList list, Tr_exp expr)
{
	
}

int Tr_ExpList_empty(Tr_expList list)
{
	return 0;
}

static T_expList Tr_ExpList_convert(Tr_expList list)
{
	return NULL;
}

Tr_exp Tr_seqExp(Tr_expList list)
{
	return NULL;
}

Tr_exp Tr_simpleVar(Tr_access access, Tr_level level)
{
	return NULL;
}

Tr_exp Tr_fieldVar(Tr_exp recordBase, int fieldOffset)
{
	return NULL;
}

Tr_exp Tr_subscriptVar(Tr_exp arrayBase, Tr_exp index)
{
	return NULL;
}

Tr_exp Tr_arrayExp(Tr_exp size, Tr_exp init)
{
	return NULL;
}

Tr_exp Tr_recordExp(int n, Tr_expList list)
{
	return NULL;
}

Tr_exp Tr_letExp(Tr_expList list)
{
	return NULL;
}

Tr_exp Tr_doneExp(void)
{
	return NULL;
}

Tr_exp Tr_breakExp(Tr_exp breakk)
{
	return NULL;
}


Tr_exp Tr_whileExp(Tr_exp test, Tr_exp done, Tr_exp body)
{
	return NULL;
}

static Tr_exp Tr_ifExpNoElse(Tr_exp test, Tr_exp then)
{
	return NULL;
}

static Tr_exp Tr_ifExpWithElse(Tr_exp test, Tr_exp then, Tr_exp elsee)
{
	return NULL;
}

Tr_exp Tr_ifExp(Tr_exp test, Tr_exp then, Tr_exp elsee)
{
	return NULL;
}

Tr_exp Tr_assignExp(Tr_exp var, Tr_exp exp)
{
	return NULL;
}

Tr_exp Tr_arithExp(A_oper op, Tr_exp left, Tr_exp right)
{
	return NULL;
}

Tr_exp Tr_relExp(A_oper op, Tr_exp left, Tr_exp right)
{
	return NULL;
}


Tr_exp Tr_eqExp(A_oper op, Tr_exp left, Tr_exp right)
{
	return NULL;
}

Tr_exp Tr_eqStringExp(A_oper op, Tr_exp left, Tr_exp right)
{
	return NULL;
}


Tr_exp Tr_eqRef(A_oper op, Tr_exp left, Tr_exp right)
{
	return Tr_Ex(T_Const(0));
}

Tr_exp Tr_callExp(Tr_level level, Tr_level funLevel, Temp_label funLabel, Tr_expList argList)
{
	return NULL;
}

static F_fragList stringList = NULL;
Tr_exp Tr_stringExp(string str)
{
	return NULL;
}

Tr_exp Tr_intExp(int n)
{
	return Tr_Ex(T_Const(n));
}

static Temp_temp nilTemp = NULL;
Tr_exp Tr_nilExp(void)
{
	return NULL;
}

Tr_exp Tr_noExp(void)
{
	return Tr_Ex(T_Const(0));
}

void Tr_procEntryExit(Tr_level level, Tr_exp body, Tr_accessList formals)
{
	return NULL;
}

F_fragList Tr_getResult(void)
{
	return NULL;
}
