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

//void Max(TREE tree, int& max)
//{
//    if (tree)
//    {
//        if (max < tree->data)
//            max = tree->data;
//        Max(tree->pLeft, max);
//        Max(tree->pRight, max);
//    }
//}

int Max(TREE tree)
{
    // Node phải cùng == max
    if (!tree->pRight)
        return tree->data;
    
    //// Gán giá trị node cha = max
    //int max = tree->data;

    //// Nếu node cha có tồn tại cây con trái
    //if (tree)
    //{
    //    // Giá trị trái cùng của node cha
    //    int leftVal = Max(tree->pLeft);
    //    if (max < leftVal)
    //        max = leftVal;
    //}

    //// Nếu node cha có tồn tại cây con phải
    //if (tree)
    //{
    //    // Giá trị phải cùng của node cha
    //    int rightVal = Max(tree->pLeft);
    //    if (max < rightVal)
    //        max = rightVal;
    //}
    return Max(tree->pRight);
}

int main()
{
    TREE tree;
    KhoiTaoCay(tree);
    Nhap(tree);
    XuatNLR(tree);
    /*int max = INT_MIN;
    Max(tree, max);
    cout << "\nMax = " << max;*/
    return 1;
}