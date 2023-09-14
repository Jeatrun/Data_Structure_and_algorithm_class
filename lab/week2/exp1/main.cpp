#include <stdio.h>
#include "Stu.h"
#include <malloc.h>

int main(){
    stu *student1;//定义结构体指针变量
    student1=(stu*)malloc(sizeof(stu));  
    //input
    printf("\n\tstudent 1\n");
    printf("please enter the name: ");
    scanf("%s",student1->name);
    printf("please enter the number: ");
    scanf("%ld",&student1->num);
    printf("please enter the birthdate(yyyy.mm.dd): \n");
    scanf("%d.%d.%d",&student1->birthdate.year,&student1->birthdate.month,&student1->birthdate.day);
    
    //output
    printf("\n\tInformation of student1\n");
    printf("name: %s\tnumber: %ld\n",student1->name,student1->num);
    printf("birthdate:%d.%d.%d\n",student1->birthdate.year,student1->birthdate.month,student1->birthdate.day);
    
    free(student1);

    stu student2;//定义结构体变量
    //input
    printf("\n\t student 2\n");
    printf("please enter the name: ");
    scanf("%s",student2.name);
    printf("please enter the number: ");
    scanf("%ld",&student2.num);
    printf("please enter the birthdate(yyyy.mm.dd): \n");
    scanf("%d.%d.%d",&student2.birthdate.year,&student2.birthdate.month,&student2.birthdate.day);
    
    //output
    printf("\n\tInformation of student2:\n");
    printf("name: %s\tnumber: %ld\n",student2.name,student2.num);
    printf("birthdate:%d.%d.%d\n",student2.birthdate.year,student2.birthdate.month,student2.birthdate.day);



    return 0;
}

