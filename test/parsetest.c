#include <stdio.h>
#include "utils.h"
#include "past.h"
#include "errormsg.h"
#include "frame.h"

int main(int argc, char **argv) {
    if (argc!=3) {
        fprintf(stderr,"usage: a.out filename\n"); 
        exit(1);
    }

    exp_t ast_root = NULL;

    ast_root = parse(argv[1]);

    // print ast
    FILE *out = fopen(argv[2], "w");
	if(ast_root)
    	pr_exp(out, ast_root, 0);
	else
		fprintf(stderr, "Error!");
    fclose(out);

    Esc_findEscape(ast_root); /* set varDec's escape field */
	
    F_fragList frags;
    frags = SEM_transProg(ast_root);
    // if (anyErrors) return 1; /* don't continue */

    return 0;
}
