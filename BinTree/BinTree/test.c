#include "BinTree.h"
#include "Queue.h"


BTNode* CreateBinTree(BTDataType array[], int size, BTDataType invalid) {
	int index = 0;
	return _CreateBinTree(array, size, &index, invalid);
}

BTNode* _CreateBinTree(BTDataType array[], int size, int* index, BTDataType invalid) {
	BTNode* pRoot = NULL;
	if (*index < size && array[*index] != invalid) {
		//根节点
		pRoot = BuyBinTreeNode(array[*index]);
		(*index)++;
		//左子树
		pRoot->_pLeft = _CreateBinTree(array, size, index, invalid);
		(*index)++;
		//右子树
		pRoot->_pRight = _CreateBinTree(array, size, index, invalid);
	}
	return pRoot;
}

BTNode* BuyBinTreeNode(BTDataType data) {
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NewNode == NULL) {
		assert(0);
		return NULL;
	}
	NewNode->data = data;
	NewNode->_pLeft = NULL;
	NewNode->_pRight = NULL;
	return NewNode;
}

void PreOrder(BTNode* pRoot) {
	if (pRoot != NULL) {
		printf("%c", pRoot->data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}
void InOrder(BTNode* pRoot) {
	if (pRoot != NULL) {
		InOrder(pRoot->_pLeft);
		printf("%c", pRoot->data);
		InOrder(pRoot->_pRight);
	}
}
void PostOrder(BTNode* pRoot) {
	if (pRoot != NULL) {
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c", pRoot->data);
	}
}

void BinTreeDestroy(BTNode** pRoot) {
	if (*pRoot != NULL) {
		BinTreeDestroy(&(*pRoot)->_pLeft);
		BinTreeDestroy(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

int GetBinTreeSize(BTNode* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	return GetBinTreeSize(pRoot->_pLeft) + GetBinTreeSize(pRoot->_pRight) + 1;
}

int GetBinTreeLeafCount(BTNode* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL) {
		return 1;
	}
	return GetBinTreeLeafCount(pRoot->_pLeft) + GetBinTreeLeafCount(pRoot->_pRight);
}

int GetBinTreeHeight(BTNode* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	int leftHight = 0;
	int rightHight = 0;
	leftHight = GetBinTreeHeight(pRoot->_pLeft);
	rightHight = GetBinTreeHeight(pRoot->_pRight);
	return 1 + ((leftHight > rightHight) ? leftHight : rightHight);
}

int GetBinTreeKLevelNodeCount(BTNode* pRoot, int k) {
	if (pRoot == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return GetBinTreeKLevelNodeCount(pRoot->_pLeft, k - 1) + GetBinTreeKLevelNodeCount(pRoot->_pRight, k - 1);
}

BTNode* BinarTreeFind(BTNode* pRoot, BTDataType data) {
	if (pRoot == NULL) {
		return NULL;
	}
	if (pRoot->data == data) {
		return pRoot;
	}
	BTNode* pNode = NULL;
	if (NULL != (pNode = BinarTreeFind(pRoot->_pLeft, data))) {
		return pNode;
	}
	return BinarTreeFind(pRoot->_pRight, data);
}

void LevelOrder(BTNode* pRoot) {
	Queue p;
	if (pRoot == NULL) {
		return;
	}
	QueueInit(&p);
	QueuePush(&p, pRoot);
	while (!QueueEmpty(&p)) {
		QDataType pd = QueueFront(&p);
		printf("%c", pd->data);
		if (pd->_pLeft != NULL) {
			QueuePush(&p, pd->_pLeft);
		}
		if (pd->_pRight != NULL) {
			QueuePush(&p, pd->_pRight);
		}
		QueuePop(&p);
	}
	QueueDestroy(&p);
}

void Swap(BTNode** Left, BTNode** Ringht) {
	BTNode* temp = *Left;
	*Left = *Ringht;
	*Ringht = temp;
}

void MirrorNor(BTNode* pRoot) {
	Queue p;
	if (pRoot == NULL) {
		return;
	}
	QueueInit(&p);
	QueuePush(&p, pRoot);
	while (!QueueEmpty(&p)) {
		QDataType pd = QueueFront(&p);
		Swap(&pd->_pLeft, &pd->_pRight);
		if (pd->_pLeft != NULL) {
			QueuePush(&p, pd->_pLeft);
		}
		if (pd->_pRight != NULL) {
			QueuePush(&p, pd->_pRight);
		}
		QueuePop(&p);
	}
	QueueDestroy(&p);
}

void Mirror(BTNode* pRoot) {

	if (pRoot == NULL) {
		return;
	}
	Swap(&pRoot->_pLeft, &pRoot->_pRight);
	Mirror(pRoot->_pLeft);
	Mirror(pRoot->_pRight);
}

int main() {
	char array[] = "ABD***CE**F";
	BTNode* pRoot = CreateBinTree(array, strlen(array), '*');
	printf("先序遍历:");
	PreOrder(pRoot);
	printf("\n中序遍历:");
	InOrder(pRoot);
	printf("\n后序遍历:");
	PostOrder(pRoot);
	printf("\n");
	printf("树的高度:%d\n", GetBinTreeHeight(pRoot));
	printf("第k层节点个数:%d\n", GetBinTreeKLevelNodeCount(pRoot, 3));
	printf("树的节点数:%d\n", GetBinTreeSize(pRoot));
	printf("树的叶子节点的个数:%d\n", GetBinTreeLeafCount(pRoot));
	if (BinarTreeFind(pRoot, 'F')) {
		printf("F is in tree!\n");
	}
	printf("层序遍历:");
	LevelOrder(pRoot);
	MirrorNor(pRoot);
	LevelOrder(pRoot);
	Mirror(pRoot);
	LevelOrder(pRoot);
	BinTreeDestroy(&pRoot);
	return 0;
}
