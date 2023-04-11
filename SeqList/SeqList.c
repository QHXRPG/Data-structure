//
// Created by 邱浩轩 on 2023/4/11.
//

#include "SeqList.h"
#include "stdio.h"
#include "stdlib.h"

//动态顺序表
typedef int SLDatatype;

//初始化
void SLInit(SL *psl)
{
    psl->a = (SLDatatype*) malloc(sizeof(SLDatatype) * 4);  //开辟四个空间
    if(psl->a == NULL)
    {
        perror("malloc fail");
        return;
    }
    psl->size = 0;
    psl->capacity = 0;
}

void SLDestroy(SL *psl)
{
    free(psl->a);
    psl->a = NULL;
    psl->capacity = 0;
    psl->size = 0;
}

void SLCheckCapacity(SL *psl)
{
    if(psl->size == psl->capacity)
    {
        SLDatatype *tmp = realloc(psl->a, sizeof(SLDatatype)* psl->capacity *2);  //扩容到原来的两倍
        if(tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        psl->a = tmp;
        psl->capacity = psl->capacity * 2;
    }
}

void SLPrint(SL *psl)
{
    for(int i=0;i<psl->size;i++)
    {
        printf("%d ", psl->a[i]);
    }
}



void SLPushBack(SL *psl, SLDatatype x)
{
    psl->a[psl->size] = x;
    psl->size++;
}

void SLPushFront(SL *psl, SLDatatype x)
{

}

void SLPopBack(SL *psl)
{

}

void SLPopFront(SL *psl)
{

}

void test_seqlist() {
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPrint(&sl);
}
