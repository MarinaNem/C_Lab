#include "TreeNode.h"
#include <cassert>

bool TreeNode::isTerminal(TreeNode node) // ��������� �������� �� ������� ������������
{
	return (childQty(node) == 0 || node.field.checkFieldStatus() != PlayField::fsNormal);
}

void TreeNode::addChild(TreeNode* node, TreeNode* child) // ��������� ������ �������
{
	assert(childQty(*node) != 0);
	child->parent = node;
	TreeNode n = *node;
	n.children.push_back(child);
}

int TreeNode::childCount(const TreeNode node) // ���������� ���������� �������� � ������ �������
{
	return node.children.size();
}

const PlayField& TreeNode::value(const TreeNode node) // ��������� ���� � ������ �������
{
	return node.field;
}

TreeNode& TreeNode::operator[](int index)
{
	return *children[index];
}

int TreeNode::childQty(const TreeNode node) // ���������� ��������� ���������� �������� �� ������ ������
{
	PlayField field = node.field;
	return field.getEmptyCells().size();
}
