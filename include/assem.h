#ifndef TIGER_ASSEM_H_
#define TIGER_ASSEM_H_
/*
 * assem.h - Function prototypes to translate to Assem-instructions
 *             using Maximal Munch.
 */
#include <stdio.h>
#include "utils.h"
#include "temp.h"

typedef struct {Temp_labelList labels;} *AS_targets;
AS_targets AS_Targets(Temp_labelList labels);

typedef struct AS_instr_ *AS_instr;
struct AS_instr_ {
	enum {I_OPER, I_LABEL, I_MOVE} kind;
	union {
		struct {
			string_t assem;
			Temp_tempList dst, src; 
			AS_targets jumps;
		} OPER;
		struct {string_t assem; Temp_label label;} LABEL;
		struct {string_t assem; Temp_tempList dst, src;} MOVE;
	} u;
};

AS_instr AS_Oper(string_t a, Temp_tempList d, Temp_tempList s, AS_targets j);
AS_instr AS_Label(string_t a, Temp_label label);
AS_instr AS_Move(string_t a, Temp_tempList d, Temp_tempList s);

void AS_print(FILE *out, AS_instr i, Temp_map m);

typedef struct AS_instrList_ *AS_instrList;
struct AS_instrList_ { AS_instr head; AS_instrList tail;};
AS_instrList AS_InstrList(AS_instr head, AS_instrList tail);

AS_instrList AS_splice(AS_instrList a, AS_instrList b);
void AS_printInstrList(FILE *out, AS_instrList iList, Temp_map m);

typedef struct AS_proc_ *AS_proc;
struct AS_proc_ {
  string_t prolog;
  AS_instrList body;
  string_t epilog;
};

AS_proc AS_Proc(string_t p, AS_instrList b, string_t e);

#endif // TIGER_ASSEM_H_
