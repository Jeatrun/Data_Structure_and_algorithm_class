
#include "BTNode.h"

int main(int argc, char** argv) {
	
	char str[] = "A(B(D(,G)),C(E,F))";
	BTNode *T;
	CreateBTree(T,str);
	DispBTree(T);
	printf("\nthe number of nodes :%d",nodeCountReturn(T));
	int m=0;
	nodeCountQuotation(T,m);
	printf("\n the number of nodes :%d",m);
	nodeCountG(T);
	printf("\n the number of nodes :%d",countG);
	int countNL=0;
	countNodesAtLayerK(T, 1, 3,countNL);
	printf("\n the number of nodes at layer3 :%d\n",countNL);

	preorder(T);
	printf("\n");
	inorder(T);
	printf("\n");
	postorder(T);
	printf("\n");
	
	return 0;
}
