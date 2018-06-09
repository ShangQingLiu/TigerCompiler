#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

string_t string(const char *str)
{
    string_t p = checked_malloc(strlen(str) + 1);
    strcpy(p, str);
    return p;
}

void *checked_malloc(int size)
{
    void *p = malloc(size);
    assert(p);
    return p;
}

list_t list(void *data, list_t tail)
{
    list_t p = checked_malloc(sizeof(*p));
    p->data = data;
    p->tail = tail;
    return p;
}

void addTo(void *data, list_t *head)
{
    *head = list(data, *head);
}

void addToOrder(void *data, list_t *head)
{
    list_t p, last = NULL;
    assert(head);
    for (p=*head; p; p=p->tail) {
        if (data > p->data) break;
        last = p;
    }
    if (last == NULL) {
        *head = list(data, *head);
    }
    else {
        last->tail = list(data, last->tail);
    }
}

void mergeList(list_t *a, list_t *b)
{
    list_t pa = *a, pb = *b, last = NULL, p;
    assert(a && b);
    if (*b == NULL) return;
    if (*a == NULL) {
        *a = *b;
        return;
    }

    while (pa && pb) {
        if (pa->data < pb->data) {
            if (last != NULL) {
                last->tail = pa;
                last = pa;
                pa = pa->tail;                
            }
            else {
                last = pa;
                pa = pa->tail; 
            }
        }
        else {
            if (last != NULL) {
                last->tail = pb;
                last = pb;
                pb = pb->tail; 
            }
            else {
                p = pb;
                pb = pb->tail;
                p->tail = pa;
                *a = p;
                last = p;
            }
        }
    }
    if (pa) last->tail = pa;
    else last->tail = pb;
}

char deleteFrom(void *data, list_t *head)
{
    list_t p, last = NULL;
    assert(head);
    for (p=*head; p; p=p->tail) {
        if (p->data == data)
            break;
        else last = p;
    }
    if (p == NULL) return 0;        // Not found

    if (last == NULL) {
        p = p->tail;
        free(*head);
        *head = p;
    }
    else {
        last->tail = p->tail;
        free(p);
    }
    return 1;
}

U_boolList U_BoolList(bool head, U_boolList tail)
{
	U_boolList list = checked_malloc(sizeof(*list));
	list->head = head;
	list->tail = tail;
	return list;
}
