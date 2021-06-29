void XuatMenu()
{
	cout << "==================HE THONG CHUC NANG==================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap vao day so";
	cout << "\n2. Chen mot so vao dau day";
	cout << "\n3. Chen mot so vao cuoi day";
	cout << "\n4. Chen mot so vao day tai mot vi tri quy dinh";
	cout << "\n5. Xoa phan tu dau day";
	cout << "\n6. Xoa phan tu cuoi day";
	cout << "\n7. Xoa phan tu tai vi tri cho truoc";
	cout << "\n8. Xuat cac gia tri khac nhau trong day va so lan xuat hien cua no";
	cout << "\n====================================================";
}

int ChonMenu(int soMenu)
{
	int stt = -1;
	while (stt < 0 || stt > soMenu)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap tuy chon menu tuong ung: ";
		cin >> stt;
	}
	return stt;
}

void XuLyMenu(int menu, DaySo a, int& n)
{
	int value, location;

	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Nhap vao day so\n";
		NhapTuDong(a, n);
		XuatDay(a, n);
		break;
	case 2:
		system("cls");
		cout << "\n2. Chen mot so vao dau day\n";
		cout << "\nNhap gia tri can chen vao dau chuoi: ";
		cin >> value;
		Chen_ViTri(a, n, 0, value);
		XuatDay(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Chen mot so vao cuoi day\n";
		cout << "\nNhap gia tri can chen vao cuoi chuoi: ";
		cin >> value;
		Chen_ViTri(a, n, n, value);
		XuatDay(a, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Chen mot so vao day tai mot vi tri quy dinh\n";
		cout << "\nNhap vi tri can chen: ";
		cin >> location;
		cout << "\nNhap gia tri can chen: ";
		cin >> value;
		Chen_ViTri(a, n, location, value);
		XuatDay(a, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Xoa phan tu dau day\n";
		Xoa_ViTri(a, n, 0);
		cout << "\nMang hien hanh...";
		XuatDay(a, n);
		break;
	case 6:
		system("cls");
		cout << "\n6. Xoa phan tu cuoi day\n";
		Xoa_ViTri(a, n, n);
		cout << "\nMang hien hanh...";
		XuatDay(a, n);
		break;
	case 7:
		system("cls");
		cout << "\n7. Xoa phan tu tai vi tri cho truoc\n";
		cout << "\nNhap vi tri can xoa: ";
		cin >> location;
		Xoa_ViTri(a, n, location);
		XuatDay(a, n);
		break;
	case 8:
		system("cls");
		cout << "\n8. Xuat cac gia tri khac nhau trong day va so lan xuat hien cua no\n";
		XuatDay(a, n);
		SoLanXuatHien(a, n);
		break;
	default:
		break;
	}
	_getch();
}