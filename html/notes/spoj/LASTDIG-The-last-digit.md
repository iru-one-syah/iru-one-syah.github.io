# LASTDIG - The last digit

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 13, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/LASTDIG/" target="_blank">https://www.spoj.com/problems/LASTDIG/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int matrix[10][4], i, j;
    for (i=0;i<10;i++)
    {
        for (j=0;j<4;j++)
        {
            matrix[i][j] = ((int) pow(i,j+1)) % 10;
        }
    }
    
    int N,n,a,b,a_rem,b_rem;
    scanf("%d",&N);
    for (n=0;n<N;n++)
    {
        scanf("%d %d",&a,&b);
        if (b==0){
            printf("1\n");
        }
        else if (a==0) {
            printf("0\n");
        }
        else{
            a_rem = a % 10;
            b_rem = b % 4;
            if (b_rem==0) b_rem = 4;
            printf("%d\n",matrix[a_rem][b_rem-1]);            
        }
    }    
    return 0;
}
```
