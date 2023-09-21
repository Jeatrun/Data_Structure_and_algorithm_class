#include"Sqlist.h"

int main(){
    int A[10]={12,3,4,5,6,7,2,8,78,5};
    SqList *L1;
    CreateList(L1, A, 10);
    DispList(L1);
    
    printf("\n");
    ListInsert(L1, 2, 45);
    DispList(L1);

    printf("\n");
    ElemType e1;
    ListDelete(L1, 2, e1);
    DispList(L1);
    printf("element deleted: %d",e1);
    return 0;
    
}