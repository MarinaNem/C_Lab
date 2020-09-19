#pragma once
#include <fstream>

constexpr unsigned int m2D_size = 2;
constexpr unsigned int m3D_size = 3;

class MatrixBase
{
public:
    unsigned int size() const; //���������� ������ �������
    virtual int element(unsigned int i, unsigned int j) const = 0; //���������� ������� �������
    virtual int& element(unsigned int i, unsigned int j) = 0; //���������� ������ �� ������� �������
    void operator*=(int iMult); //��������� �� ��������� iMult
    void operator+=(MatrixBase* iAdd); //�������� ������
    friend std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix);

protected:
    MatrixBase() = delete;
    MatrixBase(unsigned int iSize) : m_size(iSize){}

private:
    const unsigned int m_size;
};
