#include <iostream>
#include "BinaryTree.h"

using namespace std;
//Немытова Марина РИ-280002
//Nemytova Marina RI-280002

TreeNode* CreateMinimalBST(int* arr, int startIndex, int endIndex)
{
    arr += startIndex;
    int middleIndex = (endIndex + startIndex) / 2;
    int middle = *(arr + middleIndex - startIndex);
    arr -= startIndex;
    TreeNode* node = new TreeNode(middle);
    if (endIndex < startIndex) return nullptr;
    node->SetLeftChild(CreateMinimalBST(arr, startIndex, middleIndex - 1));
    node->SetRightChild(CreateMinimalBST(arr, middleIndex + 1, endIndex));
    return node;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int* startArr = arr;
    int startIndex = 0;
    int endIndex = 8;

    startArr += startIndex;
    int middleIndex = (endIndex - startIndex) / 2;
    int middle = *(arr + middleIndex);
    BinaryTree* tree = new BinaryTree(middle);
    TreeNode* root = tree->GetRootNode();
    root->SetLeftChild(CreateMinimalBST(startArr, startIndex, middleIndex - 1));
    root->SetRightChild(CreateMinimalBST(startArr, middleIndex + 1, endIndex));
    BinaryTree Btree = *tree;
    TreeNode* node = Btree.Search(5);
    if (node) cout << "Address "<< node << "  Value " << node->GetValue();
    else cout << "Nothing found";
}
