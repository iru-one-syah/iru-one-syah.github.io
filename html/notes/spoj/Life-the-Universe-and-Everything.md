# Life, the Universe, and Everything

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 13, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/TEST/" target="_blank">https://www.spoj.com/problems/TEST/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int d=0;
    scanf("%d",&d);
    while (d!=42)
    {
        printf("%d\n",d);
        scanf("%d",&d);
    }
}
```
