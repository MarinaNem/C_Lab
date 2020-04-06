#include "TreeNode.h"
#include <cassert>

bool TreeNode::isTerminal(TreeNode node) const // Проверяет является ли вершина терминальной
{
	return (childQty(node) == 0 || node.field.checkFieldStatus() != PlayField::fsNormal);
}

void TreeNode::addChild(TreeNode* node, TreeNode* child) // Добавляет нового потомка
{
	assert(childQty(*node) != 0);
	child->parent = node;
	TreeNode n = *node;
	n.children.push_back(child);
}

int TreeNode::childCount(TreeNode node) const // Определяет количество потомков у данной вершины
{
	return node.children.size();
}

const PlayField& TreeNode::value(TreeNode node) // Состояние поля в данной вершине
{
	return node.field;
}

TreeNode& TreeNode::operator[](int index)
{
	return *children[index];
}

int TreeNode::childQty(const TreeNode node) const // Определяет возможное количество потомков на данном уровне
{
	PlayField field = node.field;
	return field.getEmptyCells().size();
}
