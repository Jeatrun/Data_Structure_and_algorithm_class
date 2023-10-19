#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    LiQueue *q;
    InitQueue(q);
    //menu
    int choice;
    while(1){
        ElemType num;
        printf("1.排队\n2.就诊\n3.查看队列\n4.下班\n");
        printf("Please choose an option:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int queNum;
                printf("please enter the patients' number that want to queue: ");
                scanf("%d",&queNum);
                for(int i=queNum;i>0;i--){
                    printf("please enter your number: ");
                    scanf("%d",&num);
                    enQueue(q,num);
                }
                //system("pause");
                //system("cls");
                break;
            case 2:
                deQueue(q,num);
                //system("pause");
                //system("cls");
                break;
            case 3:
                 DispQueue(q);
                // system("pause");
                //system("cls");
                break;
            case 4:
                DestroyQueue(q);
                // system("pause");
                //system("cls");
                break;
            }
    }    
}