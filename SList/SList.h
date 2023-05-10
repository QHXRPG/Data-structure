//
// Created by 邱浩轩 on 2023/4/15.
//

#ifndef DATA_STRUCTURE_SLIST_H
#define DATA_STRUCTURE_SLIST_H

#endif //DATA_STRUCTURE_SLIST_H

#include "stdio.h"
#include "stdbool.h"
typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode *next;
}SLTNode;

void SLTPrint(SLTNode *phead);
void SLTPushFront(SLTNode **pphead, SLTDataType x);
void SLTPushBack(SLTNode **pphead, SLTDataType x);
void SLTPopBack(SLTNode **pphead);
void SLTPopFront(SLTNode **pphead);
SLTNode *SLTFind(SLTNode *phead, SLTDataType x);
void SLTInsert(SLTNode **pphead, SLTNode *pos, SLTDataType x);
void SLTInsertAfter(SLTNode *pos, SLTDataType x);
void SLTErase(SLTNode  **pphead, SLTNode *pos);
void SLTEraseAfter(SLTNode *pos);

SLTNode *mergeTwoList(SLTNode *list1, SLTNode *list2);
SLTNode *SLTreversal(SLTNode *head);
SLTNode *SLTreversal_headpush(SLTNode *head);
SLTDataType SLTThe_kth_penultimate_node(SLTNode *head, int k);
SLTNode *SLT_segmentation(SLTNode *head, int x);
SLTNode *SLT_middleNode(SLTNode *head);
bool SLT_Palindrome(SLTNode *head);
SLTNode *FindSLT_Intersection(SLTNode *headA, SLTNode *headB);
bool is_SLT_Ring(SLTNode *head);
SLTNode *SLT_Entrypoint(SLTNode *head);