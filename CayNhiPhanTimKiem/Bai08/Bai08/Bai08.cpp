#include <iostream>

using namespace std;

struct NODE
{
    int data;
    NODE* pLeft;
    NODE* pRight;
};
typedef struct NODE* TREE;

void KhoiTaoCay(TREE& tree)
{
    tree = NULL;
}

void ThemNodeVaoCay(TREE& tree, int x)
{
    if (!tree)
    {
        NODE* pNode = new NODE;
        pNode->data = x;
        pNode->pLeft = NULL;
        pNode->pRight = NULL;
        tree = pNode;
    }
    else
    {
        if (tree->data > x)
            ThemNodeVaoCay(tree->pLeft, x);
        else if (tree->data < x)
            ThemNodeVaoCay(tree->pRight, x);
    }
}

void Nhap(TREE& tree)
{
    int n, x;
    cout << "\nNhap vao so phan tu cua cay >> ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu x >> ";
        cin >> x;
        ThemNodeVaoCay(tree, x);
    }
}

void XuatNLR(TREE tree)
{
    if (tree)
    {
        cout << tree->data << ' ';
        XuatNLR(tree->pLeft);
        XuatNLR(tree->pRight);
    }
}

NODE* TimKiem(TREE tree, int x)
{
    // Nếu cây rỗng
    if (!tree)
        return NULL;
    else
    {
        // Nếu phần tử cần tìm kiếm nhỏ hơn node root
        if (x < tree->data)
            TimKiem(tree->pLeft, x);
        else if (x > tree->data)
            TimKiem(tree->pRight, x);
        else    // tree.data == x
            return tree;
    }
}

int main()
{
    TREE tree;
    KhoiTaoCay(tree);
    Nhap(tree);
    XuatNLR(tree);
    cout << "\n Nhap phan tu can tim kiem >> ";
    int x;
    cin >> x;
    NODE* pNode = TimKiem(tree, x);
    if (!tree)
        cout << "\nPhan tu " << x << " khong ton tai trong cay";
    else
        cout << "\nPhan tu " << x << " ton tai trong cay";
    return 1;
}