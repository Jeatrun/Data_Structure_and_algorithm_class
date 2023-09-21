#include<malloc.h>
#define MaxSize 20
#include<stdio.h>
/**定义**/
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;

}SqList;



/**实现**/
//删除i=>删除位置,e=>删除元素
bool ListDelete(SqList *&L,int i,ElemType &e)
{
    //判断i合法性
    if(i<0||i>L->length)
    {return false;}

    //2.取元素
    e=L->data[i-1];

    //3.移位
    for(int j=i-1;j<L->length-1;j++){
        L->data[j]=L->data[j+1];
    }

    //4.length  
    L->length--;


    return true;

}

//插入 i=>插入位置,e=>输入元素
bool ListInsert(SqList *&L,int i,ElemType e){
    //1.判断位置合法性
    if(i<1||i>L->length+1)
    {return false;}
    
    //2.移位
    for(int j=L->length;j>=i;j--){
        L->data[j]=L->data[j-1];
    }
    
    //3.赋值
    L->data[i-1]=e;

    //4.length+1
    L->length++;

    return true;
}

//创建,由数组a[]创建
void CreateList (SqList *&L,ElemType a[],int n){
    //1.分配内存
    L=(SqList*)malloc(sizeof(SqList));

    //2.a[i]===>L->data[i]
    for(int i=0;i<n;i++){
        L->data[i]=a[i];
    }

    //3.L->length
    L->length=n;
}

//显示
void DispList(SqList *L){
    for(int i=0;i<L->length;i++){
        printf("%4d",L->data[i]);
    }
}