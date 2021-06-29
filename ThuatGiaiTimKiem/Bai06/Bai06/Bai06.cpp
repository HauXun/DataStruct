#include <iostream>

using namespace std;

int BinarySearch(int a[], int n, int x)
{
    int l = 0, r = n - 1;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (a[mid] < x)
			l = mid + 1;
		else
			r = mid;
	}
	if (a[l] == x)
		return l;
	return -1;
}

void PrintArray(int a[], int n, int l, int r)
{
	for (int i = l; i <= r; i++)
	{
		cout << a[i] << "\t";
	}
}

bool Solve(int a[], int b[], int n, int s)
{
	b[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		b[i] = b[i - 1] + a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i] == s)
		{
			PrintArray(a, n, 0, i);
			return true;
		}
		if (b[i] > s)
		{
			int l = BinarySearch(b, n, b[i] - s);
			if (l != -1)
			{
				PrintArray(a, n, l + 1, i);
				return true;
			}
		}
	}
}

int main()
{
	int a[100], b[100];
	int n, s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> s;
	bool k = Solve(a, b, n, s);
	if (!k)
		cout << -1;
	return 0;
}