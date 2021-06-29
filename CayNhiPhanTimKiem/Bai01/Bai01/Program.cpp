#include <iostream>
using namespace std;

// Nhập vào cây nhị phân các số nguyên
// Xuất ra màn hình các phần tử của cây nhị phân

// Khai báo cấu trúc NODE
struct node
{
	int data;
	node* pLeft;
	node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

// Khởi tạo cây
void KhoiTaoCay(TREE& tree)
{
	tree = NULL;
}

// Hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE& tree, int x)
{
	// Nếu cây rỗng
	if (!tree)
	{
		// Khởi tạo node để thêm vào cây
		NODE* pNode = new NODE;
		pNode->data = x;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;

		// pNode là node gốc <=> x chính là node gốc
		tree = pNode;
	}
	else	// Cây có tồn tại phần tử
	{
		// Nếu phần tử thêm vào nhỏ hơn node gốc => Thêm vào nhánh cây bên trái
		if (tree->data > x)
			// Duyệt qua trái để thêm phần tử x
			ThemNodeVaoCay(tree->pLeft, x);
		// Nếu phần tử thêm vào lớn hơn node gốc => Thêm vào nhánh cây bên phải
		else if (tree->data < x)
			ThemNodeVaoCay(tree->pRight, x);
	}
}

// Xuất cây nhị phân theo NLR
void XuatNLR(TREE tree)
{
	// Cây không rỗng
	if (tree)
	{
		// Xuất dữ liệu trong node
		cout << tree->data << ' ';
		XuatNLR(tree->pLeft);	// Duyệt qua trái
		XuatNLR(tree->pRight);	// Duyệt qua phải
	}
}

void Nhap(TREE& tree)
{
	int n, x;
	cout << "\nNhap vao so phan tu cua cay >> ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu x >> ";
		cin >> x;
		ThemNodeVaoCay(tree, x);
	}
}

int main()
{
	TREE tree;
	KhoiTaoCay(tree);
	Nhap(tree);
	XuatNLR(tree);
	return 1;
}