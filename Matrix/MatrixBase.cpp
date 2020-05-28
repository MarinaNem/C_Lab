#include "MatrixBase.h"
#include <iostream>
using namespace std;

unsigned int MatrixBase::size() const
{
	return m_size;
}

void MatrixBase::operator*=(int iMult)
{
	for (unsigned int i = 0; i < m_size; i++)
		for(unsigned int j = 0; j < m_size; j++)
			element(i, j) *= iMult;
}

void MatrixBase::operator+=(MatrixBase* iAdd)
{
	for (unsigned int i = 0; i < m_size; i++)
		for (unsigned int j = 0; j < m_size; j++)
		{
			this->element(i, j) += (*iAdd).element(i, j);
		}
}

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix)
{
	unsigned int size = iMatrix.size();
	for (unsigned int i = 0; i < size; i++)
	{
		for (unsigned int j = 0; j < size; j++)
			stream << iMatrix.element(i, j) << " ";
		stream << std::endl;
	}
	return stream;
}

int Matrix2D::element(unsigned int i, unsigned int j) const
{
	return matrix[i + 2 * j];
}

int& Matrix2D::element(unsigned int i, unsigned int j)
{
	return matrix[i + 2 * j];
}

int Matrix3D::element(unsigned int i, unsigned int j) const
{
	return matrix[i + 3 * j];
}

int& Matrix3D::element(unsigned int i, unsigned int j)
{
	return matrix[i + 3 * j];
}
