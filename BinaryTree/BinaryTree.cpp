#include "BinaryTree.h"

void BinaryTree::Insert(int value, TreeNode* currentNode) 
{
	while (currentNode)
	{
		if (value == currentNode->GetValue()) return; //If the value exists, then do nothing / ���� �������� ����������, �� ������ �� ������
		else if (value > currentNode->GetValue()) //If the value is greater, then go along the right branch / ���� �������� ������, �� ���� �� ������ �����
		{
			if (currentNode->GetRightChild()) //Is there a child of the current node on the right / ���������� �� ������ ������� �������� ����
			{
				currentNode = currentNode->GetRightChild(); //We move to this descendant / ������������ �� ����� �������
			}
			else //Otherwise, create a new one at this place / ����� ������� ������ �� ���� �����
			{
				currentNode->SetRightChild(new TreeNode(value));
				return;
			}
		}
		else //Otherwise, go along the left branch / ����� ���� �� ����� �����
		{
			if (currentNode->GetLeftChild())
			{
				currentNode = currentNode->GetLeftChild();
			}
			else
			{
				currentNode->SetLeftChild(new TreeNode(value));
				return;
			}
		}
	}
}

TreeNode* BinaryTree::Search(int value, TreeNode* currentNode) const
{
	while (currentNode)
	{
		int currentValue = currentNode->GetValue();
		TreeNode* left = currentNode->GetLeftChild();
		TreeNode* right = currentNode->GetRightChild();

		if (value == currentValue) return currentNode; //If you find a node, then return / ���� ����� ����, �� ����������
		else if (value > currentValue) //If the value is greater, search on the right / ���� �������� ������, ���� ������
		{
			if (right == nullptr) return nullptr; //If there is nothing on the right, then return nullptr / ���� ������ ������ ���, �� ���������� nullptr
			else currentNode  = right; //Otherwise, move to the right / ����� ������������� ������
		}
		else //The value is less, so we are looking on the left / �������� ������, ������ ���� �����
		{
			if (left == nullptr) return nullptr;
			else currentNode = left;
		}
	}
}

void BinaryTree::DestroyTree(TreeNode* root) //Recursive destruction of all tree nodes / ����������� ����������� ���� ����� ������
{
	if (root)
	{
		DestroyTree(root->GetLeftChild());
		DestroyTree(root->GetRightChild());
		delete root;
	}
}
