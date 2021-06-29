#include <iostream>

using namespace std;

bool BinarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (a[middle] == x)
            return true;
        else if (a[middle] > x)
             right = middle - 1;
            //left = middle + 1;
        else
             left = middle + 1;
            //right = middle - 1;
    }
    return false;
}

bool RecursiveBinarySearch(int a[], int left, int right, int x)
{
    if (left > right)
        return false;
    int middle = (left + right) / 2;
    if (a[middle] == x)
        return true;
    else if (a[middle] > x)
        return RecursiveBinarySearch(a, left, middle - 1, x);
    else
        return RecursiveBinarySearch(a, middle + 1, right, x);
    return false;
}

void Sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
             if (a[j] < a[i])
            //if (a[j] > a[i])
                swap(a[i], a[j]);
}

void Xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << "\n";
}

int main()
{
    int a[10] = { 5, 7, 6, 2, 4, 8, 3, 9, 10, 1 };

    Sort(a, 10);
    Xuat(a, 10);
    int x;
    while (true)
    {
        cout << "\nNhap  -1 de thoat...";
        cout << "\nNhap x: ";
        cin >> x;
        if (x == -1)
            break;
        //if (BinarySearch(a, 10, x))
        if (RecursiveBinarySearch(a, 0, 9, x))
            cout << "\nTim thay x";
        else
            cout << "\nKhong tim thay";
    }
    cout << "\nCam on da su dung chuong trinh";
    cout << "\n";
}
