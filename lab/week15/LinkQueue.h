#include <malloc.h>
#include <stdio.h> 

typedef int ElemType;

//----- 队列的链式存储-----
typedef struct qnode 
{ 			// 结点类型
     ElemType  data;
     struct qnode  *next;
} QNode;
typedef struct 
{ // 链队列类型
      QNode*  front;  // 队头指针
      QNode*  rear;    // 队尾指针
}LiQueue;


void InitQueue(LiQueue *&q)
{  
	q=(LiQueue *)malloc(sizeof(LiQueue));
    q->front=q->rear=NULL;
}
void DestroyQueue(LiQueue *&q)
{  
	QNode *p=q->front,*r;  //p指向队头数据节点
    if (p!=NULL)		  //释放数据节点占用空间
    {  
		r=p->next;
		while (r!=NULL)
		{   
			free(p);
	   		p=r;
			r=p->next;
		}
   }
   free(p);
   free(q);	  //释放链队节点占用空间
}
bool QueueEmpty(LiQueue *q)
{
	return(q->rear==NULL);
}
void enQueue(LiQueue *&q,ElemType e)
{  
	QNode *p;
    p=(QNode *)malloc(sizeof(QNode));
    p->data=e;
    p->next=NULL;
    if (q->rear==NULL) //若链队为空,新节点是队首节点又是队尾节点
		q->front=q->rear=p;
    else
    {  
		q->rear->next=p;//将*p节点链到队尾,并将rear指向它
		q->rear=p;
    }
}
bool deQueue(LiQueue *&q,ElemType &e)
{  
	QNode *t;
    if (q->rear==NULL) 
		return false;	//队列为空
    t=q->front;		   //t指向第一个数据节点
    if (q->front==q->rear)  //队列中只有一个节点时
		q->front=q->rear=NULL;
    else			   //队列中有多个节点时
		q->front=q->front->next;
    e=t->data;
    free(t);
    return true;
}

void DispQueue(LiQueue *q)   
{	//从队头到队尾，逐个显示出来 
	QNode *p= q->front;
	while(p != NULL)
	{
		printf("%4d",p->data);
		p = p->next;
	}
}

