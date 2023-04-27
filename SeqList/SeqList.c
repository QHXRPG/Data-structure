//
// Created by 邱浩轩 on 2023/4/11.
//

#include "SeqList.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

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
    int end = psl->size -1;
    while(end >= 0)
    {
        psl->a[end+1] = psl->a[end];
        end--;
    }
    psl->a[0] = x;
    psl->size++;
}

void SLPopBack(SL *psl)
{
//    if(psl->size == 0)
//    {
//        return;
//    }
    assert(psl->size>0);
    psl->size--;
}

void SLPopFront(SL *psl)
{
    assert(psl->size>0);
    int start =0;
    while(start < psl->size - 1)
    {
        psl->a[start] = psl->a[start+1];
        start++;
    }
    psl->size--;
}

void SLInsert(SL *psl, int pos, SLDatatype x)
{
    assert(0<=pos && pos<=psl->size);
    SLCheckCapacity(psl);
    int end = psl->size -1;
    while(end>= pos)
    {
        psl->a[end+1] = psl->a[end];
        end--;
    }
    psl->a[pos] = x;
    psl->size++;
}

void SLErase(SL*psl, int pos)
{
    assert(0<=pos && pos<=psl->size);
    SLCheckCapacity(psl);
    assert(psl->size>0);

    int start = pos+1;
    while(start<psl->size)
    {
        psl->a[start-1] = psl->a[start];
        start++;
    }
    psl->size--;
}

int SLFind(SL *psl, SLDatatype x)
{
    for(int i=0; i<psl->size; i++)
    {
        if(psl->a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void SLModify(SL *psl, int pos, SLDatatype x)
{
    assert(0<=pos && pos<=psl->size);
    psl->a[pos] = x;
}

void test_seqlist() {
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPrint(&sl);
}
