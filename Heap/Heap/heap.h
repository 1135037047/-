#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

 
typedef int HDataType;
typedef int(*PCOM)(HDataType left, HDataType right);
int Less(HDataType left, HDataType right);
typedef struct Heap {
	HDataType* array;
	int size;
	int capacity;
	PCOM Compare;
}Heap;

void HeapSort(HDataType array[], int size);
void HeapInit(Heap* hp, int array[],int size,PCOM Compare);
void HeapInsert(Heap* hp, HDataType data);
void HeapEraser(Heap* hp, int size);
HDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestory(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapInitEmpty(Heap* hp, int size, PCOM);