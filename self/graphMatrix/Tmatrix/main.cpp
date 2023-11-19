#include "triangularMatrix.h"

int main(){
    Amatrix amatrix;
    int matrix[3][3]={
        0,1,1,
        1,0,1,
        1,1,0};
    amatrix=createMatrix(matrix, 3);
    
    Disp(amatrix, 3);

}
