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
	QNode* _front; // ָ���ͷԪ�� 
	QNode* _back; // ָ���βԪ�� 
}Queue;

//���г�ʼ��
void QueueInit(Queue* q);
//��β����Ԫ��
void QueuePush(Queue* q, QDataType data);
//�����µĽڵ�ռ�
QNode* BuyQueueNode(QDataType data);
//ɾ����ͷԪ��
void QueuePop(Queue* q);
//�鿴��ͷԪ��
QDataType QueueFront(Queue* q);
//�鿴��βԪ��
QDataType QueueBack(Queue* q);
//�鿴����Ԫ�ظ���
int QueueSize(Queue* q);
//�鿴�����Ƿ�Ϊ��
int QueueEmpty(Queue* q);
//���ٶ���
void QueueDestroy(Queue* q);