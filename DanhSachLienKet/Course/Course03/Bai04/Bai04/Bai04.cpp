#include <iostream>

using namespace std;

int n;

struct Node
{
	int data;
	Node* pNext;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

void Init(List& list)
{
	list.pHead = list.pTail = NULL;
}

Node* CreatNode(int x)
{
	Node* pNode = new Node;
	if (!pNode)
		exit(1);
	pNode->data = x;
	pNode->pNext = NULL;
	return pNode;
}

bool IsEmpty(List list)
{
	if (!list.pHead)
		return true;
	return false;
}

void AddHead(List& list, int x)
{
	Node* pNode = CreatNode(x);
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void AddTail(List& list, int x)
{
	Node* pNode = CreatNode(x);
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	else
	{
		list.pTail->pNext = pNode;
		list.pTail = pNode;
	}
}

void QuickSort(List& list)
{
	if (list.pHead == list.pTail)
		return;
	List l1, l2;
	Init(l1);
	Init(l2);
	Node* pivot;
	Node* pNode;
	pivot = list.pHead;
	list.pHead = list.pHead->pNext;	// Cập nhập lại pHead
	pivot->pNext = NULL;			// Cô lập pivot

	// Tiến hành tách 2 danh sách l1, l2
	while (list.pHead)
	{
		pNode = list.pHead;
		list.pHead = list.pHead->pNext;
		pNode->pNext = NULL;
		if (pNode->data <= pivot->data)
			AddHead(l1, pNode->data);
		else
			AddHead(l2, pNode->data);
	}
	// Gọi đệ quy sắp xếp l1, l2
	QuickSort(l1);
	QuickSort(l2);
	if (l1.pHead)	// Không rỗng
	{
		list.pHead = l1.pHead;
		l1.pTail->pNext = pivot;
	}
	else
		list.pHead = pivot;
	pivot->pNext = l2.pHead;
	if (l2.pHead)
		list.pTail = l2.pTail;
	else
		list.pTail = pivot;
}

void Input(List& list)
{
	srand(365);
	cout << "\nNhap so phan tu ban dau cua dslk >> ";
	cin >> n;
	for (int i = 0; i <= n; i++)
		AddTail(list, rand() % 10);
}

void Output(List list)
{
	Node* pNode = list.pHead;
	while (pNode)
	{
		cout << " " << pNode->data;
		pNode = pNode->pNext;
	}
	cout << "\n";
}

int main()
{
	List list;
	Init(list);
	Input(list);
	Output(list);
	QuickSort(list);

	Output(list);
	return 0;
}