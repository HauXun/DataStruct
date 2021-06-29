#include <iostream>
#include <fstream>

using namespace std;

struct NODE
{
    int data;
    NODE* pLeft;
    NODE* pRight;
};
typedef NODE* TREE;

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

void XuatNLR(TREE tree)
{
    if (tree)
    {
        cout << tree->data << ' ';
        XuatNLR(tree->pLeft);
        XuatNLR(tree->pRight);
    }
}

void DocFile(TREE& tree, ifstream& in)
{
    int n;
    in >> n;
    for (int i = 0; i <= n; i++)
    {
        int x;
        in >> x;
        ThemNodeVaoCay(tree, x);    
    }
}

void DocFile_1(TREE& tree, ifstream& in)
{
    int x;
    char c;
    while (!in.eof())
    {
        in >> x;
        ThemNodeVaoCay(tree, x);
        in >> c;
    }
}

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

void XuatNode_1Con(TREE tree)
{
    if (tree)
    {
        if (!tree->pLeft && tree->pRight || tree->pLeft && !tree->pRight)
            cout << tree->data << ' ';
        XuatNode_1Con(tree->pLeft);
        XuatNode_1Con(tree->pRight);
    }
}

void XuatNode2Con(TREE tree)
{
    if (tree)
    {
        if (tree->pLeft && tree->pRight)
            cout << tree->data << ' ';
        XuatNode2Con(tree->pLeft);
        XuatNode2Con(tree->pRight);
    }
}

int Max(TREE tree)
{
    if (tree->pRight)
        Max(tree->pRight);
    else
        return tree->data;
}

int main()
{
    TREE tree;
    KhoiTaoCay(tree);

    ifstream in;
    in.open("data_1.txt", ios_base::in);

    //DocFile(tree, in);
    DocFile_1(tree, in);
    XuatNLR(tree);
    cout << "\nNode la\n";
    XuatNodeLa(tree);
    cout << "\nNode 1 con\n";
    XuatNode_1Con(tree);
    cout << "\nNode 2 con\n";
    XuatNode2Con(tree);
    cout << "\n Max >> " << Max(tree);
    in.close();
    return 1;
}