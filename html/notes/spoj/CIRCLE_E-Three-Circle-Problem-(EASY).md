# CIRCLE_E - Three Circle Problem (EASY)

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 22, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/CIRCLE_E/" target="_blank">https://www.spoj.com/problems/CIRCLE_E/</a>

## Solution:

in `C` language.

```c
// http://www.gogeometry.com/geometry/soddy_descartes_circles.htm

#include <stdio.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    
    long double a, b, c, d;
    for(;T>0;T--){
        scanf("%Lf %Lf %Lf",&a,&b,&c);
        d = (a*b*c)/(a*b+a*c+b*c+2*(sqrt(a*b*c*(a+b+c))));
        printf("%.15Lf\n",d);
    }
    
    return 0;
}
```

in `python3`.

```python
#http://www.gogeometry.com/geometry/soddy_descartes_circles.htm

T = int(input())
while (T>0):
    R = list(map(int, input().split()))
    
    a = R[0]
    b = R[1]
    c = R[2]
    
    d = (a*b*c)/(a*b+a*c+b*c+2*((a*b*c*(a+b+c))**0.5))
    
    print("%.15f" % d)
    
    T-=1
```