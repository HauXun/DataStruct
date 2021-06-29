#include <iostream>

using namespace std;

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
}

void SelectionSort(int a[], int n)
{
	int csMin;
	for (int i = 0; i < n - 1; i++)
	{
		csMin = i;
		for (int j = i + 1; j < n; j++)
			if (a[csMin] > a[j])
				csMin = j;
		swap(a[csMin], a[i]);
	}
}

int main()
{
    int a[] = { 3,3,6,3,7,2,7,3,5,2,4,7,2,3,1 };
    int n = sizeof(a) / sizeof(int);
	SelectionSort(a, n);
	Output(a, n);
	return 0;
}