#include <stdio.h>
#include "SqList.h"
int main(){
    int num[8]={2,0,0,5,1,0,2,9};
    int *p_num=num;
    SqList *mylist;
    InitList(mylist);
    InsertList(mylist,p_num,8);
    DispList(mylist);
    DestroyList(mylist);

    return 0;
}

