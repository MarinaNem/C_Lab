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

	bool isTerminal(TreeNode node) const; // Проверяет является ли вершина терминальной
	void addChild(TreeNode* node, TreeNode* child); // Добавляет нового потомка
	int childCount(TreeNode node) const; // Определяет количество потомков у данной вершины
	const PlayField& value(TreeNode node); // Состояние поля в данной вершине
	TreeNode& operator[](int index);
	int GetLevel(TreeNode node) const { return childQty(node); };
private:
	int childQty(TreeNode node) const; // Определяет возможное количество потомков на данном уровне
	std::vector<TreeNode*> children; 
	TreeNode* parent; 
	PlayField field; 
};