#include "Am.h"

void dispPath(mgraph *G, int *Parents, int vertex)
{
    if (Parents[vertex] == -1)
    {
        printf("%d", G->verxs[vertex]);
    }
    else
    {
        dispPath(G, Parents, Parents[vertex]);
        printf("->%d", G->verxs[vertex]);
    }
}

void findShortestPath(mgraph *G, int sv, int ev)
{
    bool visitedVertex[G->vNum]; // store the status of visited vertexs
    int Distance[G->vNum];
    int Parents[G->vNum];
    int preDistance = 0;
    int curDistance = 0;
    // 1.initiation
    for (int i = 0; i < G->vNum; i++)
    {
        visitedVertex[i] = false;
        Distance[i] = INFINITY;
        Parents[i] = -1;
    }

    for (int curVertexIndex = sv; curVertexIndex < G->vNum;)
    {
        // if the current vertex == source vertex,then set the visited status to true and distance to 0
        if (curVertexIndex == sv)
        {
            visitedVertex[curVertexIndex] = true;
            Distance[curVertexIndex] = 0;
        }
        // when the current vertex=ev,end the loop
        if (curVertexIndex == ev)
        {
            break;
        }
        // 2.find the Adjacent vertexs
        for (int adVertexIndex = 0; adVertexIndex < G->vNum; adVertexIndex++)
        {
            // if the
            if (G->adMatrix[curVertexIndex][adVertexIndex] != INFINITY)
            {
                curDistance = preDistance + G->adMatrix[curVertexIndex][adVertexIndex];
                if (!visitedVertex[adVertexIndex] && curDistance < Distance[adVertexIndex])
                {
                    // 3.record the distance and the parent vertex into those arrays
                    Distance[adVertexIndex] = curDistance;
                    Parents[adVertexIndex] = curVertexIndex;
                }
            }
        }
        // 4.find the shortest distance of the unvisited vertexs
        int shortestDistance = INFINITY;
        int shortestVertexIndex = -1; // store the index of the vertex which has the shortest distance
        for (int adVertexIndex = 0; adVertexIndex < G->vNum; adVertexIndex++)
        {

            if (!visitedVertex[adVertexIndex] && Distance[adVertexIndex] < shortestDistance)
            {
                shortestDistance = Distance[adVertexIndex];
                shortestVertexIndex = adVertexIndex;
            }
        }
        // 5.set the vertex to be visited,and add it to current distance
        visitedVertex[shortestVertexIndex] = true;
        // if the shortest distance <current distance,then change the preDistance to the shortestDistance
        if (shortestDistance < curDistance)
        {
            preDistance = shortestDistance;
        }
        else
        {
            preDistance += shortestDistance;
        }
        // 6.change the current vertex to the shortest vertex,then keep looping start from the new vertex
        curVertexIndex = shortestVertexIndex;
    }
    // 7. Distance[ev] is the shortest distance
    printf("the shortest distance is %d :", Distance[ev]);
    // 8.trace the parent vertexs from ev to the sv to generate the path
    dispPath(G, Parents, ev);
}
