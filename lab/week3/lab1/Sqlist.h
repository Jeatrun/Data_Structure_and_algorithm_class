#include <stdlib.h>
#define MaxSize 20
#include<stdio.h>
/**定义**/
typedef int ElemType;
typedef struct{
    // data array
    ElemType data[MaxSize];
    // length of the list
    int length;

}SqList;



/**实现**/

//销毁
void DestoyList(SqList *&L){
    free(L);

}
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

//初始化
bool ListInit(SqList *&L){
    // 初始化一个顺序表
    int size;
    ElemType Elem[MaxSize];
    printf("请输入所输入顺序表的长度(<= %d )\n",MaxSize);
    scanf("%d",&size);
    if(size>MaxSize){
        printf("大小超过 %d !请重新输入!",MaxSize);
        return false;
    }

    printf("请输入长度为 %d 的数据\n",size);
    for(int i=0;i<size;i++){
         scanf("%d",&(Elem[i])); 
    }

    CreateList(L,Elem,size);
    return true;
}

//显示
//Displays the elements of a list
void DispList(SqList *L){
    //Loop through the list
    for(int i=0;i<L->length;i++){
        //Print the element at the current index
        printf("%4d",L->data[i]);
    }
    //Print a new line
    printf("\n");
}

void DispMenu(){
        printf("****************\n");
        printf("0.创建顺序表\n");
        printf("1.插入顺序表\n");
        printf("2.删除顺序表\n");
        printf("3.查看顺序表\n");
        printf("4.退出程序\n");
        printf("****************\n");
        printf("请输入:");
        
}
