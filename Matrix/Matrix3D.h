#pragma once
#include "MatrixBase.h"

class Matrix3D :public MatrixBase
{
public:
    Matrix3D() : MatrixBase(m3D_size) {}
    virtual int element(unsigned int i, unsigned int j) const override;
    virtual int& element(unsigned int i, unsigned int j) override;
private:
    int matrix[m3D_size * m3D_size];
};
