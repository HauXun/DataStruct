#include <iostream>
#include <time.h>
#include <math.h>

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
        while (a[i] > p)
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

bool Check(int n)
{
    int k = (int)sqrt(n);
    return pow(k, 2) == n;
}

void PrinArray(int a[], int n)
{
    if (n == 0)
        cout << "NULL";
    else
    {
        cout << a[0] << '\t';
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
                cout << a[i] << '\t';
        }
    }
}

int main()
{
    int a[100], b[100];
    int n, k = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
    }
    for (int i = 0; i < n; i++)
    {
        if (Check(a[i]))
            b[k++] = a[i];
    }
    QuickSort(b, 0, k - 1);
    PrinArray(b, k);
    return 0;
}