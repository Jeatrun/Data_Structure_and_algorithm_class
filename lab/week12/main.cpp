
#include "BTNode.h"

void test01(){
	char str[] = "A(B(D(,G)),C(E,F))";
	BTNode *T;
	CreateBTree(T, str);
	DispBTree(T);
	printf("\nthe number of nodes :%d", nodeCountReturn(T));
	int m = 0;
	nodeCountQuotation(T, m);
	printf("\n the number of nodes :%d", m);

	int leavesCount = 0;
	countLeaves(T, leavesCount);
	printf("\n the number of leaves :%d", leavesCount);

	nodeCountG(T);
	printf("\n the number of nodes :%d", countG);
	int countNL = 0;
	countNodesAtLayerK(T, 1, 3, countNL);
	printf("\n the number of nodes at layer3 :%d\n", countNL);


}
int main()
{
	char str[] = "A(B(D(,G)),C(E,F))";
	BTNode *T;
	CreateBTree(T, str);
	// printf("pre order:");
	// preorder(T);
	// printf("\n");
	// printf("in order:");
	// inorder(T);
	// printf("\n");
	// printf("post order:");
	// postorder(T);
	// printf("\n");
	printf("larger than C:");
	display_bigger_C(T);
	printf("\n");
	printf("smaller than D:");
	display_smaller_D(T);
	return 0;
}
