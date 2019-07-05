#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef char BTDataType;
typedef struct BTNode {
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType data;
}BTNode;
//����һ����
BTNode* _CreateBinTree(BTDataType* array, int size, int* index, BTDataType invalid);
BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid);
//�����µĶ������ڵ�
BTNode* BuyBinTreeNode(BTDataType data);
//�������
void PreOrder(BTNode* pRoot);
//�������
void InOrder(BTNode* pRoot);
//�������
void PostOrder(BTNode* pRoot);
//�������
void LevelOrder(BTNode* pRoot);
//���ľ���
void Mirror(BTNode* pRoot);
//��������
void BinTreeDestroy(BTNode** pRoot);
//�������ĸ���
BTNode* CopyBinTree(BTNode* pRoot);
//���Ľڵ����
int GetBinTreeSize(BTNode* pRoot);
//����k��Ľڵ����
int GetBinTreeKLevelNodeCount(BTNode* pRoot, int k);
//����Ҷ�ӽڵ����
int GetBinTreeLeafCount(BTNode* pRoot);
//���ĸ߶�
int GetBinTreeHeight(BTNode* pRoot);
//��������ֵΪdata�Ľڵ�
BTNode* BinarTreeFind(BTNode* pRoot, BTDataType data);
