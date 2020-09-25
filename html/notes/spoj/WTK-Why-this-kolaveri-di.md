# WTK - Why this kolaveri di

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 29, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/WTK/" target="_blank">https://www.spoj.com/problems/WTK/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int T, N, n, ans;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&N);
        if (N<=1){
            printf("%d\n",N);
            continue;
        }
        for (n=0,ans=1;n<N;n++){
            ans = (ans + (N-1-n)) % (n+1) + 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
```
