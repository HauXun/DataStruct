#include <iostream>

using namespace std;

int SearchMin(int a[], int n)
{
    int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[k] > a[i])
			k = i;
	}
	return k;
}

int SearchMax(int a[], int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[k] <= a[i])
			k = i;
	}
	return k;
}

void PrinArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}

int main()
{
	int a[100];
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int csMin = SearchMin(a, n);
	int csMax = SearchMax(a, n);
	swap(a[csMin], a[csMax]);
	PrinArray(a, n);
	return 0;
}