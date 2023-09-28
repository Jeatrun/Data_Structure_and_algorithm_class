#include "LinkList.h"
int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    LinkNode *L1;
    CreateListR(L1, A, 5);
    DispList(L1);
    return 0;
}