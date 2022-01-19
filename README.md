# Practice for test

### Q08 for recursive functions
Remember to build up recursively starting from length of preexisting array and growing

### Binary Search
Remember declaration is ```void BinSearch(int a[10], int low, int mid, int end, int find)```

### Merge Sort
Remember to declare n1, n2 for the sub arrays.
Tasks are :
1. Split array
2. Populate lower fo two arrays until one array is finished
3. Cleanup

##### Declaration 
```asm
void merge (int A[], int lo, int high) {
    if (lo < hi) {
        int mid = (lo + hi)/2;
        merge (A, lo, mid);
        merge (A, mid + 1, hi);
        combine (A, lo, mid, hi);
    }
}
```

### Quick sort
Remember on quick sort call to avoid pivot.
Tasks are :
1. First set a pivot and pointer to pivot
2. Increment hi (both lo and hi are incremented/decremented then checked, so it needs to be one ahead)
3. Enter loop while lo < hi
4. Find element on right that should be on the left
5. Find element on left that should be on the right
6. If low is less than hi then swap
7. Repeat 3-6
8. Swap pivot and current middle element (empty slot)

##### Declaration
```asm
void quickSort(int A[7], int lo, int hi) {
    if (lo < hi) {
        int pivot = partition (A, lo, hi);
        quickSort(A, lo, pivot - 1);
        quickSort(A, pivot + 1, hi);
    }
}
```

### Convert different bases
Remember to use loop from end of string, increasing power each time as you go closer to furthest left value.
Here is the code from geeksforgeeks :
```asm
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 
// Function to convert a number from given base 'b'
// to decimal
int toDeci(char *str, int base)
{
    int len = strlen(str);
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;
 
    // Decimal equivalent is str[len-1]*1 +
    // str[len-2]*base + str[len-3]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if (val(str[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }
 
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}
```

### Review formulas for arithmetic and geometric series / sum
nth term in series - 
> An = A1 + (n - 1)d
>> An representing any term. A1 is the base term and (n-1) represents the number of times the difference has been used (-1 since the first term doesn’t have a difference). Finally, d represents the difference between each term.

sum of series terms - 
> Sn = (n (A1 + A2)) / 2
>> Sn representing the sum. n represents the number of terms. A1 is the first term, and A2 is the second term.

summing geometric sequence - 
> Sn = (a1 (1 - r^n)) / (1 - r)
>> Sn representing the sum. n represents the number of terms. A1 is the first term. r is the common ratio, and can be calculated by dividing two consecutive terms.