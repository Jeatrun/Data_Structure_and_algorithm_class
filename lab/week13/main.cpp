#include"huffmanTree.h"

int main(){
    char c[]="abcdef";
    int w[]={8,3,4,6,5,5};
    int num =6;
    htNode HT[2*num-1];

    //initiation
    for(int i=0;i<num;i++){
        HT[i].data=c[i];
        HT[i].weight=w[i];
       
    }
    createHT(HT, num,6);

    printf("haffmantree:\n");
    for(int j=0;j<2*num-1;j++){
        printf("%c %lf\n",HT[j].data,HT[j].weight);
    }
}