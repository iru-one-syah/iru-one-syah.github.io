# CMPLS - Complete the Sequence!

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 25, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/CMPLS/" target="_blank">https://www.spoj.com/problems/CMPLS/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int T, S, C, i, j, k;
    scanf("%d",&T);
    
    for(;T>0;T--){
        scanf("%d %d",&S,&C);
        long long P[S][S+C];
        for (i=0;i<S;i++)  scanf("%lld",&P[0][i]);
        
        for (j=1;j<S;j++){
            for (i=1;i<S+1-j;i++){
                P[j][i-1] = P[j-1][i]-P[j-1][i-1];
            }
        }
        
        for (i=1;i<=C;i++) P[S-1][i] = P[S-1][0];
        
        for (j=S-2,i=2;j>=0;j--,i++){
            for (k=0;k<C;k++) P[j][k+i] = P[j][k+i-1]+P[j+1][k+i-1];
        }
        
        for (i=S;i<S+C;i++){
            if (i!=S+C-1) printf("%lld ",P[0][i]);
            else printf("%lld\n",P[0][i]);
        }
    }
    return 0;
}
```
