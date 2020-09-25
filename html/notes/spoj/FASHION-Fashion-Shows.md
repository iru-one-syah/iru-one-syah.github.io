# FASHION - Fashion Shows

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 13, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/FASHION/" target="_blank">https://www.spoj.com/problems/FASHION/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

void SelectionSort(int X[], int size)
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
    int T, t, N, n;
    scanf("%d",&T);
    
    for (t=0;t<T;t++)
    {
        scanf("%d",&N);
        int man[N], woman[N];
        int r=0;

        for (n=0;n<N;n++){
            scanf("%d",&man[n]);
        }
        
        for (n=0;n<N;n++){
            scanf("%d",&woman[n]);
        }
        
        SelectionSort(man,N);
        SelectionSort(woman,N);
        
        for (n=0;n<N;n++) r+=man[n]*woman[n];
        printf("%d\n",r);
    }
    
    return 0;
}
```
