#include "stdio.h"
#include "stdlib.h"
#include <cstdlib>
#define MaxSize 100
#define M 8
#define N 8
typedef int ElemType;

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

void CreateMatrix(TsMatrix &m, ElemType a[M][N])
{
    m.rows = 0;
    m.cols = 0;
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
void FastTranspose(TsMatrix &tm, TsMatrix om)
{

    tm.rows = om.cols;
    tm.cols = om.rows;
    tm.nums = om.nums;

    // create 2 arrays
    int num[MaxSize], pos[MaxSize];

    // init the arrays
    for (int i = 0; i < MaxSize; i++)
    {
        num[i] = 0;
        pos[i] = 0;
    }
    // ergodic all  the nodes
    for (int i = 0; i < om.nums; i++)
    {
        // store the col to the numArr
        num[om.data[i].c]++;
    }

    int colN = 0;
    // count the number for each col in numArr from the Tsmatrix
    for (int i = 1; i < om.nums; i++)
    {
        pos[i] = colN;
        colN += num[i];
    }

    // convert the row and col in om to tm
    int curOcol = 0, curTrow = 0;
    for (int i = 0; i < om.nums; i++)
    {
        curOcol = om.data[i].c;
        curTrow = pos[curOcol];
        tm.data[curTrow].r = om.data[curOcol].c;
        tm.data[curTrow].c = om.data[curOcol].r;
        tm.data[curTrow].d = om.data[curOcol].d;
        ++curTrow;
    }
}