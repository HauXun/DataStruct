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

void BubbleSort(int a[], int n)
{
	bool swapper = true;
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				swapper = false;
			}
		}
		if (swapper)
			break;
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
	BubbleSort(a, n);
	PrinArray(a, n);
	return 0;
}