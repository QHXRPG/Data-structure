//
// Created by 邱浩轩 on 2023/4/15.
//

#ifndef DATA_STRUCTURE_SLIST_H
#define DATA_STRUCTURE_SLIST_H

#endif //DATA_STRUCTURE_SLIST_H

#include "stdio.h"
typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode *next;
}SLTNode;

void SLTPrint(SLTNode *phead);
void SLTPushFront(SLTNode **pphead, SLTDataType x);