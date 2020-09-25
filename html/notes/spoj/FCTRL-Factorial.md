# FCTRL - Factorial

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 13, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/FCTRL/" target="_blank">https://www.spoj.com/problems/FCTRL/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int N, n, X, x, temp;
    scanf("%d",&N);
    for (n=0;n<N;n++)
    {
        scanf("%d",&x);
        temp = x/5;
        X = temp;
        while (temp>0){
            temp /= 5;
            X += temp;
        }
        printf("%d\n",X);
    }
    
    return 0;
}
```
