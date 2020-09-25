# BC - Break the Chocolate

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 27, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/BC/" target="_blank">https://www.spoj.com/problems/BC/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int T, t;
    scanf("%d",&T);
    int B;
    long long unsigned A, N, M, K;
    for (t=1;t<=T;t++){
        scanf("%lld %lld %lld",&N,&M,&K);
        A = N*M*K-1;
        B = ceil(log2(N)) + ceil(log2(M)) + ceil(log2(K));
        printf("Case #%d: %llu %d\n",t,A,B);
    }
    return 0;
}
```
