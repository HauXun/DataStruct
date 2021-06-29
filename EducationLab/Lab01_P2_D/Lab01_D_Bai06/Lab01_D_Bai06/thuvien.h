#define MAX 100
#define THOAT 0

struct DATE
{
	int ngay;
	int thang;
	int nam;
};

struct NHANVIEN
{
	int msNV;
	char hoTen[MAX];
	DATE ntn;
	char diaChi[MAX];
	double luong;
};

void Read_Struct(char* filename, NHANVIEN a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	n = 0;
	while (!in.eof())
	{
		in >> a[n].msNV;
		in >> a[n].hoTen;
		in >> a[n].ntn.ngay;
		in >> a[n].ntn.thang;
		in >> a[n].ntn.nam;
		in >> a[n].diaChi;
		in >> a[n].luong;
		n++;
	}
	in.close();
}

void Xuat(NHANVIEN a[MAX], int n)
{
	cout << setiosflags(ios::left)
		<< setw(10) << "MS"
		<< setw(20) << "Ho Ten"
		<< setw(14) << "NTNSinh"
		<< setw(20) << "DiaChi"
		<< setw(20) << "Luong" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setiosflags(ios::left)
			<< setw(10) << a[i].msNV
			<< setw(20) << a[i].hoTen
			<< setw(2) << a[i].ntn.ngay << "/"
			<< setw(2) << a[i].ntn.thang << "/"
			<< setw(8) << a[i].ntn.nam
			<< setw(20) << a[i].diaChi
			<< setiosflags(ios::fixed) << setprecision(2) <<  setw(20) << a[i].luong << endl;
	}
}