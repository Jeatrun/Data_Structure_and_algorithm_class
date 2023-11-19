#include <stdio.h>
#include <stdlib.h>
#define  Maxsize 50
typedef struct{
    int matrix[Maxsize];
    
}Amatrix;

/*
0 1 1
1 0 1
1 1 0
*/
Amatrix createMatrix(int m[3][3],int num){
    Amatrix amatrix;
    int matrixIndex=0;
    for(int i=0;i<num;i++){
        for(int j=i;j<num;j++){
            amatrix.matrix[matrixIndex]=m[i][j];
            matrixIndex++;
        }

    }
    return amatrix;

}
void Disp(Amatrix amatrix,int num){
    // display the array directly
    for(int i=0;i<(num*(num+1)/2);i++){
        printf("%d ",amatrix.matrix[i]);
    }
    printf("\n");

   
}
