#include "stdio.h"
#include "stdlib.h"
#include <cstdlib>
#define MaxSize 100
#define M 8
#define N 8
typedef int ElemType;

typedef struct {
    int r;
    int c;
    ElemType d;
} TupNode;

typedef struct {
    int rows;
    int cols;
    int nums;
    TupNode data[MaxSize];
}TsMatrix;

void CreateMatrix(TsMatrix &m,ElemType a[M][N]) {
    m.rows = 0;
    m.cols = 0;
    m.nums = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(a[i][j]!=0){
               m.data[m.nums].r = i;
               m.data[m.nums].c = j;
               m.data[m.nums].d = a[i][j];
               m.nums++;
            }
        }

    }

}

void Disp(TsMatrix m){
    printf("\t %d \t %d \t %d \n",m.rows,m.cols,m.nums);
    printf("----------------------------\n");
    for(int k=0;k<m.nums;k++){
        printf("\t %d \t %d \t %d \n",m.data[k].r,m.data[k].c,m.data[k].d);
    }
}void Transpose(TsMatrix &m) {
  //¿ìËÙ×ªÖÃ




   m = t;
}