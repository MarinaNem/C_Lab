#include "BinaryTree.h"

void BinaryTree::Insert(int value, TreeNode* currentNode) 
{
	while (currentNode)
	{
		if (value == currentNode->GetValue()) return; //If the value exists, then do nothing / Если значение существует, то ничего не делаем
		else if (value > currentNode->GetValue()) //If the value is greater, then go along the right branch / Если значение больше, то идем по правой ветви
		{
			if (currentNode->GetRightChild()) //Is there a child of the current node on the right / Существует ли справа потомок текущего узла
			{
				currentNode = currentNode->GetRightChild(); //We move to this descendant / Перемещаемся на этого потомка
			}
			else //Otherwise, create a new one at this place / Иначе создаем нового на этом месте
			{
				currentNode->SetRightChild(new TreeNode(value));
				return;
			}
		}
		else //Otherwise, go along the left branch / Иначе идем по левой ветви
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

		if (value == currentValue) return currentNode; //If you find a node, then return / Если нашли узел, то возвращаем
		else if (value > currentValue) //If the value is greater, search on the right / Если значение больше, ищем справа
		{
			if (right == nullptr) return nullptr; //If there is nothing on the right, then return nullptr / Если справа ничего нет, то возвращаем nullptr
			else currentNode  = right; //Otherwise, move to the right / Иначе передвигаемся вправо
		}
		else //The value is less, so we are looking on the left / Значение меньше, значит ищем слева
		{
			if (left == nullptr) return nullptr;
			else currentNode = left;
		}
	}
}

void BinaryTree::DestroyTree(TreeNode* root) //Recursive destruction of all tree nodes / Рекурсивное уничтожение всех узлов дерева
{
	if (root)
	{
		DestroyTree(root->GetLeftChild());
		DestroyTree(root->GetRightChild());
		delete root;
	}
}
