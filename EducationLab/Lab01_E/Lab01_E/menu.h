void XuatMenu()
{
	cout << "\n============== BANG CHON CHUC NANG ================";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Chuyen du lieu cua tap tin cac so nguyen vao mang 1 chieu";
	cout << "\n2. Chuyen du lieu cua tap tin cau truc vao mang cau truc";
	cout << "\n===================================================";
}

int ChonMenu(int soMenu)
{
	int stt = -1;
	while (stt < 0 || stt > soMenu)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap tuy chon chuc nang tuong ung: ";
		cin >> stt;
	}
	return stt;
}

void XuLyMenu(int menu, int a[MAX], NHANVIEN b[MAX], int& n)
{
	char filename[MAX];
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;
	case 1:
	case 2:
		system("cls");
		cout << "\n1. Chuyen du lieu cua tap tin cac so nguyen vao mang 1 chieu";
		cout << "\nNhap ten file de doc: ";
		_flushall();
		gets_s(filename);
		ReadText(filename, a, b, n);
		break;
	}
	system("pause");
}