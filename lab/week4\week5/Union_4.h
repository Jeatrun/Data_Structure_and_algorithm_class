//无序集合的并集，采用数组flag存放标志 
void Union_4(LinkList *&LA,LinkList *LB)		
{
	LinkNode *ra = LA, *pre;
	int flag[1000];
	while(ra->next != NULL)	//ra指向LA尾结点 
	{
		ra = ra->next;
		flag[ra->data] = 1;
	}
	ra->next = LB->next;	//LA后面接上LB 
	pre = ra;
	ra = ra->next;	//从连接后的（LA+LB）的LB的第一个结点开始 
	while(ra != NULL)
	{
		if(flag[ra->data] == 1)	//存在重复的结点
		{
			pre->next = ra->next;
			free(ra); 
			ra = pre->next;
		}
		else
		{
			flag[ra->data] = 1;
			ra = ra->next;
			pre = pre->next;
		}
	} 
}

