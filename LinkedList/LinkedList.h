//
// Created by Harlan on 2016/10/15.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

#include <cstdio>
#include <cstdlib>

#define OK 1
#define ERROR -1
#define TRUE 2
#define FALSE -2

typedef int ElemType;
typedef int Status;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

/**
 * Initialize a LinkedList
 * @param L
 * @return Status(OK, ERROR)
 */
Status init(LinkedList &L) {
    L = (LinkedList) malloc(sizeof(LNode));
    if (!L)return ERROR;
    L->next = NULL;
    printf("initialized successfully!\n");
    return OK;
}

/**
 * destroy a LinkedList, free the memory.
 * @param L
 * @return
 */
Status destroy(LinkedList &L) {
    LinkedList tmp;
    while (L) {
        tmp = L->next;
        free(L);
        L = tmp;
    }
}

/**
 * judge if a LinkedList is empty.
 * @param L
 * @return
 */
Status isEmpty(LinkedList &L) {
    if (!L)return ERROR;
    return L->next == NULL ? TRUE : FALSE;
}

int getLength(LinkedList &L) {
    if (!L)return ERROR;
    int length = 0;
    LinkedList p = L->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

/**
 * get the i'th Elem.
 * @param L
 * @param i
 * @param e
 * @return
 */
Status getElem(LinkedList &L, int i, ElemType *e) {
    if (!L)return ERROR;
    if (i < 1)return ERROR;
    LinkedList p = L->next;
    int j = 1;
    while (p && j < i) {
        j++;
        p = p->next;
    }
    if (!p || j > i)return ERROR;
    (*e) = p->data;
    return OK;
}

/**
 * compare two Elem.
 * @param e1
 * @param e2
 * @return
 */
Status compare(ElemType e1, ElemType e2) {
    return e1 == e2 ? 0 : (e1 > e2 ? 1 : -1);
}

/**
 * find a Elem in a LinkedList
 * @param L
 * @param e
 * @return return ERROR if errors occurred, 0 if not found, i if found.
 */
int find(LinkedList &L, ElemType e) {
    if (!L)return ERROR;
    LinkedList p = L->next;
    int i = 1;
    while (p) {
        if (compare(p->data, e) == 0) {
            printf("target found!\n");
            return i;
        }
        i++;
        p = p->next;
    }
    printf("target not found!\n");
    return 0;
}

/**
 * find the previous elem of cur_e
 * @param L
 * @param cur_e
 * @param pre_e
 * @return return 0 if not find, ERROR if errors occurred, OK if found.
 */
Status preElem(LinkedList &L, ElemType cur_e, ElemType *pre_e) {
    if (!L)return ERROR;
    LinkedList p, q;
    p = L->next;
    q = L;
    while (p) {
        if (compare(p->data, cur_e) == 0) {
            if (q != L) {
                (*pre_e) = q->data;
                return OK;
            } else { //cur_e is the first elem.
                printf("cur_e is the first elem.\n");
                return 0;
            }
        } else {
            q = p;
            p = p->next;
        }
    }
    return 0;
}

/**
 * find the next elem of cur_e
 * @param L
 * @param cur_e
 * @param next_e
 * @return return 0 if not find, ERROR if errors occurred, OK if found.
 */
Status nextElem(LinkedList &L, ElemType cur_e, ElemType *next_e) {
    if (!L)return ERROR;
    LinkedList p = L->next;
    while (p) {
        if (compare(p->data, cur_e) == 0) {
            if (p->next) {
                (*next_e) = p->next->data;
                return OK;
            } else {
                printf("cur_e is the last elem.\n");
                return 0;
            }
        } else {
            p = p->next;
        }
    }
    return 0;
}

/**
 * insert an elem into a LinkedList.
 * @param L
 * @param i
 * @param e
 * @return OK if succeeded, ERROR if errors occurred.
 */
Status insert(LinkedList &L, int i, ElemType e) {
    int j = 0;
    LinkedList s, p = L;
    while (p && j < i - 1) {
        j++;
        p = p->next;
    }
    if (!p || j > i - 1) {
        return ERROR;
    }
    s = (LinkedList) malloc(sizeof(LNode));
    if (!s)return ERROR;
    s->data = e;
    s->next = p->next;
    p->next = s;
    printf("inserted successfully!\n");
    return OK;
}

/**
 * delete the i'th elem.
 * @param L
 * @param i
 * @param e
 * @return OK if succeeded, ERROR if errors occurred.
 */
Status delElem(LinkedList &L, int i, ElemType *e) {
    if (!L)return ERROR;
    LinkedList p = L->next, q;
    int k = 1;
    while (p && k < i - 1) {
        p = p->next;
        k++;
    }
    if (!p || k > i - 1)return ERROR;
    q = p->next;
    (*e) = q->data;
    p->next = q->next;
    free(q);
    printf("deleted successfully with e = %d!\n", *e);
    return OK;
}

/**
 * traverse a LinkedList.
 * @param L
 */
void traverse(LinkedList &L) {
    if (!L) {
        printf("L == NULL!\n");
        return;
    }
    LinkedList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

#endif //DATASTRUCTURE_LINKEDLIST_H
