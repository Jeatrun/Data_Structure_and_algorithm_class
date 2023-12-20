#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"
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
    printf("the vertex number and the edge(arc)number is %d(%d)",adlist->vertexNum,adlist->edgeNum);
}
int visited[MAX];

void find_DFS(adList *adList, int ap, bool visited[])
{
    edgeNode *lp; // list position
    lp=adList->adList[ap].firstArc;
    // 2.print this vertex;
    visited[ap] = true;
    printf("%c", adList->adList[ap].info);
    // 3.visit every unvisited vertex from the vNode array
    while(lp!=NULL){
        if (visited[lp->adjvertex] == false)
        {
            // 4.set the current list position as the unvisited vertex;
            find_DFS(adList, lp->adjvertex, visited);
        }
        lp=lp->next;
    }
    // 5.if all nodes in Vnode array have been visited,return to the previous list position
    return;

}

void DFS(adList *adlist,int sv){
    //definition
    bool visited[adlist->vertexNum];
    //initialization
    for(int i=0;i<adlist->vertexNum;i++){
        visited[i] = false;
        
    }
    // 1.let the list position start at the start vertex sv from the adlist
    find_DFS(adlist, sv, visited);
}
void DFS1(adList *adlist){
    // definition
    int i;
    bool visited[adlist->vertexNum];
    // initialization
    for (int i = 0; i < adlist->vertexNum; i++)
    {
        visited[i] = false;
    }

    for (i = 0;i<adlist->vertexNum;i++){
        if (visited[i] == false)
        {
            find_DFS(adlist, i,visited);
         }
    }
}
