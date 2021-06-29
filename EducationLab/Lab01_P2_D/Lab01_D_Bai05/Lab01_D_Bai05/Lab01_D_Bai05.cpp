#include <iostream>
#include <fstream>

using namespace std;

#include "thuvien.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
}

void ChayChuongTrinh()
{
    int a[MAX][MAX], n;
    char filename_read[MAX], filename_write[MAX];
    system("cls");
    cout << "\nNhap ten file de doc: ";
    cin >> filename_read;
    Read(filename_read, a, n);
    Display(filename_read);
    cout << "\nNhap ten file can ghi: ";
    cin >> filename_write;
    Write(filename_write, a, n);
    cout << "\nNoi dung file " << filename_write << " : \n";
    Display(filename_write);
}