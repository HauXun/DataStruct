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

// Xuất node có 2 lá
void XuatNode2La(TREE tree)
{
    if (tree)
    {
        if (tree->pLeft && tree->pRight)
            cout << tree->data << ' ';
        XuatNode2La(tree->pLeft);
        XuatNode2La(tree->pRight);
    }
}

// Xuất node có 1 lá
void XuatNode1La(TREE tree)
{
    if (tree)
    {
        if ((tree->pLeft && !tree->pRight) || (!tree->pLeft && tree->pRight))
            cout << tree->data << ' ';
        XuatNode1La(tree->pLeft);
        XuatNode1La(tree->pRight);
    }
}

// Xuất node lá
void XuatNodeLa(TREE tree)
{
    if (tree)
    {
        if (!tree->pLeft && !tree->pRight)
            cout << tree->data << ' ';
        XuatNodeLa(tree->pLeft);
        XuatNodeLa(tree->pRight);
    }
}

int main()
{
    TREE tree;
    KhoiTaoCay(tree);
    Nhap(tree);
    XuatNLR(tree);
    cout << "\n Node co 2 la: ";
    XuatNode2La(tree);
    cout << "\n Node co 1 la: ";
    XuatNode1La(tree);
    cout << "\n Node la: ";
    XuatNodeLa(tree);
    return 1;
}