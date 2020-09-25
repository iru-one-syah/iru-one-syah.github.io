# FAST2 - Fast Sum of two to an exponent

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 21, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/FAST2/" target="_blank">https://www.spoj.com/problems/FAST2/</a>

## Solution:

in `python3`.

```python
O = []
res = 0
for i in range(0,501):
    res += 2**i
    O.append((res % 1298074214633706835075030044377087))

T = int(input())
while (T):
    n = int(input())
    print(O[n])
    T-=1
```