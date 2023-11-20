#include "Am.h"

void findShortestPath(mgraph *G, VertexType sv, VertexType ev)
{
    VertexType vertexArry[MAX], v;
    int weightArry[MAX];
    bool vertexStatement[G->vNum];
    int totalWeight = 0, minWeight = INFINITY;
    // let the first one to be sv
    vertexArry[0] = sv;
    int waIndex = 0, vaIndex = 1;

    // Initialize vertexStatement array
    for (VertexType i = 0; i < G->vNum; i++)
    {
        vertexStatement[i] = false;
    }

    // 1.start from the source verx sv
    for (VertexType v = sv; v < G->vNum;)
    {

        // 5.when the v equals to the end of vetex ev, exit the loop
        if (v == ev)
        {
            break;
        }
        VertexType nextV = 0;
        // 2.find the v which has the smallest weight of the edges that conneted with v1
        for (VertexType colV = 0; colV < G->vNum; colV++)
        {

            if (G->adMatrix[v][colV] != INFINITY && G->adMatrix[v][colV] < minWeight && vertexStatement[colV] == false)
            {
                minWeight = G->adMatrix[v][colV];
                nextV = colV;
            }
        }
        // 3.store the weight w and verx v separately into 2 arrays
        vertexArry[vaIndex] = nextV;
        weightArry[waIndex] = minWeight;
        vertexStatement[nextV] = true;
        // 4.keep looping step 2,with the vertex v
        v = nextV;
        vaIndex++;
        waIndex++;
        minWeight = INFINITY;
    }
    // 6.count the total weight thru weightArry
    for (int i = 0; i < vaIndex - 1; i++)
    {
        totalWeight += weightArry[i];
    }

    // 7.print the result
    for (int i = 0; i < vaIndex; i++)
    {
        printf("%d", vertexArry[i]);
        if (i != vaIndex - 1)
        {
            printf("->");
        }
    }
    printf("\n the total weight is: %d", totalWeight);
}