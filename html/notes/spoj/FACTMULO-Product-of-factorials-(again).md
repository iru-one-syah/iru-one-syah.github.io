# FACTMULO - Product of factorials (again)

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 27, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/FACTMULO/" target="_blank">https://www.spoj.com/problems/FACTMULO/</a>

## Solution:

in `python2`.

```python
T = int(input())

while (T):
    p, n = list(map(int,raw_input().split()))
    x, ans = p, 0
    
    while (n >= x):
        n_by_x = n/x;
        ans += n_by_x*(n+1) - (x*n_by_x*(n_by_x + 1))/2
        x = x*p
        
    print(ans)
    T -= 1
```
