// 哈希表大小可变（参考作业）

#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "table.h"

#define TABSIZE 127

typedef struct binder_ *binder;
struct binder_
{
	void *key;
	void *value;
	binder next;
	void *prevtop;
};

struct table_s
{
	binder table[TABSIZE];
	void *top;
};

// Initiate a new binder
static binder Binder(void *key, void *value, binder next, void *prevtop)
{
	binder b = checked_malloc(sizeof(*b));
	b->key = key;
	b->value = value;
	b->next = next;			// Linked list in one bucket
	b->prevtop = prevtop;	// Store for popping top element
	return b;
}

// Create an empty table
table_t TableEmpty(void)
{
	table_t t = checked_malloc(sizeof(*t));
	memset(t, 0, sizeof(*t));
}

// Insert an item to table
void TableEnter(table_t t, void *key, void *value)
{
	int index;
	assert(t && key);
	index = ((unsigned)key) % TABSIZE;
	t->table[index] = Binder(key, value, t->table[index], t->top);
	t->top = key;
}

// Look up a key in the table for its value. NULL for notfound
void *TableLookup(table_t t, void *key)
{
	int index;
	binder b;
	assert(t && key);
	index = ((unsigned)key) % TABSIZE;
	// Search in the linked list
	for (b = t->table[index]; b; b = b->next)
		if (b->key == key)
			return b->value;
	return NULL;
}

// Pop the top item
void *TablePop(table_t t)
{
	void *k;
	binder b;
	int index;
	assert(t);
	k = t->top;
	assert(k);
	index = ((unsigned)k) % TABSIZE;
	b = t->table[index];
	assert(b);
	t->table[index] = b->next;
	t->top = b->prevtop;
	return b->key;
}

// Show the table
void TableDump(table_t t, tab_dump_func_t show)
{
	void *k = t->top;
	int index = ((unsigned)k) % TABSIZE;
	binder b = t->table[index];
	if (b == NULL)
		return;
	t->table[index] = b->next;
	t->top = b->prevtop;
	show(b->key, b->value);
	TAB_dump(t, show);
	assert(t->top == b->prevtop && t->table[index] == b->next);
	t->top = k;
	t->table[index] = b;
}
