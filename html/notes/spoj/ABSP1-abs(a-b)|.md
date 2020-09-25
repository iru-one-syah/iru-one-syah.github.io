# ABSP1 - abs(a-b) I

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 21, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ABSP1/" target="_blank">https://www.spoj.com/problems/ABSP1/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

long long sum;

void ABS(long long A[], int n)
{
    sum = 0;
    for (long long i = 0; i < n-1 ;i++)
    {
        sum += (i+1)*A[i+1] - (n-1-i)*A[i];
    }
}

int main()
{
    int T, n;
    scanf("%d",&T);
    while (T>0)
    {
        scanf("%d",&n);
        long long A[n], a;
        for (a=0;a<n;a++) scanf("%lld",&A[a]);
        ABS(A,n);
        printf("%lld\n",sum);
        T--;
    }
    
    return 0;
}
```
