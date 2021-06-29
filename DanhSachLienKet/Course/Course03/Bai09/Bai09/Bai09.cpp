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

void AddNode(List& list, int x)
{
	Node* pNode = CreatNode(x);
	if (!list.pHead)
		list.pHead = list.pTail = pNode;
	else
	{
		if (list.pHead->data > pNode->data)
		{
			pNode->pNext = list.pHead;
			list.pHead = pNode;
		}
		else
		{
			Node* i = list.pHead;
			while (i->pNext && i->pNext->data < pNode->data)
			{
				i = i->pNext;
			}
			pNode->pNext = i->pNext;
			i->pNext = pNode;
		}
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

void Input(List& list)
{
	srand(365);
	cout << "\nNhap so phan tu ban dau cua dslk >> ";
	cin >> n;
	for (int i = 0; i <= n; i++)
		AddNode(list, rand() % 10);
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
	return 0;
}