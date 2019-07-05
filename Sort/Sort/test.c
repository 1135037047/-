#include "Sort.h"
#include "Stack.h"

void Swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//时间复杂度O(N^2) 空间复杂度O(1)  稳定的
void InsertSort(int* array, int size) {
	assert(array);
	int key,end;
	for (int i = 1; i < size; ++i) {
		key = array[i];
		end = i - 1;
		while (end >= 0 && key < array[end]) {
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
//时间复杂度O((1-1.6)N^1.25)  空间复杂度O(1)  不稳定
void ShellSort(int array[],int size) {
	int gap = size / 3 + 1;
	int key, end;
	for (; gap > 0; gap = gap / 3 + 1) {
		for (int i = gap; i < size; ++i) {
			key = array[i];
			end = i - gap;
			while (end >= 0 && key < array[end]) {
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}
//时间复杂度O(N^2) 空间复杂度O(N) 不稳定
void SelectSort(int array[], int size) {
	for (int i = 0; i < size -1; ++i) {
		int maxPos = 0;
		for (int j = 1; j < size - i; ++j) {
			if (array[j] > array[maxPos]) {
				maxPos = j;
			}
		}
		if (maxPos != size - i - 1) {
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}



void Adjustdown(int array[], int parent, int size) {
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size && array[child + 1] > array[child]) {
			child = child + 1;
		}
		if (array[child] > array[parent]) {
			Swap(&array[child], &array[parent]);
		}
		parent = child;
		child = 2 * parent + 1;
	}
}
//时间复杂度O(NlogN) 空间复杂度O(1) 不稳定
void HeapSort(int array[], int size) {
	for (int i = (size - 1) >> 1; i >= 0; --i) {
		Adjustdown(array,i,size);
	}
	for (int i = size - 1; i > 0; --i) {
		Swap(&array[0], &array[i]);
		Adjustdown(array, 0, i);
	}
}

//时间复杂度O(N^2) 空间复杂度O(1) 不稳定
void SelectSortOP(int array[], int size) {
	int begin = 0;
	int end = size - 1;
	while (begin < end) {
		int maxPos = begin;
		int minPos = begin;
		int index = begin + 1;
		while (index <= end) {
			if (array[index] > array[maxPos]) {
				maxPos = index;
			}
			if (array[index] < array[minPos]) {
				minPos = index;
			}
			index++;
		}
		if (maxPos != end) {
			Swap(&array[maxPos], &array[end]);
		}
		if (minPos == end) {
			Swap(&array[maxPos], &array[begin]);
		}
		else if (minPos != begin) {
			Swap(&array[minPos], &array[begin]);
		}
		begin++;
		end--;
	}
}

//时间复杂度O(N^2) 空间复杂度O(1)  稳定
void BubbleSort(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 1; j < size - i; ++j) {
			if (array[j] < array[j - 1]) {
				Swap(&array[j], &array[j - 1]);
			}
		}
	}
}

int GetMiddleIndex(int array[], int left, int right) {
	int mid = left + (right - left) >> 1;
	if (array[left] < array[right - 1]) {
		if (array[left] < array[mid]) {
			if (array[mid] < array[right - 1]) {
				return mid;
			}
			else {
				return right - 1;
			}
		}
		else {
			return left;
		}
	}
	else {
		if (array[left] > array[mid]) {
			if (array[mid] > array[right - 1]) {
				return mid;
			}
			else {
				return right - 1;
			}
		}
		else {
			return left;
		}
	}
}

//时间复杂度O(N) 空间复杂度O(N)
int Partion1(int array[], int left, int right) {
	int begin = left;
	int end = right - 1;
	int dev = GetMiddleIndex(array, left, right);
	Swap(&array[dev], &array[right - 1]);
	int key = array[right - 1];
	while (begin < end) {
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		while (begin < end && array[end] >= key) {
			end--;
		}
		if (begin != end) {
			Swap(&array[begin], &array[end]);
		}
	}
	if (begin != right) {
		Swap(&array[begin], &array[right - 1]);
	}
	return begin;
}
//时间复杂度O(N) 空间复杂度O(N)
int Partion2(int array[], int left, int right) {
	int begin = left;
	int end = right - 1;
	int dev = GetMiddleIndex(array, left, right);
	Swap(&array[dev], &array[right - 1]);
	int key = array[right - 1];
	while (begin < end) {
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		if (begin < end) {
			array[end] = array[begin];
			end--;
		}
		while (begin < end && array[end] >= key) {
			end--;
		}
		if (begin < end) {
			array[begin] = array[end];
			begin++;
		}
	}
	array[begin] = key;
	return begin;
}
//时间复杂度O(N) 空间复杂度O(N)
int Partion3(int array[], int left, int right) {
	int cur = left;
	int prev = cur - 1;
	int dev = GetMiddleIndex(array, left, right);
	Swap(&array[dev], &array[right - 1]);
	int key = array[right - 1];
	while (cur < right) {
		if (array[cur] < key && ++prev != cur) {
			Swap(&array[cur], &array[prev]);
		}
		cur++;
	}
	if (++prev != right - 1) {
		Swap(&array[right - 1], &array[prev]);
	}
	return prev;
}
//时间复杂度最差O(N^2) 最优O(NlogN) 优化之后时间复杂度近似为O(NlogN)
//空间复杂度O(logN)   不稳定
void QuickSort(int array[], int left,int right) {
	if (right - left < 16) {
		InsertSort(array, right - left);
	}
	else {
		int div = Partion3(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

void QuickSortNor(int array[],int size) {
	int left = 0;
	int right = size;
	int dev = Partion1(array, left, size);
	Stack p;
	StackInit(&p);
	StackPush(&p, right);
	StackPush(&p, left);
	while (!StackEmpty(&p)) {
		left = StackTop(&p);
		StackPop(&p);
		right = StackTop(&p);
		StackPop(&p);
		if (right - left > 1) {
			int dev = Partion1(array, left, right);
			StackPush(&p, right);
			StackPush(&p, dev + 1);
			StackPush(&p, dev);
			StackPush(&p, left);
		}
	}
	StackDestroy(&p);
}

void _MergeData(int array[], int left, int mid, int right, int* temp) {
	int index = left;
	int ptr1 = left;
	int ptr2 = mid;
	while (ptr1 < mid && ptr2 < right) {
		if (array[ptr1] < array[ptr2]) {
			temp[index++] = array[ptr1++];
		}
		else {
			temp[index++] = array[ptr2++];
		}
	}
	while (ptr1 < mid) {
		temp[index++] = array[ptr1++];
	}
	while (ptr2 < right) {
		temp[index++] = array[ptr2++];
	}
}

//时间复杂度O(NlogN) 空间复杂度O(N) 稳定
void _MergeSort(int array[], int left, int right,int* temp) {
	if (right - left > 1) {
		int mid = left + ((right - left) >> 1);
		_MergeSort(array, left, mid,temp);
		_MergeSort(array, mid, right, temp);
		_MergeData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, sizeof(int) * (right - left));
	}
}

//时间复杂度O(NlogN) 空间复杂度O(N) 稳定
void MergeSortNor(int array[],int size) {
	int* temp = (int*)malloc(sizeof(int) * size);
	if (temp == NULL) {
		assert(0);
		return;
	}
	int gap = 1;
	while (gap < size) {
		for (int i = 0; i < size; i += 2 * gap) {
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid > size) {
				mid = size;
			}
			if (right > size) {
				right = size;
			}
			_MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, sizeof(int) * size);
		gap = 2 * gap;
	}
}

void MergeSort(int array[], int size) {
	int* temp = (int*)malloc(sizeof(int) * size);
	if (temp == NULL) {
		assert(0);
		return;
	}
	_MergeSort(array, 0, size,temp);
	free(temp);
}

void CountSort(int array[], int size) {
	int maxnum = array[0];
	int minnum = array[0];
	for (int i = 0; i < size; ++i) {
		if (array[i] > maxnum) {
			maxnum = array[i];
		}
		if (array[i] < minnum) {
			minnum = array[i];
		}
	}
	int size1 = maxnum - minnum + 1;
	int* temp = (int*)calloc(size1,sizeof(int));
	if (temp == NULL) {
		assert(0);
		return;
	}
	for (int i = 0; i < size; ++i) {
		temp[i - minnum]++;
	}
	int count = 0;
	for (int i = 0; i < size1; ++i) {
		while (temp[i]) {
			array[count++] = i + minnum;
			temp[i]--;
		}
	}
}

int main() {
	int arr[] = { 3,1,5,7,2,6,9,4,8,0 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}