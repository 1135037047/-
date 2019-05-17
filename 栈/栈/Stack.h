#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define SIZE 5
typedef int SDataType;
typedef struct Stack {
	SDataType* arr;
	int capaciity;
	int size;
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps, SDataType data);
void StackPop(Stack* ps);
SDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestroy(Stack* ps);
void BuySpace(Stack* ps);
