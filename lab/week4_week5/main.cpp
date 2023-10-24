#include "LinkList.h"

// week5 AUB
void AUB(LinkNode *LA, LinkNode *LB)
{
    int len_LA = ListLength(LA);
    int len_LB = ListLength(LB);
    ElemType e;
    // 1.take every elem of B;
    /*
        existed error:
            for(int i=1;i<len_LB;i++)
        fixed:
            for(int i=1;i<=len_LB;i++)
    */
    for (int i = 1; i <= len_LB; i++)
    {
        GetElem(LB, i, e);

        // 2.look if the same
        if (LocateElem(LA, e) == 0)
        {
            ListInsert(LA, ++len_LA, e);
        }
    }
    DispList(LA);
}
// week6

int mathod1()
{
    int A[4] = {7, 8, 9, 10};
    LinkNode *L1;
    CreateListR(L1, A, 4);
    DispList(L1);

    int B[8] = {2,2,0,5,2,1,0,7};
    LinkNode *L2;
    CreateListR(L2, B, sizeof(B) / sizeof(int));
    DispList(L2);
    AUB(L1, L2);
    return 0;
}
void mathod_2()
{
}
int main()
{
    mathod1();
    return 0;
}