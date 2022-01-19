//
// Created by colin on 1/18/2022.
//

void BinSearch(int a[10], int low, int mid, int end, int find);

int main() {

    // Binary search
    int n = 10;
    int find = 15;
    int a[10] = {1,4,5,6,8,9,12,15,19,21};

    BinSearch (a, 0, 5, n, find);
}

void BinSearch(int a[10], int low, int mid, int end, int find) {

    if (mid < low || mid > end)
        return;

    if (a[mid] == find)
        printf ("Found at index %i = %i.\n", mid, a[mid]);

    if (a[mid] < find)
        BinSearch (a, mid, (mid + end)/2, end, find);

    if (a[mid] > find)
        BinSearch (a, low, (mid + end)/2, mid, find);

}
