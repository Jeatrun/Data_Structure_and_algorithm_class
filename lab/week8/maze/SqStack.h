#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef struct
{
	int i;
	int j;
	int di;
}BoxS;
typedef BoxS SElemType;

//----- 栈的顺序存储表示 -----
typedef struct 
{
	SElemType data[MaxSize]; 
    int top;		//栈顶指针
}SqStack;

//----- 顺序栈基本运算的实现 -----
void InitStack(SqStack *&s)
{  
	s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
} 
void DestroyStack(SqStack *&s)
{
	free(s);
}
bool StackEmpty(SqStack *s)
{
	return(s->top==-1);
}
bool Push(SqStack *&s,SElemType e)
{
	if (s->top==MaxSize-1)  //栈满的情况，即栈上溢出
		return false;
    s->top++;		   //栈顶指针增1
    s->data[s->top]=e;	   //元素e放在栈顶指针处
    return true;
}
bool Pop(SqStack *&s,SElemType &e)
{
    if (s->top==-1)	//栈为空的情况，即栈下溢出
		return false;
    e=s->data[s->top];	//取栈顶指针元素的元素
    s->top--;		//栈顶指针减1
    return true;
}
bool GetTop(SqStack *s,SElemType &e)
{
	if (s->top==-1)	//栈为空的情况，即栈下溢出    
    	return false;
    e=s->data[s->top];	//取栈顶指针元素的元素
    return true;
}
int StackLength(SqStack *s)
{
	return s->top+1;
}

//针对栈解决迷宫问题的数据类型而写的输出操作
//从栈底开始显示 
void DispStack(SqStack *S)
{
	printf("一条迷宫路径如下：");
	for(int i=0;i<StackLength(S);i++)
	{	
		if(i%5 == 0)		//输出5个换行一次 
			printf("\n");
		printf("\t(%d,%d)",S->data[i].i,S->data[i].j); 
		
	}

}
