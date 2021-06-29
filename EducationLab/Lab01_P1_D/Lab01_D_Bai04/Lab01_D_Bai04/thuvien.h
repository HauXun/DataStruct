#define MAX 100

typedef char String[MAX];

void NhapChuoi(String a)
{
	int i = 0;
	char x;
	cout << "\nChuoi se tu dong duoc gan sau khi ban nhap xong.";
	cout << "\nNhap Chuoi: ";
	_flushall();
	x = _getch();
	while (x != 13)
	{
		a[i++] = x;
		x = _getch();
	}
	a[i] = 0;
}

void XuatChuoi(String a)
{
	cout << a;
}

//int StrLength(String s)
//{
//	return strlen(s);
//}

int StringLength(String s)
{
	int i;
	for (i = 0; s[i] != NULL; i++);
	return i;
}

//void StrReverse(String s)
//{
//	_strrev(s);
//}

void HoanVi(char& a, char& b)
{
	char x = a;
	a = b;
	b = x;
}

void StringReverse(String s)
{
	for (int i = 0; i < strlen(s) / 2; i++)
		HoanVi(s[i], s[strlen(s) - i - 1]);
}

//void StrCpy(String s, String t)
//{
//	strcpy_s(t, MAX, s);
//}

void ChepChuoi(String s, String t)
{
	for (int i = 0; (s[i] = t[i]) != NULL; i++);
}

//int StrCmp(String s, String t) //Phan biet chu hoa
//{
//	return strcmp(s, t);
//}

int SoSanhChuoi_PB(String s, String t)
{
	int i;
	for (i = 0; (s[i] && t[i] != 0); i++)
	{
		if (s[i] < t[i])
			return -1;
		if (s[i] > t[i])
			return 1;
	}
	if (s[i] != 0)
		return 1;
	if (t[i] != 0)
		return -1;
	return 0;
}

char Chuyen_KT_Hoa(char x)
{
	if ('a' <= x && x <= 'z')
		x -= 32;
	return x;
}

//int _strcmpi_SoSanhChuoi_KPB(String s, String t)
//{
//	return _strcmpi(s, t);
//}

int SoSanhChuoi_KPB(String s, String t)
{
	int i;
	for (i = 0; (s[i] && t[i] != 0); i++)
	{
		if (Chuyen_KT_Hoa(s[i]) < Chuyen_KT_Hoa(t[i]))
			return -1;
		if (Chuyen_KT_Hoa(s[i]) > Chuyen_KT_Hoa(t[i]))
			return 1;
	}
	if (s[i] != 0)
		return 1;
	if (t[i] != 0)
		return -1;
	return 0;
}

//void strcat_s_Noi_ChuoiSau_VaoSau_ChuoiTruoc(String s, String t)
//{
//	strcat_s(s, MAX, t);
//}

void Noi_ChuoiSau_VaoSau_ChuoiTruoc(String s, String t)
{
	int l = strlen(s);
	for (int i = 0; t[i] != NULL; i++)
		s[l++] = t[i];
	s[l] = NULL;
}