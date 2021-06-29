#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pNext;
};

int main()
{
    Node* head = new Node();
    head->data = 1;
    head->pNext = NULL;

    Node* second = new Node();
    second->data = 2;
    second->pNext = NULL;

    Node* third = new Node();
    third->data = 3;
    third->pNext = NULL;

    // Liên kết
    head->pNext = second;
    second->pNext = third;

    // Truy cập phần tử head
    int data = head->data;
    cout << data << '\n';

    Node* pNode = head;
    while (pNode)
    {
        data = pNode->data;
        cout << data << " -> ";
        pNode = pNode->pNext;
    }

    return 1;
}