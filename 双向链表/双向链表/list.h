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


//��ʼ������
void DLListNodeInit(PDLNode* pHead);
//��������ڵ�
PDLNode BuyDLListNode();
//����һ��data�����������ĵ�һ��Ԫ����
void DLListNodePushFront(PDLNode pHead,DLDataType data);
//����һ��data���������������һ��Ԫ����
void DLListNodePushBack(PDLNode pHead, DLDataType data);
//ɾ������ĵ�һ��Ԫ��
void DLListNodePopFront(PDLNode pHead);
//ɾ����������һ��Ԫ��
void DLListNodePopBack(PDLNode pHead);
//����һ��data����������������λ��
void DLListNodeInsert(PDLNode pwd,DLDataType data);
//ɾ������������λ�õ�Ԫ��
void DLListNodeErase(PDLNode pwd);
//����������ֵΪdata��Ԫ��
PDLNode DLListNodeFind(PDLNode pHead,DLDataType data);
//�������
void DLListNodeClear(PDLNode pHead);
//��������
void DLListNodeDestory(PDLNode* pHead);
