#include <iostream>
#include "BinaryTree.h"

using namespace std;
//Немытова Марина РИ-280002
//Nemytova Marina RI-280002

TreeNode* CreateMinimalBST(int* arr, BinaryTree* tree, int startIndex, int endIndex)
{
    if (endIndex < startIndex) return tree->GetRootNode();
    arr += startIndex;
    int middleIndex = (endIndex + startIndex) / 2;
    int middle = *(arr + middleIndex - startIndex);
    tree->Insert(middle);
    arr -= startIndex;
    CreateMinimalBST(arr, tree, startIndex, middleIndex - 1);
    CreateMinimalBST(arr, tree, middleIndex + 1, endIndex);
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
    TreeNode* root = CreateMinimalBST(startArr,tree, 0, 8);
    BinaryTree Btree = *tree;
    TreeNode* node = Btree.Search(5);
    if (node) cout << "Address "<< node << "  Value " << node->GetValue();
    else cout << "Nothing found";
}
