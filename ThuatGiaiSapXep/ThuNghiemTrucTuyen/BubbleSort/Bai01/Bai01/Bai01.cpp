#include <iostream>
#include <time.h>

using namespace std;

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
		}
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}

int main()
{
	int a[10];
	int n = sizeof(a) / sizeof(int);
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 10 + 1;
	}
	BubbleSort(a, n);
	Output(a, n);
	return 0;
}