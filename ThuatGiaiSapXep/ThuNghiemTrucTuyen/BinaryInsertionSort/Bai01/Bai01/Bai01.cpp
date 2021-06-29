#include <iostream>

using namespace std;

void BinaryInsertion(int* a, int n)
{
	int left, right, m;
	int x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		left = 0, right = i - 1;
		while (left <= right)
		{
			m = (left + right) / 2;
			if (x < a[m])
				right = m - 1;
			else
				left = m + 1;
		}
		for (int j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[left] = x;
	}
}

void Output(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}
	cout << "\t";
}

int main()
{
	int a[] = { 1,4,2,3,6,5,7 };
	int n = sizeof(a) / sizeof(int);
	Output(a, n);
	BinaryInsertion(a, n);
	Output(a, n);
	return 0;
}