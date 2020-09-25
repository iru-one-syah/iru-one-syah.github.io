# ANARC08B - Adding Sevens

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 25, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ANARC08B/" target="_blank">https://www.spoj.com/problems/ANARC08B/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char hex[30]= "063010093079106103119011127107";

int hex2dec(char S[]){
    int n = strlen(S)/3, j;
    char dec[n];
    memset(dec,'\0',n+1);
    for(n--;n>=0;n--){
        for (j=0;j<10;j++){
            if ((S[n*3]==hex[j*3])&&(S[n*3+1]==hex[j*3+1])&&(S[n*3+2]==hex[j*3+2])){
                dec[n] = j+'0';
                break;
            }
        }
    }
    return atoi(dec);
}

void dec2hex(int c){
    int temp, i=1;
    temp = c/10;
    for (;temp;temp/=10,i++);
    char cs[i];
    memset(cs,'\0',i+1);
    sprintf(cs,"%d",c);
    char C[i*3];
    memset(C,'\0',i*3+1);
    for (;i>0;i--){
        C[3*(i-1)]   = hex[(int)(cs[i-1]-'0')*3];
        C[3*(i-1)+1] = hex[(int)(cs[i-1]-'0')*3+1];
        C[3*(i-1)+2] = hex[(int)(cs[i-1]-'0')*3+2];
    }
    printf("=%s\n",C);
}

void split(char S[], int ab[]){
    int n = strlen(S), i, ai, bi;
    for (i=0;i<n;i++){
        if (S[i]=='+')
            break;
    }
    char A[i], B[n-i-2];
    memset(A,'\0',i+1);
    memset(B,'\0',n-i-2+1);
    for (ai=0;ai<i;A[ai]=S[ai],ai++);
    for (bi=i+1;bi<n-1;bi++) B[bi-i-1] = S[bi];
    ab[0] = hex2dec(A);
    ab[1] = hex2dec(B);
    printf("%s+%s",A,B);
}

int main(){
    char S[1000];
    int ab[2];
    while (1){
        scanf("%s",S);
        if (strlen(S)==3){
            break;
        }
        else{
            split(S,ab);
            dec2hex(ab[0]+ab[1]);
            memset(S,'\0',1000+1);
        }
    }
    return 0;
}
```
