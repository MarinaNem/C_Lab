#pragma once
#include <vector>
#include <cassert>
class PlayField {
public:
    enum squareState { csEmpty, csCross, csNought }; // ��������� ������
    enum FieldStatus { fsInvalid, fsNormal, fsCrossesWin, fsNoughtsWin, fsDraw }; // ��������� ����


    class CellIdx //��������� ������ �� ����
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
    squareState fieldState[9]{ csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty }; //��������� ����
    std::vector<CellIdx*> getEmptyCells(); //���������� ��� ������ ������� ������
    PlayField makeMove(const CellIdx square); // ������ ��� �� ����
    FieldStatus checkFieldStatus(); // ���������� ��������� ����

private:
    squareState mark = csCross; //������� �����
    squareState operator[](CellIdx square);
    PlayField operator+(CellIdx square);
    bool hasMoves(); // �������� ������� �����
    bool checkWin(const PlayField::squareState mark, PlayField::squareState* fieldState); // ��������� �������� ��������
    bool hasHorizontal(const PlayField::squareState mark, PlayField::squareState* fieldState); // �������� �������� � �������������� �����
    bool hasVertical(const PlayField::squareState mark, PlayField::squareState* fieldState); // �������� �������� � ������������ �����
    bool hasDiagonal(const PlayField::squareState mark, PlayField::squareState* fieldState); // �������� �������� � ������������ �����
};