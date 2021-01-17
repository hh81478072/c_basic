#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack Stack;
typedef struct SEle SEle;
typedef void Data;

Stack* Stack_init(void);
Stack* Stack_init_arr(void **arr, int len);
void Stack_register_str(Stack *s, void *data_str);
void Stack_exit(Stack *s);
void Stack_add(Stack *s, void *d);
void Stack_pop(Stack *s);
void Stack_clr(Stack *s);
bool Stack_empty(Stack *s);
Data* Stack_top(Stack *s);
void Stack_print(Stack *s);

#endif
