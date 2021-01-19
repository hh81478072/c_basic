#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) { \
    typeof(a) tmp = a; \
    a = b; \
    b = tmp; \
}

void bubble_sort (int *arr, int len) {
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap (arr[j], arr[j + 1]);
    return;
}

void insert_sort (int *arr, int len) {
    int tmp, i, j;
    for (i = 0; i < len - 1; i++) {
        j = i + 1;
        tmp = arr[j];
        for (; j > 0 && arr[j - 1] > tmp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
    return;
}

int main() {
    //int test[] = {1 ,2 ,4 ,7, 9, -1};
    int test[] = {3,5,1,-7,4,9,-6,8,10,4};
    int ans[] = {-7, -6, 1, 3, 4, 4, 5, 8, 9, 10};
    int len = sizeof(test)/sizeof(int);
    
    for (int i = 0; i < len; i++)
        printf("%d ", test[i]);
    printf("\n");

    bubble_sort(test, len);
    insert_sort(test, len);
    for (int i = 0; i < len; i++)
        if(test[i] != ans[i]) {
            printf ("Wrong!!\n");
            break;
        }


    for (int i = 0; i < len; i++)
        printf("%d, ", test[i]);
    printf("\n");
    return 0;
}