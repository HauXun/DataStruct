#include <iostream>

using namespace std;

void QuickSort(int a[], int l, int r)
{
    int p = a[(l + r) / 2];
    int i = l, j = r;
    while (i < j)
    {
        while (a[i] < p)
        {
            i++;
        }
        while (a[j] > p)
        {
            j--;
        }
        if (i <= j)
            swap(a[i++], a[j--]);
    }
    if (i < r)
        QuickSort(a, i, r);
    if (l < j)
        QuickSort(a, l, j);
}

int Result(int a[], int n, int k)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > k)
            count++;
    }
    return count + 1;
}

int main()
{
    int a[100];
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    QuickSort(a, 0, n - 1);
    cout << Result(a, n, k);
    return 0;
}