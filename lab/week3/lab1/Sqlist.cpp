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
                        printf("˳����Ѵ���!��˳���Ϊ������ʾ:\n");
                        DispList(L1);
                        system("pause");
                        system("cls");
                        break;

                    }
                    ListInit(L1);
                    printf("�����ɹ�,������˳�������:\n");
                    DispList(L1);

                    system("pause");
                    system("cls");
                }
                break;
            case 1:
                {
                    int insertNum,insertPos;

                    printf("������Ҫ�����λ��:");
                    scanf("%d",&insertPos);
                    printf("������Ҫ�������ֵ:");
                    scanf("%d",&insertNum);
                    ListInsert(L1,insertPos,insertNum);

                    printf("����ɹ�,�޸ĺ��˳�������:\n");
                    DispList(L1);
                    
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                {
                    int delPos;
                    ElemType delElem;
                    printf("������Ҫ�����λ��:");
                    scanf("%d",&delPos);   
                    ListDelete(L1,delPos,delElem);

                    printf("ɾ���ɹ�,�޸ĺ��˳�������:\n");
                    DispList(L1);
                    
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                {
                    printf("��ѯ����˳�������:\n");
                    DispList(L1); 
                    
                    system("pause");
                    system("cls");
                }
                break;    
        }



    }
    DestoyList(L1);
}