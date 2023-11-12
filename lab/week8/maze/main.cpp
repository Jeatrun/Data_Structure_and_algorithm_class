#include <stdio.h>
#include <stdlib.h>
#include "Recursion.h"

int main()
{
    mazeCord path[(M + 2) * (N + 2)];
    int pathIndex = 0;
    int mg[M + 2][N + 2] = {
        1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 1, 1,
        1, 0, 1, 0, 0, 1,
        1, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1};
    FindMaze(1, 1, 4, 4, path, &pathIndex, mg);
    Display(path, pathIndex);
    return 0;
}