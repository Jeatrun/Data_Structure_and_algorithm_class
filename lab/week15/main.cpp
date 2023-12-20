
#include "adList.h"

int main()
{
    adList *adlist = (adList *)malloc(sizeof(adList));
    int n = 5;
    char vertex[] = "ABCDE";
    int admatrix[5][5] = {
        0, 6, 2, INF, INF,
        INF, 0, INF, INF, 3,
        INF, 3, 0, 1, INF,
        INF, 4, INF, 0, 5,
        INF, INF, INF, INF, 0};
    createAdList(adlist, admatrix, vertex, n);
    disp(adlist);
    printf("\n");
    printf("Depth first search :");
    DFS(adlist, 1);
    printf("\n");
    // printf("Breadth first search :");
    // BFS(adlist,0);
}