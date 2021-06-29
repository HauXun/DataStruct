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

void XuatLRN(TREE tree)
{
    if (tree)
    {
        XuatLRN(tree->pLeft);
        XuatLRN(tree->pRight);
        cout << tree->data << ' ';
    }
}

int main()
{
    TREE tree;
    KhoiTaoCay(tree);
    Nhap(tree);
    XuatLRN(tree);
    return 1;
}