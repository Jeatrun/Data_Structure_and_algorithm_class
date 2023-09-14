#include <stdio.h>
#include "Stu.h"
#include <malloc.h>

int main(){
    stu *student1;
    student1=(stu*)malloc(sizeof(stu));
    student1->num=30;
    printf("%ld\n",student1->num);

    stu student2;//定义结构体变量
    student2.num=13;
    printf("%ld\n",student2.num);


    return 0;
}

