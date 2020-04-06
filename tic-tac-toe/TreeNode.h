#pragma once
#include "PlayField.h"

class TreeNode
{
public:
	TreeNode(PlayField newField, TreeNode* newParent)
	{
		field = newField;
		parent = newParent;
	}

	bool isTerminal(TreeNode node) const; // ��������� �������� �� ������� ������������
	void addChild(TreeNode* node, TreeNode* child); // ��������� ������ �������
	int childCount(TreeNode node) const; // ���������� ���������� �������� � ������ �������
	const PlayField& value(TreeNode node); // ��������� ���� � ������ �������
	TreeNode& operator[](int index);
	int GetLevel(TreeNode node) const { return childQty(node); };
private:
	int childQty(TreeNode node) const; // ���������� ��������� ���������� �������� �� ������ ������
	std::vector<TreeNode*> children; 
	TreeNode* parent; 
	PlayField field; 
};