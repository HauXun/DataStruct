#include <iostream>
#include <time.h>

using namespace std;

int n = 0;

struct node
{
    int data;
    node* pNext;
};
typedef struct node NODE;

struct list
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct list LIST;

void KhoiTaoDSLK(LIST& list)
{
    list.pHead = list.pTail = NULL;
}

NODE* KhoiTaoNode(int x)
{
    NODE* pNode = new NODE;
    if (pNode == NULL)
    {
        cout << "\nKhong du bo nho de cap phat node!";
        return NULL;
    }
    else
    {
        pNode->data = x;
        pNode->pNext = NULL;
    }
}

void XuatDanhSach(LIST list)
{
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
        cout << i->data << '\t';
    cout << '\n';
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

//Xóa node nằm sau node x trong danh sách
void XoaSauNodeX(LIST& list, NODE* xNode)
{
    //Duyệt từ đầu đến cuối để tìm node x
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
    {
        // Phát hiện node x
        if (i->data == xNode->data)
        {
            // Node nằm sau node x <=> node sẽ bị xóa
            NODE* k = i->pNext;
            i->pNext = k->pNext;    //Cập nhập mối liên kết giữa node x với node sau node k
            delete k;               //Xóa node nằm sau node x
        }
    }
}

int main()
{
    LIST list;
    KhoiTaoDSLK(list);

    srand(time(NULL));
    for (int i = 0; i < 1; i++)
    {
        int nRand = rand() % 10;
        NODE* pNode = KhoiTaoNode(nRand);
        AddHead(list, pNode);
        n++;
    }
    cout << "\nDanh sach lien ket\n";
    XuatDanhSach(list);
    system("pause");
    int x;
    cout << "\nNhap gia tri node x >> ";
    cin >> x;
    NODE* xNode = KhoiTaoNode(x);
    XoaSauNodeX(list, xNode);
    XuatDanhSach(list);
    return 1;
}