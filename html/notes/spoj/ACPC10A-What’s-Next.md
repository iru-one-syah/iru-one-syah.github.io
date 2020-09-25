# ACPC10A - What’s Next

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 13, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ACPC10A/" target="_blank">https://www.spoj.com/problems/ACPC10A/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int a, b, c;
    
    scanf("%d %d %d",&a,&b,&c);
    
    while (!(a==0 && b==0 && c==0))
    {
        if ((c-b)==(b-a)){
            printf("AP %d\n",c+(c-b));
        }
        else if (c/b==b/a){
            printf("GP %d\n",c*(c/b));
        }
        
        scanf("%d %d %d",&a,&b,&c);
    }
    
    return 0;
}
```
