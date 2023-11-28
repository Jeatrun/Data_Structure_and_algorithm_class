#include "shortestPath.h"

int main()
{
    int sv = 0, ev = 4;
    mgraph *G;
    createMGraph(G);
    findShortestPath(G, sv, ev);
    return 0;
}