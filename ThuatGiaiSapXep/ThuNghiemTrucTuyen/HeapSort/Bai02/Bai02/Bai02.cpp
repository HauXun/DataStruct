#include <iostream>
#include <time.h>

using namespace std;

void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << '\n';
}

void HieuChinh(int a[], int n, int i)
{
	int largest;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[i])
		largest = l;
	else
		largest = i;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		HieuChinh(a, n, largest);
	}
}

void BuildHeap(int a[], int n)
{
	for (int i = (n / 2 - 1); i >= 0; i--)
		HieuChinh(a, n, i);
}

void HeapSort(int a[], int n)
{
	BuildHeap(a, n);
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		HieuChinh(a, i, 0);
	}
}

int main()
{
	int a[10];
	int n = sizeof(a) / sizeof(int);
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
	PrintArray(a, n);
	HeapSort(a, n);
	PrintArray(a, n);
}