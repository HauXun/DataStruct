#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Date
{
    int ngay;
    int thang;
    int nam;
};
typedef struct Date DATE;

struct SinhVien
{
    string maSv;
    string hoTen;
    DATE ngaysinh;
    float dtb;
};
typedef struct SinhVien SINHVIEN;

struct Node
{
    SINHVIEN data;
    Node* pNext;
};
typedef struct Node NODE;

struct List
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct List LIST;

void KhoiTaoDSLK(LIST& list)
{
    list.pHead = list.pTail = NULL;
}

NODE* KhoiTaoNode(SINHVIEN x)
{
    NODE* pNode = new NODE;
    if (!pNode)
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

void DateReader(ifstream& in, DATE& date)
{
    in >> date.ngay;
    in.seekg(1, 1);     // Dịch sang bên phải 1 byte để bỏ 1 kí tự
    in >> date.thang;
    in.seekg(1, 1);     // Dịch sang bên phải 1 byte để bỏ 1 kí tự
    in >> date.nam;

}

void Reader(ifstream& in, SINHVIEN& sv)
{
    getline(in, sv.hoTen, ',');     // Đọc đến dấu , thì dừng
    in.seekg(1, 1);                 // Tại vị trí hiện tại dịch sang phải 1 byte để bỏ khoảng trắng ' '
    getline(in, sv.maSv, ',');      // Đọc đến dấu , thì dừng
    in.seekg(1, 1);                 // Tại vị trí hiện tại dịch sang phải 1 byte để bỏ khoảng trắng ' '
    DateReader(in, sv.ngaysinh);
    in.seekg(2, 1);                 // Tại vị trí hiện tại dịch sang phải 2 byte để bỏ dấu phẩy ',' và khoảng trắng ' '
    in >> sv.dtb;

    // Tạo biến tạm để đọc kí tự xuống dòng ở cuối mỗi dòng chuỗi
    string temp;
    getline(in, temp);
}

void FileReader(ifstream& in, LIST& list)
{
    // Đọc đến cuối file thì dừng
    while (!in.eof())
    {
        // Đọc thông tin sinh viên
        SINHVIEN sv;
        Reader(in, sv);
        // Khởi tạo node sinh viên
        NODE* pNode = KhoiTaoNode(sv);
        // Thêm node sinh viên vào dslk
        AddTail(list, pNode);
    }
}

void Output(SINHVIEN sv)
{
    cout << "\nHoten : " << sv.hoTen;
    cout << "\nMa sinh vien: " << sv.maSv;
    cout << "\nNgay sinh : " << sv.ngaysinh.ngay << '/' << sv.ngaysinh.thang << '/' << sv.ngaysinh.nam;
    cout << "\nDiem trung binh : " << sv.dtb;
}

void XuatDSSV(LIST list)
{
    int count = 1;
    for (NODE* i = list.pHead; i != NULL; i = i->pNext)
    {
        cout << "\n\tSINH VIEN THU " << count++;
        Output(i->data);
    }
}

int main()
{
    LIST list;
    KhoiTaoDSLK(list);
    ifstream in;
    in.open("sinhvien.txt", ios::in);
    FileReader(in, list);
    XuatDSSV(list);
    in.close();
    return 1;
}