#include "Matrix3D.h"

int Matrix3D::element(unsigned int i, unsigned int j) const
{
	return matrix[i + m3D_size * j];
}

int& Matrix3D::element(unsigned int i, unsigned int j)
{
	return matrix[i + m3D_size * j];
}
