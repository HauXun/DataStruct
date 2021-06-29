void XuatMenu()
{
	cout << "\n====================== CHON CHUC NANG ========================";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Nhap ma tran vuong";
	cout << "\n2. Xem ma tran vuong";
	cout << "\n3. Xuat cac duong cheo song song duong cheo chinh";
	cout << "\n4. Xuat cac duong cheo song song duong cheo phu";
	cout << "\n5. Tinh tong cac gia tri cua ma tran tam giac tren";
	cout << "\n6. Tinh tong cac gia tri cua ma tran tam giac duoi";
	cout << "\n==============================================================\n";
}

int ChonMenu(int soMenu)
{
	int stt;
	do
	{
		system("cls");
		XuatMenu();
		cout << "\nChon chuc nang : ";
		cin >> stt;
	} while (stt < 0 || stt > soMenu);

	return stt;
}

void XuLyMenu(int menu, MaTranVuong a, int& n)
{
	int sum;
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;
	case 1:
		cout << "\n1. Nhap ma tran vuong";
		NhapMaTranTuDong(a, n);
		cout << "\nMa tran vuong vua nhap:\n";
		XuatMaTran(a, n);
		break;
	case 2:
		cout << "\n2. Xem ma tran vuong";
		cout << "\nMa tran vuong hien hanh:\n";
		XuatMaTran(a, n);
		break;
	case 3:
		cout << "\n3. Xuat cac duong cheo song song duong cheo chinh";
		XuatMaTran(a, n);
		Xuat_DuongCheo_SS_DCChinh(a, n);
		break;
	case 4:
		cout << "\n4. Xuat cac duong cheo song song duong cheo phu";
		XuatMaTran(a, n);
		Xuat_DuongCheo_SS_DCPhu(a, n);
		break;
	case 5:
		cout << "\n5. Tinh tong cac gia tri cua ma tran tam giac tren";
		XuatMaTran(a, n);
		sum = TinhTong_Tren_CheoChinh(a, n);
		cout << "\nTong cac gia tri cua ma tran tam giac tren: sum = " << sum;
		break;
	case 6:
		cout << "\n6. Tinh tong cac gia tri cua ma tran tam giac duoi";
		XuatMaTran(a, n);
		sum = TinhTong_Duoi_CheoPhu(a, n);
		cout << "\nTong cac gia tri cua ma tran tam giac duoi: sum = " << sum;
		break;
	}
	_getch();
}
