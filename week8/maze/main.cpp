/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "mgpath.h"

int main(){
    int mg[M+2][N+2]={
        1,1,1,1,1,1,
        1,0,0,0,1,1,
        1,0,1,0,0,1,
        1,0,0,0,1,1,
        1,1,0,0,0,1,
        1,1,1,1,1,1
    }
    PathType path;
    path.length=0;
    mgpath(1,1,M,N,mg,path);

}