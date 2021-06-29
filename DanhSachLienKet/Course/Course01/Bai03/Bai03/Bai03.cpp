// Thêm 1 node y vào trước node x trong dslk đơn

#include <iostream>
#include <time.h>

using namespace std;

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
    pNode->data = x;
    pNode->pNext = NULL;
    return pNode;
}

void XuatDanhSach(LIST list)
{
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
        cout << i->data << "\t";
}

//Thêm vào đầu dslk
void AddHead(LIST& list, NODE* pNode)
{
    // Nếu danh sách rỗng
    if (list.pHead == NULL)
        list.pHead = list.pTail = pNode;
    else
    {
        pNode->pNext = list.pHead;
        list.pHead = pNode;
    }
}

//Thêm node y vào trước node x trong dslk đơn
void ThemNodeY_TruocNodeX(LIST& list, NODE* xNode, NODE* yNode)
{
    // Nếu danh sách chỉ tồn tại duy nhất 1 node và node này == xNode ==> Bài toán chèn đầu
    if (xNode->data == list.pHead->data && list.pHead->pNext == NULL)
        AddHead(list, yNode);       //Thêm node y vào đầu danh sách
    else
    {
        //Node giữ mối liên kết với node nằm trước node x
        NODE* k = new NODE;

        //Duyệt danh sách từ đầu đến cuối để tìm node x
        for (NODE* i = list.pHead; i != NULL; i = i->pNext)
        {
            //Phát hiện node x có tồn tại trong danh sách
            if (xNode->data == i->data)
            {
                //Mỗi lần phát hiện 1 node x thì khởi tạo 1 node y mới hoàn toàn (tránh lặp con trỏ gây mất dữ liệu)
                NODE* y2 = KhoiTaoNode(yNode->data);
                //Thực hiện bài toán thêm node y2 vào sau node k ==> Bài toán thêm vào trước node x
                y2->pNext = i;
                k->pNext = y2;
            }
            k = i;      //Giữ liên kết với node nằm trước node x trong danh sách
        }
    }
}

int main()
{
    LIST list;
    KhoiTaoDSLK(list);

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int nRand = rand() % 100;
        NODE* pNode = KhoiTaoNode(nRand);
        AddHead(list, pNode);
    }
    cout << "\nDanh sach lien ket\n";
    XuatDanhSach(list);

    int x, y;
    cout << "\nNhap gia tri node y >> ";
    cin >> y;
    NODE* yNode = KhoiTaoNode(y);
    cout << "\nNhap gia tri node x trong dslk >> ";
    cin >> x;
    NODE* xNode = KhoiTaoNode(x);
    ThemNodeY_TruocNodeX(list, xNode, yNode);
    cout << "\n\n\tDanh sach lien ket\n";
    XuatDanhSach(list);
    return 1;
}