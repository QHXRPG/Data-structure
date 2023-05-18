//
// Created by 邱浩轩 on 2023/5/17.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#endif //DATA_STRUCTURE_QUEUE_H

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

typedef int QDataType;
typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType data;
}QNode;

struct Queue
{
    QNode *phead;
    QNode *ptail;
    int size;
};
void QueueInit(struct Queue *pq);
void QueueDestroy(struct Queue *pq);
void QueuePush(struct Queue *pq, QDataType x);
bool QueueEmpty(struct Queue *pq);
void QueuePop(struct Queue *pq);
QDataType QueueFront(struct Queue *pq);
QDataType QueueBack(struct Queue *pq);
int QueueSize(struct Queue *pq);