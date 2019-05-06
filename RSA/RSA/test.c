#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void Printf(unsigned long long arr[],int size) {
	for (int i = 0; i < size; ++i) {
		printf("%llu,", arr[i]);
	}
}

unsigned long long FindE(unsigned long long fn) {
	unsigned long long e = rand() % fn;
	while (Gcd(fn, e) == 1) {
		unsigned long long e = rand() % fn;
	}
	return e;
}

int Gcd(unsigned long long fn, unsigned long long e) {
	if (e == 0) {
		return fn;
	}
	return Gcd(e, fn % e);
}

unsigned long long CountD1(unsigned long long e, unsigned long long fn) {
	unsigned long long d = 1;
	while ((d * e) % fn != 1&&d != fn) {
		d++;
	}
	return d;
}
unsigned long long CountD(unsigned long long a, unsigned long long b) {//a > b
	unsigned long long x[3] = { 1,0,a };
	unsigned long long y[3] = { 0,1,b };
	unsigned long long t[3] = { 0 };
	int Q;
	while (1) {
		if (y[2] == 0) {
			return x[2] = Gcd(a, b);
		}
		if (y[2] == 1) {
			return y[2] = Gcd(a, b);
		}
		Q = x[2] / y[2];
		for (int i = 0; i < 3; i++) {
			t[i] = x[i] - Q * y[i];
			x[i] = y[i];
			y[i] = t[i];
		}
	}
}
void LetterAndDNum(char arr[],char arr2[]) {
	int num;
	int size = strlen(arr);
	for (int i = 0; i < size; ++i) {
		num = arr[i] % 32;
		arr2[2 * i] = num / 10;
		arr2[2 * i + 1] = num % 10;
	}
}


int DtoB(char Bi[],unsigned long long temp) {
	int i;
	for (i = 0; temp > 0; temp /= 2,i++) {
		Bi[i] = temp % 2;
	}
	return i;
}
unsigned long long ModularArithmetic(unsigned long long temp, unsigned long long e,
	unsigned long long n) {
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

void Encrypt(char arr2[], unsigned long long arr3[],int size,int size2,
	unsigned long long e, unsigned long long n) { 
	unsigned long long temp = 0;
	for (int i = 0; i < size2; i += size) {
		for (int j = 0; j < size; j++) {
			temp += arr2[i + j] * pow(10,size - 1 - j);
		}

		arr3[i/size] = ModularArithmetic(temp, e, n);
	}
}

void Decode(unsigned long long arr[], unsigned long long d, unsigned long long n,int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = ModularArithmetic(arr[i], d, n);
	}
}
int main() {
	//printf("%d",Gcd(1970,1066));
	srand((unsigned long long)time(0));
	unsigned long long q, p;
	p = 7;//1593;
	q = 17;//7041;
	//p = 7;
	//q = 17;
	unsigned long long n = p * q;
	unsigned long long fn = (p - 1) * (q - 1);
	unsigned long long e = 5;// 1757316971;
	unsigned long long d = CountD(fn, e);
	//char arr[] = "Please wait for me"; 
	char arr[] = "s";
	char arr2[sizeof(arr) * 2 * 2] = { 0 };
	unsigned long long arr3[sizeof(arr) * 2 * 2] = { 0 };
	LetterAndDNum(arr, arr2);
	int size1 = 2;
	int size2 = 2 * strlen(arr);
	Encrypt(arr2, arr3, size1,size2,e,n);
	int size3 = size2 / size1 + !!(size2 % size1);
	Printf(arr3, size3);
	Decode(arr3, d, n,size3);
	Printf(arr3, size3); 
	system("pause");
	return 0;
}