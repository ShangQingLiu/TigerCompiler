#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"

#define BUFSIZE 1024

void *checked_malloc(int size)
{
    static int count = 0;
    count += size;
    void *p = malloc(size);
    if (!p) {
        printf("Size: %d  %d\n", count, size);
    }
    assert(p);
    return p;
}

void *checked_realloc(void *p, size_t size)
{
	void *ptr = realloc(p, size);
	if (!ptr) {
		fprintf(stderr, "\nRand out of memory (realloc)!\n");
		exit(1);
	}
	return ptr;
}

void freeList(list_t l)
{
    list_t p;
    while (l)
    {
        p = l;
        l = l->tail;
        free(p);
    }
}

string_t string(const char *str)
{
    string_t p = checked_malloc(strlen(str) + 1);
    strcpy(p, str);
    return p;
}

string_t String_format(const char *s, ...)
{
	char buffer[BUFSIZE], *result = NULL;
	const char *p = s; /* cursor pointer */
	const char *str = NULL; /* pointer to variable argument strings */
	int len = 0; /* size of result */
	int i = 0; /* size of buffer */
	int n = 0; /* length of variable argument strings */
	bool isDigit = FALSE; /* needed so we can free memory allocated to string */
	va_list ap;
	va_start(ap, s);
	for (; *p; p++) {
		if (*p == '%') {
			switch (*++p) {
			case 's':
					str = va_arg(ap, const char *);
					break;
			case 'd':
					str = String_from_int(va_arg(ap, int));
					isDigit = TRUE;
					break;
			default:
					assert(0); /* Invalid format specifier */
			}
			n = strlen(str);
		} else {
			if (i < BUFSIZE - 1) {
				buffer[i++] = *p; continue;
			} else {
				str = p;
				n = 1;
			}
		}
		if (i + n > BUFSIZE) {
			result = checked_realloc(result, sizeof(*result) * (len + i + 1));
			if (len > 0) strncat(result, buffer, i);
			else strncpy(result, buffer, i);
			len += i;
			i = 0;
		}
		strncpy(buffer + i, str, n);
		i += n;
		if (isDigit) { free((void *)str); str = NULL; isDigit = FALSE; }
	}
	if (i > 0) {
		result = checked_realloc(result, sizeof(*result) * (len + i + 1));
		if (len > 0) strncat(result, buffer, i);
		else strncpy(result, buffer, i);
		/* can forget about i and len here, since we are exiting */
	}
	va_end(ap);
	return result;
}

string_t String_from_int(int n)
{
	char *str = checked_malloc(sizeof(*str) * (BUFSIZE + 1));
	snprintf(str, BUFSIZE + 1, "%d", n);
	return str;
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
        else if (data == p->data) return;
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
        if (pa->data > pb->data) {
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
        else if (pa->data == pb->data) {
            if (last != NULL) {
                last->tail = pa;
                last = pa;
                pa = pa->tail;
                pb = pb->tail;
            }
            else {
                last = pa;
                pa = pa->tail;
                pb = pb->tail;
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
