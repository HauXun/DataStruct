#include <iostream>
#include <time.h>

using namespace std;

void ShakerSort(int a[], int n)
{
	int l, r, mark;
	l = 0, r = mark = n - 1;
	while (l < r)
	{
		for (int i = r; i > l; i--)
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				mark = i;
			}
		l = mark;
		for (int j = l; j < r; j++)
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				mark = j;
			}
		r = mark;
	}
}

void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
}

int main()
{
	int a[10] = { 1,6,3,8,4,9,7,0,2,4 };
	ShakerSort(a, 10);
	Xuat(a, 10);
}