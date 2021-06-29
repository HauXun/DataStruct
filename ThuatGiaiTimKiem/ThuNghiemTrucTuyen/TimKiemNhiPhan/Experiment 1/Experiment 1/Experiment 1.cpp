#include <iostream>
#include <time.h>
#define n 10

using namespace std;

void Nhap(int a[])
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % (10 - 1 + 1) + 1;
}

void Xuat(int a[])
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
}

void Sort(int a[])
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
			{
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
}

int BinarySearch(int a[], int x)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (a[middle] == x)
			return 1;
		else if (a[middle] < x)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return 0;
}

int main()
{
	int a[n];
	Nhap(a);
	Sort(a);
	Xuat(a);
	
	int x;
	while (true)
	{
		cout << "\nNhap  -1 de thoat...";
		cout << "\nNhap x: ";
		cin >> x;
		if (x == -1)
			break;
		if (BinarySearch(a, x))
			cout << "\nTim thay x";
		else
			cout << "\nKhong tim thay";
	}
	cout << "\nCam on da su dung chuong trinh";
	cout << "\n";
}