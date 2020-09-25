# AP2 - AP - Complete The Series (Easy)

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 25, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/AP2/" target="_blank">https://www.spoj.com/problems/AP2/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    
    long long a3, an_8, Sn, n, d, a;
    for(;T>0;T--){
        scanf("%lld %lld %lld",&a3,&an_8,&Sn);
        
        n = 2*Sn/(a3+an_8);
        printf("%lld\n",n);
        
        d = (an_8-a3)/(n-5);
        a = a3 - 2*d;
        printf("%lld",a);
        
        for (;n>1;n--){
            printf(" %lld",a+=d);
        }
        printf("\n");
    }
    return 0;
}
```
