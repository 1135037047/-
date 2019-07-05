#include "Slist.h"

void SListInit(PSList s) {
	assert(s);
	s->pHead = NULL;

}

void SListPrintf(PSList s) {
	assert(s);
	PNode pCur = s->pHead;
	while (pCur) {
		printf("%d", pCur->data);
		pCur = pCur->Next;
	}
	printf("NULL\n");
}

PNode BuySListNode() {
	PNode PNewNode = (PNode)malloc(sizeof(Node));
	if (PNewNode == NULL) {
		assert(0);
		return NULL;
	}
	return PNewNode;
}

void SListPushBack(PSList s,SDataType data) {
	assert(s);
	PNode pCur = s->pHead;
	PNode PNewNode = BuySListNode();
	if (s->pHead == NULL) {
		s->pHead = PNewNode;
		s->pHead->data = data;
		s->pHead->Next = NULL;
	}
	else {
		while (pCur->Next) {
			pCur = pCur->Next;
		}
		pCur->Next = PNewNode;
		PNewNode->data = data;
		PNewNode->Next = NULL;
	}
}

void SListPushFront(PSList s, SDataType data) {
	assert(s);
	PNode PNewNode = BuySListNode();
	if (s->pHead != NULL) {
		PNewNode->data = data;
		PNewNode->Next = s->pHead;
		s->pHead = PNewNode;
	}
	else{
		PNewNode->data = data;
		PNewNode->Next = NULL;
		s->pHead = PNewNode;
	}	
}


void SListPopBack(PSList s) {
	assert(s);
	PNode pCur = s->pHead;
	if (s->pHead) {
		if (s->pHead->Next == NULL) {
			free(s->pHead);
			s->pHead = NULL;
			return;
		}
		while (pCur->Next->Next) {
			pCur = pCur->Next;
		}
		free(pCur->Next);
		pCur->Next = NULL;
	}
	else {
		return;
	}
}

void SListPopFront(PSList s) {
	assert(s);
	PNode pCur = s->pHead;
	if (pCur) {
		s->pHead = s->pHead->Next;
		free(pCur);
	}
	else {
		return;
	}
}

void SListInsert(PNode pos, SDataType data) {
	if (pos == NULL) {
		return;
	}
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	pNewNode->data = data;
	pNewNode->Next = pos->Next;
	pos->Next = pNewNode;
}

void SListErase(PSList s, PNode pos) {
	assert(s);
	if (pos == NULL) {
		return;
	}
	if (s->pHead == NULL) {
		return;
	}
	while (s->pHead != pos&&s->pHead->Next!= NULL) {
		s->pHead = s->pHead->Next;
	}   
	if (s->pHead == pos) {
		s->pHead = pos->Next;
		free(pos);
	}
}

PNode SListFind(PSList s,SDataType data) {
	assert(s);
	while(s->pHead && s->pHead->data != data) {
		s->pHead = s->pHead->Next;
	}
	if (s->pHead->data == data) {
		return s->pHead;
	}
	return NULL;
}
size_t SListSize(PSList s) {
	assert(s);
	size_t count = 0;
	while (s->pHead) {
		s->pHead = s->pHead->Next;
		++count;
	}
	return count;
}

int SListEmpty(PSList s) {
	assert(s);
	if (s->pHead == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}

void SListClear(PSList s) {
	assert(s);
	if (s->pHead == NULL) {
		return;
	}
	s->pHead = NULL;
}

//不带头节点与清空相同
void SListDestroy(PSList s) {

}

typedef struct ListNode ListNode;
typedef struct ListNode* PListNode;
PNode middleNode(PSList head) {
	PNode firstNode = head->pHead;
	PNode secNode = head->pHead;
	while (secNode->Next && secNode->Next->Next) {
		firstNode = firstNode->Next;
		secNode = secNode->Next->Next;
	}
	firstNode = firstNode->Next;
	return firstNode;
}
int main() {
	SList s;
	SListInit(&s);
	SListPushFront(&s, 5);
	SListPushFront(&s, 4);
	SListPushFront(&s, 3);
	SListPushFront(&s, 2);
	SListPushFront(&s, 1);
	SListPushFront(&s, 1);
	middleNode(&s);
	SListPrintf(&s);
	
	system("pause");
	return 0;
}