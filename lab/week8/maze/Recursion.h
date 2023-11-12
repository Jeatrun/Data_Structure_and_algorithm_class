#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
#define M 4
#define N 4


typedef struct
{
    int mazeMap[M+2][N+2];
    SqStack *path;

} maze;

void FindMaze(int xi, int yi, int xe, int ye, maze& maze)
{
    
    InitStack(maze.path);
    int curX = xi, curY = yi;
    // base case
    if (curX == xe && curY == ye)
    {
        // what should the base case return?
        //push the cordinate to the path stack
        Push(maze.path, curX, curY);
        //change the path to be -1
        maze.mazeMap[curX][curY] = -1;
        return;
    }
    else {
        //if the posistion is not the exit,then move right
        if(maze.mazeMap[curX][curY+1] == 0){
            maze.mazeMap[curX][curY] = -1;
            Push(maze.path, curX, curY);
            FindMaze(curX, curY+1, xe, ye, maze);
        }
        //if the right position couldn't reach,then move down;
        else if(maze.mazeMap[curX+1][curY] == 0){
            maze.mazeMap[curX][curY] = -1;           
            Push(maze.path, curX, curY);
            FindMaze(curX+1, curY, xe, ye, maze);
        }

        //if the down position couldn't reach,then move left;
        else if(maze.mazeMap[curX][curY-1] == 0){
            
            maze.mazeMap[curX][curY] = -1;
            Push(maze.path, curX, curY);
            FindMaze(curX, curY-1, xe, ye, maze);
        }
        //if the left position couldn't reach,then move up;
        else if(maze.mazeMap[curX-1][curY] == 0){
            maze.mazeMap[curX][curY] = -1;
            Push(maze.path, curX, curY);
            FindMaze(curX-1, curY, xe, ye, maze);
        }
        //if both derections couldn't reach,then go back and mark this position to 1 ;

        else{
            maze.mazeMap[curX][curY] = 1;
            int preX,preY;
            //get the previous cord from the stack
            GetTop(maze.path,preX,preY);
            //set the previous to be 0
            //maze.mazeMap[preX][preY] = 0;
            FindMaze(preX,preY,xe,ye,maze);
        }
    }

}