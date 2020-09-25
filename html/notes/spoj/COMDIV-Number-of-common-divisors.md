# COMDIV - Number of common divisors

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 25, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/COMDIV/" target="_blank">https://www.spoj.com/problems/COMDIV/</a>

## Solution:

in `C` language.

```c
#include <stdio.h> 
#include <string.h>
#include <math.h>

#define LIMITER 1000000

int primes[LIMITER+1];
int delta, delta2;

void seive_init()
{
    delta2 = LIMITER;
    delta  = sqrt(delta2);
    
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

int gcd(int A, int B)
{
    int temp;
    while (B){
        temp = B;
        B = A % B;
        A = temp;
    }
    return A;
}

int main()
{
    seive_init();
    
    int T, A, B, D, ans, i;
    scanf("%d",&T);
    
    while (T--){
        scanf("%d %d",&A,&B);
        if (primes[A] && primes[B]){
            if (A!=B) printf("1\n");
            else printf("2\n");
            continue;            
        }
        
        D = gcd(A,B);
        if (primes[D]){
            printf("2\n");        
        }
        else if (D==1){
            printf("1\n");
        }
        else{
            ans=2;
            delta = sqrt(D)+1;
            for(i=2;i<delta;i++){
                if ((D%i)==0) ans += (i*i!=D) ? 2 : 1;
            }
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
```
