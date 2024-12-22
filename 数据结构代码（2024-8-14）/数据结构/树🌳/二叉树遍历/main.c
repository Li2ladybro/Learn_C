#include "BinaryTree.h"

int main()
{
	char* arr = "abc##de#g##f###";
	int i = 0;
	BTNode* root = CreateTree(arr, &i);
	PrevOrderPrint(root);
	printf("\n");
	InOrderPrint(root);
	BinaryTreeDestroy(root);
}

