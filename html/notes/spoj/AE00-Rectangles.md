# AE00 - Rectangles

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 13, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/AE00/" target="_blank">https://www.spoj.com/problems/AE00/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int N, n1, n2, count=0;
    scanf("%d",&N);
    for (n1=1;n1<=N;n1++)
    {
        for (n2=n1;n2<=N;n2++)
        {
            if ((n1*n2)>N) break;
            count++;
        }            
    }
    printf("%d\n",count);
    
    return 0;
}
```
