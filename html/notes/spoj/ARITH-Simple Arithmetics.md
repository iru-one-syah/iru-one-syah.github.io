# ARITH - Simple Arithmetics

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 19, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ARITH/" target="_blank">https://www.spoj.com/problems/ARITH/</a>

## Solution:

in `python3`.

```python
T = int(input())
while (T>0):
    S = input()
    
    if '+' in S:
        a, b = S.split('+')
        c = str(int(a) + int(b))
        operator = '+'
    elif '-' in S:
        a, b = S.split('-')
        c = str(int(a) - int(b))
        operator = '-'
    else:
        a, b = S.split('*')
        c = str(int(a) * int(b))
        operator = '*'
        
    if (operator=='+' or operator=='-'):
        len_a = len(a)
        len_b = len(b)+1
        len_c = len(c)
        
        max_len = max(len_a,len_b,len_c)
        
        print((max_len-len_a)*' '+a)
        print((max_len-len_b)*' '+operator+b)
        
        if (len_c!=1) and (operator!='+'):                
            if (len_b > len_c):
                n = len_b*'-'
                print((max_len-len_b)*' '+n)
            else:
                n = len_c*'-'
                print((max_len-len_c)*' '+n)
        else:
            if ((len_a > len_b) and (len_a==len_c)):
                n = len_a*'-'
                print((max_len-len_a)*' '+n)
            else:
                n = len_b*'-'
                print((max_len-len_b)*' '+n)
        
        print((max_len-len_c)*' '+c)
    else:
        len_a = len(a)
        len_b = len(b)+1
        len_c = len(c)
        
        max_len = max(len_a,len_b,len_c)
        n2 = len_c*'-'
        
        print((max_len-len_a)*' '+a)
        print((max_len-len_b)*' '+operator+b)
        
        if ((len_b-1)>1):
            b_rev = b[::-1]
            
            for i in range(len_b-1):
                e = str(int(a)*int(b_rev[i]+i*'0'))
                len_e = len(e)
                
                if ((i==0) and (len_a<=len_b-1)):
                    n1 = len_b*'-'
                    print((max_len-len_b)*' '+n1)
                elif ((i==0) and (len_e!=1)):
                    n1 = len_e*'-'
                    print((max_len-len_e)*' '+n1)
                elif ((i==0) and (len_e==1)):
                    n1 = len_b*'-'
                    print((max_len-len_b)*' '+n1)
                    
                if (len_e==1):
                    e = e+i*'0'
                    len_e = len(e)
                print((max_len-len_e)*' '+e[0:len_e-i])
        
        print((max_len-len_c)*' '+n2)
        print((max_len-len_c)*' '+c)
    
    print('')
    T-=1;
```