﻿#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* pNext;
};
typedef struct Node NODE;

struct List
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct List LIST;

void Init(LIST& list)
{
    list.pHead = list.pTail = NULL;
}

NODE* GetNode(int x)
{
    NODE* pNode = new NODE;
    if (pNode == NULL)
        return NULL;
    pNode->data = x;
    pNode->pNext = NULL;
    return pNode;
}

void AddHead(LIST& list, NODE* pNode)
{
    if (list.pHead == NULL)
        list.pHead = list.pTail = pNode;
    else
    {
        pNode->pNext = list.pHead;
        list.pHead = pNode;
    }
}

void AddTail(LIST& list, NODE* pNode)
{
    if (list.pHead == NULL)
        list.pHead = list.pTail = pNode;
    else
    {
        list.pTail->pNext = pNode;
        list.pTail = pNode;
    }
}

void Input(LIST& list, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int nRand = rand() % 10;
        NODE* pNode = GetNode(nRand);
        AddTail(list, pNode);
    }
}

void Output(LIST list)
{
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
        cout << i->data << '\t';
    cout << '\n';
}

void GiaiPhong(LIST& list)
{
    NODE* i;
    while (list.pHead != NULL)
    {
        i = list.pHead;
        list.pHead = list.pHead->pNext;
        delete i;
    }
}

// Xóa node nằm sau node x
void XoaNodeSauNodeX(LIST& list, NODE* xNode)
{
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
    {
        if (i->data == xNode->data)
        {
            NODE* k = i->pNext;
            i->pNext = k->pNext;
            delete k;
        }
    }
}

int main()
{
    LIST list;
    Init(list);

    int n;
    cout << "\nNhap vao so luong Node >> ";
    cin >> n;

    Input(list, n);
    Output(list);

    int x;
    cout << "\nNhap vao node x >> ";
    cin >> x;
    NODE* xNode = GetNode(x);
    cout << "\nDSLK sau khi xoa node sau node " << xNode->data << " ...\n";
    XoaNodeSauNodeX(list, xNode);
    Output(list);

    cout << "\nGiai phong Node...\n";
    GiaiPhong(list);
    cout << "\nDSLK...";
    Output(list);
    return 0;
}