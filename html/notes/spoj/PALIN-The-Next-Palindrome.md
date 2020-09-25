# PALIN - The Next Palindrome

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 15, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/PALIN/" target="_blank">https://www.spoj.com/problems/PALIN/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

#define MAXDIG 1000000

int main()
{
    int T, t, k, c, i, temp, ctemp, carry, onOFF=0, NormalCase=0;
    char K[MAXDIG];
    scanf("%d",&T);
    for (t=0;t<T;t++)
    {
        scanf("%s",K);
        k = 0;
        onOFF = 0;
        NormalCase = 0;
        while ((int) K[k]) k++;
        c = ((k%2)==0) ? (k/2)-1 : (k-1)/2;
        ctemp = c;
        
        if ((k!=1) && ((k%2)==0) && ((int) (K[ctemp]-'0') >= (int) (K[k-1-ctemp]-'0'))){
            NormalCase = 1;
        }
        
        if ((k!=1) && ((k%2)==1) && ((int) (K[ctemp-1]-'0') >= (int) (K[k-1-ctemp]-'0'))){
            NormalCase = 1;
        }
        
        if (NormalCase){
            while (K[ctemp] == K[k-1-ctemp]){
                ctemp--;
                if ((ctemp==-1) || ((int) (K[ctemp]-'0') < (int) (K[k-1-ctemp]-'0'))) {
                    ctemp = c;
                    onOFF = 1;
                    break;
                }
            }
        }
        
        if ((onOFF==0) && NormalCase){
            for (i=ctemp+1;i<k;i++) K[i] = K[k-1-i];
        }
        else{
            temp = (int) (K[ctemp]-'0') + 1;
            K[ctemp] = temp%10 + '0';
            carry = temp/10;
            ctemp -= 1;
            while ((ctemp != -1) && carry){
                temp = (int) (K[ctemp]-'0') + carry;
                K[ctemp] = temp%10 + '0';
                carry = temp/10;
                ctemp--;
            }
            if (carry) {
                for (i=k;i>0;i--) K[i] = K[i-1];
                K[0] = carry + '0';
                k++;
            }
            for (i=c+1;i<k;i++) K[i] = K[k-1-i];
        }
        
        printf("%s\n",K);
        for (i=0;i<MAXDIG;i++) K[i] = 0;
    }
    return 0;
}
```
