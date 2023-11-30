#include<stdio.h>
#include<stdlib.h>

 typedef struct{
    char data;
    double weight;
    int parent,lchild,rchild;
 }htNode ;

findSmallestNodes(ht[]){

}



void createHT(htNode ht[],int n,int sp){
   int lnode,rnode;
   //initiation
   for(int i=0;i<2*n-1;i++){
      ht[i].lchild=-1;
      ht[i].rchild=-1;
      ht[i].parent=-1;
   }
    //5.change the cp to cp+1,looping til cp==2n-2
   for(int cp=sp;cp<2*n-1;cp++){
      //1.find the 2 smallest nodes
      findSmallestNodes(ht,cp,n,lnode,rnode);
      //2.set their parent to the current posistion(start from starting position sp)
      ht[lnode].parent=cp;
      ht[rnode].parent=cp;
       //3.add the weights and sent to at cp's weight
      ht[cp].weight=ht[lnode].weight+ht[rnode].weight;
      //4.set the 2 nodes as cp's lchild & rchild(the smaller one go to left)
      ht[cp].lchild=lnode;
      ht[cp].rchild=rnode;
   }
   


  
}
viod htCode(){
   
}