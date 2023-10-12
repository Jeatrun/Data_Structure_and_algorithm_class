#include"LinkList.h"
//方法一：简单排序 
void sort(LinkList *&L)		//单链表递增排序   O(n^2) 
{
	LinkList *p, *pre, *q;
	p = L->next->next;		//p指向L的第2个数据结点 
	L->next->next = NULL;	//构造只有一个数据节点的有序表 
	while(p != NULL)
	{
		q = p->next;		//q保存p结点后续结点的指针 
		pre = L;			//从有序表开头进行比较，pre指向插入p的前驱结点 
		while(pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;		//扫描原链表余下的结点 
	} 
}

//方法二：利用快速排序
#define MaxSize 50
void QuickSort(int R[],int s,int t) 	//快速排序，平均时间复杂度 O(nlogn)
//对R[s]至R[t]的元素进行快速排序
{
	int i=s,j=t;
	int temp;
    if(s<t)         //区间内至少存在2个元素的情况
    {
		temp=R[s];		//用区间的第1个记录作为基准
		while (i!=j)	//从两端交替向中间扫描,直至i=j为止
		{
			while (j>i && R[j]>=temp) j--;  
			R[i]=R[j];
			while (i<j && R[i]<=temp) i++;
			R[j]=R[i];
		}
        R[i]=temp;       
        QuickSort(R,s,i-1);    //对左区间递归排序
        QuickSort(R,i+1,t);    //对右区间递归排序
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

