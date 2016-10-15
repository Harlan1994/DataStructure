//
// Created by Harlan on 2016/10/15.
//

#include "SqList.h"

SqList L;

int main() {

    init(&L);
    while (true) {
        printf("*****************************\n");
        printf("*         1、插入            *\n");
        printf("*         2、删除            *\n");
        printf("*         3、打印            *\n");
        printf("*         4、退出            *\n");
        printf("******************************\n");
        int op;
        scanf("%d", &op);
        switch (op) {
            case 1: {
                printf("请输入插入位置和插入的值（空格隔开）：\n");
                int i;
                ElemType e;
                scanf("%d %d", &i, &e);
                Status result = insertElem(&L, i, e);
                if (result == OK)printf("插入成功。\n");
                printf("序列为：\n");
                traverse(&L);
                break;
            }
            case 2: {
                printf("请输入删除的值的位置：");
                int j;
                ElemType e1;
                scanf("%d", &j);
                Status result1 = deleteElem(&L, j, &e1);
                if (result1 == OK)printf("删除成功。\n");
                printf("您删除的值为 e = %d\n", e1);
                break;
            }
            case 3:{
                printf("序列为：\n");
                traverse(&L);
                break;
            }
            case 4:
                return 0;
            default:
                break;
        }
    }
}