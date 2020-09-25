# PTIME - Prime Time

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 19, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/PTIME/" target="_blank">https://www.spoj.com/problems/PTIME/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <string.h>
#include <math.h>

#define LIMITER 11000

char primes[LIMITER+1];
int  delta, delta2;

void seive_init()
{
    memset(primes,1,LIMITER+1);
    primes[0] = primes[1] = 0;
    
    int i, j;
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

int main()
{
    delta2 = LIMITER;
    delta  = sqrt(delta2);
    
    seive_init();
    
    int only_prime[1500];
    memset(only_prime,0,1500*sizeof(int));
    
    int i,j;
    for (i=0,j=0;i<=delta2;i++){
        if (primes[i]){
            only_prime[j] = i;
            j++;
        }
    }
    
    int N, res, temp;
    scanf("%d",&N);
    
    for (i=0;only_prime[i]<=N;i++){
        res = 0; temp=N;
        while (temp=temp/only_prime[i]){
            res += temp;
        }
        if (res!=0){
            printf("%d^%d",only_prime[i],res);
            if (only_prime[i+1]<N) printf(" * ");
        }
    }
    printf("\n");
    
    return 0;
}
```
