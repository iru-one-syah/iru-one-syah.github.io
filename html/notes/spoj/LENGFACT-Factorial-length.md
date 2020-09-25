# LENGFACT - Factorial length

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 21, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/LENGFACT/" target="_blank">https://www.spoj.com/problems/LENGFACT/</a>

## Solution:

in `c` language.

```c
// http://www.luschny.de/math/factorial/FactorialDigits.html

#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979323846

long long kamenetsky(long long n){
    return (long long) (ceil((1.0/2.0)*(log(2*pi)-2*n+log(n)*(1+2*n))/log(10.0)));
}

int main()
{
    int T, t;
    double digits;
    long long i, N;
    
    scanf("%d",&T);
    
    for (t=0;t<T;t++)
    {
        scanf("%lld",&N);
        
        if (N<=1){
            printf("1\n");
        }
        else{
            printf("%lld\n", kamenetsky(N));
        }
        
    }
    return 0;
}
```

in `python3`.

```python
# http://www.luschny.de/math/factorial/FactorialDigits.html
from math import ceil, log, pi, e

def kamenetsky(n):
    return int(ceil((1/2)*(log(2*pi)-2*n+log(n)*(1+2*n))/log(10)))

n = int(input())
while (n > 0):
    x = int(input())
    if (x<=1):
        print(1)
    else:
        print(kamenetsky(x))
    n-=1
```