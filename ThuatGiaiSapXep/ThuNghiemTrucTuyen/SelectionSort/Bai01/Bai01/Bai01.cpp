#include <iostream>

using namespace std;

void Nhap(int a[], int &n)
{
    cout << "Nhap n >> ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "] >> ";
        cin >> a[i];
    }
}

void Xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
}

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j]) min = j;
            swap(a[min], a[i]);
        }
    }
}

int main()
{
    int a[100];
    int n;
    Nhap(a, n);
    cout << "Mang truoc khi sap xep...";
    Xuat(a, n);
    SelectionSort(a, n); 
    cout << "Mang sau khi sap xep...";
    Xuat(a, n);
    return 0;
}