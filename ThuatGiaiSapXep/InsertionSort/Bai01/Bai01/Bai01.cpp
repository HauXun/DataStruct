#include <iostream>
#include <time.h>

using namespace std;

void PrinArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}
	cout << "\n";
}

void InsertionSort(int a[], int n)
{
	int j, x;
	for (int i = 1; i < n; i++)
	{
		j = i;
		x = a[i];
		while (j > 0 && a[j - 1] > x)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = x;
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
	InsertionSort(a, n);
	PrinArray(a, n);
	return 0;
}