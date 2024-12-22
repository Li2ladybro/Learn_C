#include"BinaryTree.h"
#include"Queue.h"

//�������
BinaryNode* BinaryTreeCreateNode(ElemType data)
{
	BinaryNode* newNode = (BinaryNode*)malloc(sizeof(BinaryNode));
	if (newNode == NULL)
	{
		printf("�ڴ治��\n");
		exit(-1);
	}
	newNode->_data = data;
	newNode->_leftChild = newNode->_rightChild = NULL;
	return newNode;
}

//�����������������������
BinaryNode* BinaryTreeCreate(char* arr, int* pi)
{
	if (arr[(*pi)] == '#')
	{
		/*BTNode* newNode = BinaryTreeCreateNode(arr[(*pi)]);
		(*pi)++;
		return newNode;*/

		//���ؿս��
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

//����
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

//�������
void PrevOrder(BinaryNode* root)
{
	//�ȸ�����
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);

	//����������
	PrevOrder(root->_leftChild);

	//����������
	PrevOrder(root->_rightChild);
}

//�������
void InOrder(BinaryNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//����������
	InOrder(root->_leftChild);

	printf("%c ", root->_data);

	//����������
	InOrder(root->_rightChild);
}

//�������
void PostOrder(BinaryNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//����������
	PostOrder(root->_leftChild);

	//����������
	PostOrder(root->_rightChild);

	printf("%c ", root->_data);
}

//�������
void LevelOrder(BinaryNode* root)
{
	if (root == NULL)
	{
		printf("NULL\n");
		return;
	}

	Queue queue;
	QueueInint(&queue);
	QueuePush(&queue,root);    //��������

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

//���еĽ�����
int TreeSize(BinaryNode* root)
{
	if (root == NULL)
	{
		//�����Ϊ��ֱ���˳�������0��
		return 0;
	}
	else
	{
		//����㲻Ϊ��
		//����1+������������+������������
		return 1 + TreeSize(root->_leftChild) + TreeSize(root->_rightChild);
	}
}

//����Ҷ�ӽ��ĸ���
int TreeLeafSize(BinaryNode* root)
{
	//��������Ϊ��
	if (root ==NULL)
	{
		return 0;
	}
	else
	{
		//����㲻Ϊ��
		if (root->_leftChild == NULL && root->_rightChild == NULL)
		{
			//�����Ҷ����򷵻�
			return 1;
		}
		else
		{
			//����������Ҷ�ӽ�����+������Ҷ�ӽ�����
			return TreeLeafSize(root->_leftChild) + TreeLeafSize(root->_rightChild);
		}
	}
}
//�����½��
BinaryNode* CreateNode(ElemType data)
{
	BinaryNode* newNode = (BinaryNode*)malloc(sizeof(BinaryNode));
	if (newNode == NULL)
	{
		printf("�½�㿪��ʧ��\n");
		exit(-1);
	}

	newNode->_data = data;
	newNode->_leftChild = NULL;
	newNode->_rightChild = NULL;
	return newNode;
}

//��������k������Ŀ
int BinaryTreeLeaveKSize(BinaryNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	//�ߵ�����˵��root!=NULL,��ʱk=1
	if (k == 1)
	{	
		return 1;
	}
	return BinaryTreeLeaveKSize(root->_leftChild,k-1) + BinaryTreeLeaveKSize(root->_rightChild,k-1);
}

//����X�Ľ�㣨���������
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

//�ж��Ƿ�����ȫ������
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