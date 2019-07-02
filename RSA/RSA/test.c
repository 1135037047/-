#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int Miller_Rabin() {
	long long n = rand();
	while (1) {
		
		if (n < 2) {
			n = n + 3;
			continue;
		}
		if (n == 2) {
			return n;
		}
		long long q = 0, m = n - 1;
		while (m % 2 == 0) {
			m /= 2;
			++q;
		}
		if (q == 0) {
			n = n + 3;
			continue;
		}
		long long a = rand() % (n - 2) + 2;
		long long x1 = (long long)pow(a, m), x2;
		x2 = x1 % n;
		if (x2 == 1 && x1 != 1 && x1 != n - 1) {
			n = n + 3;
			continue;
		}
		for (int i = 1; i <= q; ++i) {
			x2 = (x1 * x1) % n;
			if (x2 == 1 && x1 != 1 && x1 != n - 1) {
				n = n + 3;
				continue;
			}
			x1 = x2;
		}
		if (x2 != 1) {
			n = n + 3;
			continue;
		}
		else {
			return n;
		}
	}
}


void Printf(long long arr[],int size) {
	for (int i = 0; i < size; ++i) {
		printf("%lld,", arr[i]);
	}
	printf("\n");
}

long long FindE(long long fn) {
	long long e = rand() % (fn - 2) + 2;
	while (Gcd(fn,e) != 1) {
		long long e = rand() % (fn - 2) + 2;
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
//快速指数算法
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
	//分组
	for (int i = 0; i < size2; i += size) {
		long long temp = 0;
		for (int j = 0; j < size; j++) {
			temp += arr2[i + j] * pow(10,size - 1 - j);
		}
		//对每一个分组进行加密
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
	long long q, p;
	p = Miller_Rabin();
	q = Miller_Rabin();
	long long n = p * q;
	long long fn = (p - 1) * (q - 1);
	long long e = FindE(fn);
	//欧几里得算法求乘法逆元
	long long d = CountD(fn,e);
	//存储字符串
	char arr[1024]; 
	printf("请输入要加密的消息:\n");
	scanf("%[^\n]", arr);
	//存储字符串的ASCII
	char arr2[sizeof(arr) * 2 * 2] = { 0 };

	long long arr3[sizeof(arr) * 2 * 2] = { 0 };
	//将字符串转换为数字存储在arr2
	LettersAndNum(arr, arr2);
	//分组长度
	int size1 = SizeN(n);
	//arr2中存储内容的长度
	int size2 = 2 * strlen(arr);
	//分组个数
	int size3 = size2 / size1 + !!(size2 % size1);
	printf("明文:");
	for (int i = 0; i < 2 * strlen(arr); i++) {
		printf("%d", arr2[i]);
	}
	printf("\n");
	//加密
	Encrypt(arr2, arr3, size1,size2,e,n);
	printf("密文:");
	Printf(arr3, size3);
	//解密
	Decode(arr3, d, n,size3);
	printf("解密明文:");
	Printf(arr3, size3); 
	//将密文组转换为两位数的ASCII码
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