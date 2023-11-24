#include "stdio.h"
#include "stdlib.h"
#include <cstdlib>
#define MaxSize 100
#define M 8
#define N 8
typedef int ElemType;
ElemType b[M][N]; // 定义全局变量
typedef struct
{
    int r;
    int c;
    ElemType d;
} TupNode;

typedef struct
{
    int rows;
    int cols;
    int nums;
    TupNode data[MaxSize];
} TsMatrix;
void DisplaySparseMatrix(ElemType a[M][N])
{
    // 打印矩阵
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void CreateMatrix(TsMatrix &m, ElemType a[M][N])
{
    m.rows = M;
    m.cols = N;
    m.nums = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] != 0)
            {
                m.data[m.nums].r = i;
                m.data[m.nums].c = j;
                m.data[m.nums].d = a[i][j];
                m.nums++;
            }
        }
    }
}

void Disp(TsMatrix m)
{
    printf("\t %d \t %d \t %d \n", m.rows, m.cols, m.nums);
    printf("----------------------------\n");
    for (int k = 0; k < m.nums; k++)
    {
        printf("\t %d \t %d \t %d \n", m.data[k].r, m.data[k].c, m.data[k].d);
    }
}
void TranTat(TsMatrix t, TsMatrix &tb)
{
    int p, q = 0, v; //
    tb.rows = t.cols;
    tb.cols = t.rows;
    tb.nums = t.nums;
    if (t.nums != 0) //
    {
        for (v = 0; v < t.cols; v++)
            //
            for (p = 0; p < t.nums; p++) //
                if (t.data[p].c == v)
                {
                    tb.data[q].r = t.data[p].c;
                    tb.data[q].c = t.data[p].r;
                    tb.data[q].d = t.data[p].d;
                    q++;
                }
    }
}
void SparseToDense(TsMatrix m)
{
    // 初始化二维矩阵
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            b[i][j] = 0;
        }
    }

    // 将稀疏矩阵的值填入二维矩阵
    for (int k = 0; k < m.nums; k++)
    {
        b[m.data[k].r][m.data[k].c] = m.data[k].d;
    }
}
