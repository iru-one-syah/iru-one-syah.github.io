# ACODE - Alphacode

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 27, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ACODE/" target="_blank">https://www.spoj.com/problems/ACODE/</a>

## Solution:

in `c` language.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char S[5000];
    int ans[3]={1,1,1}, size, i;
    
    while (1){
        scanf("%s",S); size = strlen(S);
        
        if (size==1){
            if (S[size-1]=='0') break;
        }
        
        if (S[size-1] == '0') ans[0] = 0;
        
        for (i=size-1;i>0;i--){
            if (S[i-1] == '0'){
                ans[1] = ans[0];
                ans[0] = 0;
            }
            else if ((S[i-1]-'0')*10+(S[i]-'0')<=26){
                ans[2]  = ans[0];
                ans[0] += ans[1];
                ans[1]  = ans[2];
            }
            else ans[1] = ans[0];
        }
        printf("%d\n",ans[0]);
        
        for (i=0;i<3;ans[i]=1,i++);
    }
    return 0;
}
```

in `python3`.

```python
while True:
    S = input(); size = len(S); ans = [1,1,1]
    
    if  S == '0':
        break
    
    if  S[size-1] == '0':
        ans[0] = 0
        
    for i in range(size-1,0,-1):
        if  S[i-1] == '0':
            ans[1] = ans[0]
            ans[0] = 0
        elif int(S[i-1]+S[i])<=26:
            ans[2]  = ans[0]
            ans[0] += ans[1]
            ans[1]  = ans[2]
        else:
            ans[1] = ans[0]

    print(ans[0])
```