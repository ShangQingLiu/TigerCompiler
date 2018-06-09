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

extern bool anyErrors;

/* print the assembly language instructions to filename.s */
static void doProc(FILE *out, F_frame frame, T_stm body)
{
	T_stmList stmList;
	AS_instrList iList;
	struct COL_result coloring;
	
	stmList = C_linearize(body);
	stmList = C_traceSchedule(C_basicBlocks(stmList));
	printStmList(stdout, stmList);
	/* printStmList(stdout, stmList);*/
	iList  = F_codegen(frame, stmList); /* 9 */
	printf("cg finish: %x\n", iList);

	while (1) {
		G_graph fg = FG_AssemFlowGraph(iList);
		G_show(stdout, fg->mynodes, NULL);
		printf("flowgraph finish: %x\n", fg);
		Live_graph lg = Live_liveness(fg);
		G_show(stdout, lg->graph->mynodes, NULL);
		printf("livegraph finish: %x\n", lg);
		coloring = COL_color(lg, NULL, NULL);
		// if (coloring.spills == NULL) break;
		// else iList = Rewrite(coloring, iList);
		break;
	}

	//fprintf(out, "BEGIN %s\n", Temp_labelstring(F_name(frame)));
	AS_printInstrList (out, iList,
					   Temp_layerMap(F_tempMap,Temp_name()));
	//fprintf(out, "END %s\n\n", Temp_labelstring(F_name(frame)));
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
		 
		#if 0
			pr_exp(out, absyn_root, 0); /* print absyn data structure */
			fprintf(out, "\n");
		#endif

		sprintf(outfile, "%s.ast", argv[1]);
		out = fopen(outfile, "w");
		if(absyn_root)
			pr_exp(out, absyn_root, 0);
		else
			fprintf(stderr, "Error!");
		
		Esc_findEscape(absyn_root); /* set varDec's escape field */
		
		frags = SEM_transProg(absyn_root);
		printf("F: %x\n", frags);
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
					fprintf(out, "section .text\n\"\t%s\t.db\t\"%s\"\n", 
							frags->head->u.stringg.str,
							frags->head->u.stringg.label);
					isFirstString = 0;
				} else {
					fprintf(out, "\t%s\t.db\t\"%s\"\n", 
							frags->head->u.stringg.str,
							frags->head->u.stringg.label);
				}
			}
		}
		fclose(out);
		return 0;
	}
	EM_error(0,"usage: tiger file.tig");
	return 1;
}
