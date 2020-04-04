#include <iostream>
#include <vector>
#include "PlayField.h"
#include "TreeNode.h"
using namespace std;

// Немытова Марина РИ-280002
// Nemytova Marina RI-280002

int crossWin = 0;
int noughtWin = 0;
int drawCount = 0;

void printSquare(PlayField::squareState state) //Отрисовка символа
{
	if (state == PlayField::csCross) cout << "Х";
	if (state == PlayField::csNought) cout << "О";
	if (state == PlayField::csEmpty) cout << " ";
}

void drawField(PlayField field) //Отрисовка поля
{
	cout << " -------------" << endl;
	for (int line = 0; line <= 2; line++)
	{
		for (int column = 0; column <= 2; column++)
		{
			cout << " | ";
			int id = PlayField::CellIdx(line, column).GetId();
			printSquare(field.fieldState[id]);
		}
		cout << " | ";
		cout << "\n ------------- " << endl;
	}
	cout << endl;
}

void fieldWalk(TreeNode* node, PlayField field, PlayField::squareState mark);

bool CreateTree(PlayField field, TreeNode* node)
{
	if (node->isTerminal(*node)) //Если последняя нода, то проверяем как закончилась игра, иначе идем дальше
	{
		PlayField field = node->value(*node);
		auto status = field.checkFieldStatus();
		if (status != PlayField::fsNormal)
		{
			switch (status)
			{
			case PlayField::fsCrossesWin:
				crossWin++;
				break;
			case PlayField::fsNoughtsWin:
				noughtWin++;
				break;
			case PlayField::fsDraw:
				drawCount++;
				break;
			}
			return true;
		}
	}
	if (node->GetLevel(*node) % 2 == 0) fieldWalk(node, field, PlayField::squareState::csCross);
	else fieldWalk(node, field, PlayField::squareState::csNought);
}

void fieldWalk(TreeNode* node, PlayField field, PlayField::squareState mark) //Проход по полю
{
	for (int i = 0; i < 9; i++)
	{
		PlayField field = node->value(*node);
		if (field.fieldState[i] == PlayField::csEmpty)
		{
			PlayField newField = field.makeMove(PlayField::CellIdx::GetCellIdx(i)); //Делаем ход
			TreeNode childNode = TreeNode(newField, node); //Создаем потомка
			node->addChild(node, &childNode); //Добавляем потомка в дерево
			CreateTree(field, &childNode); //Создаем дерево
		}
		
	}
}

int main()
{
	PlayField field;
	setlocale(LC_ALL, "Russian");
	cout << "Программа определяет количество выигрышных, проигрышных и ничьих окончаний игры для первого хода." << endl;
	for (int i = 0; i < 9; i++)
	{
		field.fieldState[i] = PlayField::csCross;
		drawField(field);
		TreeNode* treeRoot = &TreeNode(field, nullptr);
		CreateTree(field, treeRoot); //Создаем дерево для сделанного первого хода
		cout << "Выигрышей: " << crossWin << endl;
		cout << "Проигрышей: " << noughtWin << endl;
		cout << "Ничьих: " << drawCount << endl;
		field.fieldState[i] = PlayField::csEmpty;
		crossWin = 0;
		noughtWin = 0;
		drawCount = 0;
	}
}