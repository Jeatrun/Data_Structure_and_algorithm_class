#include <stdio.h>
#include "SqList.h"
#include <malloc.h>

int main(){
    stu *student1;
    student1=(stu*)malloc(sizeof(stu));
    student1->num=30;
    printf("%d\n",student1->num);

    stu student2;//����ṹ�����
    student2.num=13;
    printf("%d\n",student2.num);


    return 0;
}
