#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"


void swap(int *left, int *right) {
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

void insertion_sort(int A[], int N) {
    int j, p;
    int tmp;
    for (p = 1;  p < N; p++) {
        tmp = A[p];
        for (j = p; j > 0 && A[j - 1] > tmp; j--) {
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}

int median(int A[], int left, int right) {
    int center = (left + right) / 2;

    if (A[left] > A[center])
        swap(&A[left], &A[center]);
    if (A[left] > A[right])
        swap(&A[left], &A[right]);
    if (A[center] > A[right])
        swap(&A[center], &A[right]);

    swap(&A[center], &A[right - 1]);
    return A[right - 1];
}


#define Cutoff (3)
void Qsort(int A[], int left, int right) {
    int i, j;
    int pivot;

    if (left + Cutoff <= right) {
        pivot = median(A, left, right);
        i = left; j = right - 1;
        for (;;) {
            while(A[++i] < pivot) {}
            while(A[--j] > pivot) {}
            if (i < j)
                swap(&A[i], &A[j]);
            else
                break;
        }
        swap(&A[i], &A[right - 1]);  // restore pivot
        Qsort(A, left, i - 1);
        Qsort(A, i + 1, right);
    } else {
        insertion_sort(A + left, right - left + 1);
    }
}

void quick_sort(int A[], int N) {
    Qsort(A, 0, N - 1);
}

int main(int argc, char *argv[])
{
    int n = 500;
    int arr[n];
    int i;
    for (i = 0; i < n; i++)
        arr[i] = i;
    for( i = 1; i < n; i++ )
        swap( &arr[ i ], &arr[ rand( ) % ( i + 1 ) ] );
    quick_sort(arr, n);
    for (i = 0; i < n; i++)
        if (arr[i] != i)
            fprintf(stderr, "Sort failed: %d %d\n", i, arr[i]);
    fprintf(stderr, "Sort Succeed!\n");
    return 0;
}
