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

void XoaNode(TREE& tree, int x)
{
    if (!tree)
        return;
    else
    {
        if (x < tree->data)
            XoaNode(tree->pLeft, x);
        else if (x > tree->data)
            XoaNode(tree->pRight, x);
        else
        {
            NODE* temp = tree;
            // Nếu không có cây con trái
            if (!tree->pLeft)
                tree = tree->pRight;
            // Nếu không có cây con phải
            else if (!tree->pRight)
                tree = tree->pLeft;
            delete temp;
        }
    }
}

int main()
{
    TREE tree;
    KhoiTaoCay(tree);
    Nhap(tree);
    XuatNLR(tree);
    cout << "\nNhap vao gia tri can xoa >> ";
    int x;
    cin >> x;
    XoaNode(tree, x);
    XuatNLR(tree);
    return 1;
}