# AMR10G - Christmas Play

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 29, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/AMR10G/" target="_blank">https://www.spoj.com/problems/AMR10G/</a>

## Solution:

in `C` language.

```c
// https://en.wikipedia.org/wiki/Quicksort

#include <stdio.h>

#define length(x) (int) (sizeof(x)/sizeof(x[0]))

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int lo, int hi){
    int pivot = A[hi];
    int i = lo;
    for (int j=lo; j<= hi-1; j++){
        if (A[j] < pivot){
            swap(&A[i],&A[j]);
            i++;
        }
    }
    swap(&A[i],&A[hi]);
    return i;
}

void quicksort(int A[], int lo, int hi){
    if (lo<hi){
        int p = partition(A,lo,hi);
        quicksort(A,lo,p-1);
        quicksort(A,p+1,hi);
    }
}

int min(int x1, int x2){
    return (x1<x2)?x1:x2;
}

int main()
{
    int T, K, N, i;
    scanf("%d",&T);
    while (T--){
        scanf("%d %d",&N,&K);
        
        int X[N], MIN = 1000000000;
        for (i=0;i<N;i++){
            scanf("%d",&X[i]);
        }
        
        if (K==1){
            printf("0\n");
            continue;
        }
        
        quicksort(X, 0, N-1); 
        if (N==K){
            MIN = X[N-1]-X[0];
            printf("%d\n",MIN);
            continue;
        }
        
        for (i=0;i<=N-K;i++){
            MIN = min(MIN,X[i+K-1]-X[i]);
        }
        
        printf("%d\n",MIN);
    }
    return 0;
}
```
