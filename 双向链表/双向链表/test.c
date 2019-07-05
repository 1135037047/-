#include "list.h"

void DLListNodeInit(PDLNode* pHead) {
	*pHead = (PDLNode)malloc(sizeof(DLNode));
	if (*pHead == NULL) {
		assert(0);
		return;
	}
	(*pHead)->Ppre = *pHead;
	(*pHead)->Pnext = *pHead;
	(*pHead)->data = NULL;
}

void DLListNodePushFront(PDLNode pHead, DLDataType data) {
	assert(pHead);
	PDLNode NewNode = BuyDLListNode();
	NewNode->data = data;
	NewNode->Pnext = pHead->Pnext;
	NewNode->Ppre = pHead;
	pHead->Pnext->Ppre = NewNode;
	pHead->Pnext = NewNode;
}

void DLListNodePopFront(PDLNode pHead) {
	assert(pHead);
	if (pHead->Pnext == pHead) {
		return;
	}
	pHead->Pnext = pHead->Pnext->Pnext;
	free(pHead->Pnext->Ppre);
	pHead->Pnext->Ppre = pHead;
}

void DLListNodePushBack(PDLNode pHead, DLDataType data) {
	assert(pHead);
	PDLNode NewNode = BuyDLListNode();
	NewNode->data = data;
	NewNode->Pnext = pHead;
	NewNode->Ppre = pHead->Ppre;
	pHead->Ppre->Pnext = NewNode;
	pHead->Ppre = NewNode;
}

void DLListNodePopBack(PDLNode pHead) {
	assert(pHead);
	if (pHead->Pnext == pHead) {
		return;
	}
	pHead->Ppre = pHead->Ppre->Ppre;
	free(pHead->Ppre->Pnext);
	pHead->Ppre->Pnext = pHead;
}

void DLListNodeInsert(PDLNode pwd, DLDataType data) {
	assert(pwd);
	PDLNode NewNode = BuyDLListNode();
	NewNode->data = data;
	NewNode->Pnext = pwd;
	NewNode->Ppre = pwd->Ppre;
	pwd->Ppre->Pnext = NewNode;
	pwd->Ppre = NewNode;
}

void DLListNodeErase(PDLNode pwd) {
	if (pwd == NULL) {
		return;
	}
	pwd->Ppre->Pnext = pwd->Pnext;
	pwd->Pnext->Ppre = pwd->Ppre;
	free(pwd);
}

PDLNode DLListNodeFind(PDLNode pHead, DLDataType data) {
	assert(pHead);
	PDLNode Node = pHead->Pnext;
	while (Node != pHead&&Node->data != data) {
		Node = Node->Pnext;
	}
	if (Node == pHead) {
		return NULL;
	}
	else {
		return Node;
	}
}

void DLListNodeClear(PDLNode pHead) {
	assert(pHead);
	PDLNode Node = pHead->Pnext;
	while(Node != pHead) {
		Node = Node->Pnext;
		free(Node->Ppre);
	}
	pHead->Pnext = pHead;
	pHead->Ppre = pHead;
}

void DLListNodeDestory(PDLNode* pHead) {
	assert(*pHead);
	DLListNodeClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}
PDLNode BuyDLListNode() {
	PDLNode NewNode = (PDLNode)malloc(sizeof(DLNode));
	if (NewNode == NULL) {
		assert(0);
		return;
	}
	NewNode->Pnext = NULL;
	NewNode->Ppre = NULL;
	NewNode->data = NULL;
	return NewNode;
}
int main() {
	PDLNode pHead = NULL;
	DLListNodeInit(&pHead);
	DLListNodePushFront(pHead, 5);
	DLListNodePushBack(pHead, 4);
	DLListNodePushBack(pHead, 5);
	DLListNodePushBack(pHead, 4);
	DLListNodePushFront(pHead, 4);
	DLListNodePopBack(pHead);
	DLListNodePopFront(pHead);
	DLListNodeInsert(DLListNodeFind(pHead,5), 2);
	DLListNodeErase(DLListNodeFind(pHead, 4));
	DLListNodeClear(pHead);
	DLListNodeDestory(&pHead);
	system("pause");
	return 0;
}