//
// Created by 邱浩轩 on 2023/5/14.
//
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "Stack.h"

void STInit(ST *pst)
{
    assert(pst);
    pst->a = NULL;
    pst->top = 0; //top指向栈顶元素顶下一个元素
    pst->capaicty = 0;
}

void STDestroy(ST *pst)
{
    assert(pst);
    free(pst->a);  //a是数组，free把整个数组释放
    pst->a = NULL;
    pst->top = pst->capaicty = 0;
}

void STPush(ST *pst, STDataType x)
{
    if(pst->top == pst->capaicty)
    {
        int newCapacity = pst->capaicty == 0 ? 4 : pst->capaicty * 2;
        STDataType *tmp = (STDataType*) realloc(pst->a, newCapacity * sizeof(STDataType));
        if(tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        pst->a = tmp;
        pst->capaicty = newCapacity;
    }
    pst->a[pst->top] = x;
    pst->top++;
}

void STPop(ST *pst)
{
    assert(pst);
    assert(!STEmpty(pst));
    pst->top--;
}

STDataType STTop(ST *pst)
{
    assert(pst);
    assert(!STEmpty(pst));
    return pst->a[pst->top-1];
}

bool STEmpty(ST *pst)
{
    assert(pst);
    return pst->top == 0;
}

bool STSize(ST *pst)
{
    assert(pst);
    return pst->top;
}

//括号匹配
bool isVaid(char *s)
{
    ST st;
    STInit(&st);
    while(*s)
    {
        if(*s == '{' || *s == '(' || *s == '[')
        {
            STPush(&st, *s);
        }
        else
        {
            if(STEmpty(&st))
            {
                STDestroy(&st);  //为空只代表top为零，不代表没有空间
                return false;
            }
            char top = STTop(&st);
            STPop(&st);
            if((*s == '}'&& top !='{')||(*s == ']' && top != '[')||(*s == ')' && top != '('))
            {
                return false;
            }
        }
        s++;
    }
    if(!STEmpty(&st))
    {
        STDestroy(&st);
        return false;
    }
    STDestroy(&st);
    return true;
}

