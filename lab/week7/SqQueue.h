//循环队列 
#define MaxSize 5

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;

//初始化队列
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
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
bool enQueue(SqQueue *&q, ElemType e)
{
	if((q->rear+1)%MaxSize == q->front) //队列已满 
	{
		return false;	
	}
	q->rear = (q->rear+1)%MaxSize;
	q->data[q->rear] = e;
	return true;
} 

//出队列
bool deQueue(SqQueue *&q, ElemType &e)
{
	if(q->front == q->rear)	//队列为空
	{
		return false;
	}
	q->front = (q->front+1)%MaxSize;
	e = q->data[q->front];
	return true;
} 

int LengthQueue(SqQueue *q)
{
	if(q->front != q->rear)
	{
		return (q->rear - q->front + MaxSize)%MaxSize;
	}
	return 0;
}

void DispQueue(SqQueue *q)
{
	int k; 
	int cout=0;
	if(q->front != q->rear)		//队列不为空 
	{
		k = (q->front+1)%MaxSize;
		printf("\n\n");
		while(k != q->rear)
		{
			printf("下标：%d，值：%d\n",k,q->data[k]); 
			k = (k+1)%MaxSize;
		}	
		printf("下标：%d，值：%d\n",k,q->data[k]);  //输出最后一个元素 
		
//		cout++;
//		while(cout <= LengthQueue(q))
//		{//输出 
//			printf("%d ",q->data[k]); 
//			k = (k+1)%MaxSize;
//			cout++;
//		}
	}
}





