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

//----- ջ��˳��洢��ʾ -----
typedef struct 
{
	SElemType data[MaxSize]; 
    int top;		//ջ��ָ��
}SqStack;

//----- ˳��ջ���������ʵ�� -----
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
	if (s->top==MaxSize-1)  //ջ�����������ջ�����
		return false;
    s->top++;		   //ջ��ָ����1
    s->data[s->top]=e;	   //Ԫ��e����ջ��ָ�봦
    return true;
}
bool Pop(SqStack *&s,SElemType &e)
{
    if (s->top==-1)	//ջΪ�յ��������ջ�����
		return false;
    e=s->data[s->top];	//ȡջ��ָ��Ԫ�ص�Ԫ��
    s->top--;		//ջ��ָ���1
    return true;
}
bool GetTop(SqStack *s,SElemType &e)
{
	if (s->top==-1)	//ջΪ�յ��������ջ�����    
    	return false;
    e=s->data[s->top];	//ȡջ��ָ��Ԫ�ص�Ԫ��
    return true;
}
int StackLength(SqStack *s)
{
	return s->top+1;
}

//���ջ����Թ�������������Ͷ�д���������
//��ջ�׿�ʼ��ʾ 
void DispStack(SqStack *S)
{
	printf("һ���Թ�·�����£�");
	for(int i=0;i<StackLength(S);i++)
	{	
		if(i%5 == 0)		//���5������һ�� 
			printf("\n");
		printf("\t(%d,%d)",S->data[i].i,S->data[i].j); 
		
	}

}
