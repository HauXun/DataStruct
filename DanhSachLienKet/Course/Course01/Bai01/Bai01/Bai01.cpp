//Bài toán
//Nhập danh sách liên kết đơn các số nguyên. Tìm giá trị lơn nhất trong danh sách

#include <iostream>

using namespace std;

//KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN
//Khai báo cấu trúc 1 node

struct node
{
    int data;       //Dữ liệu chứa trong 1 node
    node* pNext;    //Con trỏ dùng để liên kết giữa các node với nhau
};
typedef struct node NODE;       //Thay thế struct node thành NODE

//Khai báo cấu trúc của danh sách liên kết đơn
struct list
{
    NODE* pHead;        //Node quản lí đầu danh sách
    NODE* pTail;        //Node quản lí cuối danh sách
};
typedef struct list LIST;       //Thay thế struct list thành LIST


//KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN
void KhoiTao(LIST& list)
{
    //Cho 2 node trỏ đến NULL - Vì danh sách liên kết đơn chưa có phần tử
    list.pHead = list.pTail = NULL;
}

//Hàm khởi tạo 1 node
NODE* KhoiTaoNODE(int x)
{
    NODE* pNode = new NODE;     //Cấp phát vùng nhớ cho NODE pNode
    if (pNode == NULL)
    {
        cout << "Khong du bo nho de cap phat!";
        return NULL;
    }

    pNode->data = x;            //Truyền giá trị x vào cho data
    pNode->pNext = NULL;        //Đầu tiên khai báo NODE thì NODE đó chưa có liên kết đến node nào hết
                                //==> Con trỏ của nó sẽ trỏ đến NULL
    return pNode;               //Trả về NODE pNode vừa khởi tạo
}

//Hàm thêm node vào đầu danh sách liên kết
void AddHead(LIST& list, NODE* pNode)
{
    // Danh sách đang rỗng
    if (list.pHead == NULL)
        // Node đầu cũng chính là node cuối và là pNode
        list.pHead = list.pTail = pNode;
    else
    {
        pNode->pNext = list.pHead;      //Cho con trỏ của node cần thêm là node pNode liên kết đến node đầu - pHead
        list.pHead = pNode;             //Cập nhập pHead chính là node pNode
    }
}

//Hàm thêm node vào cuối danh sách lien kết
void AddTail(LIST& list, NODE* pNode)
{
    if (list.pHead == NULL)
        list.pHead = list.pTail = pNode;
    else
    {
        list.pTail->pNext = pNode;          //Cho con trỏ của pTail liên kết với node pNode
        list.pTail = pNode;                 //Cập nhập lại pNode là node pTail
    }
}

//Hàm xuất danh sách liên kết đơn
void XuatDanhSach(LIST list)
{
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
        cout << i->data << "\t";
}

//Hàm tìm giá trị lớn nhất trong danh sách
int TimMAX(LIST list)
{
    int max = list.pHead->data;     //Giả sử node đầu là node lơn nhất

    //Bắt đầu duyệt từ node thứ 2 để kiêm tra
    for (NODE* i = list.pHead->pNext; i != NULL; i = i->pNext)
    {
        if (max < i->data)
            max = i->data;      //Cập nhập lại giá trị max
    }
    return max;
}

int main()
{
    LIST list;
    KhoiTao(list);      //Khởi tạo danh sách liên kết đơn
    int n;
    cout << "Nhap so luong node can them >> ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "\nNhap gia tri so nguyen >> ";
        cin >> x;
        NODE* pNode = KhoiTaoNODE(x);   //Khởi tạo 1 node số nguyên
        AddTail(list, pNode);           //Thêm node pNode vào đầu danh sách liên kết đơn
    }
    cout << "\n\n\tDanh sach lien ket don\n";
    XuatDanhSach(list);
    cout << "\n\n\tGia tri lon nhat: " << TimMAX(list) << endl;

    return 1;
}