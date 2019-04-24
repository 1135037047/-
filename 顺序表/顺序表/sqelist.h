#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
typedef int DataType;
typedef struct Seqlist {
	int* arr;
	int capacity;
	int size;
}Seqlist,*PSeq;
typedef struct Seqlist Seqlist;
typedef struct Seqlist* PSeq;
#define SIZE 5

// 顺序表的初始化 
void SeqListInit(PSeq ps, int capacity);

// 在顺序表的尾部插入值为data的元素 
void SeqListPushBack(PSeq ps, DataType data);

// 删除顺序表最后一个元素 
void SeqListPopBack(PSeq ps);

// 在顺序表的头部插入值为data的元素 
void SeqListPushFront(PSeq ps, DataType data);

// 删除顺序表头部的元素 
void SeqListPopFront(PSeq ps);

// 在顺序表pos位置插入值为data的元素 
void SeqListInsert(PSeq ps, int pos, DataType data);

// 删除顺序表中pos位置上的元素 
void SeqListErase(PSeq ps, int pos);

// 在顺序表中查找值为data的元素，找到返回该元素在顺序表中的下标，否则返回-1 
int SeqListFind(PSeq ps, DataType data);

// 检测顺序表是否为空，如果为空返回非0值，非空返回0 
int SeqListEmpty(PSeq ps);

// 返回顺序表中有效元素的个数 
int SeqListSize(PSeq ps);

// 返回顺序表的容量大小 
int SeqListCapacity(PSeq ps);

// 将顺序表中的元素清空 
void SeqListClear(PSeq ps);

// 删除顺序表中第一个值为data的元素 
void SeqListRemove(PSeq ps, DataType data);

// 销毁顺序表 
void SeqListDestroy(PSeq ps);

// 顺序表的扩容 
void CheckCapacity(PSeq ps);
