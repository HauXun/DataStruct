#define MAX 100

typedef int DaySo[MAX];

void NhapDay(DaySo a, int& n)
{
	cout << "\nNhap kich thuoc cua day: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void NhapTuDong(DaySo a, int& n)
{
	cout << "\nNhap vao kich thuoc cua mang: ";
	cin >> n;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % (20 - 0 + 1) - 0;
}

void XuatDay(DaySo a, int n)
{
	cout << "\nMang hien hanh...\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}

void Chen_ViTri(DaySo a, int& n, int location, int value)
{
	n++;
	for (int i = n - 1; i >= location; i--)
		a[i] = a[i - 1];
	a[location] = value;
}

void Xoa_ViTri(DaySo a, int& n, int location)
{
	for (int i = location; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
}

void SoLanXuatHien(DaySo a, int n)
{
	int dem = 0;
	DaySo b;
	for (int i = 0; i < MAX; i++)
		b[i] = 0;
	
	for (int i = 0; i < n; i++) 
	{
			b[a[i]]++;
	}
	for (int i = 0; i < MAX; i++)
	{
		if (b[i] > 0) {
			cout << "\nGia tri " << i << " xuat hien " << b[i] << " lan!\n";
		}
	}
}