#define MAX 100

void File_Array(char* filename, int a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file !";
		return;
	}

	//đọc dữ liệu đầu tiên của tập tin (hàng đầu), luu vao n.
	in >> n;
	//đọc dữ liệu đầu tiên của tập tin (hàng đầu), luu vao n.

	for (int i = 0; i < n; i++)
		// lần lượt đọc dữ liệu tập tin ghi vảo mảng 1 chiều arr
		in >> a[i];
	in.close();
}