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

	bool isTerminal(const TreeNode node); // Проверяет является ли вершина терминальной
	void addChild(TreeNode* node, TreeNode* child); // Добавляет нового потомка
	int childCount(const TreeNode node); // Определяет количество потомков у данной вершины
	const PlayField& value(TreeNode node); // Состояние поля в данной вершине
	TreeNode& operator[](int index);
	int GetLevel(const TreeNode node) { return childQty(node); };
private:
	int childQty(const TreeNode node); // Определяет возможное количество потомков на данном уровне
	std::vector<TreeNode*> children; 
	TreeNode* parent = nullptr; 
	PlayField field; 
};