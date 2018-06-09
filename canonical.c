#include<stdio.h>
#include"utils.h"
#include"temp.h"
#include "canonical.h"

/*Local Function Prototype*/
//抽出一个语句中所有ESEQ
static T_stm do_stm(T_stm stm);

/*
*返回一个语句S和一个表达式e，其中
*e不包含ESEQ
*/
static struct stmExp do_exp(T_exp exp);
static C_stmListList mkBlocks(T_stmList stms, Temp_label done);
static T_stmList getNext(void);


static bool isNop(T_stm x){
  return x->kind == T_EXP && x->u.EXP->kind == T_CONST;
}
/*判别语句是否可与表达式交换*/
static bool commute(T_stm x, T_exp y){
  return isNop(x) || y->kind == T_NAME || y->kind == T_CONST;
}

/*返回一个等价SEQ(s1,s2), 但如果其中一个为空就直接
*返回另外一个
*/
static T_stm seq(T_stm x, T_stm y){
  if(isNop(x)) return y;
  if(isNop(y)) return x;
  return T_Seq(x,y);
}
typedef struct expRefList_ *expRefList;
struct expRefList_{
  T_exp *head;
  expRefList tail;
};
struct stmExp {
  T_stm s;
  T_exp e;
};

//expRefList 初始化
static expRefList ExpRefList(T_exp *head, expRefList tail){
  expRefList pt = (expRefList)checked_malloc(sizeof *pt);
  pt->head = head;
  pt->tail = tail;
  return pt;
}
/*
*从表达式表中抽出所有ESEQ并且将ESEQ
*中的语句合并回一个T_stm
*/
static T_stm reorder(expRefList rlist){
  if(!rlist)//空
    return T_Exp(T_Const(0));
  else if((*rlist->head)->kind == T_CALL){
    Temp_temp t = Temp_newtemp();
    *rlist->head = T_Eseq(T_Move(T_Temp(t),*rlist->head),T_Temp(t));
    return reorder(rlist);
  }
  else{
    struct stmExp se = do_exp(*rlist->head);
    T_stm s = reorder(rlist->tail);
    if(commute(s,se.e)){
      *rlist->head = se.e;
      return seq(se.s,s);
    }
    else{
      Temp_temp tt = Temp_newtemp();
      *rlist->head = T_Temp(tt);
      return seq(se.s,seq(T_Move(T_Temp(tt),se.e),s));
    }
  }
}
static expRefList getCallForRlist(T_exp exp){
  expRefList rlist, cu;
  T_expList args = exp->u.CALL.args;
  cu = rlist = ExpRefList(&exp->u.CALL.fun, NULL);
  for(;args;args = args->tail){
    cu = cu->tail = ExpRefList(&args->head,NULL);
  }
  return rlist;
}

//stmExp初始化
static struct stmExp StmExp(T_stm stm, T_exp exp){
  struct stmExp x;
  x.s = stm;
  x.e = exp;
  return x;
}

static struct stmExp do_exp(T_exp exp){
  switch(exp->kind){
    case T_BINOP:
      return StmExp(
        reorder(
          ExpRefList(&exp->u.BINOP.left, ExpRefList(&exp->u.BINOP.right,NULL))
        ),exp
      );
    case T_MEM:
      return StmExp(
        reorder(
          ExpRefList(&exp->u.MEM,NULL)
        ),exp
      );
    case T_ESEQ:
      struct stmExp se = do_exp(exp->u.ESEQ.exp);
      return StmExp(reorder(NULL),exp);
  }
}

static T_stm do_stm(T_stm stm)
{
  switch(stm->kind){
  case T_SEQ:
    return seq(
      do_stm(stm->u.SEQ.left),
      do_stm(stm->u.SEQ.right)
    );
  case T_JUMP:
    return seq(reorder(ExpRefList(&stm->u.JUMP.exp,NULL)),stm);
  case T_CJUMP:
    return seq(reorder(ExpRefList(&stm->u.CJUMP.left,ExpRefList(&stm->u.CJUMP.right,NULL))),stm);
  case T_MOVE:
    if(stm->u.MOVE.dst->kind ==T_TEMP && stm->u.MOVE.src->kind == T_CALL)
      return seq(reorder(getCallForRlist(stm->u.MOVE.src)),stm);
    else if(stm->u.MOVE.dst->kind == T_TEMP)
      return seq(reorder(ExpRefList(&stm->u.MOVE.src,NULL)),stm);
    else if(stm->u.MOVE.dst->kind == T_MEM)
      return seq(reorder(ExpRefList(&stm->u.MOVE.dst->u.MEM,ExpRefList(&stm->u.MOVE.src,NULL))),stm);
    else if(stm->u.MOVE.dst->kind == T_ESEQ){
      T_stm s = stm->u.MOVE.dst->u.ESEQ.stm;
      stm->u.MOVE.dst = stm->u.MOVE.dst->u.ESEQ.exp;
      return do_stm(T_Seq(s,stm));
    }
     assert(0);
  case T_EXP:
      if(stm->u.EXP->kind == T_CALL){
        return seq(reorder(getCallForRlist(stm->u.EXP)),stm);
      }
      else
        return seq(reorder(ExpRefList(&stm->u.EXP,NULL)),stm);
      default:
        return stm;
 }
}

/*get rid of SEQ's ouput list*/
static T_stmList linear (T_stm stm, T_stmList right)
{
  if(stm->kind == T_SEQ){
    return linear(stm->u.SEQ.left, linear(stm->u.SEQ.right,right));
  }
  else
    return T_StmList(stm,right);
}

T_stmList C_linearize(T_stm stm){
  return linear(do_stm(stm),NULL);
}

static C_stmListList StmListList(T_stmList head, C_stmListList tail){
  C_stmListList p = (C_stmListList)checked_malloc(sizeof *p);
  p->head = head;
  p->tail = tail;
  return p; 
}

/*寻找下一个*/
static C_stmListList next(T_stmList prestms, T_stmList stms, Temp_label done){
  if(!stms)
    return next(prestms,
    T_StmList(T_Jump(T_Name(done),Temp_LabelList(done,NULL)),NULL),done);
  if(stms->head->kind == T_JUMP || stms->head->kind == T_CJUMP){
    C_stmListList sl;
    prestms->tail = stms;
    sl = mkBlocks(stms->tail,done);
    stms->tail = NULL;
    return sl;
  }
  else if(stms->head->kind == T_LABEL){
    Temp_label lab = stms->head->u.LABEL;
    return next(prestms, T_StmList(
      T_Jump(T_Name(lab),Temp_LabelList(lab,NULL)),stms
    ),done); 
  }
  else{
    prestms->tail = stms;
    return next(stms,stms->tail,done);
  }
}

//Blocks init
/*LABEL->NEXT->NEXT...->CJUMP||JUMP*/
static C_stmListList mkBlocks(T_stmList stms, Temp_label done)
{
	if (!stms) {
		return NULL;
	}
	if (stms->head->kind != T_LABEL) {
		return mkBlocks(T_StmList(T_Label(Temp_newlabel()), stms), done);
	}
	/* else there already is a label */
	return StmListList(stms, next(stms, stms->tail, done));
}

struct C_block C_basicBlocks(T_stmList stmList)
{
	struct C_block b;
	b.label = Temp_newlabel();
	b.stmLists = mkBlocks(stmList, b.label);

	return b;
}

static table_t block_env;
static struct C_block global_block;

static T_stmList getLast(T_stmList list)
{
	T_stmList last = list;
	while (last->tail->tail)
		last = last->tail;
	return last;
}


static void trace(T_stmList list)
{
	T_stmList last = getLast(list);
	T_stm lab = list->head;
	T_stm s = last->tail->head;
	S_enter(block_env, lab->u.LABEL, NULL);
	if (s->kind == T_JUMP) {
		T_stmList target = (T_stmList)S_look(block_env, s->u.JUMP.jumps->head);
		if (!s->u.JUMP.jumps->tail && target) {
			last->tail = target;	/* merge the 2 lists removing JUMP stm */
			trace(target);
		} else
			last->tail->tail = getNext();	/* merge and keep JUMP stm */
	}
	/* we want false label to follow CJUMP */
	else if (s->kind == T_CJUMP) {
		T_stmList true = (T_stmList)SymbolLookup(block_env, s->u.CJUMP.true);
		T_stmList false = (T_stmList)SymbolLookup(block_env, s->u.CJUMP.false);
		if (false) {
			last->tail->tail = false;
			trace(false);
		} else if (true) {	/* convert so that existing label is a false label */
			last->tail->head = T_Cjump(T_notRel(s->u.CJUMP.op),
				s->u.CJUMP.left, s->u.CJUMP.right, s->u.CJUMP.false, s->u.CJUMP.true);
			last->tail->tail = true;
			trace(true);
		} else {
			Temp_label false = Temp_newlabel();
			last->tail->head = T_Cjump(s->u.CJUMP.op, s->u.CJUMP.left, s->u.CJUMP.right, s->u.CJUMP.true, false);
			last->tail->tail = T_StmList(T_Label(false), getNext());
		}
	}
	else
		assert(0);
}
/* get the next block from the list of stmLists, using only those that have
 * not been traced yet */
static T_stmList getNext()
{
	if (!global_block.stmLists)
		return T_StmList(T_Label(global_block.label), NULL);
	else {
		T_stmList s = global_block.stmLists->head;
		if (SymbolLookup(block_env, s->head->u.LABEL)) {	/* label exists in the table */
			trace(s);
			return s;
		} else {
			global_block.stmLists = global_block.stmLists->tail;
			return getNext();
		}
	}
}
		 /* traceSchedule : Tree.stm list list * Tree.label -> Tree.stm list
		    From a list of basic blocks satisfying properties 1-6,
		    along with an "exit" label,
		    produce a list of stms such that:
		    1. and 2. as above;
		    7. Every CJUMP(_,t,f) is immediately followed by LABEL f.
		    The blocks are reordered to satisfy property 7; also
		    in this reordering as many JUMP(T.NAME(lab)) statements
		    as possible are eliminated by falling through into T.LABEL(lab).
		  */
T_stmList C_traceSchedule(struct C_block b)
{
	C_stmListList sList;
	block_env = SymbolEmpty();
	global_block = b;

	for (sList = global_block.stmLists; sList; sList = sList->tail) {
		SymbolEnter(block_env, sList->head->head->u.LABEL, sList->head);
	}

	return getNext();
}
