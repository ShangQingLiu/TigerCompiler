#ifndef TIGER_SEMANT_H_
#define TIGER_SEMANT_H_

#include "ast.h"
#include "types.h"
#include "translate.h"

struct expty {Tr_exp exp; Type_t ty;};

F_fragList SEM_transProg(exp_t exp);

#endif /* TIGER_SEMANT_H_ */
