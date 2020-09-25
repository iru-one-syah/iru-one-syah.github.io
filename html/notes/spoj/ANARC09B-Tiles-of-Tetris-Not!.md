# ANARC09B - Tiles of Tetris, Not!

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 25, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ANARC09B/" target="_blank">https://www.spoj.com/problems/ANARC09B/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

long long divider(long long W, long long H){
    long long temp;
    while (W){
        temp = W;
        W = H % W;
        H = temp;
    }
    return H;
}

int main(){
    long long W, H, D;
    while (1){
        scanf("%lld %lld",&W,&H);
        if ((W==0) && (H==0)) break;
        else{
            D = divider(W,H);
            printf("%lld\n",(W/D)*(H/D));
        }
    }
    return 0;
}
```
