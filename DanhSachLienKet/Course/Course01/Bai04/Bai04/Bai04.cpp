#include <iostream>
#include <time.h>

using namespace std;

int n = 0;

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
	return pNode;
}

void XuatDanhSach(LIST list)
{
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		cout << i->data << '\t';
	cout << '\n';
}

void AddHead(LIST& list, NODE* pNode)
{
	//Nếu danh sách rỗng
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void AddTail(LIST& list, NODE* pNode)
{
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	else
	{
		list.pTail->pNext = pNode;
		list.pTail = pNode;
	}
}

//Thêm node y vào trước node x trong dslk đơn
void ThemNodeY_TruocNodeX(LIST& list, NODE* xNode, NODE* yNode)
{
	if (xNode->data == list.pHead->data && list.pHead->pNext == NULL)
		AddHead(list, yNode);
	else
	{
		NODE* k = new NODE;
		for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		{
			if (xNode->data == i->data)
			{
				NODE* y2 = KhoiTaoNode(yNode->data);
				y2->pNext = i;
				k->pNext = y2;
			}
			k = i;
		}
	}
}

//Get size LIST
int GetSize(LIST list)
{
	int size = 0;
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		size++; //n
	return size; //n
}

//Hàm thêm node x vào vị trí bất kì
void ThemNodeX_At(LIST& list, NODE* xNode, int vt)
{
	if (list.pHead == NULL || vt == 1)
		AddHead(list, xNode);
	else if (vt == GetSize(list) + 1)
		AddTail(list, xNode);
	else
	{
		int cntL = 0;
		NODE* k = new NODE;
		for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		{
			cntL++;
			if (cntL == vt)
			{
				NODE* x2 = KhoiTaoNode(xNode->data);
				x2->pNext = i;
				k->pNext = x2;
				break;
			}
			k = i;
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
		//n++;
	}
	cout << "\nDanh sach lien ket hien hanh";
	XuatDanhSach(list);
	int x;
	cout << "\nNhap vao gia tri node x >> ";
	cin >> x;
	NODE* xNode = KhoiTaoNode(x);
	int vt = - 1;
	do
	{
		cout << "\nNhap vao vi tri muon chen >> ";
		cin >> vt;
		if (vt < 1 || vt > GetSize(list) + 1) //n
		{
			cout << "\nVi tri phai nam trong doan tu [1 - " << GetSize(list) + 1 << "]"; //n
			system("pause");
		}
	} while (vt < 1 || vt > GetSize(list) + 1); //n
	ThemNodeX_At(list, xNode, vt);
	cout << "\n\n\tDanh sach lien ket\n";
	XuatDanhSach(list);
}