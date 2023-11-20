#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INFINITY 1000000000

typedef int VertexType;

typedef struct
{
    VertexType verxs[MAX];
    int adMatrix[MAX][MAX];
    int vNum, eNum;
} mgraph;

void initMatrix(mgraph *&G)
{
    for (int i = 0; i < G->vNum; i++)
    {
        for (int j = 0; j < G->vNum; j++)
        {
            G->adMatrix[i][j] = INFINITY;
        }
    }
}

void createMGraph(mgraph *&G)
{
    G = (mgraph *)malloc(sizeof(mgraph));
    // enter the nums of verxs and edges
    printf("plase enter the nums of verxs:");
    scanf("%d", &G->vNum);
    printf("plase enter the nums of edges:");
    scanf("%d", &G->eNum);

    // enter the verxs
    for (int i = 0; i < G->vNum; i++)
    {
        printf("please enter the %d th vex's value: ", i + 1);
        scanf(" %d", &G->verxs[i]);
    }
    // initiate the matrix
    initMatrix(G);

    // enter the weight of the edges
    for (int i = 0; i < G->eNum; i++)
    {
        int v1, v2, w;
        printf("please enter the %d th edge's v1,v2,w: ", i + 1);
        scanf("%d,%d,%d", &v1, &v2, &w);
        G->adMatrix[v1][v2] = w;
    }
}
void printMGraph(mgraph *G)
{
    for (int i = 0; i < G->vNum; i++)
    {
        for (int j = 0; j < G->vNum; j++)
        {
            if (G->adMatrix[i][j] == INFINITY)
            {
                printf("% ");
            }
            else
            {
                printf("%d ", G->adMatrix[i][j]);
            }
        }
        printf("\n");
    }
}
