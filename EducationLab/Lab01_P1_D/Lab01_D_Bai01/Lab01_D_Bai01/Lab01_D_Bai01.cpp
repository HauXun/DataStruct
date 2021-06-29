#include <iostream>
#include <conio.h>
#include <time.h>

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
    int soMenu = 8, menu, n = 0;
    DaySo a;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
    } while (menu > 0);
    _getch();
}