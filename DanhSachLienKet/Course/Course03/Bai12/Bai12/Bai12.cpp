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

void Reserve(List& list)
{
	if (list.pHead)
	{
		if (list.pHead == list.pTail)
			return;
		else if (list.pTail == list.pHead->pNext)
		{
			list.pHead = list.pHead->pNext;
			list.pTail = list.pTail->pNext;
		}
		else
		{
			Node* temp;
			Node* parent;
			Node* current;
			temp = parent = list.pHead;
			current = list.pHead->pNext;
			list.pHead = current->pNext;
			current->pNext = parent;
			while (list.pHead->pNext != temp)
			{
				parent = current;
				current = list.pHead;
				list.pHead = list.pHead->pNext;
				current->pNext = parent;
			}
			list.pHead->pNext = current;
			list.pTail = temp;
			list.pTail->pNext = list.pHead;
		}
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

int main()
{
	List list;
	Init(list);
	Input(list);
	Output(list);
	Reserve(list);
	Output(list);
	return 0;
}