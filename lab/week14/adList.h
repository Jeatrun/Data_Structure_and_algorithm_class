#include <stdio.h>
#include <stdlib.h>
#define INF 32767
#define MAX 10

typedef  char infoType;

typedef struct eNode{
    int adjvertex;
    struct eNode *next;
    int weight;

} edgeNode;

typedef struct vNode{
    infoType info;
    edgeNode *firstArc;

}vNode;

typedef struct{
    vNode adList[MAX];
    int vertexNum;
    int edgeNum;
} adList;

void createAdList(adList *&adlist,int adMatrix[5][5],char V[MAX],int n){
    //initialization
    adlist->vertexNum = n;
    adlist->edgeNum = 0;
    for(int i = 0;i < n;i++){
        adlist->adList[i].info = V[i];
        adlist->adList[i].firstArc = NULL;
    }
    //value appliment
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(adMatrix[i][j] != 0 &&adMatrix[i][j] != INF){
                //if the node is the first node
                eNode *p = (eNode *)malloc(sizeof(eNode));
                p->adjvertex = j;
                p->weight = adMatrix[i][j];
                if(adlist->adList[i].firstArc == NULL){
                    p->next = NULL;
                    adlist->adList[i].firstArc = p;
                }else{
                    p->next = adlist->adList[i].firstArc;
                    adlist->adList[i].firstArc = p;
                }
                adlist->edgeNum++;                                
            }
            
        }
        
    }
}

void disp(adList *adlist){
    for(int i=0; i<adlist->vertexNum;i++){
        printf("%d(%c):",i,adlist->adList[i].info);
        eNode *p = adlist->adList[i].firstArc;
        while(p != NULL){

            printf("%d[%d]",p->adjvertex,p->weight);
            if(p->next!=NULL){
                printf("-->");
            }
            p = p->next;
        }
        printf("\n");
    }
    printf("the vertex number and the edge(arc)number is %d,%d",adlist->vertexNum,adlist->edgeNum);
}
