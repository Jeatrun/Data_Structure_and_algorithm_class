#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"

//*************队列实现方式*********************************109页*/
void dispapath(SqQueue *qu, int front)
{
	int k=front;
	int j, ns=0;
	printf("\n");
	do{
		j=k;
		k=qu->data[k].pre;
		qu->data[j].pre=-1;
	}while(k!=0);
	printf("一条迷宫路径如下：\n");
	k=0;
	while(k<MaxSize)
	{
		if(qu->data[k].pre == -1)
		{
			ns++;
			printf("\t(%d,%d)",qu->data[k].i,qu->data[k].j);
			if(ns%5 == 0)		//输出5个换行一次 
				printf("\n");
		}
		k++;
	}
	printf("\n");
}
bool mgpath_q(int xi, int yi, int xe, int ye, int mg[M+2][M+2])
{
	BoxQ e;
	int i, j, di, i1, j1;
	SqQueue *qu;
	InitQueue(qu);
	
	e.i=xi; e.j=yi; e.pre=-1;
	enQueue(qu, e);
	mg[xi][yi]=-1;
	
	while(!QueueEmpty(qu))
	{
		deQueue(qu, e);
		i=e.i; j=e.j;
		if(i==xe && j==ye)
		{
			dispapath(qu, qu->front);
			DestroyQueue(qu);
			return true;
		}
		for(di=0; di<4; di++)
		{
			switch(di)
			{
				case 0:i1=i-1;j1=j;break;
				case 1:i1=i;j1=j+1;break;
				case 2:i1=i+1;j1=j;break;
				case 3:i1=i;j1=j-1;break;
			}
			if(mg[i1][j1] == 0)
			{
				e.i=i1; e.j=j1;
				e.pre = qu->front;
				enQueue(qu,e);
				mg[i1][j1]=-1;
			}
		}
	}
	DestroyQueue(qu);
	return false;	
}

