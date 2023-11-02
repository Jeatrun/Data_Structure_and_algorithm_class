#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef struct
{
	int i;
	int j;
	int pre;
}BoxQ;		//�������� 
typedef BoxQ QElemType;

//----- ���е�˳��洢��ʾ -----
//˳����� 
typedef struct
{
	QElemType data[MaxSize];
	int front, rear;
} SqQueue;

//��ʼ������
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
} 

//���ٶ���
void DestroyQueue(SqQueue *&q)
{
	free(q);
} 

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue *q) 
{
	return(q->front == q->rear);
}

//������
bool enQueue(SqQueue *&q, QElemType e)
{
	if(q->rear == MaxSize-1) //�������� 
		return false;	
	q->rear++;
	q->data[q->rear] = e;
	return true;
} 

//������
bool deQueue(SqQueue *&q, QElemType &e)
{
	if(q->front == q->rear)	//����Ϊ��
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
} 






