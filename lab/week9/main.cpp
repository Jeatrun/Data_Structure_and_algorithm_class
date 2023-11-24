#include "TsMatrix.h"
int main()
{
    ElemType a[M][N] = {
        {0, 2, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 05, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 20, 0, 0, 0, 6, 0},
        {0, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},

    };
    TsMatrix om, tm;
    CreateMatrix(om, a);
    Disp(om);
    DisplaySparseMatrix(a);
    TranTat(om,tm);
    Disp(tm);
    SparseToDense(tm);
    DisplaySparseMatrix(b);
}