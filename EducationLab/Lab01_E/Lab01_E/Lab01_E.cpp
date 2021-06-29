#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
}

void ChayChuongTrinh()
{
    int a[100], n;
    NHANVIEN b[100];
    int soMenu = 2, menu;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, b, n);
    } while (menu > 0);
}