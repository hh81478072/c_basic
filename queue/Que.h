/*
 * =====================================================================================
 *
 *       Filename:  Que.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/28/2020 04:37:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hchkuo (), hchkuo@avery-design.com.tw
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef QUE_H
#define QUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QEle QEle;
typedef struct Que Que;

Que *Que_init(void);
void Que_exit(Que *q);
void Que_add(Que *q, void *d);
void Que_pop(Que *q);
void Que_clr(Que *q);
bool Que_empty(Que *q);
void *Que_head(Que *q);
void *Que_tail(Que *q);

#endif
