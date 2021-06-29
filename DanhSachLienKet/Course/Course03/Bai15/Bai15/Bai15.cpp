#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pNext;
};

struct Queue
{
    Node* pHead;
    Node* pTail;
};

void Init(Queue& q)
{
    q.pHead = q.pTail = NULL;
}

bool IsEmpty(Queue& q)
{
    return q.pHead == NULL;
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

void Push(Queue& q, int x)
{
    Node* pNode = CreatNode(x);
    if (IsEmpty(q))
        q.pHead = q.pTail = pNode;
    else
    {
        pNode->pNext = q.pHead;
        q.pHead = pNode;
    }
}

int Top(Queue q)
{
    if (q.pHead)
        return q.pHead->data;
    return 0;
}


int Pop(Queue& q)
{
    if (!IsEmpty(q))
    {
        Node* pNode = q.pHead;
        q.pHead = q.pHead->pNext;
        return pNode->data;
        delete pNode;
    }
    return 0;
}

void Input(Queue& q)
{
    int n;
    cout << "\nNhap so luong phan tu cua dslk >> ";
    cin >> n;
    srand(365);
    for (int i = 0; i < n; i++)
        Push(q, rand() % 10);
}

void Output(Queue q)
{
    for (Node* i = q.pHead; i != NULL; i = i->pNext)
        cout << ' ' << i->data;
}

int main()
{
    Queue q;
    Init(q);
    Input(q);
    Output(q);
}