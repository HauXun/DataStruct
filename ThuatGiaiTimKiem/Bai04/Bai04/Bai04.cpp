#include <iostream>

using namespace std;

int main()
{
    int a[100];
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool kt = true;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && a[i] % 2 == 1)
        {
            cout << a[i] << "\t";
            kt = false;
        }
    }
    if (kt) cout << "NULL";
    return 0;
}