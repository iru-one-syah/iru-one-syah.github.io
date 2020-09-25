# ABSYS - Anti-Blot System

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 22, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ABSYS/" target="_blank">https://www.spoj.com/problems/ABSYS/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000000
char A[MAX], B[MAX], C[MAX];

void split(char S[])
{
    long long i, n;
    n = strlen(S);
    
    long long ai, bi, ci;
    ai = 0; bi = 0; ci = 0;
    
    int OnOFF = 1;
    for (i=0;i<n;i++){
        if (S[i] == ' '){
            OnOFF+=1;
            continue;
        }
        else if (OnOFF == 1){
            A[ai] = S[i]; ai++;
        }
        else if (OnOFF == 3){
            B[bi] = S[i]; bi++;
        }
        else if (OnOFF == 5){
            C[ci] = S[i]; ci++;
        }
    }
}

int ismachula(char X[])
{
    long long i, n;
    n = strlen(X);
    
    for (i=0;i<n;i++){
        if (X[i] == 'm'){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int T;
    char S[MAX];
    scanf("%d",&T);
    while (T>0)
    {
        scanf(" %[^\n]s",S);
        
        split(S);
        
        if (ismachula(A)){
            printf("%lld + ",atoll(C)-atoll(B));
            printf("%lld = %lld\n",atoll(B),atoll(C));
        }
        else if (ismachula(B)){
            printf("%lld + %lld",atoll(A),atoll(C)-atoll(A));
            printf(" = %lld\n",atoll(C));
        }
        else{
            printf("%lld + %lld",atoll(A),atoll(B));
            printf(" = %lld\n",atoll(A)+atoll(B));
        }
        
        memset(A,'\0', sizeof(char)*MAX);
        memset(C,'\0', sizeof(char)*MAX);
        memset(B,'\0', sizeof(char)*MAX);
        
        T--;
    }
    return 0;
}
```
