#include "Stack.h"

void StackInit(Stack* ps) {
	assert(ps);
	ps->arr = (SDataType*)malloc(5 * sizeof(SDataType));
	if (ps->arr == NULL) {
		assert(0);
		return;
	}
	ps->capaciity = 5;
	ps->size = 0;
}

void StackPush(Stack* ps, SDataType data) {
	assert(ps);
	if (ps->capaciity == ps->size) {
		BuySpace(ps);
	}
	ps->arr[ps->size] = data;
	ps->size++;
}

void StackPop(Stack* ps) {
	assert(ps);
	if (ps->size == 0) {
		return;
	}
	ps->size--;
}

SDataType StackTop(Stack* ps) {
	assert(ps);
	if (ps->size == 0) {
		return NULL;
	}
	return ps->arr[ps->size - 1];
}

int StackEmpty(Stack* ps) {
	assert(ps);
	return !ps->size;
}

int StackSize(Stack* ps) {
	assert(ps);
	return ps->size;
}

void StackClear(Stack* ps) {
	assert(ps);
	ps->size = 0;
}
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
}

void BuySpace(Stack* ps) {
	assert(ps);
	ps->arr = realloc(ps->arr, 2 * (ps->capaciity) * sizeof(SDataType));
	if (ps->arr == NULL) {
		assert(0);
		return;
	}
	ps->capaciity = 2 * (ps->capaciity);
}

int main() {
	Stack ps;
	StackInit(&ps);
	StackDestroy(&ps);
	return 0;
}