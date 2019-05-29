#include "Queue.h"

void QueueInit(Queue* q) {
	assert(q);
	q->_back = q->_front = NULL;

}

QNode* BuyQueueNode(QDataType data) {
	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	if (NewNode == NULL) {
		assert(0);
		return NULL;
	}
	NewNode->_data = data;
	NewNode->_pNext = NULL;
	return NewNode;
}

void QueuePush(Queue* q,QDataType data) {
	assert(q);
	QNode* NewNode = BuyQueueNode(data);
	if (q->_back == NULL) {
		q->_back = NewNode;
		q->_front = NewNode;
	}
	else {
		q->_back->_pNext = NewNode;
		q->_back = q->_back->_pNext;
	}
}

void QueuePop(Queue* q) {
	assert(q);
	if (q->_front == NULL) {
		return;
	}
	QNode* p = q->_front;
	q->_front = q->_front->_pNext;
	free(p);
	p = NULL;
	if (q->_front == NULL) {
		q->_back = NULL;
	}
}

QDataType QueueFront(Queue* q) {
	assert(q);
	if (q->_front == NULL) {
		return 0 - 1;
	}
	return q->_front->_data;
}

QDataType QueueBack(Queue* q) {
	assert(q);
	if (q->_back == NULL) {
		return NULL;
	}
	return q->_back->_data;
}

int QueueSize(Queue* q) {
	assert(q);
	if (q->_front == NULL) {
		return 0;
	}
	int count = 1;
	QNode* p = q->_front;
	while(p != q->_back) {
		p = p->_pNext;
		count++;
	}
	return count;
}

int QueueEmpty(Queue* q) {
	assert(q);
	return !q->_front;
}

void QueueDestroy(Queue* q) {
	assert(q);
	while (q->_front != NULL) {
		QueuePop(q);
	}
}
int main() {
	Queue q;
	QueueInit(&q);
	QueueDestroy(&q);	
}