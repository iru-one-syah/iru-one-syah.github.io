# ADDREV - Adding Reversed Numbers

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 16, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ADDREV/" target="_blank">https://www.spoj.com/problems/ADDREV/</a>

## Solution:

in `c` language.

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int N, n, a, b, ab, pa, pb, pab, arev=0, brev=0, abrev=0, i;
    scanf("%d",&N);
    
    int remainder;
    for (n=0;n<N;n++)
    {
        scanf("%d %d",&a,&b);
        pa = (int) log10(a);
        pb = (int) log10(b);
        
        for (i=0;i<=pa;i++)
        {
            remainder = (a % (int) pow(10,i+1))/pow(10,i);
            arev += remainder*pow(10,pa-i);
            a = a - remainder;
        }
        
        for (i=0;i<=pb;i++)
        {
            remainder = (b % (int) pow(10,i+1))/pow(10,i);
            brev += remainder*pow(10,pb-i);
            b = b - remainder;
        }
        
        ab = arev+brev;
        pab = (int) log10(ab);
        
        for (i=0;i<=pab;i++)
        {
            remainder = (ab % (int) pow(10,i+1))/pow(10,i);
            abrev += remainder*pow(10,pab-i);
            ab = ab - remainder;
        }
        
        printf("%d\n",abrev);
        arev = 0; brev = 0; abrev = 0;
    }
}
```

in `python3`.

```python
n = int(input())
while (n > 0):
    x1, x2 = input().split(" ")
    x1 = int(x1[::-1])
    x2 = int(x2[::-1])
    x3 = str(x1+x2)
    print(int(x3[::-1]))
    n = n - 1
```