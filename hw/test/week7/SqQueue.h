// ѭ������
#include <stdio.h>
#include <malloc.h>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;

// ��ʼ������
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

// ���ٶ���
void DestroyQueue(SqQueue *&q)
{
	free(q);
}

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue *q)
{
	return (q->front == q->rear);
}

// ������
bool enQueue(SqQueue *&q, ElemType e) // �� e ����
{
	if ((q->rear + 1) % MaxSize == q->front) // ��������
	{
		return false;
	}

	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MaxSize;
	return true;
}

// ������
bool deQueue(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear) // ����Ϊ��
	{
		return false;
	}
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}

int LengthQueue(SqQueue *q)
{
	if (q->front != q->rear)
	{
		return (q->rear - q->front + MaxSize) % MaxSize;
	}
	return 0;
}

void DispQueue(SqQueue *q)
{
	int k;
	int cout = 0;
	if (q->front != q->rear) // ���в�Ϊ��
	{
		k = (q->front + 1) % MaxSize;
		printf("\n\n");
		while (k != q->rear)
		{
			printf("�±꣺%d��ֵ��%d\n", k, q->data[k]);
			k = (k + 1) % MaxSize;
		}
		printf("�±꣺%d��ֵ��%d\n", k, q->data[k]); // ������һ��Ԫ��

		//		cout++;
		//		while(cout <= LengthQueue(q))
		//		{//���
		//			printf("%d ",q->data[k]);
		//			k = (k+1)%MaxSize;
		//			cout++;
		//		}
	}
}
