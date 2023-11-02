#include "SqStack.h"
//*************栈实现方式*********************************93页*/
bool mgpath_s(int xi, int yi, int xe, int ye, int mg[M+2][N+2])
{
	BoxS e;
	int i,j,di,i1,j1,k;
	bool find;
	
	SqStack *st;
	InitStack(st);
	
	e.i=xi; e.j=yi; e.di=-1;
	Push(st,e);
	mg[xi][yi]=-1;
	
	while(!StackEmpty(st))
	{
		GetTop(st,e);
		i=e.i; j=e.j; di=e.di;
		if(i==xe && j==ye)
		{
			DispStack(st);
			printf("\n");
			DestroyStack(st);
			return true; 
		}
		
		find=false;
		while(di<4 && !find)
		{
			di++;
			switch(di)
			{
				case 0:i1=i-1;j1=j;break;
				case 1:i1=i;j1=j+1;break;
				case 2:i1=i+1;j1=j;break;
				case 3:i1=i;j1=j-1;break;
			}
			if(mg[i1][j1]==0) find=true;
		}
		
		if(find)
		{
			st->data[st->top].di = di;
			e.i=i1; e.j=j1; e.di=-1;
			Push(st,e);
			mg[i1][j1]=-1;
		}
		else
		{
			Pop(st,e);
			mg[e.i][e.j]=0;
		}
	}
	DestroyStack(st);
	return false;
}
