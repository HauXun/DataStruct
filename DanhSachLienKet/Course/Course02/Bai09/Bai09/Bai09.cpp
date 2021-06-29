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

void XoaDau(LIST& list)
{
    if (list.pHead == NULL)
        return;
    NODE* pNode = list.pHead;
    list.pHead = list.pHead->pNext;
    delete pNode;
}

void XoaCuoi(LIST& list)
{
    if (list.pHead == NULL)
        return;
    if (list.pHead->pNext == NULL)
    {
        XoaDau(list);
        return;
    }
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
    {
        if (i->pNext == list.pTail)
        {
            delete list.pTail;
            i->pNext = NULL;
            list.pTail = i;
            return;
        }
    }
}

// Xóa node đầu tiên có giá trị bằng x
void XoaNodeXDauTien(LIST& list, int x)
{
    if (list.pHead->data == x)
    {
        XoaDau(list);
        return;
    }
    if (list.pTail->data == x)
    {
        XoaCuoi(list);
        return;
    }

    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
    {
        if (i->pNext->data == x)
        {
            NODE* delNode = i->pNext;
            NODE* k = delNode->pNext;
            i->pNext = k;
            delete delNode;
            return;
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
    cout << "\nDSLK sau khi xoa node co gia tri " << x << " dau tien...\n";
    XoaNodeXDauTien(list, x);
    Output(list);

    cout << "\nGiai phong Node...\n";
    GiaiPhong(list);
    cout << "\nDSLK...";
    Output(list);
    return 0;
}