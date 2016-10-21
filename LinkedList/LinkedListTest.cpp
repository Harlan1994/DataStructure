//
// Created by Harlan on 2016/10/21.
//

#include <cstdio>
#include "LinkedList.h"

int main() {

    LinkedList L;
    init(L);

    while (true) {
        printf("*****************************\n");
        printf("*         1¡¢²åÈë            *\n");
        printf("*         2¡¢É¾³ý            *\n");
        printf("*         3¡¢´òÓ¡            *\n");
        printf("*         4¡¢ÍË³ö            *\n");
        printf("******************************\n");

        int op;
        scanf("%d", &op);
        switch (op) {
            case 1:
                int i;
                ElemType e;
                printf("input i & e:\n");
                scanf("%d %d", &i, &e);
                insert(L, i, e);
                break;
            case 2:
                int i1;
                ElemType *e1;
                delElem(L, i, e1);
                break;
            case 3:
                traverse(L);
                break;
            case 4:
                printf("%d\n", getLength(L));
            default:
                break;
        }
    }
}