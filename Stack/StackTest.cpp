//
// Created by Harlan on 2016/11/3.
//

#include "Stack.h"

int main() {
    Stack S;
    init(S);

    int arr[10] = {1, 3, 5, 6, 1, 8, 1, 7, 9, 10};
    for (int i = 0; i < 10; i++) {
        push(S, arr[i]);
    }
    traverse(S);
    ElemType e;
    pop(S, &e);
    getTop(S, &e);
    getLength(S);
    return 0;
}