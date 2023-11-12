#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 4
typedef struct
{
    int i;
    int j;
} mazeCord;
void FindMaze(int xi, int yi, int xe, int ye, mazeCord path[], int *pathIndex, int mazeMap[M + 2][N + 2])
{
    int curX = xi, curY = yi;
    // base case
    if (curX == xe && curY == ye)
    {
        // push the coordinate to the path
        path[*pathIndex].i = curX;
        path[*pathIndex].j = curY;
        (*pathIndex)++;
        // change the path to be -1
        mazeMap[curX][curY] = -1;
        return;
    }
    else
    {
        // if the posistion is not the exit,then move right
        if (mazeMap[curX][curY + 1] == 0)
        {
            mazeMap[curX][curY] = -1;
            path[*pathIndex].i = curX;
            path[*pathIndex].j = curY;
            (*pathIndex)++;
            FindMaze(curX, curY + 1, xe, ye, path, pathIndex, mazeMap);
        }
        // if the right position couldn't reach,then move down;
        else if (mazeMap[curX + 1][curY] == 0)
        {
            mazeMap[curX][curY] = -1;
            path[*pathIndex].i = curX;
            path[*pathIndex].j = curY;
            (*pathIndex)++;
            FindMaze(curX + 1, curY, xe, ye, path, pathIndex, mazeMap);
        }

        // if the down position couldn't reach,then move left;
        else if (mazeMap[curX][curY - 1] == 0)
        {
            mazeMap[curX][curY] = -1;
            path[*pathIndex].i = curX;
            path[*pathIndex].j = curY;
            (*pathIndex)++;
            FindMaze(curX, curY - 1, xe, ye, path, pathIndex, mazeMap);
        }
        // if the left position couldn't reach,then move up;
        else if (mazeMap[curX - 1][curY] == 0)
        {
            mazeMap[curX][curY] = -1;
            path[*pathIndex].i = curX;
            path[*pathIndex].j = curY;
            (*pathIndex)++;
            FindMaze(curX - 1, curY, xe, ye, path, pathIndex, mazeMap);
        }
        // if both derections couldn't reach,then go back and mark this position to 1 ;
        else
        {
            mazeMap[curX][curY] = 1;
            (*pathIndex)--;
            FindMaze(path[*pathIndex].i, path[*pathIndex].j, xe, ye, path, pathIndex, mazeMap);
        }
    }
}

void Display(mazeCord path[], int pathIndex)
{
    for (int i = 0; i < pathIndex; i++)
    {
        printf("[%d, %d]\n", path[i].i, path[i].j);
    }
}