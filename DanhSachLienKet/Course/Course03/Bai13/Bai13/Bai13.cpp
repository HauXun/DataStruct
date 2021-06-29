#include <iostream>

using namespace std;

int n;

struct Node
{
    int data;
    Node* pNext;
    Node* pPrev;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

void Init(List& list)
{
    list.pHead = list.pTail = NULL;
}

Node* CreatNode(int x)
{
    Node* pNode = new Node;
    if (!pNode)
        exit(1);
    pNode->data = x;
    pNode->pNext = NULL;
    pNode->pPrev = NULL;
    return pNode;
}

bool IsEmpty(List list)
{
    return (!list.pHead);
}

void AddHead(List& list, int x)
{
    Node* pNode = CreatNode(x);
    if (IsEmpty(list))
        list.pHead = list.pTail = pNode;
    else
    {
        pNode->pNext = list.pHead;  // Con trỏ pNext của pNode trỏ tới địa chỉ của node pHead (node ban đầu)
        list.pHead->pPrev = pNode;  // Trỏ ngược lại
        list.pHead = pNode;         // Cập nhập node pHead (lúc sau)
    }
}

void AddTail(List& list, int x)
{
    Node* pNode = CreatNode(x);
    if (IsEmpty(list))
        AddHead(list, x);
    else
    {
        list.pTail->pNext = pNode;  // Trỏ thuận
        pNode->pPrev = list.pTail;  // Trỏ ngược
        list.pTail = pNode;         // Cập nhập pTail
    }
}

Node* Search(List list, int k)
{
    Node* pNode = list.pHead;
    while (pNode)
    {
        if (pNode->data == k)
            return pNode;
        pNode = pNode->pNext;
    }
    return NULL;
}

void AddMid(List& list, int x, int k)
{
    Node* pNode = Search(list, k);
    if (pNode)
    {
        Node* xNode = CreatNode(x);
        Node* i = pNode->pNext;
        pNode->pNext = xNode;
        xNode->pPrev = pNode;
        xNode->pNext = i;
        i->pPrev = xNode;
    }
}

void AddAtK(List& list, int x, int k)
{
    if (IsEmpty(list) || k <= 1)
        AddHead(list, x);
    else if (k >= n)
        AddTail(list, x);
    else
    {
        Node* xNode = CreatNode(x);
        Node* pNode = new Node;
        Node* i = list.pHead;
        Node* j = new Node;
        int count = 0;
        while (i)
        {
            count++;
            pNode = i;
            if (count == k)
                break;
            i = i->pNext;
        }
        j = list.pHead;
        while (j->pNext != pNode)
        {
            j = j->pNext;
        }
        j->pNext = xNode;
        xNode->pPrev = j;
        xNode->pNext = i;
        i->pPrev = xNode;
    }
}

void Input(List& list)
{
    cout << "\nNhap so luong phan tu cua dslk >> ";
    cin >> n;
    srand(365);
    for (int i = 0; i <= n; i++)
        AddTail(list, rand() % 10);
}

void Output(List list)
{
    Node* pNode = list.pHead;
    while (pNode)
    {
        cout << " " << pNode->data;
        pNode = pNode->pNext;
    }
    cout << '\n';
}

void DelHead(List& list)
{
    if (!IsEmpty(list))
    {
        Node* pNode = list.pHead;
        list.pHead = list.pHead->pNext;
        list.pHead->pPrev = NULL;
        delete pNode;
    }
}

void DelTail(List& list)
{
    if (!IsEmpty(list))
    {
        Node* pNode = list.pTail;
        list.pTail = list.pTail->pPrev;
        list.pTail->pNext = NULL;
        pNode->pPrev = NULL;
        delete pNode;
    }
}

void DelAtK(List& list, int k)
{
    if (k <= 1)
        DelHead(list);
    else if (k >= n)
        DelTail(list);
    else
    {
        int count = 0;
        if (!IsEmpty(list))
        {
            Node* pNode = list.pHead;
            Node* i = new Node;
            while (pNode)
            {
                count++;
                i = pNode;
                if (count == k)
                    break;
                pNode = pNode->pNext;
            }
            Node* j = list.pHead;
            while (j->pNext != i)
            {
                j = j->pNext;
            }
            j->pNext = i->pNext;
            (i->pNext)->pPrev = j;
            delete i;
        }
    }
}

void QuickSort(List& list)
{
    if (list.pHead == list.pTail)
        return;
    List l1, l2;
    Init(l1);
    Init(l2);
    Node* pivot;
    Node* pNode;
    pivot = list.pHead;
    list.pHead = list.pHead->pNext;
    pivot->pNext = NULL;
    pivot->pPrev = NULL;
    while (list.pHead)
    {
        pNode = list.pHead;
        list.pHead = list.pHead->pNext;
        pNode->pNext = NULL;
        pNode->pPrev = NULL;
        if (pNode->data <= pivot->data)
            AddHead(l1, pNode->data);
        else
            AddHead(l2, pNode->data);
    }
    QuickSort(l1);
    QuickSort(l2);
    if (l1.pHead)
    {
        list.pHead = l1.pHead;
        l1.pTail->pNext = pivot;
        pivot->pPrev = l1.pTail;
    }
    else
        list.pHead = pivot;
    pivot->pNext = l2.pHead;
    if (l2.pHead)
    {
        list.pTail = l2.pTail;
        l2.pHead->pPrev = pivot;
    }
    else
        list.pTail = pivot;
}

int main()
{
    List list;
    Init(list);
    Input(list);
    Output(list);
    QuickSort(list);

    Output(list);
    return 1;
}