#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ring {
    int *buf;
    int head;
    int tail;
    int cnt;
    int size;
};

int ring_init (struct ring **r, int size)
{
    *r = calloc(1, sizeof(struct ring));
    (*r)->buf = calloc(size, sizeof(int));
    (*r)->size = size;

    return 0;
}

bool ring_is_full (struct ring *r)
{
    return (r->cnt >= r->size);
}

int ring_add (struct ring *r, int item)
{
    if (ring_is_full(r)) {
        return -1;
    }

    r->buf[r->tail] = item;
    r->tail = (r->tail + 1) % r->size;
    r->cnt++;

    return 0;
}

int ring_del (struct ring *r)
{
    if (!r->cnt) {
        return -1;
    }

    r->head = (r->head + 1) % r->size;
    r->cnt--;

    return 0;
}

int ring_head (struct ring *r)
{
    if (!r->cnt) {
        return -1;
    }

    return r->buf[r->head];
}

int ring_tail (struct ring *r)
{
    if (!r->cnt) {
        return -1;
    }

    return r->buf[r->tail];
}

void ring_print_all (struct ring *r)
{
    int i;

    for (i = 0; i < r->size; i++) {
        printf("%d, ", r->buf[i]);
    }
    printf("\n");
}

void ring_print (struct ring *r)
{
    int i, j;

    for (i = 0; i < r->cnt; i++) {
        j = (r->head + i) % r->size;
        printf("%d, ", r->buf[j]);
    }
    printf("\n");
}

int main() {
    struct ring *r;

    ring_init(&r, 8);

    ring_add(r, 1);
    ring_add(r, 3);
    ring_add(r, 3);
    ring_add(r, 1);
    ring_add(r, 4);
    ring_add(r, 2);
    ring_add(r, 3);
    ring_add(r, 1);

    ring_print(r);

    ring_del(r);
    ring_print(r);

    ring_del(r);
    ring_del(r);
    ring_del(r);
    ring_del(r);
    ring_del(r);
    ring_del(r);
    ring_del(r);
    ring_del(r);
    ring_del(r);

    ring_print(r);
    printf("====\n");

    ring_add(r, 5);
    ring_add(r, 3);
    ring_add(r, 5);
    ring_add(r, 1);
    ring_add(r, 9);
    ring_add(r, 2);
    ring_add(r, 4);
    ring_add(r, 1);

    ring_print(r);
    return 0;
}
