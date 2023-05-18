//
// Created by 邱浩轩 on 2023/5/17.
//

#include "queue.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "Stack.h"


void QueueInit(struct Queue *pq)
{
    assert(pq);
    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

void QueueDestroy(struct Queue *pq)
{
    assert(pq);
    QNode *cur = pq->phead;
    while (cur)
    {
        QNode *next = cur->next;
        free(cur);
        cur = next;
    }
    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

void QueuePush(struct Queue *pq, QDataType x)
{
    assert(pq);
    QNode *newnode = (QNode*) malloc(sizeof(QNode));
    if(newnode == NULL)
    {
        perror("malloc fail!!\n");
    }
    newnode->next = NULL;
    newnode->data = x;
    if(pq->ptail == NULL)
    {
        assert(pq->phead == NULL); //二者顺序可以调换
        pq->phead = pq->ptail = newnode;
    }
    else
    {
        pq->ptail->next = newnode;
        pq->ptail = newnode;
    }
    pq->size++;
}

bool QueueEmpty(struct Queue *pq)
{
    assert(pq);
    return pq->size == 0;
}

void QueuePop(struct Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    //一个节点
    if(pq->phead->next == NULL)
    {
        free(pq->phead);
        pq->phead = pq->ptail = NULL;
    }

    //多个节点
    else
    {
        QNode *next = pq->phead->next;
        free(pq->phead);
        pq->phead = next;
    }
    pq->size--;
}


QDataType QueueFront(struct Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->phead->data;
}

QDataType QueueBack(struct Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->ptail->data;
}

int QueueSize(struct Queue *pq)
{
    assert(pq);
    return pq->size;
}


//两个队列实现一个栈的功能
typedef struct Mystack
{
    struct Queue q1;
    struct Queue q2;
}MST;

MST *MSTCreate()
{
    MST *obj = (MST*) malloc(sizeof(MST));
    if(obj == NULL)
    {
        perror("malloc fail!\n");
    }
    QueueInit(&obj->q1);
    QueueInit(&obj->q2);
    return obj;
}

void MSTPush(MST *obj, QDataType x)
{
    assert(obj);
    if(!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    } else
    {
        QueuePush(&obj->q2, x);
    }
}

QDataType MSTPop(MST *obj)
{
    assert(obj);
    struct Queue *pempty = &obj->q1;
    struct Queue *pnotempty = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        pempty = &obj->q2;
        pnotempty = &obj->q1;
    }

    while(QueueSize(pnotempty) > 1)
    {
        QueuePush(pempty, QueueFront(pnotempty));
        QueuePop(pnotempty);
    }
    QDataType top = QueueFront(pnotempty);
    QueuePop(pnotempty);
    return top;
}

QDataType MSTTop(MST *obj)
{
    assert(obj);
    if(!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

void MSTDestroy(MST *obj)
{
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}

//用栈实现队列
typedef struct Myqueue
{
    ST pushst;
    ST popst;
}MQ;

MQ *MQCreate()
{
    MQ *obj = (MQ*) malloc(sizeof(MQ));
    if(obj == NULL)
    {
        perror("malloc fail!\n");
    }
    STInit(&obj->pushst);
    STInit(&obj->popst);
    return obj;
}

void MQPush(MQ *obj, STDataType x)
{
    STPush(&obj->pushst, x);
}

bool MQEmpty(MQ *obj)
{
    return obj->pushst.capaicty == 0 &&  obj->popst.capaicty == 0;
}

STDataType MQPeek(MQ *obj)
{
    if(STEmpty(&obj->popst))   //popst为空时，倒数据进去
    {
        while (!STEmpty(&obj->pushst))   //一直倒到pushst为空为止
        {
            STPush(&obj->popst, STTop(&obj->pushst));
            STPop(&obj->pushst);
        }
    }
    return STTop(&obj->popst);
}

STDataType MQPop(MQ *obj)
{
    STDataType front = MQPeek(obj);
    STPop(&obj->popst);
    return front;
}
