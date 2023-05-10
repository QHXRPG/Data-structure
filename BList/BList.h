//
// Created by 邱浩轩 on 2023/5/10.
//

#ifndef DATA_STRUCTURE_BLIST_H
#define DATA_STRUCTURE_BLIST_H

#endif //DATA_STRUCTURE_BLIST_H
#include "stdio.h"
#include "stdbool.h"


typedef int LTDataType;
typedef struct ListNode
{
    struct ListNode *next;
    struct ListNode *prev;
    LTDataType data;
}LTNode;