# ARMY - Army Strength

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 27, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ARMY/" target="_blank">https://www.spoj.com/problems/ARMY/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int max(int x1, int x2){
    return (x1>x2) ? x1 : x2;
}

int main()
{
    int T, ng, nm, i;
    scanf("%d",&T);
    
    while (T--){
        scanf("%d %d",&ng,&nm);
        
        int NG[ng], ngmax=0;
        for (i=0;i<ng;i++){
            scanf("%d",&NG[i]);
            ngmax = max(ngmax,NG[i]);
        }
        
        int NM[nm], nmmax=0;
        for (i=0;i<nm;i++){
            scanf("%d",&NM[i]);
            nmmax = max(nmmax,NM[i]);
        }
        
        if (ngmax >= nmmax) printf("Godzilla\n");
        else printf("MechaGodzilla\n");
    }
    
    return 0;
}
```
