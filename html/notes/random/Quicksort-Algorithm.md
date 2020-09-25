# Quicksort Algorithm

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 28, 2018 </span></p>

## Algorithm

Reference - <a href="https://en.wikipedia.org/wiki/Quicksort" target=_blank>Quicksort Wikipedia</a>

**Quicksort Algorithm**

```
algorithm quicksort(A, lo, hi) is
    if lo < hi then
        p := partition(A, lo, hi)
        quicksort(A, lo, p - 1 )
        quicksort(A, p + 1, hi)

algorithm partition(A, lo, hi) is
    pivot := A[hi]
    i := lo    
    for j := lo to hi - 1 do
        if A[j] < pivot then
            swap A[i] with A[j]
            i := i + 1
    swap A[i] with A[hi]
    return i
```

## C-CODE

File : `sorted.c`

```c
//
// https://en.wikipedia.org/wiki/Quicksort
//

#include <stdio.h>

#define length(x) (int) (sizeof(x)/sizeof(x[0]))

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int lo, int hi){
    int pivot = A[hi];
    int i = lo;
    for (int j=lo; j<= hi-1; j++){
        if (A[j] < pivot){
            swap(&A[i],&A[j]);
            i++;
        }
    }
    swap(&A[i],&A[hi]);
    return i;
}

void quicksort(int A[], int lo, int hi){
    if (lo<hi){
        int p = partition(A,lo,hi);
        quicksort(A,lo,p-1);
        quicksort(A,p+1,hi);
    }
}

int main()
{
    int A[] = {9,8,7,6,5,4,3,2,1,0};
    
    printf("Before:\n");
    for (int i=0; i<length(A);i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    printf("After:\n");
    quicksort(A,0,length(A)-1);
    for (int i=0; i<length(A);i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}
```

To compile:

```bash
gcc -o RunThis sorted.c -lm
```

Then run,

```bash
./RunThis
```

Output:

```bash
irwansyah@irwansyah-CF-NX2:~/IRWANSYAH$ ./RunThis 
Before:
9 0 8 1 7 2 6 3 5 4 
After:
0 1 2 3 4 5 6 7 8 9 
```