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
    int A[] = {9,0,8,1,7,2,6,3,5,4};
    
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
