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

void Input(LIST& list)
{
    int n;
    cout << "\nNhap vao so luong Node >> ";
    cin >> n;

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

int TimMax(LIST list)
{
    int max = list.pHead->data;
    for (NODE* i = list.pHead->pNext; i != NULL; i = i->pNext)
        if (i->data > max)
            max = i->data;
    return max;
}

int main()
{
    LIST list;
    Init(list);

    Input(list);
    Output(list);

    cout << "\nMax is " << TimMax(list);
    return 0;
}