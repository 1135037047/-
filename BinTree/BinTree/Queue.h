#pragma once
#include "BinTree.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>


typedef BTNode* QDataType;
typedef struct QNode
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front; // 指向队头元素 
	QNode* _back; // 指向队尾元素 
}Queue;

//队列初始化
void QueueInit(Queue* q);
//队尾插入元素
void QueuePush(Queue* q, QDataType data);
//申请新的节点空间
QNode* BuyQueueNode(QDataType data);
//删除队头元素
void QueuePop(Queue* q);
//查看对头元素
QDataType QueueFront(Queue* q);
//查看队尾元素
QDataType QueueBack(Queue* q);
//查看队中元素个数
int QueueSize(Queue* q);
//查看队列是否为空
int QueueEmpty(Queue* q);
//销毁队列
void QueueDestroy(Queue* q);