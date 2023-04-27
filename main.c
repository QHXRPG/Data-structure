#include <stdio.h>
#include "SeqList/SeqList.h"
#include "homework/1.h"
#include "SList/SList.h"
int main() {
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
    slt3 = mergeTwoList(slt1,slt2);
    SLTPrint(slt3);
    return 0;
}
