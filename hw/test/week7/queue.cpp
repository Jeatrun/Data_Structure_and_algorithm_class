#include <iostream>
#include "SqQueue.h"
#include <stdio.h>
#include <malloc.h>
/*
���Ŷӡ��������ŶӲ��˵Ĳ����ţ����뵽�����ŶӶ����С�
�ھ���������ŶӶ�������ǰ��Ĳ��˾��������Ӷ�����ɾ����
�۲鿴�Ŷӡ����Ӷ��׵���β�г����е��ŶӲ��˵Ĳ����š�
���°ࡪ���˳����С�
*/
int main(int argc, char **argv)
{
	// �����������Ĵ��ŶӺ���
	ElemType e;
	SqQueue *q;	  // ����һ������
	InitQueue(q); // ���г�ʼ����Ȼ��Ϳ��Խ��в�����
	while (1)
	{

		printf("������(1-4),1:�Ŷ� ,2:���� ,3:�鿴�Ŷ� ,4:�°�");
		int x;
		scanf("%d", &x);
		switch (x)
		{
		case 1: // �Ŷ�
			int id;
			scanf("%d", &id);
			enQueue(q, id);
			break;
		case 2: // ����
			deQueue(q, id);
			break;
		case 3: // �鿴�Ŷ�
			DispQueue(q);
			break;
		case 4: // �°�
			DestroyQueue(q);
		}
	}
}
