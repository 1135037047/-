#include "sqelist.h"


void SeqlistPrint(PSeq ps) {
	assert(ps);
	for (int i = 0; i < ps->size; ++i) {
		printf("%d", ps->arr[i]);
	}
	printf("\n");
}
void SeqlistInit(PSeq ps, int capacity) {
	ps->arr = (int*)malloc(capacity * sizeof(int));
	if (ps == NULL) {
		assert(0);
		return;
	}
	ps->capacity = capacity;
	ps->size = 0;
}

void SeqlistPushBack(PSeq ps,DataType data) {
	assert(ps);
	if (ps->size == ps->capacity) {
		CheckCapacity(ps);
	}
	ps->arr[ps->size] = data;
	++ps->size;
}

void SeqlistPopBack(PSeq ps) {
	assert(ps);
	if (SeqlistEmpty(ps)) {
		return;
	}
	--ps->size;
}

void SeqlistPushFront(PSeq ps, DataType data) {
	assert(ps);
	if (ps->size == ps->capacity) {
		CheckCapacity(ps);
	}
	for (int i = ps->size; i > 0; --i) {
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = data;
	++ps->size;
}

void SeqlistPopFront(PSeq ps) {
	assert(ps);
	if (SeqlistEmpty(ps)) {
		return;
	}
	for (int i = 0; i < ps->size; ++i) {
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;
}

void SeqlistInsert(PSeq ps, int pos, DataType data) {
	assert(ps);
	if (ps->size == ps->capacity) {
		CheckCapacity(ps);
	}
	if (pos < 0|| pos > ps->size) {
		return;
	}
	for (int i = ps->size; i > pos; --i) {
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = data;
	++ps->size;
}

void SeqlistErase(PSeq ps, int pos) {
	assert(ps);
	if (pos > ps->size||pos < 0) {
		return;
	}
	for (int i = pos; i < ps->size - 1; ++i) {
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;
}

int SeqlistFind(PSeq ps, DataType data) {
	assert(ps);
	for (int i = 0; i < ps->size; ++i) {
		if (ps->arr[i] == data) {
			return i;
		}
	}
	return -1;
}

int SeqlistEmpty(PSeq ps) {
	assert(ps);
	if (ps->size) {
		return 0;
	}
	else {
		return -1;
	}
}

int SeqlistSize(PSeq ps) {
	assert(ps);
	return ps->size;
}

int SeqlistCapacity(PSeq ps) {
	assert(ps);
	return ps->capacity;
}

void SeqlistClear(PSeq ps) {
	assert(ps);
	ps->size = 0;
}

void SeqlistRemov(PSeq ps, DataType data) {
	assert(ps);
	SeqlistErase(ps,SeqlistFind(ps,data));
}

void SeqListDestroy(PSeq* ps) {
	assert(*ps);
	free((*ps)->arr);
	(*ps)->arr = NULL;
	(*ps)->capacity = 0;
	(*ps)->size = 0;
}

void CheckCapacity(PSeq ps) {
	assert(ps);
	ps->arr = (int*)realloc(ps->arr, (ps->capacity + SIZE)*sizeof(int));
	if (ps == NULL) {
		assert(0);
		return;
	}
	ps->capacity += SIZE;
}

int main() {
	Seqlist seqlist;
	PSeq ps = &seqlist;
	SeqlistInit(ps, SIZE);
	system("pause");
	return 0;
}