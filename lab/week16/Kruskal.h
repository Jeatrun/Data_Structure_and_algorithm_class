#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 100
#define Vnum 5

void Kruskal(int adMatrix[Vnum][Vnum]){
    //1.create an array end to record the end (biggest vertex) of the current vertex
    int end[Vnum];
    //2.find the shortest edge
    int shortestEdge=INF;
    int shortestEdgeIndex1=-1;
    int shortestEdgeIndex2=-1;
    for(int row=0;row<Vnum;row++){
        for(int col=0;col<Vnum;col++){
            if(adMatrix[row][col]<shortestEdge){
                shortestEdge=adMatrix[row][col];
                shortestEdgeIndex1=row;
                shortestEdgeIndex2=col;
                //check out whether both two vertex has the same end vertex in the end array
                if(end[row]!=end[col]){
                    //if no, find wether there has other vertex conneted to these vertex
                        int cV=-1;//connected Vertex                        
                        for(int i=0;i<Vnum;i++){
                            if(end[i]==end[col]||end[i]==end[row]){
                                cV=i;
                            }
                        }   
                    //find the biggest one
                    //col,row,end[col],end[row]
                    int biggestVertex=-1;
                    //    z = ((a < b ? a : b) < (c < d ? c : d)) ? (a < b ? a : b) : (c < d ? c : d);
                      
                    //record the biggest one into the end array for all
                    
                }
                


            }
        }
    }
    


}
