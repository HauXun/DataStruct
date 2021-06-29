#include <iostream>

using namespace std;

struct NODE
{
	int data;
	NODE* pLeft;
	NODE* pRight;
};
typedef struct NODE* TREE;

void KhoiTaoCay(TREE& tree)
{
	tree = NULL;
}

void ThemNodeVaoCay(TREE& tree, int x)
{
	if (!tree)
	{
		NODE* pNode = new NODE;
		pNode->data = x;
		pNode->pLeft = NULL;
		pNode->pRight = NULL;
		tree = pNode;
	}
	else
	{
		if (tree->data > x)
			ThemNodeVaoCay(tree->pLeft, x);
		else if (tree->data < x)
			ThemNodeVaoCay(tree->pRight, x);
	}
}

void Nhap(TREE& tree)
{
	int n;
	cout << "\nNhap vao so phan tu cua cay >> ";
	cin >> n;
	srand(365);
	for (int i = 0; i < n; i++)
	{
		ThemNodeVaoCay(tree, rand() % 10 + 1);
	}
}

void XuatNLR(TREE tree)
{
	if (tree)
	{
		cout << tree->data << ' ';
		XuatNLR(tree->pLeft);
		XuatNLR(tree->pRight);
	}
}

bool IsPrimeNumber(int x)
{
	if (x < 2)
		return false;
	else
	{
		if (x == 2)
			return true;
		else
		{
			if (x % 2 == 0)
				return false;
			else
				for (int i = 2; i < x; i++)
				{
					if (x % i == 0)
						return false;
				}
		}
	}
	return true;
}

void DemSNT(TREE tree, int& count)
{
	if (tree)
	{
		if (IsPrimeNumber(tree->data))
			count++;
		DemSNT(tree->pLeft, count);
		DemSNT(tree->pRight, count);
	}
}

int main()
{
	TREE tree;
	KhoiTaoCay(tree);
	Nhap(tree);
	XuatNLR(tree);
	int count = 0;
	DemSNT(tree, count);
	cout << "\nSo luong SNT la >> " << count;
	return 1;
}