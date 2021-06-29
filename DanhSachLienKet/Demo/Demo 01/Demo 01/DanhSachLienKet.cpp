#include "DanhSachLienKet.h"

//Create node
NODE* CreateNode(Data data)
{
	NODE* node = new NODE;
	if (node == NULL)
		return NULL; 
	node->data = data;		//Gán data cho node
	node->pNext = NULL;		//pNext trỏ tới NULL
}

//Create node
NODE* CreateNode(int n)
{
	Data data = { n };
	NODE* node = CreateNode(data);
	return node;
}

//Khởi tạo danh sách
void InitList(LIST& list)
{
	list.pHead = list.pTail = NULL;
}

//Kiểm tra list rỗng
bool IsEmpty(LIST& list)
{
	if (list.pHead == NULL)
		return true;
	return false;
}

//Thêm node vào đầu list
void AddHead(LIST& list, NODE* pNode)
{
	if (IsEmpty(list))		//Nếu list rỗng
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void AddHead(LIST& list, int n)
{
	NODE* pNode = CreateNode(n);
	AddHead(list, pNode);
}

//Thêm node vào cuối list
void AddTail(LIST& list, NODE* pNode)
{
	if (IsEmpty(list))		//Nếu list rỗng
		list.pHead = list.pTail = pNode;
	else
	{
		list.pTail->pNext = pNode;
		list.pTail = pNode;
	}
}

void AddTail(LIST& list, int n)
{
	NODE* pNode = CreateNode(n);
	AddTail(list, pNode);
}

//Chèn phần tử sau node x
void InsertNode(LIST& list, NODE* x, NODE* pNewNode)
{
	if (pNewNode == NULL || x == NULL)
		return;
	if (IsEmpty(list))		//Nếu list rỗng
		list.pHead = list.pTail = pNewNode;
	else
	{
		if (list.pTail == x) //Nếu x là node cuối list
			AddTail(list, pNewNode);
		else
		{
			pNewNode->pNext = x->pNext;
			x->pNext = pNewNode;
		}
	}
}

//Chèn phần tử sau index x
void InsertNode(LIST& list, int idx, NODE* pNewNode)
{
	NODE* pNode = GetNodeAt(list , idx);
	if (pNode != NULL)
	{
		InsertNode(list, pNode, pNewNode);
	}
}

//Get node tại index
NODE* GetNodeAt(LIST list, int idx)
{
	if (IsEmpty(list) && idx < 0)
		return NULL;
	else
	{
		int curIdx = 0;
		NODE* pNode = list.pHead;
		while (pNode != NULL && curIdx < idx)
		{
			curIdx++;
			pNode = pNode->pNext;
		}
		return pNode;
	}
}

//Xuất danh sách
void PrintList(LIST list, char* mess)
{
	cout << mess << endl;
	if (IsEmpty(list))
		cout << "List is empty!" << endl;
	else
	{
		// Lưu data node hiện tại
		NODE* pNode = list.pHead;		//Gán node = pHead
		while (pNode != NULL)
		{
			cout << pNode->data.n << "\t"; 
			pNode = pNode->pNext;
		}
		cout << "\n";
	}
}

//Get size list
int GetSize(LIST list)
{
	if (IsEmpty(list))
		return 0;
	else
	{
		int nCount = 0;
		NODE* pNode = list.pHead;
		while (pNode != NULL)
		{
			nCount++;
			pNode = pNode->pNext;
		}
		return nCount;
	}
}