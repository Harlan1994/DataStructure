//
// Created by Harlan on 2016/11/3.
//

#include "DLinkedList.h"

int main() {
    DLinkedList L;

    init(L);

    int arr[5] = {1, 2, 3, 6, 1};
    for (int i = 0; i < 5; i++) {
        insertElem(L, i + 1, arr[i]);
    }
    traverse(L);
    ElemType *e;
    deleteElem(L, 2, e);
    printf("e = %d\n", *e);

    getElem(L, 3, e);
    printf("get e = %d\n", *e);
    return 0;
}