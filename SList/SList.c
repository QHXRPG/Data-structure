//
// Created by 邱浩轩 on 2023/4/15.
//

#include "SList.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

SLTNode *BuyLTNode(SLTDataType x)
{
    SLTNode *newnode = (SLTNode*) malloc(sizeof(SLTNode));
    if(newnode == NULL)
    {
        perror("malloc fail");
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

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
    SLTNode *newnode = BuyLTNode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}

void SLTPushBack(SLTNode **pphead, SLTDataType x)
{
    SLTNode *newnode = BuyLTNode(x);
    //1.空链表
    if (*pphead == NULL)
    {
        *pphead = newnode;
    }
    //2.非空链表
    else
    {
        SLTNode *tail = *pphead;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newnode;  //newnode和tail会销毁，但是newnode和tail的next所指向的结构体不会销毁
    }
}

void SLTPopBack(SLTNode **pphead)
{
    //空,没有节点
    if(*pphead == NULL)
    {
        assert(*pphead);
        return;
    }
    //找尾
    //一个节点
    if ((*pphead)->next ==NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    //多个节点
    else
    {
        SLTNode *prev = NULL;
        SLTNode *tail = *pphead;
        while (tail->next) {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
}

void SLTPopFront(SLTNode **pphead)
{
    assert(*pphead);
    if((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    } else
    {
        SLTNode *del = *pphead;
        *pphead = del->next;
        free(del);
    }
}

SLTNode *SLTFind(SLTNode *phead, SLTDataType x)
{
    SLTNode *cur = phead;
    while(cur)
    {
        if(cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void SLTInsert(SLTNode **pphead, SLTNode *pos, SLTDataType x)
{
    assert(pphead);
    assert(pos);

    if(*pphead==pos)
    {
        SLTPushFront(pphead,x);
    }
    else
    {
        SLTNode  *prev = *pphead;
        while (prev->next != pos)
        {
            prev = prev->next;
        }
        SLTNode *newnode = BuyLTNode(x);
        prev->next = newnode;
        newnode->next = pos;
    }
}

void SLTInsertAfter(SLTNode *pos, SLTDataType x)
{
    assert(pos);

    SLTNode  *newnode = BuyLTNode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}


void SLTErase(SLTNode  **pphead, SLTNode *pos)
{
    assert(pphead);
    assert(pos);
    if(pos == *pphead)
    {
        SLTPopFront(pphead);
    } else
    {
        SLTNode *prev = *pphead;
        while(prev->next !=pos)
        {
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
    }
}

void SLTEraseAfter(SLTNode *pos)
{
    assert(pos);
    assert(pos->next);
    SLTNode  *next = pos->next;
    pos->next = next->next;
    free(next);
}

//经典题：合并两个有序链表
//方法：取小的尾插
SLTNode *mergeTwoList(SLTNode *list1, SLTNode *list2)
{
    SLTNode *list = NULL;
    SLTNode *head = NULL;
    if(list1 == NULL)
    {
        return list2;
    }
    if(list2 == NULL)
    {
        return list1;
    }
    while(list1 && list2)
    {
        if(list1->data < list2->data)
        {
            if(list == NULL)
            {
                head = list = list1;
            }
            else
            {
                list->next = list1;
                list = list->next;
            }
            list1 = list1->next;
        }
        else
        {
            if(list == NULL)
            {
                head = list = list2;
            }
            else
            {
                list->next = list2;
                list = list->next;

            }
            list2 = list2->next;
        }
    }
    if(list1)
    {
        list->next = list1;
    }
    if(list2)
    {
        list->next = list2;
    }
    return head;
}