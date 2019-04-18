#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int Strcmp(const char* str1,const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	int i = 0;
	for (; str1[i] != '\0'&&
		str2 != '\0'; ++i) {
		if (str1[i] < str2[i]) {
			return -1;
		}
		if (str1[i] > str2[i]) {
			return 1;
		}
	}
	if (str1[i] < str2[i]) {
		return -1;
	}
	else if(str1[i] > str2[i]) {
		return 1;
	}
	else {
		return 0;
	}	
}
char* Strcat(char * destination, const char* source) {
	assert(destination != NULL);
	assert(source != NULL);
	int i = 0;
	int j = 0;
	for (; destination[i] != '\0'; ++i);
	for (; source[j] != '\0'; ++j, ++i) {
		destination[i] = source[j];
	}
	destination[i] = source[j];
	return destination;
}
char* Strcpy(char* destination, const char * source) {
	assert(destination != NULL);
	assert(source != NULL);
	int size = Strlen(source);
	int i;
	for (i = 0; i < size; ++i) {
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}
size_t Strlen(const char* str) {
	assert(str != NULL);
	size_t i = 0;
	for (; str[i] != '\0'; ++i);
	return i;
}

const char* Strstr(const char* str1,const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	if (str2 == '\0') {
		return NULL;
	}
	const char* bleak_ptr = str1;
	while (*bleak_ptr!='\0') {
		const char* sub_ptr = str2;
		const char* red_ptr = bleak_ptr;
		while (*red_ptr != '\0'&&*sub_ptr != '\0'&&*red_ptr == *sub_ptr) {
				++red_ptr;
				++sub_ptr;
		}
		if (*sub_ptr == '\0') {
			return bleak_ptr;
		}
		++bleak_ptr;
	}
	return NULL;
}
const char * Strchr(const char* str, int character) {
	assert(str != NULL);
	for (; *str != '\0'&&*str != character; ++str);
	if (*str == character) {
		return str;
	}
	else {
		return NULL;
	}

}

void* Memcpy(void * destination, const void * source, size_t num) {
	char* p1 =(char*) destination;
	const char* p2 = (const char*)source;
	for (int i = 0; i < num; ++i) {
		p1[i] = p2[i];
	}
	return destination;
}
void* Memmove(void * destination, const void * source, size_t num) {
	char* p1 = (char*)destination;
	const char* p2 = (const char*)source;
	if (p2 >= p1 && p2 <= p1 + num) {
		for (int i = num - 1; i >= 0; ++i) {
			p1[i] = p2[i];
		}
	}
	else {
		for (int i = 0; i < num; ++i) {
			p1[i] = p2[i];
		}
	}
	return destination;
}
int main() {
	char a[1024] = "abcde";
	char b[1024] = "fg";
	char c[] = "bcd";
	printf("%s\n",Strcpy(b,a));
	printf("%d\n",Strlen(a));
	printf("%d\n", Strcmp(a, b));
	printf("%s\n", Strcat(a, b));
	printf("%s\n",Strstr(a, c));
	printf("%s\n", Strchr(a, 'e'));
	printf("%s\n", Memcpy(a, c, 2));
	printf("%s\n", Memmove(a, c, 3));
	system("pause");
	return 0;
}