#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
#define M 4
#define N 4
//*************�ݹ�ʵ�ַ�ʽ**********************************/
typedef struct
{	int i;		//��ǰ������к�
	int j;		//��ǰ������к�
}Box;
typedef struct
{   
    int length;	//·������
	Box data[MaxSize];
}PathType;		//����·������

int count=0;

void mgpath(int xi, int yi, int xe, int ye, PathType path, int mg[M+2][N+2])//���·��Ϊ:(xi��yi)-->(xe��ye)
{	
	int di, k, i, j;
		
	/*̽��·�� 
	if(mg[xi][yi]==0)
		printf("(%d��%d)---", xi, yi); 
	//*/ 

	if(xi==xe && yi==ye)
	{
		path.data[path.length].i = xi;
		path.data[path.length].j = yi;
		path.length++;
		printf("\n\n�Թ�·��%d����:\n", ++count);
		for(k=0;k<path.length;k++)
		{
			printf("\t(%d��%d)", path.data[k].i, path.data[k].j);
			if((k+1)%5==0)	//ÿ���ÿ5�������һ��
				printf("\n");
		}
		printf("\n");
	}
	else				//(xi��yi)���ǳ���
	{
		if(mg[xi][yi]==0)	//(xi��yi)��һ�����߷���
		{
			path.data[path.length].i = xi;
			path.data[path.length].j = yi;
			path.length++;		//·��������1                             
			mg[xi][yi]=-1;		//���������ظ���·��
			
			di=0;
			while(di<4)          	//����(xi��yi)���ܵ�ÿһ�����ڷ�λdi
			{
				switch(di)       	//�ҷ�λdi��Ӧ�ķ���(i��j)
				{
					case 0:i=xi-1; j=yi; break;
                    case 1:i=xi; j=yi+1; break;
                    case 2:i=xi+1; j=yi; break;
                    case 3:i=xi; j=yi-1; break;
                }
				mgpath(i, j, xe, ye, path, mg);		                
				di++;
			}//-while 
			
			path.length--;   //����һ������
			mg[xi][yi]=0;    //�ָ�(xi��yi)Ϊ����
			/* 
			printf("(%d��%d)���ڣ����ˣ�\n", xi, yi);
			//*/ 						
		}//-if(mg[xi][yi]==0)
	}//-�ݹ���
}
