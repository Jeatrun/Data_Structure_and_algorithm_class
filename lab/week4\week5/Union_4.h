//���򼯺ϵĲ�������������flag��ű�־ 
void Union_4(LinkList *&LA,LinkList *LB)		
{
	LinkNode *ra = LA, *pre;
	int flag[1000];
	while(ra->next != NULL)	//raָ��LAβ��� 
	{
		ra = ra->next;
		flag[ra->data] = 1;
	}
	ra->next = LB->next;	//LA�������LB 
	pre = ra;
	ra = ra->next;	//�����Ӻ�ģ�LA+LB����LB�ĵ�һ����㿪ʼ 
	while(ra != NULL)
	{
		if(flag[ra->data] == 1)	//�����ظ��Ľ��
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

