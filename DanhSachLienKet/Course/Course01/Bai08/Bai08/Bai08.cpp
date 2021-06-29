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

void DocTuMang(LIST& list) {
	int arr[] = { 1,7,7,4,5,4,7,5,0,9 };
	int length = sizeof(arr) / sizeof(int);
	for (int i = 0; i < length; ++i) {
		NODE* pNode = KhoiTaoNode(arr[i]);
		AddHead(list, pNode);
	}
}

//Xóa node nằm trước node x trong danh sách
void XoaNodeTruocNodeX(LIST& list, NODE* xNode)
{
	//Nếu list.pHead == Null thì danh sách rỗng
	if (list.pHead == NULL || list.pHead->pNext == NULL)
		return;
	else
	{
		// Node nằm trước -> Node i (cần xóa) -> Node x
		// => Node nằm trước -> Node x
		
		// Node nằm trước
		NODE* prevNode = NULL;
		for (NODE* i = list.pHead; i != NULL; prevNode = i, i = i->pNext)
		{
			// Node nằm sau
			NODE* nextNode = i->pNext;

			// Nếu node cần xóa không phải là node đầu && node phía sau có dữ liệu && node phía sau == nút x
			if (prevNode != NULL && nextNode != NULL && nextNode->data == xNode->data)
			{
				// Ghi lại node cần xóa
				NODE* delNode = i;
				// Nối node trước vào node sau
				prevNode->pNext = nextNode;
				delete delNode;
				// Cập nhật lại vị trí sau khi xóa
				i = nextNode;
				// Nếu node sau khi xóa xong tới cuối cùng thì cập nhật pTail
				if (i->pNext == NULL)
					list.pTail = i;
			}
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
		int nRand = rand() % 10;
		NODE* pNode = KhoiTaoNode(nRand);
		AddHead(list, pNode);
	}
	//DocTuMang(list);
	cout << "\nDanh sach lien ket\n";
	XuatDanhSach(list);
	system("pause");
	int x;
	cout << "\nNhap gia tri node x >> ";
	cin >> x;
	NODE* xNode = KhoiTaoNode(x);
	XoaNodeTruocNodeX(list, xNode);
	XuatDanhSach(list);
	return 1;
}