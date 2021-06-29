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

// Hàm thêm 1 node vào sau node x
void ThemSauNodex(LIST& list, NODE* xNode, NODE* yNODE)
{
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
    {
        // Tìm thấy node x
        if (i->data == xNode->data)
        {
            NODE* k = i->pNext;
            yNODE->pNext = k;
            i->pNext = yNODE;
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

    int x, y;
    cout << "\nNhap gia tri node can chen >> ";
    cin >> y;
    cout << "\nChen sau node >> ";
    cin >> x;

    NODE* yNode = GetNode(y);
    NODE* xNode = GetNode(x);

    ThemSauNodex(list, xNode, yNode);
    cout << "\nDanh sach sau khi them...\n";
    Output(list);

    cout << "\nGiai phong Node...";
    GiaiPhong(list);
    cout << "\nDSLK...";
    Output(list);
    return 0;
}