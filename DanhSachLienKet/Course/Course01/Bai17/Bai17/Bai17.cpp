#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pNext;
};
typedef struct Node NODE;

struct Queue
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct Queue QUEUE;

void KhoiTaoStack(QUEUE& q)
{
    q.pHead = q.pTail = NULL;
}

NODE* KhoiTaoNode(int x)
{
    NODE* pNode = new NODE;
    if (!pNode)
        return NULL;
    pNode->data = x;
    pNode->pNext = NULL;
    return pNode;
}

bool IsEmpty(QUEUE& q)
{
    return (q.pHead == NULL);
}

bool Push(QUEUE& q, NODE* pNode)
{
    if (!pNode)
        return false;
    if (IsEmpty(q))
        q.pHead = q.pTail = pNode;
    else
    {
        q.pTail->pNext = pNode;
        q.pTail = pNode;
    }
    return true;
}

bool Pop(QUEUE& q, int& x)
{
    if (IsEmpty(q))
        return false;
    else
    {
        NODE* pNode = q.pHead;
        x = pNode->data;
        q.pHead = q.pHead->pNext;
        delete pNode;
    }
    return true;
}

bool Top(QUEUE& q, int& x)
{
    if (IsEmpty(q))
        return false;
    x = q.pHead->data;
    return true;
}

void Input(QUEUE& q)
{
    int n;
    cout << "\nNhap so luong phan tu cua Stack >> ";
    cin >> n;
    srand(365);
    for (int i = 0; i < n; i++)
    {
        NODE* pNode = KhoiTaoNode(rand() % 10);
        Push(q, pNode);
    }
}

void Output(QUEUE q)
{
    cout << '\n';
    while (!IsEmpty(q))
    {
        int x;
        Pop(q, x);
        cout << ' ' << x;
    }
    cout << '\n';
    if (IsEmpty(q))
        cout << "\nDanh sach hien tai rong!";
    else
        cout << "\nDanh sach con phan tu!";
}

int main()
{
    QUEUE q;
    KhoiTaoStack(q);
    Input(q);
    int x;
    Top(q, x);
    cout << "\nPhan tu dau Stack >> " << x;
    Output(q);
    return 1;
}