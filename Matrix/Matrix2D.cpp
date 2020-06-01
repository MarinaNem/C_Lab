#include "Matrix2D.h"

int Matrix2D::element(unsigned int i, unsigned int j) const
{
	return matrix[i + m2D_size * j];
}

int& Matrix2D::element(unsigned int i, unsigned int j)
{
	return matrix[i + m2D_size * j];
}
