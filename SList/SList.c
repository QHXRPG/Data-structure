//
// Created by 邱浩轩 on 2023/4/15.
//

#include "stdbool.h"
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
    SLTNode *tail = NULL;
    SLTNode *list = NULL;
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
            if(tail == NULL)
            {
                list = tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }
        else
        {
            if(tail == NULL)
            {
                list = tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;

            }
            list2 = list2->next;
        }
    }
    if(list1)
    {
        tail->next = list1;
    }
    if(list2)
    {
        tail->next = list2;
    }
    return list;
}

//链表反转
SLTNode *SLTreversal(SLTNode *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    SLTNode *n1 = NULL;
    SLTNode *n2 = head;
    SLTNode *n3 = n2->next;

    while(n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if(n3)
        {
            n3 = n3->next;
        }
    }
    return n1;
}

SLTNode *SLTreversal_headpush(SLTNode *head)
{
    SLTNode *rehead = NULL;
    SLTNode *cur = head;
    SLTNode *next;

    while(cur)
    {
        next = cur->next;
        //头插
        cur->next = rehead;
        rehead = cur;

        //迭代
        cur = next;
    }
    return rehead;
}

//倒数第k个节点
SLTDataType SLTThe_kth_penultimate_node(SLTNode *head, int k)
{
    SLTNode *fast = head, *slow = head;
    while(k--)
    {
        if(fast == NULL)
        {
            return fast->data;
        }
        fast = fast->next;
    }

    while(fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

//哨兵位的头节点 -- 不插存储有效数据,不是队列里面的，是用来站岗的， 不需要用到二级指针
//链表分割，给一定值x，所有小于x的节点排在其余节点之前，不能改变顺序
SLTNode *SLT_segmentation(SLTNode *head, int x)
{
    //greaterhead， lesstail就是哨兵位
    SLTNode *lesshead, *lesstail, *greaterhead, *greatertail;
    lesshead = lesstail = (SLTNode*)malloc(sizeof(SLTNode));
    greaterhead = greatertail = (SLTNode*)malloc(sizeof(SLTNode));
    SLTNode *cur = head;

    while(cur)
    {
        if(cur->data < x)
        {
            lesstail->next = cur;
            lesstail = lesstail->next;
        }
        else
        {
            greatertail->next = cur;
            greatertail = greatertail->next;
        }
        cur = cur->next;
    }
    lesstail->next = greaterhead->next;
    greatertail->next = NULL;  //防止循环链表
    head = lesshead->next;
    free(lesshead);
    free(greaterhead);
    return head;
}

//寻找中间节点
SLTNode *SLT_middleNode(SLTNode *head)
{
    SLTNode *fast = head;
    SLTNode *slow = head;
    while (fast)
    {
        if(fast->next == NULL)
        {
            fast = fast->next;
        }
        else
        {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return slow;
}

//回文,判断链表是否对称,
// 思路：寻找中间节点，再反转形成两个链表，若两个链表相等，则为回文
bool SLT_Palindrome(SLTNode *head)
{
    SLTNode *mid = SLT_middleNode(head);
    SLTNode *rmid = SLTreversal(mid);

    while(rmid)
    {
        if(rmid->data != head->data)
        {
            return false;
        }
        else
        {
            rmid = rmid->next;
            head = head->next;
        }
    }
    return true;
}

//找两条链表交点
SLTNode *FindSLT_Intersection(SLTNode *headA, SLTNode *headB)
{
    SLTNode *tailA = headA;
    SLTNode *tailB = headB;
    int lenA = 0, lenB = 0;
    while (tailA->next)
    {
        tailA = tailA->next;
        lenA++;
    }
    while (tailB->next)
    {
        tailB = tailB->next;
    }
    if(tailA != tailB)
    {
        return NULL;
        lenB++;
    }

    int gap = abs(lenA - lenB);
    SLTNode *shortlist = headB;
    SLTNode *longlist = headA;  //不能都包在if里面，不然不能调用
    if(lenB >= lenA)
    {
        shortlist = headA;
        longlist = headB;
    }
    while (gap--)
    {
        longlist = longlist->next;
    }
    while (longlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}

//判断链表是否带环
//思路：快慢指针
bool is_SLT_Ring(SLTNode *head)
{
    SLTNode *fast = head;
    SLTNode *slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

//判断链表是否带环，若带，则求环的入口点
//思路：一个指针从相遇点走，一个指针从头开始走，他们会在入口点相遇
SLTNode *SLT_Entrypoint(SLTNode *head)
{
    SLTNode *fast = head;
    SLTNode *slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            SLTNode *meet = slow;
            while (head != meet)
            {
                head = head->next;
                meet = meet->next;
            }
            return meet;
        }
    }
    return NULL;
}

void test_SLT()
{
    SLTNode *slt1 = NULL;
    SLTPushFront(&slt1,4);
    SLTPushFront(&slt1,3);
    SLTPushFront(&slt1,3);
    SLTPushFront(&slt1,2);
    SLTPrint(slt1);

    SLTNode *slt2 = NULL;
    SLTPushFront(&slt2,6);
    SLTPushFront(&slt2,5);
    SLTPushFront(&slt2,4);
    SLTPushFront(&slt2,3);
    SLTPrint(slt2);

    SLTNode *slt3 = NULL;
    slt3 = mergeTwoList(slt1, slt2);
    SLTPrint(slt3);

    SLTNode *slt4 = NULL;
    slt4 = SLTreversal(slt3);
    SLTPrint(slt4);

    SLTDataType a;
    a = SLTThe_kth_penultimate_node(slt4, 3);
    printf("%d\n",a);

    SLTNode *slt5 = NULL;
    slt5 = SLT_segmentation(slt4, 4);
    SLTPrint(slt5);

    SLTNode *slt = NULL;
    SLTPushFront(&slt,1);
    SLTPushFront(&slt,2);
    SLTPushFront(&slt,3);
    SLTPushFront(&slt,4);
    SLTPushFront(&slt,4);
    SLTPushFront(&slt,3);
    SLTPushFront(&slt,2);
//    SLTPushFront(&slt,1);
    SLTPrint(slt);
    SLTNode *slt6 = NULL;
    slt6 = SLT_middleNode(slt);
    SLTPrint(slt6);
    bool p;
    p = SLT_Palindrome(slt);
    printf("%d\n",p);
}