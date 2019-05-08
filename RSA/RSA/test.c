#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void Sushu(int size, int arr[]) {
	int temp = 1;
	for (int i = 0; i < size; ++i) {
		int flag = 1;
		while (flag) {
			temp++;
			int j = 2;
			for (; j <= sqrt(temp); ++j) {
				if (temp % j == 0) {
					break;
				}
			}
			if (j > sqrt(temp)) {
				flag = 0;
			}
		}
		arr[i] = temp;
	}
}

void Printf(long long arr[],int size) {
	for (int i = 0; i < size; ++i) {
		printf("%lld,", arr[i]);
	}
	printf("\n");
}

long long FindE(long long fn,int arrs[]) {
	long long e = arrs[rand() % 968 + 32];
	while (Gcd(fn,e) != 1) {
		long long e = arrs[rand() % 968 + 32];
	}
	return e;
}

void NumAndLetters(long	long arr1[], char arr2[], int size1, int size3) {
	int size = size1 / 2;
	for (int i = 0; i < size3; ++i) {
		for (int j = 0; j < size; arr1[i] /= 100, j++) {
			arr2[i * size + size - j - 1] = arr1[i] % 100;
		}
	}
}

int Gcd(long long fn,long long e) {
	if (e == 0) {
		return fn;
	}
	return Gcd(e, fn % e);
}

long long CountD(long long a, long long b) {//a > b
	long long x[3] = { 1,0,a };
	long long y[3] = { 0,1,b };
	long long t[3] = { 0 };
	int Q;
	while (1) {
		if (y[2] == 0) {
			return x[2];
		}
		if (y[2] == 1) {
			if (y[1] < 0) {
				return y[1] + a;
			}
			return y[1];
		}
		Q = x[2] / y[2];
		for (int i = 0; i < 3; i++) {
			t[i] = x[i] - Q * y[i];
			x[i] = y[i];
			y[i] = t[i];
		}
	}
}
void LettersAndNum(char arr[],char arr2[]) {
	int num;
	int size = strlen(arr);
	for (int i = 0; i < size; ++i) {
		num = arr[i] % 100;
		arr2[2 * i] = num / 10;
		arr2[2 * i + 1] = num % 10;
	}
}


int DtoB(char Bi[],long long temp) {
	int i;
	for (i = 0; temp > 0; temp /= 2,i++) {
		Bi[i] = temp % 2;
	}
	return i;
}
long long ModularArithmetic(long long temp, long long e,long long n) {
	char Bi[64] = { 0 };
	int size;
	size = DtoB(Bi, e);
	unsigned long long d = 1;
	for (int i = 0; i < size; i++) {
		d = (d*d) % n;
		if (Bi[size - 1 - i] == 1) {
			d = (d * temp) % n;
		}
	}
	return d;
}

void Encrypt(char arr2[], long long arr3[],int size,int size2,
	long long e, unsigned long long n) { 
	for (int i = 0; i < size2; i += size) {
		long long temp = 0;
		for (int j = 0; j < size; j++) {
			temp += arr2[i + j] * pow(10,size - 1 - j);
		}

		arr3[i/size] = ModularArithmetic(temp, e, n);
	}
}

void Decode(long long arr[], long long d, long long n,int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = ModularArithmetic(arr[i], d, n);
	}
}

int SizeN(int n) {
	int count = 0;
	for (; n > 0; n /= 10) {
		count++;
	}
	if (count % 2 != 0) {
		count++;
	}
	return count / 2;
}

int main() {
	srand((long long)time(0));
	//[137,17389]素数范围 
	int arrs[2048] = { 0 };
	Sushu(1000, arrs);
	long long q, p;
	p = arrs[rand() % 968 + 32];
	q = arrs[rand() % 968 + 32];
	long long n = p * q;
	long long fn = (p - 1) * (q - 1);
	long long e = FindE(fn,arrs);
	long long d = CountD(fn,e);
	char arr[1024]; 
	printf("请输入要加密的消息:\n");
	scanf("%[^\n]", arr);
	char arr2[sizeof(arr) * 2 * 2] = { 0 };
	long long arr3[sizeof(arr) * 2 * 2] = { 0 };
	LettersAndNum(arr, arr2);
	int size1 = SizeN(n);
	int size2 = 2 * strlen(arr);
	int size3 = size2 / size1 + !!(size2 % size1);
	printf("明文:");
	for (int i = 0; i < 2 * strlen(arr); i++) {
		printf("%d", arr2[i]);
	}
	printf("\n");
	Encrypt(arr2, arr3, size1,size2,e,n);
	printf("密文:");
	Printf(arr3, size3);
	Decode(arr3, d, n,size3);
	printf("解密明文:");
	Printf(arr3, size3); 
	NumAndLetters(arr3, arr2, size1, size3);
	printf("消息:");
	for (int i = 0; i < strlen(arr);i++) {
		if (arr2[i] < 30) {
			printf("%c", arr2[i] + 100);
		}
		else {
			printf("%c", arr2[i]);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}