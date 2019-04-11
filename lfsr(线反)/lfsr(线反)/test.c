#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ax 4
#define digit 34

void Bin(unsigned long long num,int* arr) {
	for (int i = 0;i < digit;++i) {
		arr[digit - 1 - i] = num % 2;
		num /= 2;
	}
}

void lfsr(int* arr,int*arr2,int *J) {
	int fy;	
	for (int x = 0; x < digit; ++x) {
		J[x] = arr[ax - 1];
		fy = ((arr[0] * arr2[0] + arr[1] * arr2[1] + arr[2] * arr2[2] + arr[3] * arr2[3]) % 2);
		int i = ax - 1;
		for (; i > 0; --i) {
			arr[i] = arr[i - 1];
		}
		arr[0] = fy;
		
	}
}

void J_K(int* J,int* K,int* key) {
	if ((J[0] == 0 && K[0] == 0) || (J[0] == 1 && K[0] == 1)) {
		key[0] = J[0];
	}
	else if (J[0] == 1 && K[0] == 0) {
		key[0] = 1;
	}
	else {
		key[0] = 0;
	}
	for (int i = 1; i < digit; ++i) {
		if (J[i] == 0 && K[i] == 0) {
			key[i] = key[i - 1];
		}
		else if (J[i] == 0 && K[i] == 1) {
			key[i] = 0;
		}
		else if (J[i] == 1 && K[i] == 0) {
			key[i] = 1;
		}
		else {
			key[i] = key[i - 1] ^ 1;
		}
	}
}

void ead(int* arr1,int* arr2,int* arr3) {
	for (int i = 0; i < digit; ++i) {
		arr3[i] = arr1[i] ^ arr2[i];
	}
}

void B_D(int* arr) {
	unsigned long long result = 0;
	for (int i = 0; i < digit; ++i) {
		result +=arr[i] * pow(2, digit - 1 - i);
	}
	printf("  学号:");
	printf("%llu\n",result);
}

int main() {
	unsigned long long id = 16100101115;
	int bin[digit] = {0};
	Bin(id,bin);
	printf("  原码:");
	for (int i = 0; i < digit; ++i) {
		printf("%d", bin[i]);
	}
	printf("\n");
	int J[digit] = { 0 };
	int K[digit] = { 0 };
	int key[digit] = { 0 };
	int cry[digit] = { 0 };
	int arr[ax] = {1,0,1,0};
	int arr1[ax] = { 0,1,0,1 };
	int arr2[ax] = { 1,1,0,0 };
	lfsr(arr,arr1,J);
	lfsr(arr,arr2,K);
	J_K(J,K,key);
	printf("J 序列:");
	for (int i = 0; i < digit; ++i) {
		printf("%d", J[i]);
	}	
	printf("\n");
	printf("K 序列:");
	for (int i = 0; i < digit; ++i) {
		printf("%d", K[i]);
	}
	printf("\n");
	printf("  密钥:");
	for (int i = 0; i < digit; ++i) {
		printf("%d", key[i]);
	}
	printf("\n");
	ead(bin,key,cry);
	printf("  密文:");
	for (int i = 0; i < digit; ++i) {
		printf("%d", cry[i]);
	}
	printf("\n");
	ead(key, cry, cry);
	printf("  原码:");
	for (int i = 0; i < digit; ++i) {
		printf("%d", cry[i]);
	}
	printf("\n");
	B_D(bin);
	system("pause");
	return 0;
}