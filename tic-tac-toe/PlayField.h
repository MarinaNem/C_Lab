#pragma once
#include <vector>
#include <cassert>
class PlayField {
public:
    enum squareState { csEmpty, csCross, csNought }; // Состояние клетки
    enum FieldStatus { fsInvalid, fsNormal, fsCrossesWin, fsNoughtsWin, fsDraw }; // Состояние игры


    class CellIdx //Положение клетки на поле
    {
    public:
         static CellIdx GetCellIdx(const int id)
         {
            assert(id >= 0 || id < 9);
            int line = 0;
            int column = 0;
            line = id / 3;
            column = id % 3;
            return CellIdx(line, column);
         }
         CellIdx(const int line, const int column) 
         {
            assert(line > 0 || column > 0 || line <= 2 || column <= 2);
            lineC = line; 
            columnC = column;
            idC = lineC * 3 + columnC;
         }

        int GetId() { return idC; }
        int GetLine() { return lineC; }
        int GetColumn() { return columnC; }
    private:

        int lineC;
        int columnC;
        int idC;
    };
    squareState fieldState[9]{ csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty }; //Состояние поля
    std::vector<CellIdx*> getEmptyCells(); //Возвращает все пустые позиции клеток
    PlayField makeMove(const CellIdx square); // Делает ход на поле
    FieldStatus checkFieldStatus(); // Определяет состояние поля

private:
    squareState mark = csCross; //Текущая метка
    squareState operator[](CellIdx square);
    PlayField operator+(CellIdx square);
    bool hasMoves(); // Проверка наличия ходов
    bool checkWin(const PlayField::squareState mark, PlayField::squareState* fieldState); // Выполняет проверку выигрыша
    bool hasHorizontal(const PlayField::squareState mark, PlayField::squareState* fieldState); // Проверка выигрыша в горизонтальной линии
    bool hasVertical(const PlayField::squareState mark, PlayField::squareState* fieldState); // Проверка выигрыша в вертикальной линии
    bool hasDiagonal(const PlayField::squareState mark, PlayField::squareState* fieldState); // Проверка выигрыша в диагональной линии
};