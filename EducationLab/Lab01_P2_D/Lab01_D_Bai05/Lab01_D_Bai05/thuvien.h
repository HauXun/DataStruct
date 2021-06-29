#define MAX 100

void Read(char* filename, int a[MAX][MAX], int& n)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	in >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> a[i][j];
	in.close();
}

void Write(char* filename, int a[MAX][MAX], int n)
{
	ofstream out(filename);
	if (!out)
	{
		cout << "\nLoi mo file!";
		return;
	}
	out << n << endl;
	for (int i = 0; i < n; i++, out << endl)
		for (int j = 0; j < n; j++)
			out << a[i][j] << '\t';
	out.close();
	cout << "\nLuu file thanh cong!";
}

void Display(char* filename)
{
	int n, x;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	in >> n;
	cout << n << endl;
	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < n; j++)
		{
			in >> x;
			cout << x << '\t';
		}
	in.close();
}