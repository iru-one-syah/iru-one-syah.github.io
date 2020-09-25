# MAY99_4 - Rachu

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 29, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/MAY99_4/" target="_blank">https://www.spoj.com/problems/MAY99_4/</a>

## Solution:

in `python2`.

```python
m = 10000007
n, r = map(int,raw_input().split())
if (n<r):
    print(-1)
elif (n==r):
    print(1)
else:
    I = min(n-r,r-1)
    ans = 1
    i = 1
    j = n-1
    while (i<=I):
        ans *= j
        ans //= i
        i += 1
        j -= 1
    print(ans%m)
```
