#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void ChayChuongTrinh();

#include "thuvien.h"
#include "menu.h"

int main()
{
    ChayChuongTrinh();
    return 1;
}

void ChayChuongTrinh()
{
    String s;
    String t;
    int soMenu = 8, menu;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, s, t);
    } while (menu > 0);
    _getch();
}