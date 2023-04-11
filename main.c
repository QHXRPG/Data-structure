#include <stdio.h>
#include "SeqList/SeqList.h"

int main() {
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl,1);
    SLPushBack(&sl,2);
    SLPushBack(&sl,3);
    SLPrint(&sl);
    return 0;
}
