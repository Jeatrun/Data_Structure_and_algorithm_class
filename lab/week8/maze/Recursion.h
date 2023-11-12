#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
#define M 4
#define N 4

void FindMaze(int xi, int yi, int xe, int ye, SqStack *path, int mazeMap[M + 2][N + 2])
{

    int curX = xi, curY = yi;
    // base case
    if (curX == xe && curY == ye)
    {
        // what should the base case return?
        // push the cordinate to the path stack
        Push(path, curX, curY);
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
            Push(path, curX, curY);
            FindMaze(curX, curY + 1, xe, ye, path, mazeMap);
        }
        // if the right position couldn't reach,then move down;
        else if (mazeMap[curX + 1][curY] == 0)
        {
            mazeMap[curX][curY] = -1;
            Push(path, curX, curY);
            FindMaze(curX + 1, curY, xe, ye, path, mazeMap);
        }

        // if the down position couldn't reach,then move left;
        else if (mazeMap[curX][curY - 1] == 0)
        {

            mazeMap[curX][curY] = -1;
            Push(path, curX, curY);
            FindMaze(curX, curY - 1, xe, ye, path, mazeMap);
        }
        // if the left position couldn't reach,then move up;
        else if (mazeMap[curX - 1][curY] == 0)
        {
            mazeMap[curX][curY] = -1;
            Push(path, curX, curY);
            FindMaze(curX - 1, curY, xe, ye, path, mazeMap);
        }
        // if both derections couldn't reach,then go back and mark this position to 1 ;

        else
        {
            mazeMap[curX][curY] = 1;
            int preX, preY;
            // get the previous cord from the stack
            GetTop(path, preX, preY);
            FindMaze(preX, preY, xe, ye, path, mazeMap);
        }
    }
}