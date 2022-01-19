//
// Created by colin on 1/18/2022.
//

void quickSort(int A[7], int lo, int hi);

int partition(int *A, int lo, int hi);

// function to print array elements
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void swap (int *a, int *b) {

    int temp = *a;

    *a = *b;

    *b = temp;

}

// main function
int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6, 15, -12, 17, 91, 91, 1};

    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array\n");
    printArray(data, n);

    // perform quicksort on data
    quickSort(data, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(data, n);
}

void quickSort(int A[7], int lo, int hi) {
    if (lo < hi) {
        int pivot = partition (A, lo, hi);
        quickSort(A, lo, pivot - 1);
        quickSort(A, pivot + 1, hi);
    }
}

int partition(int *A, int lo, int hi) {

    int pivot = A[lo];
    int *pPivot = &A[lo];

    hi++;

    while (lo < hi) {

        while (A[--hi] > pivot);
        while (A[++lo] < pivot);

        printf ("High element in wrong place at location : %i, with value %i\n", hi, A[hi]);
        printf ("Low element in wrong place at location : %i, with value %i\n", lo, A[lo]);

        if (lo < hi)
            swap(&A[lo], &A[hi]);

    }

    swap (pPivot, &A[hi]);

    return hi;

}