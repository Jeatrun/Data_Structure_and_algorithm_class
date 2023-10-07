#include "LinkList.h"

void AUB(LinkNode *LA, LinkNode *LB){
    int len_LA=ListLength(LA);
    int len_LB=ListLength(LB);
    ElemType e;
    //1.take every elem of B;
    for(int i=1;i<len_LB;i++){
        GetElem(LB,i,e);
        
        //2.look if the same
        if(LocateElem(LA,e)==0){
            ListInsert(LA,++len_LA,e);
            
        }
    }
    DispList(LA);

}



int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    LinkNode *L1;
    CreateListR(L1, A, 5);
    DispList(L1);
    
    int B[5] = {8, 9, 10, 11, 12};
    LinkNode *L2;
    CreateListR(L2, B, sizeof(B)/sizeof(int));
    DispList(L2);
    AUB(L1, L2);
    return 0;
}