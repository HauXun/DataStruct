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
	pNode->data = x;
	pNode->pNext = NULL;
	return pNode;
}

void XuatDSLK(LIST list)
{
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		cout << i->data << '\t';
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

int RemoveNode_First(LIST& list, int x)
{
	// Node trỏ đến node node nằm trước node x
	NODE* j = NULL;

	NODE* i = list.pHead;
	for (i = list.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == x)
			break;
		j = i;
	}

	if (i == NULL)
		return 0;

	// Xóa node sau node j trong danh sách
	if (j != NULL)
	{
		if (i == list.pTail)
			list.pTail = j; // Xóa node cuối trong danh sách
		j->pNext = i->pNext;
	}
	else // Xóa node đầu danh sách
	{
		list.pHead = i->pNext;
		if (list.pHead == NULL)
			list.pTail = NULL;
	}
	delete i;
	return 1;
}

void Remove_X(LIST& list, int x)
{
	while (RemoveNode_First(list, x));
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
		AddTail(list, pNode);
	}
	XuatDSLK(list);
	int x;
	cout << "\nNhap node can xoa >> ";
	cin >> x;
	Remove_X(list, x);
	XuatDSLK(list);
	return 1;
}