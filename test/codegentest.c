/*
 * main.c
 */

#include <stdio.h>
#include "utils.h"
#include "symbol.h"
#include "ast.h"
#include "errormsg.h"
#include "temp.h" /* needed by translate.h */
#include "tree.h" /* needed by frame.h */
#include "assem.h"
#include "frame.h" /* needed by translate.h and printfrags prototype */
#include "semant.h" /* function prototype for transProg */
#include "canonical.h"
#include "past.h"
#include "printtree.h"
#include "escape.h"
#include "parse.h"
#include "codegen.h"
#include "color.h"
#include "regalloc.h"

extern bool anyErrors;

/* print the assembly language instructions to filename.s */
static void doProc(FILE *out, F_frame frame, T_stm body)
{
	AS_proc proc;
	T_stmList stmList;
	AS_instrList iList;
	struct COL_result coloring;
	
	// F_tempMap = Temp_name();

	stmList = C_linearize(body);
	stmList = C_traceSchedule(C_basicBlocks(stmList));
	// printStmList(stdout, stmList);
	/* printStmList(stdout, stmList);*/
	iList  = F_codegen(frame, stmList); /* 9 */
	
	// AS_printInstrList(out, iList, Temp_layerMap(F_tempMap, Temp_name())); 
	
	struct RA_result ra = RA_regAlloc(frame, iList);
	printf("fmap %p\n", F_tempMap);
	fprintf(out, "#BEGIN function\n");
	AS_printInstrList(out, ra.il, Temp_layerMap(F_tempMap, ra.coloring)); 
	fprintf(out, "#END function\n\n");
}

int main(int argc, char *argv[])
{
	exp_t absyn_root;
	F_fragList frags;
	char outfile[100];
	int isFirstString = 1;
	FILE *out = stdout;
	
	if (argc == 2) {
		absyn_root = parse(argv[1]);
		if (!absyn_root)
			return 1;
		
		sprintf(outfile, "%s.ast", argv[1]);
		out = fopen(outfile, "w");
		if(absyn_root)
			pr_exp(out, absyn_root, 0);
		else
			fprintf(stderr, "Error!");
		fclose(out);

		
		
		Esc_findEscape(absyn_root); /* set varDec's escape field */
		
		frags = SEM_transProg(absyn_root);
		if (anyErrors) return 1; /* don't continue */
		
		/* convert the filename */
		sprintf(outfile, "%s.s", argv[1]);
		out = fopen(outfile, "w");
		/* Chapter 8, 9, 10, 11 & 12 */
		for (;frags;frags=frags->tail) {
			if (frags->head->kind == F_procFrag) {
				doProc(out, frags->head->u.proc.frame, frags->head->u.proc.body);
			} else if (frags->head->kind == F_stringFrag) {
				if (isFirstString) {
					fprintf(out, "section .text\n\t%s:\tdb\t\"%s\"\n", 
							frags->head->u.stringg.label->name,
							frags->head->u.stringg.str);
					isFirstString = 0;
				} else {
					fprintf(out, "\t%s:\tdb\t\"%s\"\n",
							frags->head->u.stringg.label->name,
							frags->head->u.stringg.str);
				}
			}
		}
		fclose(out);
		printf("Compile done\n");
		return 0;
	}
	EM_error(0,"usage: tcc file.tig");
	return 1;
}
