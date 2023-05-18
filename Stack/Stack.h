//
// Created by 邱浩轩 on 2023/5/14.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#endif //DATA_STRUCTURE_STACK_H

#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

typedef char STDataType;
typedef struct Stack
{
    STDataType *a;  //数组
    int top;
    int capaicty;
}ST;

void STInit(ST *pst);
void STDestroy(ST *pst);
void STPush(ST *pst, STDataType x);
void STPop(ST *pst);
bool STEmpty(ST *pst);
bool STSize(ST *pst);
STDataType STTop(ST *pst);
bool isVaid(char *s);
