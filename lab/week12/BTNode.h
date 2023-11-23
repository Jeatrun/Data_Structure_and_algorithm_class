#include <stdio.h>
#include <malloc.h>
#define MaxSize 20
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node* lchild;	
	struct node* rchild;
}BTNode;


void CreateBTree(BTNode *&b, char *str)
{
	BTNode *St[MaxSize] , *p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;		
	ch=str[j];
	while (ch!='\0')   
	{
		switch(ch) 
		{
			case '(': 
				top++;
				St[top]=p;
				k=1;
				break;	
	        case ')':
				top--;
				break;
	        case ',':
				k=2;
				break;  
    		default:
            	p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;
				p->lchild=p->rchild=NULL;
				if(b==NULL)    
	        		b=p;
				else    		
            	{
					switch(k) 
                    {
						case 1: St[top]->lchild=p; break;
		        		case 2: St[top]->rchild=p; break;
	           		}
              	}
        }
        j++;  ch=str[j];    
    }
}


void DispBTree(BTNode *b)
{
	if (b!=NULL)
    {
		printf("%c", b->data);
		if(b->lchild!=NULL || b->rchild!=NULL)
		{
			printf("(");
	        DispBTree(b->lchild);	
			if( b->rchild != NULL )   printf(",");
				DispBTree(b->rchild);	
				printf(")");
	 	}
    }
} 
/*count the nodes*/
//return
int nodeCountReturn(BTNode *bt){
	if(bt==NULL){
		return 0;
	}
	else{
		return nodeCountReturn(bt->lchild)+nodeCountReturn(bt->rchild)+1;

	}
}
//with quotation
void nodeCountQuotation(BTNode *bt,int &count){
	if(bt==NULL){
		
	}
	else{
		count++;
		nodeCountQuotation(bt->lchild,count);
		nodeCountQuotation(bt->rchild,count);
	}
}
//with global
int countG;
void nodeCountG(BTNode *bt){
	if(bt==NULL){
		return;
	}
	else{
		countG++;
		nodeCountQuotation(bt->lchild,countG);
		nodeCountQuotation(bt->rchild,countG);
	}
}

// count the nodes at layer k
void countNodesAtLayerK(BTNode *bt,int h,int k,int &count){
	if(bt==NULL){
		return;
	}
	else {
		if(h==k){
			count++;
		}
		else if(h<k){
		 countNodesAtLayerK(bt->lchild, h+1, k, count);
		 countNodesAtLayerK(bt->rchild, h+1, k, count);
	}
	}

}

//traversal
void preorder(BTNode *bt)
{
	if(bt==NULL){
		return;
	}
	else{
		printf("%c",bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);
		
	}

}
void inorder(BTNode *bt){
	if(bt==NULL){
		return;
	}
	else{
		inorder(bt->lchild);
		printf("%c",bt->data);
		inorder(bt->rchild);
		
	}
}
void postorder(BTNode *bt){
	if(bt==NULL){
		return;
	}
	else{
		postorder(bt->lchild);
		postorder(bt->rchild);
		printf("%c",bt->data);
		
	}
}