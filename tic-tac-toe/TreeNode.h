#pragma once
#include "PlayField.h"

class TreeNode
{
public:
	TreeNode(const PlayField newField, TreeNode* newParent)
	{
		field = newField;
		parent = newParent;
	}

	bool isTerminal(const TreeNode node); // ��������� �������� �� ������� ������������
	void addChild(TreeNode* node, TreeNode* child); // ��������� ������ �������
	int childCount(const TreeNode node); // ���������� ���������� �������� � ������ �������
	const PlayField& value(TreeNode node); // ��������� ���� � ������ �������
	TreeNode& operator[](int index);
	int GetLevel(const TreeNode node) { return childQty(node); };
private:
	int childQty(const TreeNode node); // ���������� ��������� ���������� �������� �� ������ ������
	std::vector<TreeNode*> children; 
	TreeNode* parent = nullptr; 
	PlayField field; 
};