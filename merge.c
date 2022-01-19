//
// Created by colin on 1/18/2022.
//

void merge(int *A, int lo, int mid, int hi);

void printArray(int A[], int size);

void mergeSort(int *A, int lo, int hi) {

    if (lo < hi) {

        // Find mid
        int mid = (lo + hi) / 2;
        // Mergesort right
        mergeSort(A, lo, mid);
        // Mergesort left
        mergeSort(A, mid + 1, hi);
        // Merge
        merge(A, lo, mid, hi);

    }

}

void merge(int *A, int lo, int mid, int hi) {

    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    // Use two subarray split on mid
    int left[n1], right[n2];

    for (int i = 0; i < n1; ++i) {
        left[i] = A[i + lo];
    }

    for (int i = 0; i < n2; ++i) {
        right[i] = A[i + mid + 1];
    }

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    int i = 0, j = 0, counter = lo;

    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            A[counter] = left[i];
            i++;
        } else {
            A[counter] = right[j];
            j++;
        }
        counter++;
    }

    while (i < n1) {
        A[counter] = left[i];
        counter++;
        i++;
    }

    while (j < n2) {
        A[counter] = right[j];
        counter++;
        j++;
    }

    int arr_size = sizeof(A) / sizeof(A[0]);

    printf("\nCurrent array is \n");
    printArray(A, arr_size);

}

void printArray(int *A, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}