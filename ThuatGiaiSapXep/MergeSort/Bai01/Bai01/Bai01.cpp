#include <iostream>
#include <time.h>

using namespace std;

void PrinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << '\t';
    }
    cout << '\n';
}

void Merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int [n1],
        *R = new int [n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[i++];
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}
void MergeSort(int a[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10 + 1;
    }
    MergeSort(a, 0, n - 1);
    PrinArray(a, n);
}