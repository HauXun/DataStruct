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

Node* Search(List list, int x)
{
	Node* pNode = list.pHead;
	do
	{
		if (pNode->data == x)
			return pNode;
		pNode = pNode->pNext;
	} while (pNode != list.pHead);
	return NULL;
}

void AddMid(List& list, int x, int k)
{
	Node* pNode = Search(list, k);
	if (pNode)
	{
		Node* xNode = CreatNode(x);
		Node* kNode = pNode->pNext;
		pNode->pNext = xNode;
		xNode->pNext = kNode;
	}
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
	if (list.pHead)
	{
		Node* pNode = list.pHead;
		do
		{
			cout << " " << pNode->data;
			pNode = pNode->pNext;
		} while (pNode != list.pHead);
		cout << "\n";
	}
}

void DelHead(List& list)
{
	if (!IsEmpty(list))
	{
		if (list.pHead != list.pTail)
		{
			Node* pNode = list.pHead;
			list.pHead = list.pHead->pNext;
			list.pTail->pNext = list.pHead;
			delete pNode;
		}
		else
			list.pHead = list.pTail = NULL;
	}
}

void DelTail(List& list)
{
	if (!IsEmpty(list))
	{
		if (list.pHead != list.pTail)
		{
			Node* pNode = list.pHead;
			Node* i = new Node;
			while (pNode->pNext != list.pTail)
			{
				pNode = pNode->pNext;
			}
			i = pNode;
			pNode = pNode->pNext;
			list.pTail = i;
			list.pTail->pNext = NULL;
			list.pTail->pNext = list.pHead;
			delete pNode;
		}
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