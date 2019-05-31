#include "heap.h"

void Swap(HDataType* left, HDataType* right) {
	HDataType temp = *left;
	*left = *right;
	*right = temp;
}

int Big(HDataType left, HDataType right) {
	return left > right;
}

int Less(HDataType left, HDataType right) {
	return left < right;
}

void AdjustDown(Heap* hp, int parent) {
	assert(hp);
	int child = parent * 2 + 1;
	while (child < hp->size) {
		if (child + 1 < hp->size && hp->Compare(hp->array[child + 1], hp->array[child])) {
			child += 1;
		}
		if (hp->Compare(hp->array[child], hp->array[parent])) {
			Swap(&hp->array[parent], &hp->array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
	}
}

void AdjustUp(Heap* hp, int child) {
	assert(hp);
	int parent = (child - 1) >> 1;
	while (child) {
		if (hp->Compare(hp->array[child],hp->array[parent])) {
			Swap(&hp->array[child], &hp->array[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else {
			return;
		}
	}
}

void HeapInitEmpty(Heap* hp, int size, PCOM Compare) {
	assert(hp);
	hp->array = (HDataType*)malloc(sizeof(HDataType) * size);
	if (hp->array == NULL) {
		assert(0);
		return;
	}
	hp->size = 0;
	hp->capacity = size;
	hp->Compare = Compare;
}

void HeapInit(Heap* hp, HDataType array[], int size, PCOM Compare) {
	assert(hp);
	hp->array = (HDataType*)malloc(size * sizeof(HDataType));
	if (hp->array == NULL) {
		assert(0);
		return;
	}
	hp->size = 0;
	hp->capacity = size;
	hp->Compare = Compare;
	for (int i = 0; i < size; ++i) {
		hp->array[hp->size] = array[i];
		hp->size++;
	}
	for (int i = (((size - 1) - 1) >> 1); i >= 0; --i) {
		AdjustDown(hp,i);
	}
}

void HeapAdjust(HDataType array[],int size,int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size&&array[child + 1] > array[child]) {
			child += 1;
		}
		if (array[child] > array[parent]) {
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
	}
}
void HeapSort(HDataType array[],int size) {
	for (int i = (((size - 1) - 1) >> 1); i >= 0; --i) {
		HeapAdjust(array, size, i);
	}
	int end = size - 1; 
	while (end) {
		Swap(&array[0], &array[end]);
		HeapAdjust(array,end,0);
		end--;
	}
}

void HeapInsert(Heap* hp, HDataType data) {
	assert(hp);
	if (hp->size == hp->capacity) {
		hp->array = (HDataType*)realloc(hp->array, sizeof(HDataType) * hp->size * 2);
		if (hp->array == NULL) {
			assert(0);
			return;
		}
		hp->capacity = 2 * hp->capacity;
	}
	hp->array[hp->size] = data;
	hp->size++;
	AdjustUp(hp, hp->size - 1);
}
void HeapEraser(Heap* hp, int size) {
	assert(hp);
	if (hp->size == 0) {
		return;
	}
	Swap(&hp->array[size - 1], &hp->array[hp->size - 1]);
	hp->size--;
	if (size == 1) {
		size = 0;
	}
	else {
		size = ((size - 1) - 1) >> 1;
	}
	AdjustDown(hp, size);
}

int HeapEmpty(Heap* hp) {
	assert(hp);
	return !hp->size;
}

HDataType HeapTop(Heap* hp) {
	assert(hp);
	return hp->array[0];
}

int HeapSize(Heap* hp) {
	assert(hp);
	return hp->size;
}

void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}

 int main() {
	HDataType arr[] = {1,3,5,7,9,2,4,6,8,};
	Heap hp;
	Heap hpp;
	HeapInitEmpty(&hpp, 5, Big);
	HeapInsert(&hpp, 5);
	HeapInsert(&hpp, 8);
	HeapInsert(&hpp, 3);
	HeapInsert(&hpp, 1);
	HeapInsert(&hpp, 9);
	HeapInsert(&hpp, 6);
	HeapSort(hpp.array, hpp.size);
	HeapDestory(&hpp);

	HeapInit(&hp, arr, sizeof(arr) / sizeof(arr[0]), Less);
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	HeapEraser(&hp, 1);
	HeapInsert(&hp, 1);
	HeapSize(&hp);
	HeapTop(&hp);
	HeapEmpty(&hp);
	HeapSort(hp.array, hp.size);
   	HeapDestory(&hp);
	return 0;
  }