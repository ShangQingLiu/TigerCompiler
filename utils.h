#ifndef _UTILS_H_
#define _UTILS_H_

#include <assert.h>

typedef char* string_t;
string_t string(const char *str);

typedef char bool;

#define TRUE 1
#define FALSE 0

void* checked_malloc(int);

typedef struct list_s *list_t;

struct list_s {
    union {
        int i;
        bool b;
        void *data;
    };
    struct list_s *tail;
};

list_t list(void* data, list_t tail);
void addTo(void *data, list_t *head);
void addToOrder(void *data, list_t *head);
char deleteFrom(void *data, list_t *head);
void mergeList(list_t *a, list_t *b);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_ {bool head; U_boolList tail;};
U_boolList U_BoolList(bool head, U_boolList tail);


#endif
