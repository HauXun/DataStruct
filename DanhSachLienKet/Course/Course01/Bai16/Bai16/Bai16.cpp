#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pNext;
};
typedef struct Node NODE;

struct Stack
{
    NODE* pTop;
};
typedef struct Stack STACK;

void KhoiTaoStack(STACK& s)
{
    s.pTop = NULL;
}

NODE* KhoiTaoNode(int x)
{
    NODE* pNode = new NODE;
    if (!pNode)
        return NULL;
    pNode->data = x;
    pNode->pNext = NULL;
}

bool IsEmpty(STACK& s)
{
    return (s.pTop == NULL);
}

bool Push(STACK& s, NODE* pNode)
{
    if (!pNode)
        return false;
    if (IsEmpty(s))
        s.pTop = pNode;
    else
    {
        pNode->pNext = s.pTop;
        s.pTop = pNode;
    }
    return true;
}

bool Pop(STACK& s, int& x)
{
    if (IsEmpty(s))
        return false;
    else
    {
        NODE* pNode = s.pTop;
        x = pNode->data;
        s.pTop = s.pTop->pNext;
        delete pNode;
    }
    return true;
}

bool Top(STACK& s, int& x)
{
    if (IsEmpty(s))
        return false;
    x = s.pTop->data;
    return true;
}

void Input(STACK& s)
{
    int n;
    cout << "\nNhap so luong phan tu cua Stack >> ";
    cin >> n;
    srand(365);
    for (int i = 0; i < n; i++)
    {
        NODE* pNode = KhoiTaoNode(rand() % 10);
        Push(s, pNode);
    }
}

void Output(STACK s)
{
    cout << '\n';
    while (!IsEmpty(s))
    {
        int x;
        Pop(s, x);
        cout << ' ' << x;
    }
    cout << '\n';
    if (IsEmpty(s))
        cout << "\nDanh sach hien tai rong!";
    else
        cout << "\nDanh sach con phan tu!";
}

int main()
{
    STACK s;
    KhoiTaoStack(s);
    Input(s);
    int x;
    Top(s, x);
    cout << "\nPhan tu dau Stack >> " << x;
    Output(s);
    return 1;
}