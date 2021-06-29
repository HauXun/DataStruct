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

//Hàm xóa đầu
void XoaDau(LIST& list)
{
    // Nếu danh sách rỗng
    if (list.pHead == NULL)
        return;
    // Node sẽ xóa
    NODE* pNode = list.pHead;

    // Cập nhập lại list.pHead là phần tử kế tiếp
    list.pHead = list.pHead->pNext;
    delete pNode;
}

//Hàm xóa cuối
void XoaCuoi(LIST& list)
{
    if (list.pHead == NULL)
        return;

    //Trường hợp danh sách có 1 phần tử
    if (list.pHead->pNext == NULL)
    {
        XoaDau(list);
        return;
    }

    //Duyệt từ đầu danh sách đến node kế cuối
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
    {
        // Phát hiện node kế cuối
        if (i->pNext == list.pTail)
        {
            delete list.pTail;  //Xóa đi phần tử cuối
            i->pNext = NULL;    //Cho con trỏ của node kế cuối trỏ đến vùng nhớ null
            list.pTail = i;     //Cập nhập lại list.pTail
            return;
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
    XoaCuoi(list);
    XuatDanhSach(list);
    return 1;
}