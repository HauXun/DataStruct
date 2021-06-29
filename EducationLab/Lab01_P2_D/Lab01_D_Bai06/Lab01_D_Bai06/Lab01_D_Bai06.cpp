#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "thuvien.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
}

void ChayChuongTrinh()
{
    NHANVIEN a[MAX];
    char filename[MAX];
    int n;
    system("cls");
    cout << "Nhap ten file de doc: ";
    cin >> filename;
    Read_Struct(filename, a, n);
    Xuat(a, n);
}