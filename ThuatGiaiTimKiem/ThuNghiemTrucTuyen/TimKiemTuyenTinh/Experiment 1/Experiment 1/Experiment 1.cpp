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

int FindX(int *a, int x)
{
    int count = 0;
    for (int i = 0; i < LENGTH; i++)
        if (a[i] == x)
            count++;
    return count;
}

int main()
{
    int *a;
    a = Input();
    cout << "\nXuat mang...\n";
    Output(a);

    int x;
    cout << "\nNhap x = ";
    cin >> x;

    cout << "\n X xuat hien " << FindX(a, x) << " lan";

    /*if (LinearSearch(a, x))
        cout << "\n X co ton tai trong mang";
    else
        cout << "\nKhong ton tai x trong mang";*/

    cout << "\n";
    system("pause");
    return 0;
}
