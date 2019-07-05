#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int SDataType;
typedef struct SListNode {
	SDataType data;
	struct SListNode* Next;
}Node,*PNode;
typedef struct SList {
	PNode pHead;
}SList,*PSList;

// ����ĳ�ʼ�� 
void SListInit(PSList s);

// ������s���һ���ڵ�����ֵΪdata�Ľڵ� 
void SListPushBack(PSList s, SDataType data);

// ɾ������s���һ���ڵ� 
void SListPopBack(PSList s);

// ������s��һ���ڵ�ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(PSList s, SDataType data);

// ɾ������s�ĵ�һ���ڵ� 
void SListPopFront(PSList s);

// �������posλ�ú����ֵΪdata�Ľڵ� 
void SListInsert(PNode pos, SDataType data);

// ɾ������s��posλ�õĽڵ� 
void SListErase(PSList s, PNode pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻�NULL 
PNode SListFind(PSList s, SDataType data);

// ��ȡ��������Ч�ڵ�ĸ��� 
size_t SListSize(PSList s);

// ��������Ƿ�Ϊ�� 
int SListEmpty(PSList s);

// ����������Ч�ڵ���� 
void SListClear(PSList s);

// �������� 
void SListDestroy(PSList s);

//��ӡ����
void SListPrintf(PSList s);