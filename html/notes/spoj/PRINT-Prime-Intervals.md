# PRINT - Prime Intervals

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 19, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/PRINT/" target="_blank">https://www.spoj.com/problems/PRINT/</a>

## Solution:

in `C` language.

```c
/*https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Segmented_sieve*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define LIMITER 3000000000

char primes[LIMITER+1];
long long delta, delta2;

void seive_init()
{
    memset(primes,1,LIMITER+1);
    primes[0] = primes[1] = 0;
    
    long long i, j;
    for (i=2;i<=delta;i++){
        if (primes[i]){
            for (j=i*i;j<=delta2;j+=i){
                if (primes[j]){
                    primes[j] = 0;
                }
            }
        }
    }
}

void seive_algo(long long m, long long n){
    
    delta = sqrt(n);
    
    int i, j;
    for (i=2;i<=delta;i++){
        if (primes[i]){
            for (j=(m-(m%i));j<=n;j+=i){
                if (primes[j] && (j!=i) && (j>=m)){
                    primes[j] = 0;
                }
            }
        }
    }
}

int main()
{
    delta2 = sqrt(LIMITER);
    delta  = sqrt(delta2);

    seive_init();
    
    long long m, n, i, T, t;
    
    scanf("%lld",&T);
    for (t=0;t<T;t++)
    {
        scanf("%lld %lld", &m, &n);
        
        if (n>delta2){
            seive_algo(m, n);
        }
        
        for (i=m;i<=n;i++){
            if (primes[i]){
                printf("%lld\n",i);
            }
        }
    }
    
    return 0;
}
```
