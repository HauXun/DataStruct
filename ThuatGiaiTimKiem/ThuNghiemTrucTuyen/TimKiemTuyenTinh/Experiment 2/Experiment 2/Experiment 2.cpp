#include <iostream>
#include <time.h>
#define LENGTH 10

using namespace std;

int* Input()
{
    static int a[LENGTH];
    srand((unsigned)time(NULL));
    for (int i = 0; i < LENGTH; i++)
        a[i] = rand() % (10 - 1 + 1) + 1;
    return a;
}

void Output(int a[])
{
    for (int i = 0; i < LENGTH; i++)
        cout << a[i] << "\t";
    cout << "\n";
}

int LinearSearch(int a[], int x)
{
    for (int i = 0; i < LENGTH; i++)
        if (a[i] == x)
            return 1; // true
    return false; // false  
}

// Using guardians
int LinearSearch_LC(int a[], int x)
{
    //B1: Thêm phần tử x vào cuối mảng a
    a[LENGTH] = x;
    int i = 0;
    while (a[i] != x)
        i++;
    if (i == LENGTH)
        return -1;
    else
        return i;
}

int FindMax(int* a)
{
    int max = a[0];
    for (int i = 0; i < LENGTH; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int FindX(int* a, int x)
{
    int count = 0;
    for (int i = 0; i < LENGTH; i++)
        if (a[i] == x)
            count++;
    return count;
}


int main()
{
    int* a;
    a = Input();
    cout << "\nXuat mang...\n";
    Output(a);

    /*int x;
    cout << "\nNhap x = ";
    cin >> x;*/

    //cout << "\n X xuat hien " << FindX(a, x) << " lan";
    cout << "\nGia tri max trong mang la: " << FindMax(a);

    /*if (LinearSearch(a, x))
        cout << "\n X co ton tai trong mang";
    else
        cout << "\nKhong ton tai x trong mang";*/

    /*int result = LinearSearch_LC(a, x);
    if (result == -1)
        cout << "\nKhong ton tai x trong mang";
    else
        cout << "\n X co ton tai trong mang tai vi tri " << result;*/

    cout << "\n";
    system("pause");
    return 0;
}
