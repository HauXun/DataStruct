#define MAX 100

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

void ReadText(char* filename, int a[MAX], NHANVIEN b[MAX], int& n)
{
	int x;
		ifstream in(filename);
		if (!in)
		{
			cout << "\nLoi mo file !";
			return;
		}

		if (filename == "text1.txt")
		{
			in >> n;
			cout << endl << n << endl;
			for (int i = 0; i < n; i++)
			{
				in >> x;
				cout << x << '\t';
			}
			in.close();
		}
		if (filename == "text2.txt")
		{
			n = 0;
			while (!in.eof())
			{
				in >> a[n];
				cout << a[n] << '\t';
				n++;
			}
			in.close();
		}
		if (filename == "text3.txt")
		{
			n = 0;
			while (!in.eof())
			{
				in >> b[n].msNV;
				in >> b[n].hoTen;
				in >> b[n].ntn.ngay;
				in >> b[n].ntn.thang;
				in >> b[n].ntn.nam;
				in >> b[n].diaChi;
				in >> b[n].luong;
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
							<< setw(10) << b[i].msNV
							<< setw(20) << b[i].hoTen
							<< setw(2) << b[i].ntn.ngay << "/"
							<< setw(2) << b[i].ntn.thang << "/"
							<< setw(8) << b[i].ntn.nam
							<< setw(20) << b[i].diaChi
							<< setiosflags(ios::fixed) << setprecision(2) << setw(20) << b[i].luong << endl;
					}
				}
				n++;
			}
			in.close();
		}
}