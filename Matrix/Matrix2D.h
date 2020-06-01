#pragma once
#include "MatrixBase.h"

class Matrix2D :public MatrixBase
{
public:
    Matrix2D() : MatrixBase(m2D_size) {};
    virtual int element(unsigned int i, unsigned int j) const override;
    virtual int& element(unsigned int i, unsigned int j) override;
private:
    int matrix[m2D_size * m2D_size];
};
