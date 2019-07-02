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

//栈的初始化
void StackInit(Stack* ps);
//入栈
void StackPush(Stack* ps, SDataType data);
//出栈
void StackPop(Stack* ps);
//获取栈顶元素
SDataType StackTop(Stack* ps);
//获取栈中元素个数
int StackSize(Stack* ps);
//判断栈是否为空
int StackEmpty(Stack* ps);
//销毁栈
void StackDestroy(Stack* ps);
//栈空间扩容
void BuySpace(Stack* ps);
