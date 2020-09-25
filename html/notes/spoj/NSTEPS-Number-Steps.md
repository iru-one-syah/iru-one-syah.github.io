# NSTEPS - Number Steps

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 13, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/NSTEPS/" target="_blank">https://www.spoj.com/problems/NSTEPS/</a>

## Solution:

in `C` language.

```c
#include <stdio.h> 

int main()
{
    int N, x, y, n;
    scanf("%d",&N);
    
    for (n=0;n<N;n++){
        scanf("%d %d",&x,&y);
        if (x==y){
            if (x%2==1){
                printf("%d\n",2*(x-1)+1);
            }
            else printf("%d\n",2*x);
        }
        else if (x-2==y){
            if (x%2==1){
                printf("%d\n",2*(x-1)-1);
            }
            else printf("%d\n",2*x-2);
        }
        else printf("No Number\n");
    }
    
    return 0;
}
```
