#include <iostream>
#include <conio.h>

using namespace std;

struct Data
{
	int n;
};

struct NODE
{
	Data data;
	NODE* pNext;
};

struct  LIST
{
	NODE* pHead;
	NODE* pTail;
};

//Khởi tạo danh sách
void InitList(LIST& list);

//Kiểm tra list rổng
bool IsEmpty(LIST& list);

//Create node
NODE* CreateNode(Data data);

//Create node
NODE* CreateNode(int n);

//Thêm node vào đầu list
void AddHead(LIST& list, NODE* pNode);

void AddHead(LIST& list, int n);

//Thêm node vào cuối list
void AddTail(LIST& list, NODE* pNode);

void AddTail(LIST& list, int n);

//Chèn phần tử sau node x
void InsertNode(LIST& list, NODE* x, NODE* pNewNode);

//Chèn phần tử sau index x
void InsertNode(LIST& list, int idx, NODE* pNewNode);

//Xuất danh sách
void PrintList(LIST list, char* mess);

//Get size list
int GetSize(LIST list);

//Get node tại index
NODE* GetNodeAt(LIST list, int idx);