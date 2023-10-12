#include"LinkList.h"
//有序集A和B的并集 A=AUB，B不改变
//要求初始的A和B是有序的 
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
		else if(pa->data == pb->data) 	//取pb下一个节点 
			pb = pb->next;
		else	//pa->data > pb->data,重新生成一个新的节点s，将其插入到pa之前 
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
//	if(pa == NULL)	//将pb剩下的结点接到prepa之后 
//	{
//		pa = prepa;	//pa指向尾结点 
//		while(pb != NULL)
//		{
//			s = (LinkNode *)malloc(sizeof(LinkNode *));
//			s->data = pb->data;
//			s->next = pa->next;
//			pa->next = s;
//			pa = s;
//			pb = pb->next; 	//取下一个pb结点 
//		}
//	}
}

