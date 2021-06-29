#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pNext;
};

struct Stack
{
    Node* pHead;
    Node* pTail;
};

void Init(Stack& s)
{
    s.pHead = s.pTail = NULL;
}

bool IsEmpty(Stack& s)
{
    return s.pHead == NULL;
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

void Push(Stack& s, int x)
{
    Node* pNode = CreatNode(x);
    if (IsEmpty(s))
        s.pHead = s.pTail = pNode;
    else
    {
        pNode->pNext = s.pHead;
        s.pHead = pNode;
    }
}

void Input(Stack& s)
{
    int n;
    cout << "\nNhap so luong phan tu cua dslk >> ";
    cin >> n;
    srand(365);
    for (int i = 0; i < n; i++)
        Push(s, rand() % 10);
}

int Pop(Stack& s)
{
    if (!IsEmpty(s))
    {
        Node* pNode = s.pHead;
        s.pHead = s.pHead->pNext;
        return pNode->data;
        delete pNode;
    }
    return 0;
}

void Output(Stack s)
{
    for (Node* i = s.pHead; i != NULL; i = i->pNext)
        cout << ' ' << i->data;
}

int main()
{
    Stack s;
    Init(s);
    Input(s);
    Output(s);
}