# AMR11E - Distinct Primes

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 19, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/AMR11E/" target="_blank">https://www.spoj.com/problems/AMR11E/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <string.h>
#include <math.h>

#define LIMITER 10000

char primes[LIMITER+1];
char dct_primes[LIMITER+1];

int main(){
    int delta, delta2;
    
    delta2 = 3000;
    delta  = 3000;
    
    memset(primes,1,LIMITER+1);
    memset(dct_primes,0,LIMITER+1);
    primes[0] = primes[1] = 0;
    
    int i, j, k;
    for (i=2;i<=delta;i++){
        if (primes[i]){
            for (j=i+i;j<=delta2;j+=i){
                if (primes[j]){
                    primes[j] = 0;
                    dct_primes[j]+=1;
                }
                else{
                    dct_primes[j]+=1;
                }
            }
        }
    }
    
    int lucky_number[1001];
    
    for (k=0,i=1;k<=j;k++){
        if (dct_primes[k]>=3){
            lucky_number[i] = k;
            if (i==1000) break;
            i++;
        }
    }
    
    int T, n;
    scanf("%d",&T);
    
    while (T>0){
        scanf("%d",&n);
        printf("%d\n",lucky_number[n]);
        T--;
    }
    
    return 0;
}
```
