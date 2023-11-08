#include <iostream>
#include "SqQueue.h"
#include <stdio.h>
#include <malloc.h>
/*
①排队——输入排队病人的病历号，加入到病人排队队列中。
②就诊——病人排队队列中最前面的病人就诊，并将其从队列中删除。
③查看排队——从队首到队尾列出所有的排队病人的病历号。
④下班——退出运行。
*/
int main(int argc, char **argv)
{
	// 主函数调用四次排队函数
	ElemType e;
	SqQueue *q;	  // 定义一个队列
	InitQueue(q); // 进行初始化，然后就可以进行操作了
	while (1)
	{

		printf("请输入(1-4),1:排队 ,2:就诊 ,3:查看排队 ,4:下班");
		int x;
		scanf("%d", &x);
		switch (x)
		{
		case 1: // 排队
			int id;
			scanf("%d", &id);
			enQueue(q, id);
			break;
		case 2: // 就诊
			deQueue(q, id);
			break;
		case 3: // 查看排队
			DispQueue(q);
			break;
		case 4: // 下班
			DestroyQueue(q);
		}
	}
}
