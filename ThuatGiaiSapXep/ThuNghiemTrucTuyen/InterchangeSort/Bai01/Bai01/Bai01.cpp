#include <iostream>

using namespace std;

void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n -1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}
}

int main()
{
	int a[] = { 1,5,6,8,3,7,3,7,2 };
	int n = sizeof(a) / sizeof(int);
	InterchangeSort(a, n);
	Output(a, n);
	return 0;
}