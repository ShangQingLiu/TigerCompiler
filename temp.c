/*
 * temp.c - functions to create and manipulate temporary variables which are
 *          used in the IR tree representation before it has been determined
 *          which variables are to go into registers.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "symbol.h"
#include "temp.h"
#include "table.h"

struct Temp_temp_ {int num;};

string_t Temp_labelstring(Temp_label s)
{return SymbolName(s);
}

static int labels = 0;

TL_table TL_empty(void)
{
	return TableEmpty();
}

void TL_enter(TL_table t, Temp_label label, void *v)
{
	return TableEnter(t, label, v);
}

void *TL_look(TL_table t, Temp_label label)
{
	return TableLookup(t, label);
}

Temp_label Temp_newlabel(void)
{char buf[100];
 sprintf(buf,"L%d",labels++);
 return Temp_namedlabel(string(buf));
}

/* The label will be created only if it is not found. */
Temp_label Temp_namedlabel(string_t s)
{return Symbol(s);
}

static int temps = 100;

Temp_temp Temp_newtemp(void)
{Temp_temp p = (Temp_temp) checked_malloc(sizeof (*p));
 p->num=temps++;
 {char r[16];
  sprintf(r, "%d", p->num);
  Temp_enter(Temp_name(), p, string(r));
 }
 return p;
}



struct Temp_map_ {table_t tab; Temp_map under;};


Temp_map Temp_name(void) {
 static Temp_map m = NULL;
 if (!m) m=Temp_empty();
 return m;
}

Temp_map newMap(table_t tab, Temp_map under) {
  Temp_map m = checked_malloc(sizeof(*m));
  m->tab=tab;
  m->under=under;
  return m;
}

Temp_map Temp_empty(void) {
  return newMap(TableEmpty(), NULL);
}

Temp_map Temp_layerMap(Temp_map over, Temp_map under) {
  if (over==NULL)
      return under;
  else return newMap(over->tab, Temp_layerMap(over->under, under));
}

void Temp_enter(Temp_map m, Temp_temp t, string_t s) {
  assert(m && m->tab);
  TableEnter(m->tab,t,s);
}

string_t Temp_look(Temp_map m, Temp_temp t) {
  string_t s;
  assert(m && m->tab);
  s = TableLookup(m->tab, t);
  if (s) return s;
  else if (m->under) return Temp_look(m->under, t);
  else return NULL;
}

Temp_tempList Temp_TempList(Temp_temp h, Temp_tempList t) 
{Temp_tempList p = (Temp_tempList) checked_malloc(sizeof (*p));
 p->head=h; p->tail=t;
 return p;
}

Temp_tempList Temp_TempList_join(Temp_tempList first, Temp_tempList second)
{
	if (first != NULL && first != second) {
		Temp_tempList iter = first;
		for (; iter->tail; iter = iter->tail)
			;
		iter->tail = second;
	}
	return first;
}

Temp_tempList TL(Temp_temp t, Temp_tempList l)
{
	return Temp_TempList(t, l);
}

Temp_labelList Temp_LabelList(Temp_label h, Temp_labelList t)
{Temp_labelList p = (Temp_labelList) checked_malloc(sizeof (*p));
 p->head=h; p->tail=t;
 return p;
}

static FILE *outfile;
void showit(Temp_temp t, string_t r) {
  fprintf(outfile, "t%d -> %s\n", t->num, r);
}

void Temp_dumpMap(FILE *out, Temp_map m) {
  outfile=out;
  TAB_dump(m->tab,(void (*)(void *, void*))showit);
  if (m->under) {
     fprintf(out,"---------\n");
     Temp_dumpMap(out,m->under);
  }
}
