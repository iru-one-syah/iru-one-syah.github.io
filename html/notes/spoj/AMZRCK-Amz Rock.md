# AMZRCK - Amz Rock

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 29, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/AMZRCK/" target="_blank">https://www.spoj.com/problems/AMZRCK/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main(){
    int fib[45];
    fib[0] = 1;
    fib[1] = 2;
    for (int i=2;i<45;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    int T, t;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&t);
        printf("%d\n",fib[t]);
    }
    
    return 0;
}
```
