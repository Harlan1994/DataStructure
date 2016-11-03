//
// Created by Harlan on 2016/11/3.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <cstdio>
#include <cstdlib>

#define OK 1
#define ERROR -1
#define TRUE 2
#define FALSE -2
#define INIT_SIZE 20
#define INCREMENT 10

typedef int ElemType;

typedef struct {
    ElemType *base; //栈底
    ElemType *top; //栈顶
    int size;
} *Stack;

/**
 * initialize a stack
 * @param S
 */
void init(Stack &S) {
    S->base = (ElemType *) malloc(sizeof(ElemType) * INIT_SIZE);
    if (!S->base) {
        printf("Memory allocated failed!\n");
        return;
    }
    S->top = S->base;
    S->size = INIT_SIZE;
}

void destroy(Stack &S) {
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->size = 0;
    printf("S has been destroyed sucessfully!\n");
}

void isEmpty(Stack &S) {
    if (S->base == S->top) {
        printf("S is empty!\n");
    } else {
        printf("S is not empty!\n");
    }
}

int getLength(Stack &S) {
    printf("Length = %d.\n", S->top - S->base);
    return S->top - S->base;
}

void getTop(Stack &S, ElemType *e) {
    if (S->top > S->base) {
        (*e) = *(S->top - 1);
        printf("get top e = %d.\n", *e);
    } else {
        printf("S is empty!\n");
    }
}

void push(Stack &S, ElemType e) {
    if ((S->top - S->base) / sizeof(ElemType) >= S->size) {
        S->base = (ElemType *) realloc(S->base, sizeof(ElemType) * (S->size + INCREMENT));
        if (!S->base) {
            printf("Realloced failed.\n");
            return;
        }
        S->top = S->base + S->size;
        S->size += INCREMENT;
    }
    *S->top = e;
    S->top++;
    printf("pushed successfully!\n");
}


void pop(Stack &S, ElemType *e) {
    if (S->top > S->base) {
        (*e) = *(--S->top);
        printf("pop e = %d.\n", *e);
    } else {
        printf("S is empty!\n");
    }
}

void traverse(Stack &S) {
    ElemType *tmp = S->top;
    if (S->top > S->base) {
        ElemType *tmp = S->top - 1;
        while (tmp >= S->base) {
            printf("%d ", *tmp);
            tmp--;
        }
        printf("\n");
    }
}

#endif //DATASTRUCTURE_STACK_H
