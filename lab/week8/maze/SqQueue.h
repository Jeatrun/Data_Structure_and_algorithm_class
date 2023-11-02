#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef struct
{
	int i;
	int j;
	int pre;
}BoxQ;		//方块类型 
typedef BoxQ QElemType;

//----- 队列的顺序存储表示 -----
//顺序队列 
typedef struct
{
	QElemType data[MaxSize];
	int front, rear;
} SqQueue;

//初始化队列
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
} 

//销毁队列
void DestroyQueue(SqQueue *&q)
{
	free(q);
} 

//判断队列是否为空
bool QueueEmpty(SqQueue *q) 
{
	return(q->front == q->rear);
}

//进队列
bool enQueue(SqQueue *&q, QElemType e)
{
	if(q->rear == MaxSize-1) //队列已满 
		return false;	
	q->rear++;
	q->data[q->rear] = e;
	return true;
} 

//出队列
bool deQueue(SqQueue *&q, QElemType &e)
{
	if(q->front == q->rear)	//队列为空
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
} 






