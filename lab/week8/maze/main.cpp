#include <stdio.h>
#include <stdlib.h>
#include "Recursion.h"
#include "SqStack.h"

int main()
{
    SqStack *path;
    InitStack(path);
    int mg[M + 2][N + 2] = {
        1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 1, 1,
        1, 0, 1, 0, 0, 1,
        1, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1};
    FindMaze(1, 1, 4, 4, path, mg);
    DisplayStack(path);
    return 0;
}