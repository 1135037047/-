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

//ջ�ĳ�ʼ��
void StackInit(Stack* ps);
//��ջ
void StackPush(Stack* ps, SDataType data);
//��ջ
void StackPop(Stack* ps);
//��ȡջ��Ԫ��
SDataType StackTop(Stack* ps);
//��ȡջ��Ԫ�ظ���
int StackSize(Stack* ps);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);
//����ջ
void StackDestroy(Stack* ps);
//ջ�ռ�����
void BuySpace(Stack* ps);
