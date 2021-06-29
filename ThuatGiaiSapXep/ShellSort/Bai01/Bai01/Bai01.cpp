#include<iostream>
#include <time.h>

using namespace std;

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void shellSort(int a[], int n) {
	int kc, i, j, x;
	for (kc = n / 2; kc > 0; kc /= 2) {
		for (i = kc; i < n; i++) {
			x = a[i];
			for (j = i; j >= kc && a[j - kc] > x; j -= kc) {
				a[j] = a[j - kc];
			}
			a[j] = x;
		}
	}
}
int a[99999999];
int main()
{
	int n;
	cin >> n;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10 + 1;
	}
	shellSort(a, n);
	printArray(a, n);
	return 0;
}