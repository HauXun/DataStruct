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

Node* getMid(List list)
{
	if (!list.pHead)
		return NULL;
	Node* i;
	Node* j;
	i = j = list.pHead;
	while (j->pNext && j->pNext->pNext)
	{
		i = i->pNext;
		j = j->pNext;
	}
	return i;
}

Node* merge(Node* list1, Node* list2, List& list)
{
	if (!list2)
		return list1;
	if (!list1)
		return list2;
	Node* result = NULL;
	if (list1->data < list2->data)
	{
		result = list1;
		result->pNext = merge(list1->pNext, list2, list);
	}
	else
	{
		result = list2;
		result->pNext = merge(list1, list2->pNext, list);
	}
	return list.pHead = result;
}

void Input(List& list)
{
	srand(365);
	cout << "\nNhap so phan tu ban dau cua dslk >> ";
	cin >> n;
	for (int i = 0; i <= n; i++)
		AddTail(list, i);
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

	return 0;
}