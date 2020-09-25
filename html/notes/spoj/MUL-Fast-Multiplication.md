# MUL - Fast Multiplication

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 19, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/MUL/" target="_blank">https://www.spoj.com/problems/MUL/</a>

## Solution:

in `python3`.

```python
n = int(input())
while (n > 0):
    x1, x2 = input().split(" ")
    x1 = int(x1)
    x2 = int(x2)
    print(x1*x2)
    n = n - 1
```