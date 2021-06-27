﻿#include <iostream>
#include <conio.h>
#include <istream>
#include <fstream>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

#include "header.h"
#include "thuvien.h"
#include "menu.h"
#include "xulymenu.h"

void ChayChuongTrinh()
{
	int n = 0, menu;
	int soMenu = size(input);

	do
	{
		menu = ChonMenu(soMenu, input);
		XuLy(menu);
	} while (menu > 0);

	wcout << L"\n Cảm ơn đã sử dụng chương trình";
	_getch();
}

int main()
{
	NghiemTucMode();
	ChayChuongTrinh();
	return 0;
}