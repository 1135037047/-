#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Printf(char *arr,int size,int size2) {
	for (int i = 0; i < size; ++i) {
		printf("%2d ", arr[i]);
		if (!((i + 1) % size2)) {
			printf("\n");
		}
	}
}
void permute_arr(char *arr) {
	char arr1[64] = {
	arr[57],arr[49],arr[41],arr[33],arr[25],arr[17],arr[9],arr[1],
	arr[59],arr[51],arr[43],arr[35],arr[27],arr[19],arr[11],arr[3],
	arr[61],arr[53],arr[45],arr[37],arr[29],arr[21],arr[13],arr[5],
	arr[63],arr[55],arr[47],arr[39],arr[31],arr[23],arr[15],arr[7],
	arr[56],arr[48],arr[40],arr[32],arr[24],arr[16],arr[8],arr[0],
	arr[58],arr[50],arr[42],arr[34],arr[26],arr[18],arr[10],arr[2],
	arr[60],arr[52],arr[44],arr[36],arr[28],arr[20],arr[12],arr[4],
	arr[62],arr[54],arr[46],arr[38],arr[30],arr[22],arr[14],arr[6]
	};
	for (int i = 0; i < 64; ++i) {
		arr[i] = arr1[i];
	}
}
void inpermute_arr(char* arr) {
	char arr1[64] = {
		arr[39],arr[7],arr[47],arr[15],arr[55],arr[23],arr[63],arr[31],
		arr[38],arr[6],arr[46],arr[14],arr[54],arr[22],arr[62],arr[30],
		arr[37],arr[5],arr[45],arr[13],arr[53],arr[21],arr[61],arr[29],
		arr[36],arr[4],arr[44],arr[12],arr[52],arr[20],arr[60],arr[28],
		arr[35],arr[3],arr[43],arr[11],arr[51],arr[19],arr[59],arr[27],
		arr[34],arr[2],arr[42],arr[10],arr[50],arr[18],arr[58],arr[26],
		arr[33],arr[1],arr[41],arr[9],arr[49],arr[17],arr[57],arr[25],
		arr[32],arr[0],arr[40],arr[8],arr[48],arr[16],arr[56],arr[24]
	};
	for (int i = 0; i < 64; ++i) {
		arr[i] = arr1[i];
	}
}
void exten_dE(char *R,char *Re) {
	char R1[48] = {
		R[31],R[0],R[1],R[2],R[3],R[4],
		R[3],R[4],R[5],R[6],R[7],R[8],
		R[7],R[8],R[9],R[10],R[11],R[12],
		R[11],R[12],R[13],R[14],R[15],R[16],
		R[15],R[16],R[17],R[18],R[19],R[20],
		R[19],R[20],R[21],R[22],R[23],R[24],
		R[23],R[24],R[25],R[26],R[27],R[28],
		R[27],R[28],R[29],R[30],R[31],R[0]
	};
	for (int i = 0; i < 48; ++i) {
		Re[i] = R1[i];
	}

}
void permute_key1(char *key,char* key0) {
	char key1[56] = {
		key[56],key[48],key[40],key[32],key[24],key[16],key[8],
		key[0],key[57],key[49],key[41],key[33],key[25],key[17],
		key[9],key[1],key[58],key[50],key[42],key[34],key[26],
		key[18],key[10],key[2],key[59],key[51],key[43],key[35],
		key[62],key[54],key[46],key[38],key[30],key[22],key[14],
		key[6],key[61],key[53],key[45],key[37],key[29],key[21],
		key[13],key[5],key[60],key[52],key[44],key[36],key[28],
		key[20],key[12],key[4],key[27],key[19],key[11],key[3]
	};	
	for (int i = 0; i < 56; ++i) {
		key0[i] = key1[i];
	}
}
void lefts(char *arr,int size) {
	int temp;
	int i, j;
	for (i = 0; i < size; ++i) {
		temp = arr[0];
		for (j = 0; j < 28 - 1; ++j) {
			arr[j] = arr[j + 1];		
		}
		arr[27] = temp;
	}
}
void permute_key2(char *C,char *D,char *K) {
	char K1[56];
	for (int i = 0; i < 28; ++i) {
		K1[i] = C[i];
		K1[i + 28] = D[i];
	}
	char K2[48] = {
		K1[13],K1[16],K1[10],K1[23],K1[0],K1[4],
		K1[2],K1[27],K1[14],K1[5],K1[20],K1[9],
		K1[22],K1[18],K1[11],K1[3],K1[25],K1[7],
		K1[15],K1[6],K1[26],K1[19],K1[12],K1[1],
		K1[40],K1[51],K1[30],K1[36],K1[46],K1[54],
		K1[29],K1[39],K1[50],K1[44],K1[32],K1[47],
		K1[43],K1[48],K1[38],K1[55],K1[33],K1[52],
		K1[45],K1[41],K1[49],K1[35],K1[28],K1[31],
	};
	for (int i = 0; i < 48; ++i) {
		K[i] = K2[i];
	}	
}
void permute_FP(char* Fs) {
	char Fs1[32] = {
		Fs[15],Fs[6],Fs[19],Fs[20],
		Fs[28],Fs[11],Fs[27],Fs[16],
		Fs[0],Fs[14],Fs[22],Fs[25],
		Fs[4],Fs[17],Fs[30],Fs[9],
		Fs[1],Fs[7],Fs[23],Fs[13],
		Fs[31],Fs[26],Fs[2],Fs[8],
		Fs[18],Fs[12],Fs[29],Fs[5],
		Fs[21],Fs[10],Fs[3],Fs[24],
	};
	for (int i = 0; i < 32; ++i) {
		Fs[i] = Fs1[i];
	}
}
void Sprintf(char* Fs,char num,int fs) {
	for (int i = 0; i < 4; ++i,num /= 2) {
		Fs[fs + 3 - i] = num % 2;
	}
}
char Snnum(char DESs[8][4][16], char* RK,int j) {
	char num;
	num = DESs[j / 6][RK[j] * 2 + RK[j + 5]]
		[RK[j + 1] * 8 + RK[j + 2] * 4 +
		RK[j + 3] * 2 + RK[j + 4]];
	return num;
}
void to_B(unsigned long long num,char* arr,int size) {
	for (int i = 0; i < size; ++i,num /= 2) {
		arr[size - 1 - i] = num % 2;
	}
}
unsigned long long to_D(char* arr,int size) {
	unsigned long long num2 = 0;
	for (int i = 0; i < size; ++i) {
		num2 += (unsigned long long)arr[i] * (unsigned long long)pow(2, size - i - 1);
	}
	return num2;
}
void Ring(char* arr,char* key,char leftst[16],char DESs[8][4][16],
	unsigned long long *num2,char k16[16][48]) {
	char L[32];
	char R[32];
	char L1[32];
	char R1[32];
	char Re[48];
	char C[28];
	char D[28];
	char K[48];
	char RK[48];
	char Fs[32];
	for (int i = 0; i < 28; ++i) {
		C[i] = key[i];
		D[i] = key[i + 28];
	}
	for (int i = 0; i < 32; ++i) {
		L[i] = arr[i];
		R[i] = arr[i + 32];
	}
	for (int ring = 0; ring < 16; ++ring) {
		lefts(C, leftst[ring]);
		lefts(D, leftst[ring]);
		permute_key2(C, D, K);
		//Printf(K, 48, 48);
		for (int i = 0; i < 48; ++i) {
			k16[ring][i] = K[i];
		}
		exten_dE(R, Re);
		for (int i = 0; i < 48; ++i) {
			RK[i] = Re[i] ^ K[i];
		}
		char num;
		for (int j = 0; j < 43; j += 6) {
			num = Snnum(DESs, RK,j);
			Sprintf(Fs, num, (j / 6) * 4);
		}
		Printf(Fs, 32, 32);
		permute_FP(Fs);
		//Printf(Fs, 32, 32);
		for (int i = 0; i < 32; ++i) {
			L1[i] = R[i];
			R1[i] = L[i] ^ Fs[i];
		}
		for (int i = 0; i < 32; ++i) {
			L[i] = L1[i];
			R[i] = R1[i];
		}
		//Printf(k16[ring], 48, 48);
	}
	for (int i = 0; i < 32; ++i) {
		arr[i] = R[i];
		arr[i + 32] = L[i];
	}
	inpermute_arr(arr);
	Printf(arr, 64, 32);
	*num2 = to_D(arr, 64);
	//printf ("%llu\n",*num2);
	//to_B(num, arr, 64);
	//Printf(arr, 64, 8);
	
}
void jRing(char* arr,char DESs[8][4][16],char k16[16][48],
	unsigned long long* num3) {
	char L[32];
	char R[32];
	char L1[32];
	char R1[32];
	char Re[48];
	char RK[48];
	char Fs[32];
	for (int i = 0; i < 32; ++i) {
		L[i] = arr[i];
		R[i] = arr[i + 32];
	}
	for (int ring = 0; ring < 16; ++ring) {
		exten_dE(R, Re);
		for (int i = 0; i < 48; ++i) {
			RK[i] = Re[i] ^ k16[16 - 1 - ring][i];
		}
		char num;
		for (int j = 0; j < 43; j += 6) {
			num = Snnum(DESs, RK, j);
			Sprintf(Fs, num, (j / 6) * 4);
		}
		permute_FP(Fs);
		for (int i = 0; i < 32; ++i) {
			L1[i] = R[i];
			R1[i] = L[i] ^ Fs[i];
		}
		for (int i = 0; i < 32; ++i) {
			L[i] = L1[i];
			R[i] = R1[i];
		}
		//Printf(k16[ring], 48, 48);
	}
	for (int i = 0; i < 32; ++i) {
		arr[i] = R[i];
		arr[i + 32] = L[i];
	}
	inpermute_arr(arr);
	//Printf(arr, 64, 8);
	*num3 = to_D(arr, 64);
	//printf("%llu\n", *num3);
	//to_B(num, arr, 64);
	//Printf(arr, 64, 8);

}
int main() {
	unsigned long long num = 81985529216486895;
	unsigned long long num2;
	unsigned long long num3;
	//printf("%d", sizeof(unsigned long long));
	//Key 取值范围0 - 72,597,594,037,927,936
	unsigned long long Key = 1383827165325090801;
	char arr[64] = { 0 };
	char key0[64] = { 0 };	
	char key[56] = { 0 };
	char k16[16][48] = { 0 };
	char leftst[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
	char DESs[8][4][16] = {
		14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
		0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
		4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
		15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13,
		15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
		3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
		0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
		13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9,
		10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
		13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
		13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
		1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12,
		7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
		13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
		10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
		3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14,
		2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
		14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
		4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
		11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3,
		12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
		10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
		9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
		4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13,
		4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
		13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
		1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
		6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12,
		13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
		1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
		7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
		2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
	};
	//printf("%d", DESs[5][3][12]);
	//system("pause");
	//加密
	to_B(num, arr, 64);
	to_B(Key, key0, 64);
	//Printf(arr, 64, 64);
	//Printf(key0, 64, 64);
	permute_arr(arr);
	//Printf(arr, 64, 64);
	permute_key1(key0,key);
	Ring(arr, key, leftst, DESs,&num2,k16);
	printf("%llu\n", num2);
	//解密
	to_B(num2, arr, 64);
	permute_arr(arr);
	jRing(arr,DESs,k16,&num3);
	printf("%llu\n", num3);
	system("pause");
	return 0;
}