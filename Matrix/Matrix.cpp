#include <iostream>
#include "MatrixBase.h"
using namespace std;

//RI-280002 Nemytova Marina

int main()
{
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;

    int val = 1;
    for (int i = 0; i < m2a.size(); i++)
        for (int j = 0; j < m2a.size(); j++)
        {
            m2a.element(i, j) = val;
            m2b.element(i, j) = val;
            val++;
        }

    val = 1;
    for (int i = 0; i < m3a.size(); i++)
        for (int j = 0;j < m3a.size(); j++)
        {
            m3a.element(i, j) = val;
            m3b.element(i, j) = val;
            val++;
        }

    cout << m2a << endl;
    cout << m2b << endl;

    cout << m3a << endl;
    cout << m3b << endl;

    return 0;
}
