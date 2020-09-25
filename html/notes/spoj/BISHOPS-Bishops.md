# BISHOPS - Bishops

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 25, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/BISHOPS/" target="_blank">https://www.spoj.com/problems/BISHOPS/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <string.h>

#define LIMIT 110

int main()
{
    int T = 1024, I, temp, i;
    char N[LIMIT], c;
    for (;T>0;T--){
        scanf("%s",N);
        
        I = strlen(N);
        
        if ((I==1) && (N[0] <= '1')){
            printf("%s\n",N);
        }
        else{
            for (i=0;i<I/2;i++){
                c = N[I-1-i];
                N[I-1-i] = N[i];
                N[i] = c;
            }
            
            temp = (N[0]<'1') ? 10 : 0;
            N[0] = (int) (N[0]-'0') + temp - 1 + '0';
            for (i=1;temp;i++){
                temp = (N[i]<'1') ? 10 : 0;
                N[i] = (int) (N[i]-'0') + temp - 1 + '0';
            }
            if (N[I-1]=='0') I--;
            
            temp = 0;
            for (i=0;i<I;i++){
                temp = (int) (N[i]-'0') * 2 + temp;
                N[i] = temp%10 + '0';
                temp = temp/10;
            }
            if (temp) {
                N[I] = temp + '0';
                I++;
            }
            
            for (i=0;i<I;i++) printf("%c",N[I-1-i]);
            printf("\n");
            
            memset(N,'\0',LIMIT);
        }
    }
    return 0;
}
```
