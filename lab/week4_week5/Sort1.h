#include"LinkList.h"
//����һ�������� 
void sort(LinkList *&L)		//�������������   O(n^2) 
{
	LinkList *p, *pre, *q;
	p = L->next->next;		//pָ��L�ĵ�2�����ݽ�� 
	L->next->next = NULL;	//����ֻ��һ�����ݽڵ������� 
	while(p != NULL)
	{
		q = p->next;		//q����p����������ָ�� 
		pre = L;			//�������ͷ���бȽϣ�preָ�����p��ǰ����� 
		while(pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;		//ɨ��ԭ�������µĽ�� 
	} 
}

//�����������ÿ�������
#define MaxSize 50
void QuickSort(int R[],int s,int t) 	//��������ƽ��ʱ�临�Ӷ� O(nlogn)
//��R[s]��R[t]��Ԫ�ؽ��п�������
{
	int i=s,j=t;
	int temp;
    if(s<t)         //���������ٴ���2��Ԫ�ص����
    {
		temp=R[s];		//������ĵ�1����¼��Ϊ��׼
		while (i!=j)	//�����˽������м�ɨ��,ֱ��i=jΪֹ
		{
			while (j>i && R[j]>=temp) j--;  
			R[i]=R[j];
			while (i<j && R[i]<=temp) i++;
			R[j]=R[i];
		}
        R[i]=temp;       
        QuickSort(R,s,i-1);    //��������ݹ�����
        QuickSort(R,i+1,t);    //��������ݹ�����
	} 
}
void sort1(LinkList *&L)
{
	int a[MaxSize], i=0;
	int length = ListLength(L);   //O(n)
	LinkNode *p=L->next;
	while(p!=NULL)		//O(n)
	{
		a[i++] = p->data;
		p = p->next;
	}
	QuickSort(a, 0, length-1);		//O(nlogn)
	DestroyList(L);		//O(n)
	CreateListR(L, a, length);		//O(n)
}

