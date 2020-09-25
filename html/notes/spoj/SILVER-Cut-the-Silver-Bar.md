# SILVER - Cut the Silver Bar

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 29, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/SILVER/" target="_blank">https://www.spoj.com/problems/SILVER/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    while (1){
        scanf("%d",&n);
        if (n==0) break;
        printf("%d\n",(int) log2(n));
    }
    return 0;
}
```
