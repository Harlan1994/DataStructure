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

/**
 * the first Node will store the length of the list.
 */
typedef struct DLNode {
    ElemType data;
    struct DLNode *pre;
    struct DLNode *next;
} *DLinkedList;

/**
 * Initialize a DLinkedList.
 * the head Node will record the length of the list.
 * @param L
 */
void init(DLinkedList &L) {
    L = (DLinkedList) malloc(sizeof(DLNode));
    if (!L) {
        printf("Initialized failed!\n");
        return;
    }
    L->pre = NULL;
    L->next = NULL;
    L->data = 0;
    printf("L has been initialized successfully!\n");
}

/**
 * Insert e into position i, element e will be the i'th element of L.
 * @param L
 * @param i
 * @param e
 */
void insertElem(DLinkedList &L, int i, ElemType e) {
    if (!L) {
        printf("L cannot be NULL!\n");
        return;
    }
    DLinkedList p = L;
    int j = 0;

    while (p && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!p || j > i - 1) {
        printf("Illegal insert positon, i = %d\n", i);
        return;
    }

    DLinkedList s = (DLinkedList) malloc(sizeof(DLNode));
    s->data = e;
    s->next = p->next;
    if (p->next != NULL)
        p->next->pre = s;
    s->pre = p;
    p->next = s;
    L->data++;
    printf("The element e = %d has been inserted into position = %d successfully!\n", e, i);
}

/**
 * delete the i'th element, and assign e with the data of the deleted elem.
 * @param L
 * @param i
 * @param e
 */
void deleteElem(DLinkedList &L, int i, ElemType *e) {
    if (!L) {
        printf("L cannot be NULL!\n");
        return;
    }
    int j = 1;
    DLinkedList p = L->next, q;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) {
        printf("Ilegal index!\n");
        return;
    }
    q = p->next;
    (*e) = q->data;
    p->next = q->next;
    if (q->next != NULL)q->next->pre = p;
    free(q);
    printf("The element e = %d has been deleted successfully!\n", *e);
}

/**
 * Visit a DLinkedList, print all its elements.
 * @param L
 */
void traverse(DLinkedList &L) {
    if (!L) {
        printf("L cannot be NULL!\n");
        return;
    }
    DLinkedList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * get the i'th elem. and return.
 * @param L
 * @param i
 * @return
 */
void getElem(DLinkedList &L, int i, ElemType *e) {
    if (!L) {
        printf("L cannot be NULL!\n");
        return;
    }
    DLinkedList p = L;
    int j = 0;

    while (p && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!p || j > i - 1) {
        printf("Illegal insert positon, i = %d\n", i);
        return;
    }

    (*e) = p->next->data;
    printf("The element is assigned to e.\n");
}

int isEmpty(DLinkedList &L){
    if(L->next == NULL)return TRUE;
    return FALSE;
}

void destroy(DLinkedList &L){
    DLinkedList tmp;
    while(L){
        tmp = L->next;
        free(L);
        L = tmp;
    }
}

#endif //DATASTRUCTURE_DLINKEDLIST_H
