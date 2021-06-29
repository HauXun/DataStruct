void XuatMenu()
{
	cout << "\n=====================HE THONG CHUC NANG=====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap chuoi";
	cout << "\n2. Xem chuoi";
	cout << "\n3. Tinh chieu dai chuoi";
	cout << "\n4. Dao nguoc chuoi";
	cout << "\n5. Chep chuoi s sang chuoi t";
	cout << "\n6. So sanh 2 chuoi (co phan biet chu hoa)";
	cout << "\n7. So sanh 2 chuoi (khong phan biet chu hoa)";
	cout << "\n8. Noi chuoi s vao sau chuoi t";
	cout << "\n===========================================================";
}

int ChonMenu(int soMenu)
{
	int stt = -1;
	while (stt < 0 || stt > soMenu)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap vao tuy chon menu tuong ung: ";
		cin >> stt;
	}
	return stt;
}

void XuLyMenu(int menu, String s, String t)
{
	int ketQua;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Nhap chuoi\n";
		NhapChuoi(s);
		cout << "\nChuoi vua nhap: ";
		XuatChuoi(s);
		NhapChuoi(t);
		cout << "\nChuoi vua nhap: ";
		XuatChuoi(t);
		cout << "\nNhan phim bat ky de tiep tuc.";
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem chuoi\n";
		cout << "\nChuoi s: ";
		XuatChuoi(s);
		cout << "\nChuoi t: ";
		XuatChuoi(t);
		cout << "\nNhan phim bat ky de tiep tuc.";
		break;
	case 3:
		system("cls");
		cout << "\n3. Tinh chieu dai chuoi\n";
		cout << "\nChieu dai cua : "
			<< "\nChuoi s : " << StringLength(s)
			<< "\nCHuoi t : " << StringLength(t);
		break;
	case 4:
		system("cls");
		cout << "\n4. Dao nguoc chuoi\n";
		StringReverse(s); 
		StringReverse(t);
		cout << "\nChuoi s : ";
		XuatChuoi(s);
		cout << "\nChuoi t : ";
		XuatChuoi(t);
		break;
	case 5:
		system("cls");
		cout << "\n5. Chep chuoi s sang chuoi t\n";
		ChepChuoi(s, t);
		cout << "\nChuoi da chep : "
			<< "\nChuoi s : " << s
			<< "\nChuoi t : " << t;
		break;
	case 6:
		system("cls");
		cout << "\n6. So sanh 2 chuoi (co phan biet chu hoa)\n";
		cout << "\nChuoi s = ";
		XuatChuoi(s);
		cout << "\nChuoi t = ";
		XuatChuoi(t);
		ketQua = SoSanhChuoi_PB(s, t);
		if (ketQua == 1)
			cout << "\nChuoi s > Chuoi t";
		else if (ketQua == -1)
			cout << "\nChuoi s < Chuoi t";
		else
			cout << "\nChuoi s = Chuoi t";
		break;
		break;
	case 7:
		system("cls");
		cout << "\n7. So sanh 2 chuoi (khong phan biet chu hoa)\n";
		cout << "\nChuoi s = ";
		XuatChuoi(s);
		cout << "\nChuoi t = ";
		XuatChuoi(t);
		ketQua = SoSanhChuoi_KPB(s, t);
		if (ketQua == 1)
			cout << "\nChuoi s > Chuoi t";
		else if (ketQua == -1)
			cout << "\nChuoi s < Chuoi t";
		else
			cout << "\nChuoi s = Chuoi t";
		break;
	case 8:
		system("cls");
		cout << "\n8. Noi chuoi s vao sau chuoi t\n";
		cout << "\nChuoi sa = ";
		XuatChuoi(s);
		cout << "\nChuoi b = ";
		XuatChuoi(t);
		Noi_ChuoiSau_VaoSau_ChuoiTruoc(s, t);
		cout << "\nChuoi truoc sau khi noi: a = ";
		XuatChuoi(s);
		break;
	default:
		break;
	}
	_getch();
}