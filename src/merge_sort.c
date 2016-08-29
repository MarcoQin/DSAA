#include "merge_sort.h"
#include "dbg.h"

void Merge(int A[], int tmp_array[], int l_pos, int r_pos, int r_end) {
    int i, l_end, num_elements, tmp_pos;

    l_end = r_pos - 1;
    tmp_pos = l_pos;
    num_elements = r_end - l_pos + 1;

    while (l_pos <= l_end && r_pos <= r_end) {
        if (A[l_pos] <= A[r_pos]) {
            tmp_array[tmp_pos++] = A[l_pos++];
        } else {
            tmp_array[tmp_pos++] = A[r_pos++];
        }
    }
    while (l_pos <= l_end) {
        tmp_array[tmp_pos++] = A[l_pos++];
    }
    while (r_pos <= r_end) {
        tmp_array[tmp_pos++] = A[r_pos++];
    }

    for (i = 0; i < num_elements; i++, r_end--) {
        A[r_end] = tmp_array[r_end];
    }
}

void MSort(int A[], int tmp_array[], int left, int right) {
    int center;

    if (left < right) {
        center = (left + right) / 2;
        MSort(A, tmp_array, left, center);
        MSort(A, tmp_array, center + 1, right);
        Merge(A, tmp_array, left, center + 1, right);
    }
}


void MergeSort(int A[], int N) {
    int *tmp_array;

    tmp_array = malloc(N * sizeof(int));
    check_mem(tmp_array);
    MSort(A, tmp_array, 0, N - 1);
    free(tmp_array);
    return;
error:
    exit(1);
}


int main(int argc, char *argv[])
{
#define SIZE 50
    int arr[SIZE];
    int i;
    for (i = 0; i < SIZE; i++) {
        arr[i] = i;
    }
    MergeSort(arr, SIZE);
    for (i = 0; i < SIZE; i++) {
        if (arr[i] != i)
            fprintf(stderr, "Sort Fails: %d %d\n", i, arr[i]);
    }
    fprintf(stderr, "Sort complete\n");
    return 0;
}
