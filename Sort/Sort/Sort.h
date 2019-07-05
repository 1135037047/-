#pragma once
#include <stdio.h>
#include <assert.h>


//²åÈëÅÅĞò:
//²åÈëÅÅĞò
void InsertSort(int* array, int size);
//Ï£¶ûÅÅĞò
void ShellSort(int array[], int size);

//Ñ¡ÔñÅÅĞò:
void SelectSort(int array[], int size);
//¸Ä½øµÄÑ¡ÔñÅÅĞò
void SelectSortOP(int array[], int size);
//¶ÑÅÅĞò
void HeapSort(int array[], int size);

//½»»»ÅÅĞò:
//Ã°ÅİÅÅĞò
void BubbleSort(int array[], int size);
//¿ìËÙÅÅĞò
int GetMiddleIndex(int array[], int left, int right);
int Partion1(int array[], int left, int right);
int Partion2(int array[], int left, int right);
int Partion3(int array[], int left, int right);
void QuickSort(int array[], int left, int right);

//¹é²¢ÅÅĞò
void MergeSort(int array[], int size);
