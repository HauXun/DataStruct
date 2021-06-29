#include <iostream>

using namespace std;

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}
	cout << "\n";
}

int Partion(int a[], int l, int r)
{
	int p = a[r];
	int i = l - 1; // Biến giám sát quá trình thực hiện sắp xếp
	for (int j = 0; j < r; j++)
	{
		if (a[j] < p)
		{
			i++;
			swap(a[i], a[j]);
		}
		// Tìm được vị trí chính xác của phần tử cầm canh
	}
	swap(a[i + 1], a[r]);
	return (i + 1);
}

void QuickSort(int a[], int l, int r)
{
	if ( l < r)
	{
		int pivot = Partion(a, l, r);
		QuickSort(a, l, pivot - 1);
		QuickSort(a, pivot + 1, r);
	}
}

int main()
{
    int a[] = { 5,3,7,2,8,1,5,9 };
    int n = sizeof(a) / sizeof(int);
	Output(a, n);
	QuickSort(a, 0, n - 1);
	Output(a, n);
}