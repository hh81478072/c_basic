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

#include "Stack.h"

typedef struct S {
    char c;
    int i;
} S;

char* print_data(void* data) {
    S* s;
    char* buf= malloc(1024);

    s = (S*)data;

    sprintf (buf, " []   c: %c, i: %d", s->c, s->i);

    return buf; 
}

int main() {
    Stack *q;
    S *s;
    int a, *tmp = NULL;

    q = Stack_init();
    Stack_register_str(q, &print_data);

    Stack_add(q, (void*)20);
    Stack_add(q, (void*)2);
    Stack_add(q, (void*)33);
    Stack_add(q, (void*)123);

    if (Stack_empty(q))
        printf ("EMPTY\n");
    else
        printf ("NOT EMPTY\n");

    Stack_pop(q);
    Stack_pop(q);
    Stack_add(q, (void*)200);

    printf("h: %lu, t: %lu\n", (size_t)Stack_top(q), (size_t)Stack_top(q));

    Stack_clr(q);
    if (Stack_empty(q))
        printf ("EMPTY\n");
    else
        printf ("NOT EMPTY\n");

    s = malloc(sizeof(S));
    s->c='a';
    s->i=1;
    Stack_add(q, (void*)s);

    s = malloc(sizeof(S));
    s->c='b';
    s->i=2;
    Stack_add(q, (void*)s);

    s = malloc(sizeof(S));
    s->c='c';
    s->i=3;
    Stack_add(q, (void*)s);

    s = malloc(sizeof(S));
    s->c='d';
    s->i=4;
    Stack_add(q, (void*)s);

//    for (; !Stack_empty(q); Stack_pop(q)) {
//        s = (S*)Stack_top(q);
//        printf ("c: %c, i: %d\n", s->c, s->i);
//    }
    Stack_print(q);
    s = (S*)Stack_top(q);

    Stack_exit(q);


    void* arr[5];
    for (a = 0; a < 5; a++) {
        tmp = malloc(sizeof(int));
        *tmp = a + 55;
        arr[a] = (void*)(tmp); 
    }

    q = Stack_init_arr(arr, 5); 
    Stack_print(q);
    Stack_pop(q);
    printf("\n");
    Stack_print(q);

    Stack_exit(q);
    return 0;
}
