#ifndef TIGER_TYPES_H_
#define TIGER_TYPES_H_

#include "symbol.h"

typedef struct Type_s *Type_t;
typedef struct Ty_tyList_ *Ty_tyList;
typedef struct Ty_field_ *Ty_field;
typedef struct Ty_fieldList_ *Ty_fieldList;

struct Type_s {
	enum { Ty_record, Ty_nil, Ty_int, Ty_string, Ty_array,
		Ty_name, Ty_void
	} kind;
	union {
		Ty_fieldList record;
		Type_t array;
		struct {
			symbol_t sym;
			Type_t ty;
		} name;
	} u;
};

struct Ty_tyList_ {
	Type_t head;
	Ty_tyList tail;
};
struct Ty_field_ {
	symbol_t name;
	Type_t ty;
};
struct Ty_fieldList_ {
	Ty_field head;
	Ty_fieldList tail;
};

Type_t NewTyNil(void);
Type_t NewTyInt(void);
Type_t NewTyString(void);
Type_t NewTyVoid(void);

Type_t NewTyRecord(Ty_fieldList fields);
Type_t NewTyArray(Type_t ty);
Type_t NewTyName(symbol_t sym, Type_t ty);

Ty_tyList NewTyList(Type_t head, Ty_tyList tail);
Ty_field NewTyField(symbol_t name, Type_t ty);
Ty_fieldList NewFieldList(Ty_field head, Ty_fieldList tail);

char *Ty_ToString(Type_t t);
void Ty_print(Type_t t);
void TyList_print(Ty_tyList list);

#endif /* TIGER_TYPES_H_ */
