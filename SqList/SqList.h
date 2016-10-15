///////////////////////////////////
// Created by Harlan on 2016/10/15.
///////////////////////////////////

#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H

#include <cstdio>
#include <cstdlib>

#define OK 1
#define ERROR -1
#define TRUE 2
#define FALSE -2
#define INIT_SIZE 20
#define INCREMENT 10

typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType *elem;
    int length;
    int size;
} SqList;

/**
 * Initialize a SqList and return OK(1) if succeeded, ERROR(0) if failed.
 * @param L a SqList that needs to be initialized.
 * @return Status(OK, ERROR)
 */
Status init(SqList *L) {
    L->elem = (ElemType *) malloc(sizeof(ElemType) * INIT_SIZE);
    if (!L->elem)return ERROR;
    L->length = 0;
    L->size = INIT_SIZE;
    return OK;
}

/**
 * Destroy a SqList.
 * @param L A SqList that needs to be destroyed.
 * @return Status(OK, ERROR)
 */
Status destroy(SqList *L) {
    if (!L)return ERROR;
    free(L->elem);
    L->length = 0;
    L->size = 0;
    return OK;
}

/**
 * Clear a SqList, set its length to 0.
 * @param L the operation target.
 * @return Status(OK, ERROR)
 */
Status clear(SqList *L) {
    if (!L)return ERROR;
    L->length = 0;
    return OK;
}

/**
 * Judge if L is empty
 * @param L
 * @return return ERROR if error occurred, TRUE if is empty, FALSE if is not empty.
 */
Status isEmpty(const SqList *L) {
    if (!L)return ERROR;
    if (L->length <= 0)return TRUE;
    return FALSE;
}

/**
 * Get the length of L
 * @param L
 * @return ERROR if error occurred or return the length of L.
 */
int getLength(const SqList *L) {
    if (!L)return ERROR;
    return L->length;
}

/**
 * Get the element at index, return Status.
 * @param L
 * @param index
 * @param e If successed, e should be assigned the value of the target.
 * @return Status(OK, ERROR)
 */
Status getElem(const SqList *L, int index, ElemType *e) {
    if (index < 0 || index > L->length - 1)return ERROR;
    *e = L->elem[index];
    return OK;
}

/**
 * Compare two elements.
 * @param e1
 * @param e2
 * @return return 0 if e1 == e2, 1 if e1 > e2, -1 if e1 < e2.
 */
Status compare(const ElemType e1, const ElemType e2) {
    return e1 > e2 ? 1 : (e1 == e2 ? 0 : -1);
}

/**
 * find a specific element.
 * @param L
 * @param e
 * @return the index if found, ERROR if not found.
 */
Status findElem(const SqList *L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (compare(e, L->elem[i]) == 1) {
            return i;
        }
    }
    return ERROR;
}

/**
 * get the previous element of cur_e.
 * @param L
 * @param cur_e
 * @param pre_e
 * @return Status OK if found, ERROR if not.
 */
Status getPreElem(const SqList *L, const ElemType cur_e, ElemType *pre_e) {
    for (int i = 0; i < L->length; i++) {
        if (compare(cur_e, L->elem[i])) {
            if (i == 0)return ERROR;
            *pre_e = L->elem[i - 1];
            return OK;
        }
    }
    return ERROR;
}

/**
 * get the next element of cur_e.
 * @param L
 * @param cur_e
 * @param next_e
 * @return Status OK if found, ERROR if not.
 */
Status getNextElem(const SqList *L, const ElemType cur_e, ElemType *next_e) {
    for (int i = 0; i < L->length; i++) {
        if (compare(cur_e, L->elem[i])) {
            if (i == L->length - 1)return ERROR;
            *next_e = L->elem[i + 1];
            return OK;
        }
    }
    return ERROR;
}

/**
 * Insert a element to the specific position.
 * @param L
 * @param p insert e to No. p position.
 * @param e the element to be inserted.
 * @return Status OK if found, ERROR if not.
 */
Status insertElem(SqList *L, const int p, const ElemType e) {
    if (!L)return ERROR;

    //Judge if the insertion is legal.
    if (p < 1 || p > L->length + 1)return ERROR;
    ElemType *newList;
    // If the current size is not enough, realloc it with INCREMENT spaces added.
    if (L->length + 1 > L->size) {
        newList = (ElemType *) realloc(L->elem, sizeof(ElemType) * (L->size + INCREMENT));
        if (!newList)return ERROR;
        L->elem = newList;
        L->size += INCREMENT;
    }
    int i;
    //Move the elements after NO. p one space back.
    for (i = L->length - 1; i >= p - 1; i--) {
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[p - 1] = e;
    L->length++;
    return OK;
}

/**
 * delete a specific element.
 * @param L
 * @param p
 * @param e the deleted element.
 * @return Status OK if found, ERROR if not.
 */
Status deleteElem(SqList *L, const int p, ElemType *e) {
    if (!L)return ERROR;
    if (p < 1 || p > L->length)return ERROR;
    *e = L->elem[p - 1];
    for (int i = p; i < L->length; i++) {
        L->elem[i - 1] = L->elem[i];
    }
    L->length--;
    return OK;
}

/**
 * SqList traverse.
 * @param L
 * @return
 */
void traverse(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        if (i < L->length - 1)
            printf("%d ", L->elem[i]);
        else printf("%d\n", L->elem[i]);
    }
}

#endif //DATASTRUCTURE_SQLIST_H
