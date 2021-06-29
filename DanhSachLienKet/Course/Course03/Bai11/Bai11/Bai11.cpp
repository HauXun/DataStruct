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
	list.pTail->pNext = list.pHead;
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
	list.pTail->pNext = list.pHead;
}

void Reverse(List& list)
{
	Node* parent = list.pHead;
	Node* current = list.pHead->pNext;
	list.pHead = current->pNext;
	parent->pNext = NULL;
	current->pNext = parent;
	while (list.pHead->pNext)
	{
		parent = current;
		current = list.pHead;
		list.pHead = list.pHead->pNext;
		current->pNext = parent;
	}
	list.pHead->pNext = current;
}

void Input(List& list)
{
	srand(365);
	cout << "\nNhap so phan tu ban dau cua dslk >> ";
	cin >> n;
	for (int i = 0; i <= n; i++)
		AddHead(list, rand() % 10);
}

void Output(List list)
{
	while (list.pHead)
	{
		cout << ' ' << list.pHead->data;
		list.pHead = list.pHead->pNext;
	}
}
int main()
{
	List list;
	Init(list);
	Input(list);
	Output(list);
	return 0;
}