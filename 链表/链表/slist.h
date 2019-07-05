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

// 链表的初始化 
void SListInit(PSList s);

// 在链表s最后一个节点后插入值为data的节点 
void SListPushBack(PSList s, SDataType data);

// 删除链表s最后一个节点 
void SListPopBack(PSList s);

// 在链表s第一个节点前插入值为data的节点 
void SListPushFront(PSList s, SDataType data);

// 删除链表s的第一个节点 
void SListPopFront(PSList s);

// 在链表的pos位置后插入值为data的节点 
void SListInsert(PNode pos, SDataType data);

// 删除链表s中pos位置的节点 
void SListErase(PSList s, PNode pos);

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回NULL 
PNode SListFind(PSList s, SDataType data);

// 获取链表中有效节点的个数 
size_t SListSize(PSList s);

// 检测链表是否为空 
int SListEmpty(PSList s);

// 将链表中有效节点清空 
void SListClear(PSList s);

// 销毁链表 
void SListDestroy(PSList s);

//打印链表
void SListPrintf(PSList s);