# CIRCLE_H - Three Circle Problem (HARD)

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 22, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/CIRCLE_H/" target="_blank">https://www.spoj.com/problems/CIRCLE_H/</a>

## Solution:

in `python3`.

```python
#http://www.gogeometry.com/geometry/soddy_descartes_circles.htm

import decimal

context = decimal.Context(prec=85)
decimal.setcontext(context)

T = int(input())
while (T>0):
    R = input().split()
    
    a = decimal.Decimal(R[0])
    b = decimal.Decimal(R[1])
    c = decimal.Decimal(R[2])
    
    abc = a*b*c;
    b_p_c = b+c;
    
    d   = context.divide(abc,a*b_p_c+b*c+2*(decimal.Decimal.sqrt(abc*(a+b_p_c)))).to_eng_string()
    idx = d.find('.')
    
    print(d[0:idx+51])
    
    T-=1
```
