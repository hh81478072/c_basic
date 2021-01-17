/*
 * =====================================================================================
 *
 *       Filename:  Stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/28/2020 04:38:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hchkuo (), hchkuo@avery-design.com.tw
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Stack.h"

struct SEle {
    Data *data;
    SEle *prev;
};

struct Stack {
    SEle *top;
    char* (*data_str)(Data *data);
};

static char* data_str(Data *data) {
    char* buf= malloc(1024);

    sprintf (buf, " val: %d", *(int*)data);

    return buf; 
} 

Stack* Stack_init(void) {
    Stack *s = malloc(sizeof(Stack));

    s->top = NULL;
    s->data_str = data_str;

    return s;
}

void Stack_register_str(Stack *s, void *data_str) {
    s->data_str = data_str;
}

Stack* Stack_init_arr(void **arr, int len) {
    Stack *s = Stack_init();
    int i;
    
    for (i = 0; i < len; i++)
        Stack_add(s, arr[i]);

    return s;
}

void Stack_add(Stack *s, void *d) {
    SEle *se = malloc(sizeof(SEle));

    if (!se)
        exit(-1);

    se->data = d;
    se->prev = s->top;
    
    s->top = se;
}

void Stack_pop(Stack *s) {
    SEle *se = s->top;

    s->top = se->prev;

    free(se);
}

bool Stack_empty(Stack *s) {
    return !s->top;
}

void Stack_clr(Stack *s) {
    while (s->top)
        Stack_pop(s);
}

Data* Stack_top(Stack *s) {
    if (Stack_empty(s))
        return NULL;

    return s->top->data;
}

void Stack_exit(Stack *s) {
    Stack_clr(s);
    free(s);
}

void Stack_print(Stack *s) {
    SEle *se;
    int i;
    char *buf;

    se = s->top;
    i = 0;

    while (se) {
        buf = s->data_str(se->data);
        if (!i)
            printf ("[top     ]: %s\n", buf);
        else
            printf ("[top - %02d]: %s\n", i, buf);
        free(buf);
        se = se->prev;
        i++;
    }
} 
