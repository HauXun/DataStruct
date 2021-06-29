#include <iostream>
#include <time.h>

using namespace std;

void PrinArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
}

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

int main()
{
	int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10 + 1;
	}
	QuickSort(a, 0, n - 1);
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
			count++;
		else
		{
			cout << a[i - 1] << " - " << count << ";\n";
			count = 1;
		}
	}
	cout << a[n - 1] << " - " << count << ";\n";
	return 0;
}