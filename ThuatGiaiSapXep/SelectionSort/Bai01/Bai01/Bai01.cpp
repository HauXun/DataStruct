#include <iostream>
#include <time.h>

using namespace std;

void PrinArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}
	cout << '\n';
}

void SelectionSort(int a[], int n)
{
	int csMin;
	for (int i = 0; i < n - 1; i++)
	{
		csMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[csMin] > a[j])
				csMin = j;
		}
		if (i != csMin)
			swap(a[i], a[csMin]);
	}
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
	SelectionSort(a, n);
	PrinArray(a, n);
	return 0;
}