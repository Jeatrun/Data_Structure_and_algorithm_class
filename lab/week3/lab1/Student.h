#include <stdio.h>
typedef struct{
    char name[8];
    int age;

} stu;
//input of Stu
void InputData(stu &s){
    scanf("%s",&s.name);
    scanf("%d",&s.age);
}
//output of Stu
void OutputData(stu &s){
    printf("%8s",s.name);
    printf("%4d\n",s.age);
}