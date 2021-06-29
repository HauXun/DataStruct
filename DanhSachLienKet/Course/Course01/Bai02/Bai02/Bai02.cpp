//Kĩ thuật thêm 1 node y vào sau node x

#include <iostream>

using namespace std;

//Nhập danh sách liên kết đơn các số nguyên
//KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN
struct node
{
	int data;       //Dữ liệu của 1 node
	node* pNext;    //Con trỏ dùng để liên kết giữa các node với nhau
};
typedef struct node NODE;

//Khai báo cấu trúc danh sách liên kết đơn
struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

//KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN
void KhoiTaoDSLK(LIST& list)
{
	//Cho 2 node đầu và cuối trỏ đến vùng nhớ rỗng
	list.pHead = list.pTail = NULL;
}

//Hàm khởi tạo 1 cái node
NODE* KhoiTaoNode(int x)
{
	NODE* pNode = new NODE;
	if (pNode == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!";
		return NULL;
	}
	else
	{
		pNode->data = x;
		pNode->pNext = NULL;
	}
	return pNode;
}

//Hàm thêm node x vào đầu danh sách
void AddHead(LIST& list, NODE* pNode)
{
	// Danh sách đang rỗng
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;      //Dùng con trỏ của node pNode liên kết với list.pHead
		list.pHead = pNode;             //Cập nhập lại list.pHead là pNode
	}
}

//Hàm thêm node x vào cuối danh sách
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

//Xuất danh sách liên kết đơn
void XuatDanhSach(LIST list)
{
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		cout << i->data << '\t';
}

//Thêm node y vào sau node x (nằm trong dslk đơn)
void ThemNodeX_SauNodeY(LIST& list, NODE* xNode, NODE* pNode)
{
	//Nếu danh sách chỉ có 1 phần tử và phần tử đó cũng chính là node X ==> Bài toán chèn cuối
	if (xNode->data == list.pHead->data && list.pHead->pNext == NULL)
		AddTail(list, pNode);
	else
	{
		//Duyệt từ đầu danh sách đến cuối danh sách để tìm node x
		for (NODE* i = list.pHead; i != NULL; i = i->pNext)
		{
			//Nếu node x có tồn tại
			if (xNode->data == i->data)
			{
				NODE* a = KhoiTaoNode(pNode->data); //Khởi tạo node a mới để thêm vào sau node x
				//NODE* k = i->pNext;	//Gán node k trỏ đến node nằm sau node x
				a->pNext = i->pNext;	//Gán node a trỏ đến node nằm sau node x
				i->pNext = a;			//Tạo mối liên kết từ node x đến node a
			}	
		}
	}
}


//Menu
void Menu(LIST& list)
{
	int select;
	while (true)
	{
		system("cls");
		cout << "\n\n\tMENU";
		cout << "\n0. Thoat menu";
		cout << "\n1. Nhap node vao danh sach";
		cout << "\n2. Xuat danh sach lien ket don";
		cout << "\n3. Them node y vao sau node x";
		cout << "\n\n\t====";

		cout << "\nNhap lua chon >> ";
		cin >> select;

		if (select < 0 || select > 3)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai";
			system("pause");
		}
		else if (select == 1)
		{
			int x;
			cout << "\nNhap gia tri so nguyen >> ";
			cin >> x;
			NODE* pNode = KhoiTaoNode(x);		//Khởi tạo 1 node
			AddTail(list, pNode);				//Thêm node vào cuối danh sách
		}
		else if (select == 2)
		{
			XuatDanhSach(list);
			system("pause");
		}
		else if (select == 3)
		{
			int y;
			cout << "\nNhap gia tri node y can them vao sau node x >> ";
			cin >> y;
			NODE* pNode = KhoiTaoNode(y);
			int x;
			cout << "\nNhap gia tri node x >> ";
			cin >> x;
			NODE* xNode = KhoiTaoNode(x);

			ThemNodeX_SauNodeY(list, xNode, pNode);	//Thêm node y vào sau node x trong dslk đơn
			XuatDanhSach(list);
		}
		else
			return;
	}
}

int main()
{
	LIST list;
	KhoiTaoDSLK(list);		//Luôn luôn gọi hàm khởi tạo DSLK đơn trước khi thao tác với danh sách
	Menu(list);
	return 1;
}