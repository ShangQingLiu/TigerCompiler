#include <stdio.h>
#include "utils.h"
#include "symbol.h"
#include "types.h"

// Use static address for basic types
static struct Type_s tynil = {Ty_nil};
Type_t NewTyNil(void) { return &tynil; }

static struct Type_s tyint = {Ty_int};
Type_t NewTyInt(void) { return &tyint; }

static struct Type_s tystring = {Ty_string};
Type_t NewTyString(void) { return &tystring; }

static struct Type_s tyvoid = {Ty_void};
Type_t NewTyVoid(void) { return &tyvoid; }


// Create a record type with field list
Type_t NewTyRecord(Ty_fieldList fields)
{
	Type_t p = checked_malloc(sizeof(*p));
	p->kind = Ty_record;
	p->u.record = fields;
	return p;
}

// Create an array of type ty
Type_t NewTyArray(Type_t ty)
{
	Type_t p = checked_malloc(sizeof(*p));
	p->kind = Ty_array;
	p->u.array = ty;
	return p;
}

// Create a type name alias 
Type_t NewTyName(symbol_t sym, Type_t ty)
{
	Type_t p = checked_malloc(sizeof(*p));
	p->kind = Ty_name;
	p->u.name.sym = sym;
	p->u.name.ty = ty;
	return p;
}

// Create a type list
Ty_tyList NewTyList(Type_t head, Ty_tyList tail)
{
	Ty_tyList p = checked_malloc(sizeof(*p));
	p->head = head;
	p->tail = tail;
	return p;
}

// Create type field of record type
Ty_field NewTyField(symbol_t name, Type_t ty)
{
	Ty_field p = checked_malloc(sizeof(*p));
	p->name = name;
	p->ty = ty;
	return p;
}

// Create field list
Ty_fieldList NewFieldList(Ty_field head, Ty_fieldList tail)
{
	Ty_fieldList p = checked_malloc(sizeof(*p));
	p->head = head;
	p->tail = tail;
	return p;
}

/* printing functions - used for debugging */
static char str_ty[][12] = {
		"ty_record", "ty_nil", "ty_int", "ty_string",
		"ty_array", "ty_name", "ty_void"};

/* printing functions - used for error handling */
static char error_str_ty[][12] = {
		"record", "nil", "int", "string",
		"array", "name", "void"};

char *Ty_ToString(Type_t t)
{
	if (t->kind == Ty_name)
		return SymbolName(t->u.name.sym);
	return error_str_ty[t->kind];
}

/* This will infinite loop on mutually recursive types */
void Ty_print(Type_t t)
{
	if (t == NULL)
		printf("null");
	else
	{
		printf("%s", str_ty[t->kind]);
		if (t->kind == Ty_name)
		{
			printf(", %s", SymbolName(t->u.name.sym));
		}
	}
}

void TyList_print(Ty_tyList list)
{
	if (list == NULL)
		printf("null");
	else
	{
		printf("TyList( ");
		Ty_print(list->head);
		printf(", ");
		TyList_print(list->tail);
		printf(")");
	}
}
