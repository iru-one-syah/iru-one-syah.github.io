# ALICESIE - Alice Sieve

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 29, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ALICESIE/" target="_blank">https://www.spoj.com/problems/ALICESIE/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int T;
    long long N;
    scanf("%d",&T);
    while (T--){
        scanf("%lld",&N);
        printf("%lld\n",(N+1)/2);
    }
    return 0;
}
```
