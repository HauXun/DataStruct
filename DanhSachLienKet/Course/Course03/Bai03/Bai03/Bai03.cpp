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
	pNode->pNext = list.pHead;
	list.pHead = pNode;
}

void AddTail(List& list, int x)
{
	Node* pNode = CreatNode(x);
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	list.pTail->pNext = pNode;
	list.pTail = pNode;
}

Node* Search(List list, int k)
{
	Node* pNode = list.pHead;
	while (pNode)
	{
		if (pNode->data == k)
			return pNode;
		pNode = pNode->pNext;
	}
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

void AddAtK(List& list, int x, int k)
{
	if (IsEmpty(list) || k <= 1)
		AddHead(list, x);
	else if (k >= n)
		AddTail(list, x);
	else
	{
		Node* xNode = CreatNode(x);
		Node* i = new Node;
		Node* j = new Node;
		Node* pNode = list.pHead;
		int count = 0;
		while (pNode)
		{
			count++;
			i = pNode;
			if (count == k)
				break;
			pNode = pNode->pNext;
		}
		j = list.pHead;
		while (j->pNext != i)
		{
			j = j->pNext;
		}
		j->pNext = xNode;
		xNode->pNext = pNode;
	}
}

void DelHead(List& list)
{
	if (!IsEmpty(list))
	{
		Node* pNode = list.pHead;
		list.pHead = list.pHead->pNext;
		delete pNode;
	}
}

void DelTail(List& list)
{
	if (!IsEmpty(list))
	{
		Node* pNode = list.pHead;
		Node* iNode = new Node;
		while (pNode->pNext != list.pTail)
		{
			pNode = pNode->pNext;
		}
		iNode = pNode;
		pNode = pNode->pNext;
		list.pTail = iNode;
		list.pTail->pNext = NULL;
		delete pNode;
	}
}

void DelAtK(List& list, int k)
{
	if (k <= 1)
		DelHead(list);
	else if (k >= n)
		DelTail(list);
	else
	{
		int count = 0;
		if (!IsEmpty(list))
		{
			Node* pNode = list.pHead;
			Node* i = new Node;
			Node* j = new Node;
			while (pNode)
			{
				count++;
				i = pNode;
				if (count == k)
					break;
				pNode = pNode->pNext;
			}
			j = list.pHead;
			while (j->pNext != i)
			{
				j = j->pNext;
			}
			j->pNext = i->pNext;
			delete i;
		}
	}
}

void Input(List& list)
{
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
}

void Menu()
{
	List list;
	Init(list);
	Input(list);
	Output(list);
	int k, x, lc;
	do
	{
		cout << "\n______MENU______\n1_Chen dau.\n2_chen cuoi."
			<< "\n3_Chen sau vi tri node data = k.\n4_Chen vao vi tri bat ki."
			<< "\n5_Xuat Thong tin List.\n6_Xoa phan tu dau List."
			<< "\n7_Xoa phan tu o cuoi List.\n8_Xoa node o vi tri k."
			<< "\n0_Thoat.\n_Ban chon ? ";
		cin >> lc;
		switch (lc)
		{
		case 0: break;
		case 1: cout << "\nNhap x: "; cin >> x; AddHead(list, x); n++; break;
		case 2: cout << "\nNhap x: "; cin >> x; AddTail(list, x); n++; break;
		case 3: cout << "\nNhap x, k: "; cin >> x >> k; AddMid(list, x, k); n++; break;
		case 4: cout << "\nNhap x, vi tri k: "; cin >> x >> k; AddAtK(list, x, k); n++; break;
		case 5: Output(list); break;
		case 6: DelHead(list); n--; break;
		case 7: DelTail(list); n--; break;
		case 8: cout << "\nNhap vi tri k: "; cin >> k; DelAtK(list, k); n--; break;
		}
	} while (lc != 0);
}

int Main()
{
	Menu();
	return 0;
}