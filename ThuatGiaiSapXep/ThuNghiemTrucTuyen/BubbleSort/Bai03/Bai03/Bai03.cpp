#include <iostream>

using namespace std;

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << ' ' << a[i];
}

void resBubbleSort(int a[], int i, int n)
{
	for (int j = n - 1; j > i; j--)
		if (a[j] < a[i])
			swap(a[j], a[i]);
	if (i < n - 1)
		resBubbleSort(a, i + 1, n);
}

int main()
{
	int a[] = { 5,1,8,3,0,4,2,7,4,1,6,9 };
	int n = sizeof(a) / sizeof(int);
	resBubbleSort(a, 0, n);
	Output(a, n);
}