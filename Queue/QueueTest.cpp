//
// Created by Harlan on 2016/11/8.
//

#include "Queue.h"

int main() {
    LinkedQueue Q;
    init(&Q);

    int temp[11] = {1, 3, 2, 0, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 11; i++) {
        enQueue(&Q, temp[i]);
    }
    traverse(&Q);

    QElemType e;
    deQueue(&Q, &e);
    traverse(&Q);

    enQueue(&Q, 45);
    traverse(&Q);
    length(&Q);

    return 0;
}