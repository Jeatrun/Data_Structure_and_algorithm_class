#include "binaryTree.h"

int main(){
    char str[]="A(B(D(,G)),C(E,F))";
    btNode *bt;
    createBT(bt, str);
    DispBT(bt);
    return 0;


}