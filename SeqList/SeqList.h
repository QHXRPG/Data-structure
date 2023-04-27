//
// Created by 邱浩轩 on 2023/4/11.
//

#ifndef DATA_STRUCTURE_SEQLIST_H
#define DATA_STRUCTURE_SEQLIST_H

#endif //DATA_STRUCTURE_SEQLIST_H

typedef int SLDatatype;
typedef struct SeqList
{
    SLDatatype *a;
    int size;    //存储的有效数据的个数
    int capacity;  //容量
}SL;
void SLInit(SL *psl);
void SLDestroy(SL *psl);
void SLCheckCapacity(SL *psl);
void SLPushBack(SL *psl, SLDatatype x);
void SLPushFront(SL *psl, SLDatatype x);
void SLPopBack(SL *psl);
void SLPopFront(SL *psl);
void SLPrint(SL *psl);
void SLInsert(SL *psl, int pos, SLDatatype x);
int SLFind(SL *psl, SLDatatype x);
void SLErase(SL*psl, int pos);
void SLModify(SL *psl, int pos, SLDatatype x);