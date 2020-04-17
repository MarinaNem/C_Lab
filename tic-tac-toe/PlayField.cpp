#include "PlayField.h"
#include <cassert>
using namespace std;

vector<PlayField::CellIdx*> PlayField::getEmptyCells() const //Возвращает все пустые позиции клеток
{
	vector<PlayField::CellIdx*> emptyCells;
	for (int i = 0; i < 9; i++)
	{
		if (fieldState[i] == csEmpty)
		{
			CellIdx cell = PlayField::CellIdx::GetCellIdx(i);
			emptyCells.push_back(&cell);
		}
	}
	return emptyCells;
}

PlayField PlayField::makeMove(CellIdx square) // Делает ход на поле
{
	if (mark == PlayField::csCross) mark = PlayField::csNought; //Смена метки
	else mark = PlayField::csCross;
	PlayField field = *this;
	int id = square.GetId();
	assert(fieldState[id] == csEmpty || checkFieldStatus() == fsNormal);
	field.fieldState[id] = mark; //Пометка соответствующей клетки
	return field;
}

PlayField::FieldStatus PlayField::checkFieldStatus() // Определяет состояние поля
{
	if(checkWin(csCross, fieldState)) return fsCrossesWin; //Проверка победы крестика
	if(checkWin(csNought, fieldState)) return fsNoughtsWin; //Проверка победы нолика
	auto emptyCells = getEmptyCells();
	if (emptyCells.empty()) return fsDraw; //Проверка на ничью
	if (hasMoves()) return fsNormal; //Проверка наличия ходов
	else return fsInvalid;
}

bool PlayField::checkWin(PlayField::squareState mark,PlayField::squareState* fieldState) const // Выполняет проверку выигрыша
{
	if (hasHorizontal(mark, fieldState) || hasVertical(mark, fieldState) || hasDiagonal(mark, fieldState))
		return true;
	else return false;
}

bool PlayField::hasHorizontal(PlayField::squareState mark,PlayField::squareState* fieldState) const // Проверка выигрыша в горизонтальной линии
{
	for (int i = 0; i < 3; i++)
		if (fieldState[0 + i * 3] == mark && fieldState[1 + i * 3] == mark && fieldState[2 + i * 3] == mark)
			return true;
	return false;
}

bool PlayField::hasVertical(PlayField::squareState mark,PlayField::squareState* fieldState) const // Проверка выигрыша в вертикальной линии
{
	for (int i = 0; i < 3; i++)
		if (fieldState[0 + i] == mark && fieldState[3 + i] == mark && fieldState[6 + i] == mark)
			return true;
	return false;
}

bool PlayField::hasDiagonal(PlayField::squareState mark, PlayField::squareState* fieldState) const // Проверка выигрыша в диагональной линии
{
	if (fieldState[0] == mark && fieldState[4] == mark && fieldState[8] == mark ||
		fieldState[2] == mark && fieldState[4] == mark && fieldState[6] == mark)
		return true;
	return false;
}

bool PlayField::hasMoves() const // Проверка наличия ходов
{
	int cross = 0;
	int nought = 0;
	for (int i = 0; i < 9; i++)
	{
		if (fieldState[i] == csCross) cross++;
		if (fieldState[i] == csNought) nought++;
	}
	return abs(cross - nought) < 2;
}

PlayField::squareState PlayField::operator[](CellIdx square)
{
	return fieldState[square.GetId()];
}

PlayField PlayField::operator+(CellIdx square)
{

	makeMove(square);
	return *this;
}
