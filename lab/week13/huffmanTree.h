#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct
{
   char data;
   double weight;
   int parent, lchild, rchild;
} htNode;

typedef struct
{
   char code[N]; // store the huffman code at the current node
   int start;    // store the starting index of huffman code in code[]
} hCode;

void findSmallestNodes(htNode ht[], int cp, int &lnode, int &rnode)
{
   // find 2 smallest nodes
   int smallestIndex = -1;
   int secondSmallestIndex = -1;
   int smallest = 65535;
   int secondSmallest = 65535;
   for (int i = 0; i < cp; i++)
   {
      if (ht[i].parent != -1)
      {
         continue;
      }
      if (ht[i].weight < smallest)
      {
         secondSmallest = smallest;
         secondSmallestIndex = smallestIndex;
         smallest = ht[i].weight;
         smallestIndex = i;
      }
      else if (ht[i].weight < secondSmallest)
      {
         secondSmallest = ht[i].weight;
         secondSmallestIndex = i;
      }
   }
   lnode = smallestIndex;
   rnode = secondSmallestIndex;
}

void createHT(htNode ht[], int n)
{
   int lnode, rnode;
   // initiation
   for (int i = 0; i < 2 * n - 1; i++)
   {
      ht[i].lchild = -1;
      ht[i].rchild = -1;
      ht[i].parent = -1;
   }
   // 5.change the cp to cp+1,looping til cp==2n-2
   for (int cp = n; cp < 2 * n - 1; cp++)
   {
      // 1.find the 2 smallest nodes
      findSmallestNodes(ht, cp, lnode, rnode);
      // 2.set their parent to the current posistion(start from starting position sp)
      ht[lnode].parent = cp;
      ht[rnode].parent = cp;
      // 3.add the weights and sent to at cp's weight
      ht[cp].weight = ht[lnode].weight + ht[rnode].weight;
      // 4.set the 2 nodes as cp's lchild & rchild(the smaller one go to left)
      ht[cp].lchild = lnode;
      ht[cp].rchild = rnode;
   }
}
void htEncode(htNode ht[], hCode hc[], int n)
{

   // 1.start at the current position cp;
   for (int cp = 0; cp < n; cp++)
   {
      int ccp = cp; // current code position
      hc[cp].start = n;
      // 2.loop starting at cpp,find ccp's parent
      int parent = ht[ccp].parent;
      while (parent != -1)
      {
         // 3.access ccp's parent,find whether ccp is the lchild or rchild

         if (ht[parent].lchild == ccp)
         {
            // 4.if cp is the lchild,set '0' to code[n]
            hc[cp].code[hc[cp].start--] = 0;
         }
         // otherwise set to 1;
         else
         {
            hc[cp].code[hc[cp].start--] = 1;
         }
         // 5.set the current code position to ccp's parent
         ccp = parent;
         parent = ht[ccp].parent;
      }
      hc[cp].start++;
   }
}
void dispHcode(htNode ht[], hCode hc[], int n)
{
   // 1.loop starts at current position
   for (int cp = 0; cp < n; cp++)
   {
      printf("data : %c\tHuffan code:\t", ht[cp].data);
      // 2.display starts at the current code  position whitch is the value of start initially
      int ccp = hc[cp].start;
      // 3.print the code out till ccp>n
      while (ccp <= n)
      {
         printf("%d", hc[cp].code[ccp++]);
      }
      printf("\n");
   }
}

void htDecode(htNode ht[], int n, char *code)
{
   int i = 0;
   // 1.start the current position from the root of the tree
   int cp = (2 * n - 1) - 1;
   // 2.store the code's digit from the first one
   char cd = code[i];
   while (cd != '\0')
   {
      // 3.if code's digit cd ==0,set the current cp to the child we found

      if (cd == '0')
      {
         cp = ht[cp].lchild;
      }
      // 4.otherwise set to  its rchild
      else if (cd == '1')
      {
         cp = ht[cp].rchild;
      }
      i++;
      cd = code[i];
   }
   printf("the data is :%c", ht[cp].data);
}