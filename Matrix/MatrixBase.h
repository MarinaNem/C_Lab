#pragma once
#include <fstream>

class MatrixBase
{
public:
    unsigned int size() const; //Возвращает размер матрицы
    virtual int element(unsigned int i, unsigned int j) const = 0; //Возвращает элемент матрицы
    virtual int& element(unsigned int i, unsigned int j) = 0; //Возвращает ссылку на элемент матрицы
    void operator*=(int iMult); //Умножение на константу iMult
    void operator+=(MatrixBase* iAdd); //Сложение матриц
    friend std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix);

protected:
    MatrixBase() = delete;
    MatrixBase(unsigned int iSize) : m_size(iSize){}

private:
    const unsigned int m_size;
};

class Matrix2D :public MatrixBase
{
public:
    Matrix2D() : MatrixBase(2) {};
    virtual int element(unsigned int i, unsigned int j) const override;
    virtual int& element(unsigned int i, unsigned int j) override;
private:
    int matrix[4]{ 0,0,0,0 };
};

class Matrix3D :public MatrixBase
{
public:
    Matrix3D() : MatrixBase(3){}
    virtual int element(unsigned int i, unsigned int j) const override;
    virtual int& element(unsigned int i, unsigned int j) override;
private:
    int matrix[9]{ 0,0,0,0,0,0 };
};