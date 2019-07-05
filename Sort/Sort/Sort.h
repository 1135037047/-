#pragma once
#include <stdio.h>
#include <assert.h>


//��������:
//��������
void InsertSort(int* array, int size);
//ϣ������
void ShellSort(int array[], int size);

//ѡ������:
void SelectSort(int array[], int size);
//�Ľ���ѡ������
void SelectSortOP(int array[], int size);
//������
void HeapSort(int array[], int size);

//��������:
//ð������
void BubbleSort(int array[], int size);
//��������
int GetMiddleIndex(int array[], int left, int right);
int Partion1(int array[], int left, int right);
int Partion2(int array[], int left, int right);
int Partion3(int array[], int left, int right);
void QuickSort(int array[], int left, int right);

//�鲢����
void MergeSort(int array[], int size);
