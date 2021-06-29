#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
    return 1;
}

void ChayChuongTrinh()
{
    int a[MAX], n;
    char filename[MAX];
    system("cls");
    cout << "\nNhap ten file de mo: ";
    cin >> filename;
    File_Array(filename, a, n);
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    _getch();
}