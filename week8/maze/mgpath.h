#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
#define M 4
#define N 4
//*************递归实现方式**********************************/
typedef struct
{	int i;		//当前方块的行号
	int j;		//当前方块的列号
}Box;
typedef struct
{   
    int length;	//路径长度
	Box data[MaxSize];
}PathType;		//定义路径类型

int count=0;

void mgpath(int xi, int yi, int xe, int ye, PathType path, int mg[M+2][N+2])//求解路径为:(xi，yi)-->(xe，ye)
{	
	int di, k, i, j;
		
	/*探测路径 
	if(mg[xi][yi]==0)
		printf("(%d，%d)---", xi, yi); 
	//*/ 

	if(xi==xe && yi==ye)
	{
		path.data[path.length].i = xi;
		path.data[path.length].j = yi;
		path.length++;
		printf("\n\n迷宫路径%d如下:\n", ++count);
		for(k=0;k<path.length;k++)
		{
			printf("\t(%d，%d)", path.data[k].i, path.data[k].j);
			if((k+1)%5==0)	//每输出每5个方块后换一行
				printf("\n");
		}
		printf("\n");
	}
	else				//(xi，yi)不是出口
	{
		if(mg[xi][yi]==0)	//(xi，yi)是一个可走方块
		{
			path.data[path.length].i = xi;
			path.data[path.length].j = yi;
			path.length++;		//路径长度增1                             
			mg[xi][yi]=-1;		//避免来回重复找路径
			
			di=0;
			while(di<4)          	//对于(xi，yi)四周的每一个相邻方位di
			{
				switch(di)       	//找方位di对应的方块(i，j)
				{
					case 0:i=xi-1; j=yi; break;
                    case 1:i=xi; j=yi+1; break;
                    case 2:i=xi+1; j=yi; break;
                    case 3:i=xi; j=yi-1; break;
                }
				mgpath(i, j, xe, ye, path, mg);		                
				di++;
			}//-while 
			
			path.length--;   //回退一个方块
			mg[xi][yi]=0;    //恢复(xi，yi)为可走
			/* 
			printf("(%d，%d)碰壁，回退！\n", xi, yi);
			//*/ 						
		}//-if(mg[xi][yi]==0)
	}//-递归体
}
