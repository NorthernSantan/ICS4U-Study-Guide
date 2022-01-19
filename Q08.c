//
// Created by colin on 1/18/2022.
//

int nthTerm3n(int a[], int n);

int nthTermOn(int a[], int n, int i);

int nthTermIt(int a[], int n);

int main() {

    printf ("\nCurrently in Q0%i : ", 8);
    printf ("Determine the nth term of the following sequence: \n"
            "1, 2, -2, 1, 1, 0, 2, 3, 5, 10, … \n"
            "Here you can see that the nth term is the sum of the three previous terms.\n");

    int nth3n, nthOn, nthIt, n;
    int arr1[MAX_ELEMENTS] = {1,2,-2};
    int arr2[MAX_ELEMENTS] = {1,2,-2};
    int arr3[MAX_ELEMENTS] = {1,2,-2};

    do {
        printf ("Please enter the term number you want to find : ");
        scanf ("%i", &n);
        fflush(stdin);
    } while (n > MAX_ELEMENTS);

    nth3n = nthTerm3n(arr1, n - 1);
    nthOn = nthTermOn (arr2, n, LENGTH_OF_ARR);
    nthIt = nthTermIt (arr3, n);

    printf ("The %i term in the sequence using the recursive O(3^n) time complexity solution is %i.\n", n, nth3n);
    printf ("The %i term in the sequence using the recursive O(n) time complexity solution is %i.\n", n, nthOn);
    printf ("The %i term in the sequence using the iterative O(n) time complexity solution is %i.\n", n, nthIt);

    return 0;

}

int nthTermIt(int a[], int n) {

    for (int j = LENGTH_OF_ARR; j < n; ++j) {
        a[j] = a[j-1] + a[j-2] + a[j-3];
    }

    return a[n - 1];
}

int nthTermOn(int a[], int n, int i) {

    // Base case A[0], A[1], A[2]

    if (i > n)
        return a[n - 1];

    a[i] = a[i - 1] + a[i - 2] + a[i - 3];

    return nthTermOn(a, n, i + 1);

}

int nthTerm3n(int a[], int n) {

    if (n != 0 && n != 1 && n != 2)
        a[n] = nthTerm3n(a, n - 1) + nthTerm3n(a, n - 2) + nthTerm3n(a, n - 3);

    return a[n];

}