# COINS - Bytelandian gold coins

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 13, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/COINS/" target="_blank">https://www.spoj.com/problems/COINS/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <math.h>

#define NMAX 1000000001

long long values[NMAX];

long long F(long long n)
{
    if ((values[n]>0) || (n==0)){
        return values[n];
    }
    else{
        values[n] = (long long) fmax(n,F(n/2)+F(n/3)+F(n/4));
        return values[n];
    }
}

int main()
{
    values[0] = 0;
    values[1] = 1;
    
    long long n;
    int t=10;
    
    while (t>0){
        scanf("%lld",&n);
        printf("%lld\n",F(n));
        t--;
    }
    
    return 0;
}
```
