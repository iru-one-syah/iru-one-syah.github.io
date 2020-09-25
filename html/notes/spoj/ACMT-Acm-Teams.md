# ACMT - Acm Teams

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 27, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ACMT/" target="_blank">https://www.spoj.com/problems/ACMT/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int min(int E, int N){
    return (E<N) ? E : N;
}

int main()
{
    int T, E, N, n;
    scanf("%d",&T);
    while (T--){
        scanf("%d %d", &E, &N);
        
        if ((E==0) || (N==0)){
            printf("0\n");
            continue;
        }

        n = (E+N)/3;        
        printf("%d\n", (min(E,N)<n) ? min(E,N) : n);
    }
    return 0;
}
```
