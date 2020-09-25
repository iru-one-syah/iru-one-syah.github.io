# ARITH2 - Simple Arithmetics II

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 21, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ARITH2/" target="_blank">https://www.spoj.com/problems/ARITH2/</a>

## Solution:

in `python3`.

```python
T = int(input())

results = []

for t in range(T):
    I   = ['+']
    results.append(0)
    blank = input()
    I.extend(input().split())
    for i in range(int((len(I)-1)/2)):
        results[t] = int(eval('results[t]'+I[i*2]+I[i*2+1]))

for t in range(T):
    print(results[t])
```