#include <stdio.h>
#include "SqList.h"
int main(){
    int num[8]={2,2,0,5,2,0,0,5};
    int *p_num=num;
    SqList *mylist;
    InitList(mylist);
    InsertList(mylist,p_num,mylist->length);
    DispList(mylist);
    DestroyList(mylist);

    return 0;
}

