#pragma once

class TreeNode
{
public:
	TreeNode()
	{
		childLeft = nullptr;
		childRight = nullptr;
		value = 0;
	}

	TreeNode(int value)
	{
		this->value = value;
		childLeft = nullptr;
		childRight = nullptr;
	}

	//Getters, setters of value / Геттеры, сеттеры значения
	int GetValue() const { return value; };
	void SetValue(TreeNode* node, int value) { node->value = value; }

	//Getters, setters of children / Геттеры, сеттеры потомков
	TreeNode* GetLeftChild() const { return childLeft; };
	TreeNode* GetRightChild() const { return childRight; };
	void SetLeftChild(TreeNode* node) { this->childLeft = node; }
	void SetRightChild(TreeNode* node) { this->childRight = node; }

private:
	TreeNode* childLeft;
	TreeNode* childRight;
	int value;
};
