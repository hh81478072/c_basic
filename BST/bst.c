#include "stdio.h"
#include "stdint.h"
#include "inttypes.h"
#include "../stack/Stack.h"

typedef struct TNode TNode;
typedef struct BST BST;

struct TNode {
    void *data;
    Tnode *left;
    Tnode *right;
} TNode;

struct BST {
    TNode *root;
    bool (*is_larger)(void *a, void *b); 
};

static bool is_larger(void *a, void *b) {
    return (int)a > (int)b;
}

static TNode *TNode_init(void* data) {
    TNode *ptr = malloc(sizeof(TNode));

    ptr->data = data;
    ptr->left = NULL;
    prt->right = NULL;

    return ptr;
}

BST *BST_init(void* is_larger) {
    BST *b = malloc(sizeof(BST));

    b->root = NULL;
    if (f)
        b->is_larger = is_larger;
    
    return b;
}

typedef enum Ret_from {
    NONE,
    LEFT,
    RIGHT,
} Ret_from;

void BST_trav(BST *b) {
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
            parent = (TNode*)Stack_top(s);

            if (!ptr->left && !ptr->right)
                //PRINT
            if (ptr = parent->left)
                ret_from = LEFT;
            else
                ret_from = RIGHT;
        } else if (ret_from == NONE && ptr->left) {
            Stack_add(s, (void*)ptr->left);
            ptr = ptr->left;
        } else if (ret_from != RIGHT && ptr->right) {
            //PRINT
            ret_from = NONE;
            Stack_add(s, (void*)ptr->right);
            ptr = ptr->right;
        }
    } 
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
    int m[8];
    for(int i = 0; i < 8; i++)
        m[i] = i;
    for(int i = 0; i < 8; i++) {
        printf ("+%d\n", *(m + i));
        printf ("[]%d\n", (&m[i]));
    }
/////////////////////////
    uint8_t ui=255;
    printf ("UI: %"PRIx8"\n", ui);
    printf ("UI: %"PRIx8"\n", ++ui);
    printf ("UI: %"PRIx8"\n", ++ui);
    printf ("UI: %"PRIx8"\n", ++ui);
    printf ("UI: %"PRIx8"\n", ++ui);
    printf ("UI: %"PRIx8"\n", ++ui);
    return 0;
}
