//
// Created by Harlan on 2016/11/3.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

/**
 * generally, when you solve a problem, you do not need to use the structure below,
 * use this instead:
 * user "int q[MAX];" to declare a cycler queue with a copacity of MAX.
 * use "int rear = front = 0;" to initialize a cycler queue.
 * and use "if(rear == front)" to conform that the queue is empty.
 * use "(front+1)%MAX == rear" to conform that the queue is full.
 */

typedef int QElemType;

struct QNode {
    QElemType data;
    struct QNode *next;
};

/**
 * the front and the rear node don't save datas.
 */
typedef struct {
    QNode *front;
    QNode *rear;
} LinkedQueue;

void init(LinkedQueue *Q) {
    Q->front = Q->rear = (QNode *) malloc(sizeof(QNode));

    if (!Q->front) {
        printf("Init Failed!\n");
        return;
    }
    Q->front->next = NULL;
    printf("Init successfully!\n");
}

void destroy(LinkedQueue *Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    printf("Destroyed successfully!\n");
}

int isEmpty(LinkedQueue *Q) {
    if (Q->front->next == NULL) {
        return 1;
    }
    return -1;
}

int length(LinkedQueue *Q) {
    int len = 0;
    QNode *p = Q->front;
    while (p != Q->rear) {
        len++;
        p = p->next;
    }
    printf("Length = %d\n", len);
    return len;
}

void enQueue(LinkedQueue *Q, QElemType e) {
    QNode *q = (QNode *) malloc(sizeof(QNode));\
    if (!q) {
        printf("enQueue failed!\n");
        return;
    }
    q->data = e;
    q->next = NULL;
    Q->rear->next = q;
    Q->rear = q;
    printf("enQueue successfully!\n");
}

void deQueue(LinkedQueue *Q, QElemType *e) {
    QNode *p;
    if (Q->front == Q->rear) {
        printf("deQueue failed!\n");
        return;
    }
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)Q->rear = Q->front;
    (*e) = p->data;
    free(p);
    printf("deQueue successfully!\n");
}

void traverse(LinkedQueue *Q) {
    QNode *p = Q->front->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

#endif //DATASTRUCTURE_QUEUE_H
