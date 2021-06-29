#include<iostream>
#include<math.h>

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

int Solve(int a[], int n)
{
	QuickSort(a, 0, n - 1);
	if (a[0] > 0)
		return 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] - a[i - 1] > 1)
			return a[i - 1] + 1;
	}
	return a[n - 1] + 1;
}

int a[100001];
int main()
{
	int n, k = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << Solve(a, n);

	return 0;
}