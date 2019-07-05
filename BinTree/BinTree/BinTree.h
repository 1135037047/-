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
//创建一个树
BTNode* _CreateBinTree(BTDataType* array, int size, int* index, BTDataType invalid);
BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid);
//创建新的二叉树节点
BTNode* BuyBinTreeNode(BTDataType data);
//先序遍历
void PreOrder(BTNode* pRoot);
//中序遍历
void InOrder(BTNode* pRoot);
//后序遍历
void PostOrder(BTNode* pRoot);
//层序遍历
void LevelOrder(BTNode* pRoot);
//树的镜像
void Mirror(BTNode* pRoot);
//树的销毁
void BinTreeDestroy(BTNode** pRoot);
//二叉树的复制
BTNode* CopyBinTree(BTNode* pRoot);
//树的节点个数
int GetBinTreeSize(BTNode* pRoot);
//树第k层的节点个数
int GetBinTreeKLevelNodeCount(BTNode* pRoot, int k);
//树的叶子节点个数
int GetBinTreeLeafCount(BTNode* pRoot);
//树的高度
int GetBinTreeHeight(BTNode* pRoot);
//查找树中值为data的节点
BTNode* BinarTreeFind(BTNode* pRoot, BTDataType data);
