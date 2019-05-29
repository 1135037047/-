#pragma once
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

typedef int QDataType;
typedef struct QNode
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front; // ָ���ͷԪ�� 
	QNode* _back; // ָ���βԪ�� 
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
QNode* BuyQueueNode(QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);