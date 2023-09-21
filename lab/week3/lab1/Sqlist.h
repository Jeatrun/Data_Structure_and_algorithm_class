#include <stdlib.h>
#define MaxSize 20
#include<stdio.h>
/**����**/
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;

}SqList;



/**ʵ��**/

//����
void DestoyList(SqList *&L){
    free(L);

}
//ɾ��i=>ɾ��λ��,e=>ɾ��Ԫ��
bool ListDelete(SqList *&L,int i,ElemType &e)
{
    //�ж�i�Ϸ���
    if(i<0||i>L->length)
    {return false;}

    //2.ȡԪ��
    e=L->data[i-1];

    //3.��λ
    for(int j=i-1;j<L->length-1;j++){
        L->data[j]=L->data[j+1];
    }

    //4.length  
    L->length--;


    return true;

}

//���� i=>����λ��,e=>����Ԫ��
bool ListInsert(SqList *&L,int i,ElemType e){
    //1.�ж�λ�úϷ���
    if(i<1||i>L->length+1)
    {return false;}
    
    //2.��λ
    for(int j=L->length;j>=i;j--){
        L->data[j]=L->data[j-1];
    }
    
    //3.��ֵ
    L->data[i-1]=e;

    //4.length+1
    L->length++;

    return true;
}

//����,������a[]����
void CreateList (SqList *&L,ElemType a[],int n){
    //1.�����ڴ�
    L=(SqList*)malloc(sizeof(SqList));

    //2.a[i]===>L->data[i]
    for(int i=0;i<n;i++){
        L->data[i]=a[i];
    }

    //3.L->length
    L->length=n;
}

//��ʼ��
bool ListInit(SqList *&L){
    int size;
    ElemType Elem[MaxSize];
    printf("������������˳���ĳ���(<= %d )\n",MaxSize);
    scanf("%d",&size);
    if(size>MaxSize){
        printf("��С���� %d !����������!",MaxSize);
        return false;
    }

    printf("�����볤��Ϊ %d ������\n",size);
    for(int i=0;i<size;i++){
         scanf("%d",&(Elem[i])); 
    }

    CreateList(L,Elem,size);
    return true;
}

//��ʾ
void DispList(SqList *L){
    for(int i=0;i<L->length;i++){
        printf("%4d",L->data[i]);
    }
    printf("\n");
}

void DispMenu(){
        printf("****************\n");
        printf("0.����˳���\n");
        printf("1.����˳���\n");
        printf("2.ɾ��˳���\n");
        printf("3.�鿴˳���\n");
        printf("4.�˳�����\n");
        printf("****************\n");
        printf("������:");
        
}
