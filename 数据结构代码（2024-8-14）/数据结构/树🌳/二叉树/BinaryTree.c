#include"BinaryTree.h"
#include"Queue.h"

//创建结点
BinaryNode* BinaryTreeCreateNode(ElemType data)
{
	BinaryNode* newNode = (BinaryNode*)malloc(sizeof(BinaryNode));
	if (newNode == NULL)
	{
		printf("内存不足\n");
		exit(-1);
	}
	newNode->_data = data;
	newNode->_leftChild = newNode->_rightChild = NULL;
	return newNode;
}

//根据先序遍历创建二叉树树
BinaryNode* BinaryTreeCreate(char* arr, int* pi)
{
	if (arr[(*pi)] == '#')
	{
		/*BTNode* newNode = BinaryTreeCreateNode(arr[(*pi)]);
		(*pi)++;
		return newNode;*/

		//返回空结点
		(*pi)++;
		return NULL;
	}
	else
	{
		BinaryNode* root = BinaryTreeCreateNode(arr[(*pi)++]);
		root->_leftChild = BinaryTreeCreate(arr, pi);
		root->_rightChild = BinaryTreeCreate(arr, pi);
		return root;
	}
}

//销毁
void BinaryTreeDestroy(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	else
	{
		BinaryTreeDestroy(root->_leftChild);
		BinaryTreeDestroy(root->_rightChild);
		free(root);
	}

}

//先序遍历
void PrevOrder(BinaryNode* root)
{
	//先根遍历
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);

	//左子树遍历
	PrevOrder(root->_leftChild);

	//右子树遍历
	PrevOrder(root->_rightChild);
}

//中序遍历
void InOrder(BinaryNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//左子树遍历
	InOrder(root->_leftChild);

	printf("%c ", root->_data);

	//右子树遍历
	InOrder(root->_rightChild);
}

//后序遍历
void PostOrder(BinaryNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//左子树遍历
	PostOrder(root->_leftChild);

	//右子树遍历
	PostOrder(root->_rightChild);

	printf("%c ", root->_data);
}

//层序遍历
void LevelOrder(BinaryNode* root)
{
	if (root == NULL)
	{
		printf("NULL\n");
		return;
	}

	Queue queue;
	QueueInint(&queue);
	QueuePush(&queue,root);    //先入根结点

	while (QueueLength(&queue))
	{
		QueueDataElemType prev = QueueFront(&queue);

		if (prev == NULL)
		{
			printf("NULL ");
			QueuePop(&queue);
		}

		else
		{
			printf("%c ", prev->_data);
			QueuePop(&queue);
			QueuePush(&queue, prev->_leftChild);
			QueuePush(&queue, prev->_rightChild);
		}
	}
}

//树中的结点个数
int TreeSize(BinaryNode* root)
{
	if (root == NULL)
	{
		//根结点为空直接退出，返回0。
		return 0;
	}
	else
	{
		//根结点不为空
		//返回1+左子树结点个数+右子树结点个数
		return 1 + TreeSize(root->_leftChild) + TreeSize(root->_rightChild);
	}
}

//树中叶子结点的个数
int TreeLeafSize(BinaryNode* root)
{
	//如果根结点为空
	if (root ==NULL)
	{
		return 0;
	}
	else
	{
		//根结点不为空
		if (root->_leftChild == NULL && root->_rightChild == NULL)
		{
			//如果是叶结点则返回
			return 1;
		}
		else
		{
			//返回左子树叶子结点个数+右子树叶子结点个数
			return TreeLeafSize(root->_leftChild) + TreeLeafSize(root->_rightChild);
		}
	}
}
//创建新结点
BinaryNode* CreateNode(ElemType data)
{
	BinaryNode* newNode = (BinaryNode*)malloc(sizeof(BinaryNode));
	if (newNode == NULL)
	{
		printf("新结点开辟失败\n");
		exit(-1);
	}

	newNode->_data = data;
	newNode->_leftChild = NULL;
	newNode->_rightChild = NULL;
	return newNode;
}

//二叉树第k层结点数目
int BinaryTreeLeaveKSize(BinaryNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	//走到这里说明root!=NULL,此时k=1
	if (k == 1)
	{	
		return 1;
	}
	return BinaryTreeLeaveKSize(root->_leftChild,k-1) + BinaryTreeLeaveKSize(root->_rightChild,k-1);
}

//查找X的结点（先序遍历）
BinaryNode* BinaryTreeFind(BinaryNode* root, ElemType data)
{
	if (root == NULL)
	{
		return NULL;
	}
	
	if (root->_data == data)
	{
		return root;
	}
    
	BinaryNode* leftNode = BinaryTreeFind(root->_leftChild, data);

	if (leftNode)
	{
		return leftNode;
	}

	BinaryNode* rightNode = BinaryTreeFind(root->_rightChild, data);

	if (rightNode)
	{
		return rightNode;
	}

	return NULL;
}

//判断是否是完全二叉树
int BinaryTreeComplete(BinaryNode* root)
{
	if (root == NULL)
	{
		printf("NULL\n");
		return 1;
	}
	Queue queue;
	QueueInint(&queue);
	QueuePush(&queue, root);

	QueueDataElemType prev = QueueFront(&queue);

	while (QueueLength(&queue))
	{
		prev = QueueFront(&queue);
		if (prev == NULL)
		{
			break;
		}
		else
		{
			//printf("%c ", (prev->_data));
			QueuePop(&queue);
			QueuePush(&queue, prev->_leftChild);
			QueuePush(&queue, prev->_rightChild);
		}
	}

	while (QueueLength(&queue))
	{
		prev = QueueFront(&queue);
		if (prev)
		{
			return 0;
		}
		else
		{
			QueuePop(&queue);
		}
	}

	return 1;
}