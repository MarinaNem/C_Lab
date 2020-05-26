#pragma once
#include <fstream>

class MatrixBase
{
public:
    unsigned int size() const { return m_size; } //Возвращает размер матрицы
    virtual int element(unsigned int i, unsigned int j) const; //Возвращает элемент матрицы
    virtual int& element(unsigned int i, unsigned int j); //Возвращает ссылку на элемент матрицы
    void operator*=(int iMult); //Умножение на константу iMult
    void operator+=(MatrixBase iAdd); //Сложение матриц
    friend std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix);

protected:
    MatrixBase() = delete;
    MatrixBase(unsigned int iSize) : m_size(iSize) 
    {
        matrix = new unsigned int[iSize * iSize];
        for (unsigned int i = 0; i < m_size; i++)
            for (unsigned int j=0; j<m_size;j++)
        {
           this->element(i,j) = 0;
        }
    }

private:
    const unsigned int m_size;
    unsigned int* matrix;
};

class Matrix2D :public MatrixBase
{
public:
    Matrix2D() : MatrixBase(2) {}
private:
};

class Matrix3D :public MatrixBase
{
public:
    Matrix3D() :MatrixBase(3) {}
};