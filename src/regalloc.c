#include "regalloc.h"
<<<<<<< HEAD
#include "assem.h"
#include "color.h"
#include "frame.h"
#include "graph.h"
#include "liveness.h"
#include "symbol.h"
#include "table.h"
#include "temp.h"
#include "utils.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "codegen.h"
#include "flowgraph.h"

static void insert_after(AS_instrList il, AS_instr i);
static void rewrite_inst(Temp_tempList tl, Temp_temp oldt, Temp_temp newt);

static void
insert_after(AS_instrList il, AS_instr i)
{
  assert(il && "il should not be NULL");
  AS_instrList tmp = AS_InstrList(i, il->tail);
  //  il->tail->head = i;
  //  il->tail->tail = tmp;
  il->tail = tmp;
}

static void
rewrite_inst(Temp_tempList tl, Temp_temp oldt, Temp_temp newt)
{
  bool D_found = FALSE;
  for (; tl; tl = tl->tail) {
    if (tl->head == oldt) {
      tl->head = newt;
      D_found = TRUE;
    }
  }
  assert(D_found);
}

enum { AS_USE, AS_DEF };
static void
rewrite(Temp_temp spill, AS_instrList il, F_frame f)
{
  // re-write code
  AS_instr i;
  AS_instrList last = NULL;
  Temp_tempList uses;
  Temp_tempList defs;
  Temp_tempList nextuses;

  F_access inmem = F_allocLocal(f, TRUE); // ESCAPE=TRUE. it's on stack
  //printf("rewrite\n");
  bool D_use_before_def = TRUE;
  for (; il; last = il, il = il->tail) {

    i = il->head;
    switch (i->kind) {
      case I_MOVE:
        uses = i->u.MOVE.src;
        defs = i->u.MOVE.dst;
        break;
      case I_OPER: {
        uses = i->u.OPER.src;
        defs = i->u.OPER.dst;
        break;
      }
      case I_LABEL:
        continue;
    }
    bool inuse = inList(uses, spill);
    bool indef = inList(defs, spill);
    if (inuse || indef) {
      
      D_use_before_def = FALSE;
      Temp_temp t0 = Temp_newtemp();
      char* buffer;

      if (indef) {
        // store after use
        // replace spill with t0.
        buffer = checked_malloc(64);
        rewrite_inst(defs, spill, t0);
        sprintf(buffer, "\tmovl `s0, %d(%%ebp) #spill\n", inmem->u.offset);
        insert_after(il, AS_Oper(buffer, NULL, Temp_Templist(t0, NULL), NULL));
        //printf("%s%d\n", buffer, t0->num);
      }
      if (inuse) {

        // load before use.
        buffer = checked_malloc(64);
        rewrite_inst(uses, spill, t0);
        sprintf(buffer, "\tmovl %d(%%ebp), `d0 #spill\n", inmem->u.offset);
        insert_after(last, AS_Oper(buffer, Temp_TempList(t0, NULL), NULL, NULL));
        //printf("%s%d\n", buffer, Temp_num(t0));
      }

      COL_add_newly_created(t0);
    }
  }
}

static void
rewrite_programm(Temp_tempList tl, AS_instrList il, F_frame f)
{
  Temp_printList(tl);
  for (; tl; tl = tl->tail) {
    Temp_temp t = tl->head;
    printf("Spill temporary:");
    Temp_print(t);
    rewrite(t, il, f);
    printf("=======\n");
  }
}

//
// MUUUHAHAHAHAHA
// Last step: delete duplicate moves.
// I love writing this function~~~
//
// Use recursive to end this lab because I'm tired
// of for(;xx;xx=xx->tail) pattern.
static AS_instrList
del_dup_move(AS_instrList il, Temp_map coloring)
{
  if (!il) return NULL;

  // MOVE always has single dst and src.
  if (il->head->kind == I_MOVE) {
    string_t d = Temp_look(coloring, il->head->u.MOVE.dst->head);
    string_t s = Temp_look(coloring, il->head->u.MOVE.src->head);
    if (strcmp(d, s) == 0) {
      //printf("delete dup move %s %s\n", d, s);
      return del_dup_move(il->tail, coloring);
    }
    //fprintf(stdout, "MOVE a format: assem=%s, dst=%p, src=%p\n",
      //      il->head->u.MOVE.assem, d, s);
  }

  return AS_InstrList(il->head, del_dup_move(il->tail, coloring));
}

struct RA_result
RA_regAlloc(F_frame f, AS_instrList il)
{
  // your code here.
  struct RA_result ret;

  int debug = 0;
  int upper = 10;

  //extern Temp_tempList newly_created; // color.c
  //newly_created = NULL;

  for (; debug < upper; debug++) {
    G_graph flowgraph = FG_AssemFlowGraph(il, f);
    struct Live_graph livegraph = Live_liveness(flowgraph);

    Temp_tempList regs = F_registers();
    struct COL_result cr =  COL_color(livegraph, F_tempMap, regs);

    ret.coloring = cr.coloring;

    if (!cr.spills) break;

   // printf("====actual spilling====\n");
    rewrite_programm(cr.spills, il, f);
  }
  assert(debug != upper && "spill error");

  il = del_dup_move(il, ret.coloring);
  ret.il = il;
  return ret;
=======
#include "color.h"
#include "graph.h"

struct RA_result RA_regAlloc(F_frame f, AS_instrList il)
{
	struct COL_result coloring = COL_color(G_empty(),
										F_tempMap, F_registers());
	struct RA_result result = {coloring.coloring, il};
	return result;
}

AS_instrList Rewrite(struct COL_result coloring, AS_instrList il)
{
	
>>>>>>> 8f88db788dff51a3fe06273ec249d88f8d1c967f
}
