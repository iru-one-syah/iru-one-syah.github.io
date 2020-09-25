# ACT - Alpha Centauri Tennis

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 27, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ACT/" target="_blank">https://www.spoj.com/problems/ACT/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char P[500001];
    int N, T, p;
    scanf("%d",&T);
    while (T--){
        scanf("%d %s",&N,P);
        p = strlen(P);
        printf("%c\n",P[p-1]);
    }
    
    return 0;
}
```
