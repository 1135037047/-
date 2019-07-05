#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int DLDataType;
typedef struct DLListNode {
	struct DLListNode* Ppre;
	struct DLListNode* Pnext;
	DLDataType data;
}DLNode,*PDLNode;


//初始化链表
void DLListNodeInit(PDLNode* pHead);
//创建链表节点
PDLNode BuyDLListNode();
//给定一个data将其插在链表的第一个元素上
void DLListNodePushFront(PDLNode pHead,DLDataType data);
//给定一个data将其插在链表的最后一个元素上
void DLListNodePushBack(PDLNode pHead, DLDataType data);
//删除链表的第一个元素
void DLListNodePopFront(PDLNode pHead);
//删除链表的最后一个元素
void DLListNodePopBack(PDLNode pHead);
//给定一个data将其插在链表的任意位置
void DLListNodeInsert(PDLNode pwd,DLDataType data);
//删除链表中任意位置的元素
void DLListNodeErase(PDLNode pwd);
//查找链表中值为data的元素
PDLNode DLListNodeFind(PDLNode pHead,DLDataType data);
//清空链表
void DLListNodeClear(PDLNode pHead);
//销毁链表
void DLListNodeDestory(PDLNode* pHead);
