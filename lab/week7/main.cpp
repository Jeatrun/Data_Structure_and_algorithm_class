#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    LinkQueue *q;
    InitLinkQueue(q);
    // menu
    int choice;
    while (1)
    {
        ElemType str_num;
        printf("1.Enqueue\n2.Visit\n3.Display the queue\n4.Off work\n");
        printf("Please choose an option:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int queNum;
            char str[100];
            printf("please enter the patients' number that want to enqueue: ");
            scanf("%d", &queNum);
            for (int i = 0; i < queNum; i++)
            {
                printf("please enter the number(%d/%d): ", i + 1, queNum);
                scanf("%s", str);
                str_num = str;
                EnQueue(q, str_num);
            }
            system("pause");
            system("cls");
            break;
        case 2:
            if (DeQueue(q, str_num))
            {
                printf("patient %s has visited the doctor\n", str_num);
            }
            else
            {
                printf("queue is empty\n");
            };
            system("pause");
            system("cls");
            break;
        case 3:
            DisplayQueue(q);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            DestroyLinkQueue(q);
            system("pause");
            system("cls");
            return 0;
        }
    }
}