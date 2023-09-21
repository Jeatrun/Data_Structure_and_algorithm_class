#define MaxSize 20
#include <malloc.h>
typedef struct  {

        int elem[MaxSize];

        int length;

} SqList;



void InitList(SqList *&L)  {//初始化SqList

        L = (SqList *)malloc(sizeof(SqList));

        L->length = 0;

}

void InsertList(SqList *&L, int *a, int n) //插入n个元素

{

        for(int i=0; i<n; i++)

       {

                L->elem[i] = a[i];

                L->length++;

        }

}

void DestroyList(SqList *&L) //销毁SqList

{

        free(L);

}

void DispList(SqList *L)  {

        for(int i=0; i<L->length; i++){
            
            printf("$d ",L->elem[i]);

        }


}