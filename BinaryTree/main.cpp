#include <iostream>
#include "BinaryTree.h"

using namespace std;
//Немытова Марина РИ-280002
//Nemytova Marina RI-280002

void CreateTree(int* arr, BinaryTree* tree, int startIndex, int endIndex) // Recursive tree creation method (Рекурсивный метод создания дерева)
{
    if (endIndex < startIndex) return;
    arr += startIndex;
    int middleIndex = (endIndex + startIndex) / 2;
    int middle = *(arr + middleIndex - startIndex);
    tree->Insert(middle);
    arr -= startIndex;
    CreateTree(arr, tree, startIndex, middleIndex-1);
    CreateTree(arr, tree, middleIndex+1, endIndex);
} 

BinaryTree* CreateMinimalBST(int* arr, int startIndex, int endIndex)
{ 
    //Create a tree with a root - an element in the middle of the array (Создаем дерево с корнем - элементом в середине массива)
    arr += startIndex;
    int middleIndex = (endIndex - startIndex) / 2;
    int middle = *(arr + middleIndex);
    BinaryTree* tree = new BinaryTree(middle); 
    CreateTree(arr, tree, startIndex, endIndex);
    return tree;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int* startArr = arr;
    BinaryTree* tree = CreateMinimalBST(startArr, 0, 8);
    BinaryTree Btree = *tree;
    TreeNode* node = Btree.Search(5);
    if (node) cout << "Address "<< node << "  Value " << node->GetValue();
    else cout << "Nothing found";
}
