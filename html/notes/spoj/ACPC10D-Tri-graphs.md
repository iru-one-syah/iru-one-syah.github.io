# ACPC10D - Tri graphs

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 29, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ACPC10D/" target="_blank">https://www.spoj.com/problems/ACPC10D/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

long long min2(long long x1, long long x2){
    return (x1<x2)?x1:x2;
}

long long min3(long long x1, long long x2, long long x3){
    long long xt = min2(x1,x2);
    return (x3<xt)?x3:xt;
}

long long min4(long long x1, long long x2, long long x3, long long x4){
    long long xt = min3(x1,x2,x3);
    return (x4<xt)?x4:xt;
}

int main()
{
    long long N;
    long long count=0;
    while (1){
        count++;
        scanf("%lld",&N);
        if (N==0) break;
        long long i, TG[N][3];
        for (i=0;i<N;i++){
            scanf("%lld %lld %lld",&TG[i][0],&TG[i][1],&TG[i][2]);
            
            if (i==0) TG[i][2] += TG[i][1];
            else if (i==1){
                TG[i][0] += TG[i-1][1];
                TG[i][1] += min3(TG[i][0],TG[i-1][1],TG[i-1][2]);
            }
            else{
                TG[i-1][2] += min3(TG[i-1][1],TG[i-2][1],TG[i-2][2]);
                TG[i][0] += min2(TG[i-1][0],TG[i-1][1]);
                TG[i][1] += min4(TG[i][0],TG[i-1][0],TG[i-1][1],TG[i-1][2]);
            }
        }
        printf("%lld. %lld\n",count,TG[N-1][1]);
    }
    return 0;
}
```
