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

// ˳���ĳ�ʼ�� 
void SeqListInit(PSeq ps, int capacity);

// ��˳����β������ֵΪdata��Ԫ�� 
void SeqListPushBack(PSeq ps, DataType data);

// ɾ��˳������һ��Ԫ�� 
void SeqListPopBack(PSeq ps);

// ��˳����ͷ������ֵΪdata��Ԫ�� 
void SeqListPushFront(PSeq ps, DataType data);

// ɾ��˳���ͷ����Ԫ�� 
void SeqListPopFront(PSeq ps);

// ��˳���posλ�ò���ֵΪdata��Ԫ�� 
void SeqListInsert(PSeq ps, int pos, DataType data);

// ɾ��˳�����posλ���ϵ�Ԫ�� 
void SeqListErase(PSeq ps, int pos);

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е��±꣬���򷵻�-1 
int SeqListFind(PSeq ps, DataType data);

// ���˳����Ƿ�Ϊ�գ����Ϊ�շ��ط�0ֵ���ǿշ���0 
int SeqListEmpty(PSeq ps);

// ����˳�������ЧԪ�صĸ��� 
int SeqListSize(PSeq ps);

// ����˳����������С 
int SeqListCapacity(PSeq ps);

// ��˳����е�Ԫ����� 
void SeqListClear(PSeq ps);

// ɾ��˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeq ps, DataType data);

// ����˳��� 
void SeqListDestroy(PSeq ps);

// ˳�������� 
void CheckCapacity(PSeq ps);
