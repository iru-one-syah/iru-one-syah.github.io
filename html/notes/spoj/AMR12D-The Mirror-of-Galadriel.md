# AMR12D - The Mirror of Galadriel

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 29, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/AMR12D/" target="_blank">https://www.spoj.com/problems/AMR12D/</a>

## Solution:

in `C` language.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    int T, s, OnOff;
    scanf("%d",&T);
    while (T--){
        OnOff = 1;
        char S[10];
        scanf("%s",S);
        s = strlen(S);
        for (int i=0;i<=(s-1)/2;i++){
            if (S[i] != S[s-1-i]){
                OnOff = 0;
                break;
            }
        }
        if (OnOff == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
```

in `python3`.

```python
T = int(input())
for _ in range(T):
    S = input()
    if (S == S[::-1]):
        print("YES")
    else:
        print("NO")
```