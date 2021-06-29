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
    char filename[MAX];
    system("cls");
    cout << "\nNhap ten file de doc: ";
    cin >> filename;
    File_Mat(filename, a, n);
    cout << "\nn = " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
    }
}