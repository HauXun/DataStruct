#define SIZE 20

typedef int MaTranVuong[SIZE][SIZE];

void NhapMaTranTuDong(MaTranVuong a, int &n)
{
	cout << "\nNhap vao kich thuoc cua ma tran NxN: ";
	cin >> n;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (20 - 1 + 1) - 1;
}

void XuatMaTran(MaTranVuong a, int n)
{
	cout << "\nMa tran hien hanh...\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\n";
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
	}
}

void Xuat_DuongCheo_SS_DCChinh(MaTranVuong a, int n)
{
	int i, j, k;
	cout << "\nCac duong cheo phia tren duong cheo chinh:\n";
	for (k = n - 1; k >= 1; k--)
	{
		cout << "\nDuong cheo thu " << k << ":\t";
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (j - i == k)
					cout << a[i][j] << "\t";
	}

	cout << "\n\nCac duong cheo phia duoi duong cheo chinh:\n";
	for (k = n - 1; k >= 1; k--)
	{
		cout << "\nDuong cheo thu " << k << ":\t";
		for (i = 1; i < n; i++)
			for (j = 0; j < i; j++)
				if (i - j == k)
					cout << a[i][j] << "\t";
	}
}

void Xuat_DuongCheo_SS_DCPhu(MaTranVuong a, int n)
{
	int i, j, k;
	cout << "\n\nCac duong cheo nam ben trai duong cheo phu:\n";
	for (k = 0; k < n - 1; k++)
	{
		cout << "\nDuong cheo thu " << k + 1 << " : ";
		for (i = 0; i < n - 1; i++)
			for (j = 0; j < n - 1 - i; j++)
				if (j + i == k)
					cout << a[i][j] << "\t";
	}

	cout << "\n\nCac duong cheo nam ben phai duong cheo phu:\n";
	for (k = n; k < 2 * n - 1; k++)
	{
		cout << "\nDuong cheo thu " << k - n + 1 << " : ";
		for (i = 1; i < n; i++)
			for (j = n - i; j < n; j++)
				if (j + i == k)
					cout << a[i][j] << "\t";
	}
}

int TinhTong_Tren_CheoChinh(MaTranVuong a, int n)
{
	int sum = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			sum += a[i][j];
	return sum;
}

int TinhTong_Duoi_CheoPhu(MaTranVuong a, int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			sum += a[i][j];
	return sum;
}