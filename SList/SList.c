//
// Created by 邱浩轩 on 2023/4/15.
//

#include "SList.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

void SLTPrint(SLTNode *phead)
{
    SLTNode *cur = phead;
    while(cur != NULL)
    {
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void SLTPushFront(SLTNode **pphead, SLTDataType x)
{
    SLTNode *newnode = (SLTNode*) malloc(sizeof(SLTNode));
    if(newnode == NULL)
    {
        perror("malloc fail");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;
    newnode->next = *pphead;
    *pphead = newnode;
}