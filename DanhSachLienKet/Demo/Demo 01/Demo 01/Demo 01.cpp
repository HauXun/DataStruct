#include <time.h>

#include "DanhSachLienKet.h"

int main()
{
    LIST list;           //Khai báo list
    Data data = { 69 };
    //data.n = 69;

    /*Data* pData = new Data;
    pData->n = 69;*/

    //Khởi tạo list
    InitList(list);

    //Kiểm tra list rổng
    if (IsEmpty(list))
        cout << "List is empty!" << endl;
    else
        cout << "List is not empty" << endl;

    //Khai báo node
    //NODE* node = CreateNode(data/*pData*/);

    //Thêm node vào đầu list
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int nRand = rand() % 100;
        AddTail(list, nRand);
    }

    //Xuất danh sách
    char mess[100] = "Xuat Danh Sach";
    PrintList(list, mess);

    //Check node at idx
    int idx;
    cout << "Nhap vi tri de kiem tra node >> ";
    cin >> idx;
    cout << "Node thu " << idx << ": " << GetNodeAt(list, idx)->data.n << endl;
    InsertNode(list, 0, CreateNode(666));
    PrintList(list, mess);
    InsertNode(list, GetSize(list) - 1, CreateNode(999));
    PrintList(list, mess);

    //Insert node at idx
    cout << "Nhap vi tri de chen node >> ";
    cin >> idx;
    int n;
    cout << "Nhap gia tri cua node can chen >> ";
    cin >> n;
    InsertNode(list, idx, CreateNode(n));
    PrintList(list, mess);

    //Kiểm tra số lượng phần tử
    cout << "Size of list >> " << GetSize(list) << endl;

    return 1;
}