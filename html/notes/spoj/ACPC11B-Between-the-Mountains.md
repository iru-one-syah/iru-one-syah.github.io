# ACPC11B - Between the Mountains

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 27, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ACPC11B/" target="_blank">https://www.spoj.com/problems/ACPC11B/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

long long absfunc(long long x1, long long x2){
    long long ans = x1-x2;
    return (ans>0) ? ans : -ans;
}

long long min(long long x1, long long x2){
    return (x1<x2) ? x1 : x2;
}

void SelectionSort(long long X[], int size)
{
    int i, j, fmin, imin;
    for (i=0;i<size-1;i++){
        fmin = X[i];
        imin = i;
        for (j=i+1;j<size;j++){
            if (X[j] < fmin){
                imin = j;
                fmin = X[j];
            }
        }
        X[imin] = X[i];
        X[i] = fmin;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    
    while (T--) {
        int M1, i;
        scanf("%d",&M1);
        long long m1[M1];
        for (i=0;i<M1;i++) scanf("%lld",&m1[i]);
        
        int M2, j;
        scanf("%d",&M2);
        long long m2[M2];
        for (j=0;j<M2;j++) scanf("%lld",&m2[j]);
        
        SelectionSort(m1,M1);
        SelectionSort(m2,M2);
        
        long long min_alt = 1000000;
        for (i=0,j=0;(i<M1 && j<M2);){
            min_alt = min(min_alt, absfunc(m1[i],m2[j]));
            if (m1[i] < m2[j]) i++;
            else j++;
        }
        
        printf("%lld\n",min_alt);
    }
    return 0;
}
```
