# ARCTAN - Use of Function Arctan

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 22, 2018 </span></p>

## Problem

<a href="https://www.spoj.com/problems/ARCTAN/" target="_blank">https://www.spoj.com/problems/ARCTAN/</a>

## Solution:

in `C` language.

```c
#include<stdio.h>
int main(){
int T;scanf("%d",&T);
long long a,b,c,d;
for(;T>0;T--){
scanf("%lld",&a);
b=a+1;c=0;d=0;
for(;b<=2*a;b++){
if((a*b+1)%(b-a)==0)c=(b*b+1)/(b-a);
if(c!=0){if((c>d)&(d!=0))break;
else d=c;}
} printf("%lld\n",d);}}
```
