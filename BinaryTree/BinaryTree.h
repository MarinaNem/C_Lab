#pragma once
#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree()
	{
		rootNode = new TreeNode();
	}

	BinaryTree(int value)
	{
		rootNode = new TreeNode(value);
	}

	~BinaryTree()
	{
		DestroyTree(rootNode);
	}

	void Insert(int value) { Insert(value, rootNode); };
	TreeNode* Search(int value) const { return Search(value, rootNode); };

private:
	TreeNode* rootNode;
	void DestroyTree(TreeNode* root);
	TreeNode* Search(int value, TreeNode* currentNode) const;
	void Insert(int value, TreeNode* currentNode);
};
