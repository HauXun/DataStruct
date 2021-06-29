#include <iostream>
#include <time.h>

using namespace std;

void QuickSort(int a[], int l, int r)
{
	int p = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j)
	{
		while (a[i] < p)
		{
			i++;
		}
		while (a[j] > p)
		{
			j--;
		}
		if (i <= j)
			swap(a[i++], a[j--]);
	}
	if (i < r)
		QuickSort(a, i, r);
	if (l < j)
		QuickSort(a, l, j);
}

void PrinArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
}

int main()
{
	int a[100], b[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (10 - -10 + 1) + -10;
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
			b[k++] = a[i];
	}
	QuickSort(b, 0, k - 1);
	k = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] < 0)
			a[i] = b[k++];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			a[i] = b[k++];
	}
	PrinArray(a, n);
	return 0;
}