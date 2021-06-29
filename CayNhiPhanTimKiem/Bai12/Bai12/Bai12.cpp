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

void NodeThayThe(TREE& x, TREE& y)
{
    // C1
   /* if (y->pLeft)
        NodeThayThe(x, y->pLeft);
    else
    {
        // Cập nhập data của node thế chổ
        x->data = y->data;
        // Cho node x trỏ đến node thế chổ
        x = y;
        // Cập nhập mối liên kết cho node cha của node thế chổ với node con của node thế chổ
        y = y->pRight;
    }*/
    // C2
    if (y->pRight)
        NodeThayThe(x, y->pRight);
    else
    {
        // Cập nhập data của node thế chổ
        x->data = y->data;
        // Cho node x trỏ đến node thế chổ
        x = y;
        // Cập nhập mối liên kết cho node cha của node thế chổ với node con của node thế chổ
        y = y->pLeft;
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
            NODE* x = tree;
            // Nếu không có cây con trái
            if (!tree->pLeft)
                tree = tree->pRight;
            // Nếu không có cây con phải
            else if (!tree->pRight)
                tree = tree->pLeft;
            // Node 2 con
            else
            {
                // C1
                //NodeThayThe(x, tree->pRight);
                // C2
                NodeThayThe(x, tree->pLeft);
            }
            delete x;
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