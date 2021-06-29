// Bai11.cpp : Giải phóng vùng nhớ trong dslk

#include <iostream>
#include <time.h>

using namespace std;

struct NODE
{
    int data;
    NODE* pNext;
};

struct LIST
{
    NODE* pHead;
    NODE* pTail;
};

void KhoiTaoDSLK(LIST& list)
{
    list.pHead = list.pTail = NULL;
}

NODE* KhoiTaoNode(int x)
{
    NODE* pNode = new NODE;
    pNode->data = x;
    pNode->pNext = NULL;
    return pNode;
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

void XuatDSLK(LIST list)
{
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
        cout << i->data << '\t';
    cout << '\n';
}

// Hàm giải phóng vùng nhớ cho dslk
void GiaiPhongVungNho(LIST& list)
{
    NODE* i = NULL;
    // Duyệt từ đầu danh sách đến cuối danh sách
    while (list.pHead != NULL)
    {
        i = list.pHead;
        list.pHead = list.pHead->pNext;
        delete i;
    }
}

int main()
{
    LIST list;
    KhoiTaoDSLK(list);

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int nRand = rand() % 10;
        NODE* pNode = KhoiTaoNode(nRand);
        AddTail(list, pNode);
    }
    XuatDSLK(list);
    system("pause");
    GiaiPhongVungNho(list);
    cout << "\nGiai phong dslk...";
    XuatDSLK(list);
    return 1;
}