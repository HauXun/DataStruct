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

void AddHeadNode(Node** list, Node* pNode)
{
	pNode->pNext = *list;
	*list = pNode;
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

Node* merge(Node* list1, Node* list2)
{
	if (!list2)
		return list1;
	if (!list1)
		return list2;
	Node* pNode = NULL;
	Node* list = NULL;
	while (list1 || list2)
	{
		if (list1 && list2)
		{
			if (list1->data < list2->data)
			{
				pNode = list1;
				list1 = pNode->pNext;
				AddHeadNode(&list, pNode);
			}
			else
			{
				pNode = list2;
				list2 = pNode->pNext;
				AddHeadNode(&list, pNode);
			}
		}
		if (!list1 && list2)
		{
			pNode = list2;
			list2 = pNode->pNext;
			AddHeadNode(&list, pNode);
		}
		if (list1 && !list2)
		{
			pNode = list1;
			list1 = pNode->pNext;
			AddHeadNode(&list, pNode);
		}
	}
	return list;
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
	List list1, list2;
	Init(list1);
	Init(list2);
	Input(list1);
	Input(list2);
	Output(list1);
	Output(list2);
	Node* head = list1.pHead;
	Node* head2 = list2.pHead;
	Node* result = merge(head, head2);
	List list;
	Init(list);
	list.pHead = result;
	Output(list);
	return 0;
}