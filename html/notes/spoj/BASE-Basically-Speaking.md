# BASE - Basically Speaking

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 25, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/BASE/" target="_blank">https://www.spoj.com/problems/BASE/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <string.h>

int limits [17];
char dataset[16]="0123456789ABCDEF";

int limit(){
    memset(limits,0,17*sizeof(int));
    int i, j, k;
    for (i=2;i<=17;i++){
        for (k=1,j=0;j<7;k*=i,j++)
            limits[i] += (i-1)*k;
    }
}

int main()
{
    int base0, base1, i;
    char S[7];
    
    limit();
    
    while (scanf("%s %d %d",S,&base0,&base1) == 3){
        for (i=0;S[i]==' ';S[i]='\0');
        
        int dec=0, n=strlen(S), i=1;
        for (;n>0;n--){
            dec += (S[n-1] <= '9') ? (S[n-1]-'0')*i : (S[n-1]-'0'-7)*i;
            i *= base0;
        }
        
        if (dec > limits[base1]){
            printf("  ERROR\n");
            continue;
        }
        else if (dec == 0){
            printf("      0\n");
            continue;
        }
        
        memset(S,' ',7*sizeof(char));
        for (i=0; dec; i++){
            S[i] = dataset[dec % base1];
            dec  = dec / base1;
        }
        
        for (i=6;i>=0;i--) printf("%c",S[i]);
        printf("\n");
    }
    
    return 0;
}
```
