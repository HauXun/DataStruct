#include<iostream>
#include<time.h>

using namespace std;

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void quickSort(int a[], int l, int r) {
	int p = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j) {
		while (a[i] < p) {
			i++;
		}
		while (a[j] > p) {
			j--;
		}
		if (i <= j) {
			swap(a[i++], a[j--]);
			/*int temp = a[i];
			a[i++] = a[j];
			a[j--] = temp;*/
		}
	}
	if (i < r) {
		quickSort(a, i, r);
	}
	if (l < j) {
		quickSort(a, l, j);
	}
}
int a[100001];
int main()
{
	int n;
	cin >> n;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10 + 1;
	}
	printArray(a, n);
	quickSort(a, 0, n - 1);
	printArray(a, n);
	return 0;
}