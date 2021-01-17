/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/28/2020 03:26:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hchkuo (), hchkuo@avery-design.com.tw
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "Que.h"

typedef struct S {
    char c;
    int i;
} S;

typedef struct TQe {
    void *data;
    void *next;
} TQe;

int main() {
    Que *q;
    S *s;

    q = Que_init();
    
    Que_add(q, (void*)20);
    Que_add(q, (void*)2);
    Que_add(q, (void*)33);
    Que_add(q, (void*)123);

    if (Que_empty(q))
        printf ("EMPTY\n");
    else
        printf ("NOT EMPTY\n");

    Que_pop(q);
    Que_pop(q);
    Que_add(q, (void*)200);

    printf("h: %lu, t: %lu\n", (size_t)Que_head(q), (size_t)Que_tail(q));

    Que_clr(q);
    if (Que_empty(q))
        printf ("EMPTY\n");
    else
        printf ("NOT EMPTY\n");

    s = malloc(sizeof(S));
    s->c='a';
    s->i=1;
    Que_add(q, (void*)s);

    s = malloc(sizeof(S));
    s->c='b';
    s->i=2;
    Que_add(q, (void*)s);

    s = malloc(sizeof(S));
    s->c='c';
    s->i=3;
    Que_add(q, (void*)s);

    s = malloc(sizeof(S));
    s->c='d';
    s->i=4;
    Que_add(q, (void*)s);

    for (; !Que_empty(q); Que_pop(q)) {
        s = (S*)Que_head(q);
        printf ("c: %c, i: %d\n", s->c, s->i);
    }
    s = (S*)Que_head(q);

    Que_exit(q);

    return 0;
}
