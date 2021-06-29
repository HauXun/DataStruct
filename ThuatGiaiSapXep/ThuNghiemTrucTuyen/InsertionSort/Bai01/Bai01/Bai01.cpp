#include <iostream>
#include <time.h>

using namespace std;

void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
}

void InsertionSort(int a[], int n)
{
	int x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] < x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

int main()
{
	int n = 5;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10 + 1;
	}
	PrintArray(a, n);
	InsertionSort(a, n);
	PrintArray(a, n);
	return 0;
}