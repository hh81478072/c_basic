#include "stdio.h"
#include "stdint.h"
#include "inttypes.h"
#include "../stack/Stack.h"
#include "time.h"

typedef struct TNode TNode;
typedef struct BST BST;

struct TNode {
    void *data;
    TNode *left;
    TNode *right;
};

struct cache {
    int size;
    int height;
    bool dirty;
};

struct BST {
    TNode *root;
    bool (*is_larger)(void *a, void *b);
};

static bool is_larger(void *a, void *b) {
    return a > b;
}

static TNode *TNode_init(void* data) {
    TNode *ptr = malloc(sizeof(TNode));

    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

BST *BST_init(void) {
    BST *b = malloc(sizeof(BST));

    b->root = NULL;
    b->is_larger = is_larger;

    return b;
}

void BST_register_larger(BST *b, void* is_larger) {
    b->is_larger = is_larger;
}

typedef enum Ret_from {
    NONE,
    LEFT,
    RIGHT,
} Ret_from;

void BST_inorder(BST *b) {
    TNode *ptr, *parent;
    Stack *s;
    Ret_from ret_from = NONE;

    ptr = b->root;
    s = Stack_init();
    Stack_add(s, (void*)ptr);

    while (!Stack_empty(s)) {
        ptr = (TNode*)Stack_top(s);

        if ((!ptr->left && !ptr->right) ||
            (ret_from == LEFT && !ptr->right) ||
            ret_from == RIGHT) {
            Stack_pop(s);
            if (ret_from != RIGHT)
                printf("val: %d\n", (int)ptr->data);

            parent = (TNode*)Stack_top(s);
            if (!parent)
                break;
            if (ptr == parent->left)
                ret_from = LEFT;
            else
                ret_from = RIGHT;
        } else if (ret_from == NONE && ptr->left) {
            Stack_add(s, (void*)ptr->left);
            ptr = ptr->left;
        } else if (ret_from != RIGHT && ptr->right) {
            printf("val: %d\n", (int)ptr->data);
            ret_from = NONE;
            Stack_add(s, (void*)ptr->right);

            ptr = ptr->right;
        }
    }
}

void BST_trav2(TNode *n) {
    if (!n)
        return;

    BST_trav2(n->left);
    printf("val: %d\n", (int)n->data);
    BST_trav2(n->right);
}

void BST_add(BST *b, void *data) {
    TNode *ptr;

    ptr = b->root;

    if (!ptr) {
        b->root = TNode_init(data);
        return;
    }

    while (1) {
        if (b->is_larger(ptr->data, data)) {
            if (ptr->left)
                ptr = ptr->left;
            else {
                ptr->left = TNode_init(data);
                return;
            }
        } else {
            if (ptr->right)
                ptr = ptr->right;
            else {
                ptr->right = TNode_init(data);
                return;
            }
        }
    }
};


int main (int argc, char *argv[]) {
    BST *b;
    int *p;
    clock_t t;
    double time_taken;
    double time_taken2;

    b = BST_init();
    p = 1;
    BST_add(b, p);
    p = 2;
    BST_add(b, p);
    p = 4;
    BST_add(b, p);
    p = 3;
    BST_add(b, p);
    p = 4;
    BST_add(b, p);
    p = 4;
    BST_add(b, p);
    BST_add(b, 17382);
    BST_add(b, 1273);
    BST_add(b, 147);
    BST_add(b, 1373897);

    for(int i = 0; i < INT_MAX; i++){
        BST_add(b, i);
    }

    t = clock();
//    BST_trav2(b->root);
    BST_inorder(b);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

//    t = clock();
//    BST_inorder(b);
//    t = clock() - t;
//    time_taken2 = ((double)t)/CLOCKS_PER_SEC; // in seconds
//
    printf("1 took %f seconds to execute \n", time_taken);
//    printf("2 took %f seconds to execute \n", time_taken2);
    return 0;
}
