//
// Created by 邱浩轩 on 2023/5/10.
//

#include "BList.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"


LTNode *BuyLTNode(LTDataType x)
{
    LTNode *newnode = (LTNode*) malloc(sizeof(LTNode));
    if(newnode == NULL)
    {
        perror("malloc fail");
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

