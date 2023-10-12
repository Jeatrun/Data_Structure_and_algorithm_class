#include"LinkList.h"
//����A��B�Ĳ��� A=AUB��B���ı�
//Ҫ���ʼ��A��B������� 
void Union_3(LinkList *&ha, LinkList *hb)	 
{
	LinkNode *pa = ha->next, *pb = hb->next;
	LinkNode *prepa = ha, *s;
	while(pa!=NULL && pb!=NULL) //O(n+m)
	{
		if(pa->data < pb->data)
		{
			prepa = prepa->next;
			pa = pa->next;
		}
		else if(pa->data == pb->data) 	//ȡpb��һ���ڵ� 
			pb = pb->next;
		else	//pa->data > pb->data,��������һ���µĽڵ�s��������뵽pa֮ǰ 
		{
			s = (LinkNode *)malloc(sizeof(LinkNode *));
			s->data = pb->data;
			s->next = pa;
			prepa->next = s;
			prepa = s; 
			pb = pb->next;
		} 
	}
	if(pb != NULL)
		prepa->next = pb; 
//	if(pa == NULL)	//��pbʣ�µĽ��ӵ�prepa֮�� 
//	{
//		pa = prepa;	//paָ��β��� 
//		while(pb != NULL)
//		{
//			s = (LinkNode *)malloc(sizeof(LinkNode *));
//			s->data = pb->data;
//			s->next = pa->next;
//			pa->next = s;
//			pa = s;
//			pb = pb->next; 	//ȡ��һ��pb��� 
//		}
//	}
}

