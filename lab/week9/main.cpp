#include "TsMatrix.h"
int main(){
    ElemType a[M][N]={
        {0,-3,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,37,0,11,0,0,0}, 
        {0,0,0,0,0,0,0,0},
        {0,9,0,2,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,88,0,0,0,0},

    };
    TsMatrix Ts;
    CreateMatrix(Ts,a);
    Disp(Ts);
    Transpose(Ts);
    Disp(Ts);

}