#include <iostream>

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

/// <summary>
/// Tìm 1 node trong dslk
/// </summary>
/// <param name="list">Tên danh sách</param>
/// <param name="x">Chỉ số node x</param>
/// <returns>1:Tìm thấy-2:Không tìm thấy</returns>
int TimNodeX(LIST list, int x)
{
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
        if (i->data == x)
            return 1;
    return 0;
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
    cout << "\nNhap vao 1 node de tim >> ";
    cin >> x;
    if (TimNodeX(list, x))
        cout << "\nTim thay...";
    else
        cout << "\nKhong tim thay...";

    cout << "\nGiai phong Node...\n";
    GiaiPhong(list);
    cout << "\nDSLK...";
    Output(list);
    return 0;
}