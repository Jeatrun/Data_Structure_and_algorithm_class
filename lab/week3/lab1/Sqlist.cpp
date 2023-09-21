#include"Sqlist.h"

int main(){
    SqList *L1=NULL;
    /*DispList(L1);
    
    printf("\n");
    ListInsert(L1, 2, 45);
    DispList(L1);

    printf("\n");
    ElemType e1;
    ListDelete(L1, 2, e1);
    DispList(L1);
    printf("element deleted: %d",e1);
    return 0;*/
    
    int choice;
    while(choice !=4){
        DispMenu();
        scanf("%d",&choice);
        switch (choice) {
            case 0:
                {
                    if(L1!=NULL){
                        printf("顺序表已存在!该顺序表为如下所示:\n");
                        DispList(L1);
                        system("pause");
                        system("cls");
                        break;

                    }
                    ListInit(L1);
                    printf("创建成功,创建的顺序表如下:\n");
                    DispList(L1);

                    system("pause");
                    system("cls");
                }
                break;
            case 1:
                {
                    int insertNum,insertPos;

                    printf("请输入要插入的位置:");
                    scanf("%d",&insertPos);
                    printf("请输入要插入的数值:");
                    scanf("%d",&insertNum);
                    ListInsert(L1,insertPos,insertNum);

                    printf("插入成功,修改后的顺序表如下:\n");
                    DispList(L1);
                    
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                {
                    int delPos;
                    ElemType delElem;
                    printf("请输入要插入的位置:");
                    scanf("%d",&delPos);   
                    ListDelete(L1,delPos,delElem);

                    printf("删除成功,修改后的顺序表如下:\n");
                    DispList(L1);
                    
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                {
                    printf("查询到的顺序表如下:\n");
                    DispList(L1); 
                    
                    system("pause");
                    system("cls");
                }
                break;    
        }



    }
    DestoyList(L1);
}