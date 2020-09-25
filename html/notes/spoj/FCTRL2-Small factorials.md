# FCTRL2 - Small factorials

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 16, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/FCTRL2/" target="_blank">https://www.spoj.com/problems/FCTRL2/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>

int main()
{
    int T, t, N, n, temp, i, carry, result_size;
    char results[321];
    carry = 0;
    
    scanf("%d",&T);
    
    for (t=0;t<T;t++)
    {
        scanf("%d",&N);
        
        results[0] = '1';
        result_size = 0;
        
        for (n=2;n<=N;n++)
        {
            for (i=0;i<=result_size;i++)
            {
                temp = (int) (results[i]-'0') * n + carry;
                results[i] = temp % 10 + '0';
                carry = temp/10;
            }
            
            while (carry)
            {
                result_size++;
                results[result_size] = carry % 10 + '0';
                carry = carry/10;
            }
        }
        
        for (i=result_size;i>=0;i--)
        {
            printf("%c",results[i]);
        }
        printf("\n");
    }
    
    return 0;
}
```

in `python3`.

```python
import math

n = int(input())
while (n > 0):
    x = int(input())
    y = math.factorial(x)
    print(y)
    n = n - 1
```