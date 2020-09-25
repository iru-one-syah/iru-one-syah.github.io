# CANDY3 - Candy III

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 21, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/CANDY3/" target="_blank">https://www.spoj.com/problems/CANDY3/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int S, t;
    long long sums, T;
    scanf("%d",&S);
    while (S>0){
        scanf("%lld",&T);
        
        long long n;
        sums = 0;
        for (t=0;t<T;t++){
            scanf("%lld",&n);
            sums = (sums + n)%T;
        }
        if (sums){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
        S--;
    }
    return 0;
}
```
