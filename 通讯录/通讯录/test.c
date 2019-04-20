#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Contactinfo {
	char name[1024];
	char sex[1024];
	char age[1024];
	char phonenum[1024];
	char address[1024];
}Contactinfo;
typedef struct Addressbook {
	Contactinfo* contactinfo;
	int size;
	int capacity;
}Addressbook;
Addressbook addressbook;
#define SIZE 150
typedef void(*Func)();
void Empty() {
	//空函数
}
void Init() {
	addressbook.size = 0;
	addressbook.capacity = SIZE;
	addressbook.contactinfo = (Contactinfo*)malloc(
		addressbook.capacity * sizeof(Contactinfo));
	for (int i = 0; i < addressbook.capacity; ++i) {
		addressbook.contactinfo[i].name[0] = '\0';
		addressbook.contactinfo[i].sex[0] = '\0';
		addressbook.contactinfo[i].age[0] = '\0';
		addressbook.contactinfo[i].phonenum[0] = '\0';
		addressbook.contactinfo[i].address[0] = '\0';
	}
}
int Menu() {
	int choice;
	printf("========================\n");
	printf("1.添加联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.修改联系人\n");
	printf("5.显示联系人\n");
	printf("6.清空联系人\n");
	printf("7.以名字排续所有联系人\n");
	printf("8.保存联系人到文件\n");
	printf("9.加载联系人\n");
	printf("0.退出程序\n");
	printf("========================\n");
	printf("请输入指令:\n");
	scanf("%d", &choice);
	return choice;
}

void Addcontactinfo() {
	printf("新增联系人.\n");
	if (addressbook.size == addressbook.capacity) {
		printf("当前空间不足,进行扩容.\n");
		addressbook.capacity += SIZE;
		addressbook.contactinfo = (Contactinfo*)realloc
		(addressbook.contactinfo,sizeof(Contactinfo) * addressbook.capacity);
	}
	printf("请输入新增联系人姓名:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].name);
	printf("请输入新增联系人性别:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].sex);
	printf("请输入新增联系人年龄:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].age);
	printf("请输入新增联系人电话:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].phonenum);
	printf("请输入新增联系人住址:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].address);
	++addressbook.size;
	printf("新增联系人成功!\n");
}
void PrintAllcontactinfo();
void Delcontactinfo() {
	PrintAllcontactinfo();
	printf("删除联系人.\n");	
	int num;
	printf("请输入要删除联系人的序号:");
	scanf("%d", &num);
	if (num < 1 || num >addressbook.size) {
		printf("您要删除的联系人不存在!\n");
		return;
	}
	//strcpy(addressbook.contactinfo[num - 1].name, addressbook.contactinfo[addressbook.size - 1].name);
	//strcpy(addressbook.contactinfo[num - 1].sex, addressbook.contactinfo[addressbook.size - 1].sex);
	//strcpy(addressbook.contactinfo[num - 1].age, addressbook.contactinfo[addressbook.size - 1].age);
	//strcpy(addressbook.contactinfo[num - 1].phonenum, addressbook.contactinfo[addressbook.size - 1].phonenum);
	//strcpy(addressbook.contactinfo[num - 1].address, addressbook.contactinfo[addressbook.size - 1].address);
	addressbook.contactinfo[num - 1] = addressbook.contactinfo[addressbook.size - 1];
	--addressbook.size;
	printf("删除联系人成功!\n");
}

void Findcontactinfo() {
	printf("查找联系人.\n");
	char name[1024] = { 0 };
	int flag = 0;
	printf("请输入要查找联系人的姓名:\n");
	scanf("%s", name);
	for (int i = 0; i < addressbook.size; ++i) {
		if (strcmp(name, addressbook.contactinfo[i].name) == 0) {
			printf("[%d] %s %s %s %s %s\n", i + 1, addressbook.contactinfo[i].name,
				addressbook.contactinfo[i].sex, addressbook.contactinfo[i].age,
				addressbook.contactinfo[i].phonenum, addressbook.contactinfo[i].address);
			flag = 1;
		}
	}
	printf("查找联系人结束.\n");
	if(flag == 0){
		printf("没找到目标联系人!\n");
	}
}

void Updatecontactinfo() {
	printf("修改联系人.\n");
	PrintAllcontactinfo();
	int num;
	char scan[1024] = { 0 };
	printf("请输入要修改联系人的序号:");
	scanf("%d", &num);
	if (num <= 0 || num > addressbook.size) {
		printf("您输入的序号不存在!\n");
		return;
	}
	printf("请输入要修改的信息:\n输入'*'跳过当前修改\n");
	printf("姓名:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].name, scan);
	}
	printf("性别:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].sex, scan);
	}
	printf("年龄:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].age, scan);
	}
	printf("电话:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].phonenum, scan);
	}
	printf("地址:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].address, scan);
	}
	printf("修改联系人成功!\n");
}

void PrintAllcontactinfo() {
	printf("打印通讯录.\n");
	if (addressbook.size == 0) {
		printf("通讯录为空!\n");
	}
	else {
		for(int i = 0; i < addressbook.size; ++i){
		printf("[%d] %s %s %s %s %s\n", i + 1, addressbook.contactinfo[i].name,
			addressbook.contactinfo[i].sex, addressbook.contactinfo[i].age,
			addressbook.contactinfo[i].phonenum, addressbook.contactinfo[i].address);
		}
		printf("打印通讯录成功!\n");
	}
}

void ClearAllcontactinfo() {
	printf("清空所有联系人.\n");
	int num;
	printf("您确定要清空所有联系人?\n若果是,请输入'1'\n");
	scanf("%d", &num);
	if (num != 1) {
		printf("清空所有联系人取消.\n");
		return;
	}
	addressbook.size = 0;
	printf("清空联系人成功!\n");
}

void Sortcontactinfo() {
	printf("以名字排序所有联系人.\n");
	Contactinfo temp;
	for (int i = 0; i < addressbook.size; ++i) {
		for (int j = 0; j < addressbook.size - i - 1; ++j) {
			if (strcmp(addressbook.contactinfo[j].name,
				addressbook.contactinfo[j + 1].name) > 0) {
				temp = addressbook.contactinfo[j];
				addressbook.contactinfo[j] = addressbook.contactinfo[j + 1];
				addressbook.contactinfo[j + 1] = temp;
			}
		}
	}
	printf("排序全部联系人成功!\n");
}

void Savecontactinfo_tofile() {
	printf("保存联系人到文件.\n");
	int str[500][5] = { 0 };
	FILE* fp1 = fopen("../write-read.txt", "w");
	if (fp1 == NULL) {
		return;
	}
	for (int i = 0; i < addressbook.size; ++i) {
		str[i][0] = strlen(addressbook.contactinfo[i].name);
		str[i][1] = strlen(addressbook.contactinfo[i].sex);
		str[i][2] = strlen(addressbook.contactinfo[i].age);
		str[i][3] = strlen(addressbook.contactinfo[i].phonenum);
		str[i][4] = strlen(addressbook.contactinfo[i].address);	
		fwrite(str, 4, 5, fp1);
	}
	fclose(fp1);
	FILE* fp = fopen("../联系人信息.txt","w");
	if (fp == NULL) {
		return;
	}
	//fprintf(fp, "序号\t姓名\t性别\t年龄\t电话\t住址\n");
	for (int i = 0; i < addressbook.size; ++i) {
	//	fprintf(fp,"%d\t",i + 1);
		fwrite(addressbook.contactinfo[i].name,
			strlen(addressbook.contactinfo[i].name), 1, fp);
		fprintf(fp, "\t");
		fwrite(addressbook.contactinfo[i].sex ,
			strlen(addressbook.contactinfo[i].sex), 1, fp);
		fprintf(fp, "\t");
		fwrite(addressbook.contactinfo[i].age , 
			strlen(addressbook.contactinfo[i].age), 1, fp);
		fprintf(fp, "\t");
		fwrite(addressbook.contactinfo[i].phonenum ,
			strlen(addressbook.contactinfo[i].phonenum), 1, fp);
		fprintf(fp, "\t");
		fwrite(addressbook.contactinfo[i].address,
			strlen(addressbook.contactinfo[i].address), 1, fp);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("保存联系人到文件成功!\n");
}
void Loadcontactinfo() {
	printf("加载联系人.\n");
	int str[500][5] = { 0 };
	FILE* fp1 = fopen("../write-read.txt", "w");
	if (fp1 == NULL) {
		return;
	}
	for (int i = 1; i < 10; ++i) {
		fread(str, 4, 5, fp1);
	}
	fclose(fp1);
	FILE* fp = fopen("../联系人信息.txt", "r");
	if (fp == NULL) {
		return;
	}
	//fread(addressbook.contactinfo, sizeof(Contactinfo), 1, fp);
	//addressbook.size++;
	for (int i = 0; i < 10; i++) {
		fread(addressbook.contactinfo[addressbook.size].name, str[i][0], 1, fp);
		fread(addressbook.contactinfo[addressbook.size].sex, str[i][1], 1, fp);
		fread(addressbook.contactinfo[addressbook.size].age, str[i][2], 1, fp);
		fwrite(addressbook.contactinfo[addressbook.size].phonenum, str[i][3], 1, fp);
		fread(addressbook.contactinfo[addressbook.size].address, str[i][4], 1, fp);
		addressbook.size++;
	}
	fclose(fp);

	printf("加载联系人成功!\n");
}

int main() {
	Init();
	int choice;
	Func arr[] = {
		Empty,
		Addcontactinfo,
		Delcontactinfo,
		Findcontactinfo,
		Updatecontactinfo,
		PrintAllcontactinfo,
		ClearAllcontactinfo,
		Sortcontactinfo,
		Savecontactinfo_tofile,
		Loadcontactinfo
	};
	choice = Menu();
	while(1){
		if (choice >= sizeof(arr)/sizeof(arr[0]) || choice < 0) {
			printf("您输入的指令有误,请重新输入:");
			scanf("%d", &choice);
			continue;
		}
		if (choice == 0) {
			return 0;
		}
		else {
			arr[choice]();
		}
		scanf("%d", &choice);
	}
	system("pause");
	return 0;
}