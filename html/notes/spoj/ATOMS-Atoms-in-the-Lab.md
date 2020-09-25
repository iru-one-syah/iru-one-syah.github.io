# ATOMS - Atoms in the Lab

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 22, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ATOMS/" target="_blank">https://www.spoj.com/problems/ATOMS/</a>

## Solution:

in `python3`.

```python
P = int(input())
for p in range(P):
    NKM = input().split()
    for i in range(len(NKM)):
        NKM[i] = int(NKM[i])
    t = 0;
    while (NKM[0] <= NKM[2]):
        NKM[0]*=NKM[1]
        if (NKM[0] <= NKM[2]):
            t+=1
    print(int(t))
```
