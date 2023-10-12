#include"LinkList.h"
void Union2(LinkNode *&LA,LinkNode *LB){
    LinkNode *rA=LA,*p;
    LinkNode *qA=LA->next,*qB=LB->next;
    //1.find the tail pointer of LA--rA
    while(rA->next!=NULL){
        rA=rA->next;
    }
    bool ExistFlag;
    while(qB!=NULL){
    //2.for every element of LB,qB->data
        qA=LA->next;
        ExistFlag=false;
        //3.to see wether the element is in LA
        while(qA!=NULL){
            if(qA->data==qB->data){
                ExistFlag=true;
                break;
            }
            qA=qA->next;
        }
    //4.if not,create a new node,link to the tail of LA 
        if(!ExistFlag){
            p=(LinkNode*)malloc(sizeof(LinkNode));
            p->data=qB->data;
            p->next=NULL;
            rA->next=p;
            rA=p;
        }
        qB=qB->next;
    }
}