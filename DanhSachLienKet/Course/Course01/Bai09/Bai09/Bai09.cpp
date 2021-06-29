// Xóa node x đầu tiên tìm được trong dslk

#include <iostream>
#include <time.h>

using namespace std;

struct node
{
	int data;
	node* pNext;
};
typedef struct node NODE;

struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void KhoiTaoDSLK(LIST& list)
{
	list.pHead = list.pTail = NULL;
}

NODE* KhoiTaoNode(int x)
{
	NODE* pNode = new NODE;
	if (pNode == NULL)
	{
		cout << "\nKhong du bo nho de cap phat node!";
		return NULL;
	}
	else
	{
		pNode->data = x;
		pNode->pNext = NULL;
	}
}

void XuatDanhSach(LIST list)
{
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		cout << i->data << '\t';
	cout << '\n';
}

void AddHead(LIST& list, NODE* pNode)
{
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void XoaNodeXDauTien(LIST& list, NODE* xNode)
{
	//Nếu pHead == NULL thì danh sách rỗng
	if (list.pHead == NULL)
		return;

	//Ngược lại thì xét điều kiện
	else
	{
		for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		{
			// Nếu node sau bằng node x
			if (i->pNext->data == xNode->data)
			{
				// Node sẽ xóa
				NODE* delNode = i->pNext;

				// Lấy node sau node k
				NODE* k = delNode->pNext;

				// Lấy node hiện tại trỏ đến node k
				i->pNext = k;

				// Xóa delNode
				delete delNode;
				return;
			}
		}
	}
}

int main()
{
	LIST list;
	KhoiTaoDSLK(list);

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int nRand = rand() % 10;
		NODE* pNode = KhoiTaoNode(nRand);
		AddHead(list, pNode);
	}
	cout << "\nDanh sach lien ket\n";
	XuatDanhSach(list);
	system("pause");
	int x;
	cout << "\nNhap gia tri node x >> ";
	cin >> x;
	NODE* xNode = KhoiTaoNode(x);
	XoaNodeXDauTien(list, xNode);
	XuatDanhSach(list);
	return 1;
}