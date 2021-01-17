/*
 * =====================================================================================
 *
 *       Filename:  Que.c
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
#include "Que.h"

struct QEle {
    void *data;
    QEle *next;
};

struct Que {
    QEle *head;
    QEle *tail;
};

Que *Que_init(void) {
    Que *q = malloc(sizeof(Que));

    q->head = NULL;
    q->tail = NULL;

    return q;
}

void Que_add(Que *q, void *d) {
    QEle *qe = malloc(sizeof(QEle));

    if (!qe)
        exit(-1);

    qe->data = d;
    qe->next = NULL;

    if (!q->head)
        q->head = qe;

    if (q->tail)
        q->tail->next = qe;

    q->tail = qe;
}

void Que_pop(Que *q) {
    QEle *qe = q->head;

    q->head = qe->next;

    if (!q->head) 
        q->tail = NULL;

    free(qe);
}

bool Que_empty(Que *q) {
    return !q->head && !q->tail;
}

void Que_clr(Que *q) {
    while (q->head)
        Que_pop(q);
}

void *Que_head(Que *q) {
    if (Que_empty(q))
        return NULL;

    return q->head->data;
}

void *Que_tail(Que *q) {
    if (Que_empty(q))
        return NULL;

    return q->tail->data;
}

void Que_exit(Que *q) {
    Que_clr(q);
    free(q);
}
