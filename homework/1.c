//
// Created by 邱浩轩 on 2023/4/12.
//
#include "stdlib.h"
#include "stdio.h"

// 1.原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)
void Remove_all_elements_in_the_array_in_place(int *p, int len)
{
    for(int i=0;i<len;i++)
    {
        p[i] = 0;
    }
    for(int i=0;i<len;i++)
    {
        printf("%d ",p[i]);
    }
}

// 2.合并两个有序数组
void Merge_two_ordered_arrays(int *p, int *q, int *a, int len1, int len2)
{
    int len = len1+len2;
    int k1 = 0;
    int k2 = 0;
    int i = 0;
    while(len - i)
    {
        if(p[k1]<q[k2])
        {
            a[i] = p[k1];
            k1++;
            i++;
        }
        else if(q[k2]<p[k1])
        {
            a[i] = q[k2];
            k2++;
            i++;
        }
        else if(q[k2]==p[k1])
        {
            a[i] = p[k1];
            a[i+1] = q[k2];
            k1++;
            k2++;
            i++;
            i++;
        }
    }
}
