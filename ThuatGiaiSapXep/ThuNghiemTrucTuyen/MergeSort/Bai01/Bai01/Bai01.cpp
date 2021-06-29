#include <iostream>
#include <time.h>

using namespace std;

void Merge(int a[], int l, int m, int r)
{
	int i, j, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	i = 0;
	j = 0;
	while (i < n1 && j < n2)
		a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

	while (i < n1)
		a[k++] = L[i++];
	while (j < n2)
		a[k++] = R[j++];
}

void MergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, m, r);
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << "\n";
}

int main()
{
	int a[10];
	int n = sizeof(a) / sizeof(int);
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
	Output(a, n);
	MergeSort(a, 0, n - 1);
	Output(a, n);
}