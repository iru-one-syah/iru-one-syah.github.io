# CANDY - Candy I

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 21, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/CANDY/" target="_blank">https://www.spoj.com/problems/CANDY/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int T, N, sums, t, avgs, moves;
    while (1){
        scanf("%d",&T);
        
        if (T==-1) break;
        
        int n[T];
        sums = 0; moves = 0;
        for (t=0;t<T;t++){
            scanf("%d",&n[t]);
            sums += n[t];
        }
        if (sums%T){
            printf("-1\n");
        }
        else{
            avgs = sums/T;
            for (t=0;t<T;t++){
                if ((n[t]-avgs)>0) moves += n[t]-avgs;
            }
            printf("%d\n",moves);
        }
    }
    
    return 0;
}
```
