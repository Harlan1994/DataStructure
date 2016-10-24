//
// Created by Harlan on 2016/10/24.
//

#ifndef DATASTRUCTURE_DLINKEDLIST_H
#define DATASTRUCTURE_DLINKEDLIST_H

#include <malloc.h>
#include <stdio.h>

#define OK 1
#define ERROR -1
#define TRUE 2
#define FALSE -2

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *pre;
    struct DNode *next;
} *DLinkedList;

void init(DLinkedList &L) {
    L = (DLinkedList) malloc(sizeof(DNode));
    if (!L) {
        printf("Initialized failed!");
        return;
    }
    L->pre = NULL;
    L->next = NULL;

}

#endif //DATASTRUCTURE_DLINKEDLIST_H
