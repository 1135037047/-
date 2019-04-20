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
	//�պ���
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
	printf("1.�����ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.��ʾ��ϵ��\n");
	printf("6.�����ϵ��\n");
	printf("7.����������������ϵ��\n");
	printf("8.������ϵ�˵��ļ�\n");
	printf("9.������ϵ��\n");
	printf("0.�˳�����\n");
	printf("========================\n");
	printf("������ָ��:\n");
	scanf("%d", &choice);
	return choice;
}

void Addcontactinfo() {
	printf("������ϵ��.\n");
	if (addressbook.size == addressbook.capacity) {
		printf("��ǰ�ռ䲻��,��������.\n");
		addressbook.capacity += SIZE;
		addressbook.contactinfo = (Contactinfo*)realloc
		(addressbook.contactinfo,sizeof(Contactinfo) * addressbook.capacity);
	}
	printf("������������ϵ������:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].name);
	printf("������������ϵ���Ա�:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].sex);
	printf("������������ϵ������:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].age);
	printf("������������ϵ�˵绰:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].phonenum);
	printf("������������ϵ��סַ:\n");
	scanf("%s", addressbook.contactinfo[addressbook.size].address);
	++addressbook.size;
	printf("������ϵ�˳ɹ�!\n");
}
void PrintAllcontactinfo();
void Delcontactinfo() {
	PrintAllcontactinfo();
	printf("ɾ����ϵ��.\n");	
	int num;
	printf("������Ҫɾ����ϵ�˵����:");
	scanf("%d", &num);
	if (num < 1 || num >addressbook.size) {
		printf("��Ҫɾ������ϵ�˲�����!\n");
		return;
	}
	//strcpy(addressbook.contactinfo[num - 1].name, addressbook.contactinfo[addressbook.size - 1].name);
	//strcpy(addressbook.contactinfo[num - 1].sex, addressbook.contactinfo[addressbook.size - 1].sex);
	//strcpy(addressbook.contactinfo[num - 1].age, addressbook.contactinfo[addressbook.size - 1].age);
	//strcpy(addressbook.contactinfo[num - 1].phonenum, addressbook.contactinfo[addressbook.size - 1].phonenum);
	//strcpy(addressbook.contactinfo[num - 1].address, addressbook.contactinfo[addressbook.size - 1].address);
	addressbook.contactinfo[num - 1] = addressbook.contactinfo[addressbook.size - 1];
	--addressbook.size;
	printf("ɾ����ϵ�˳ɹ�!\n");
}

void Findcontactinfo() {
	printf("������ϵ��.\n");
	char name[1024] = { 0 };
	int flag = 0;
	printf("������Ҫ������ϵ�˵�����:\n");
	scanf("%s", name);
	for (int i = 0; i < addressbook.size; ++i) {
		if (strcmp(name, addressbook.contactinfo[i].name) == 0) {
			printf("[%d] %s %s %s %s %s\n", i + 1, addressbook.contactinfo[i].name,
				addressbook.contactinfo[i].sex, addressbook.contactinfo[i].age,
				addressbook.contactinfo[i].phonenum, addressbook.contactinfo[i].address);
			flag = 1;
		}
	}
	printf("������ϵ�˽���.\n");
	if(flag == 0){
		printf("û�ҵ�Ŀ����ϵ��!\n");
	}
}

void Updatecontactinfo() {
	printf("�޸���ϵ��.\n");
	PrintAllcontactinfo();
	int num;
	char scan[1024] = { 0 };
	printf("������Ҫ�޸���ϵ�˵����:");
	scanf("%d", &num);
	if (num <= 0 || num > addressbook.size) {
		printf("���������Ų�����!\n");
		return;
	}
	printf("������Ҫ�޸ĵ���Ϣ:\n����'*'������ǰ�޸�\n");
	printf("����:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].name, scan);
	}
	printf("�Ա�:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].sex, scan);
	}
	printf("����:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].age, scan);
	}
	printf("�绰:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].phonenum, scan);
	}
	printf("��ַ:");
	scanf("%s", scan);
	if (strcmp(scan, "*")) {
		strcpy(addressbook.contactinfo[num - 1].address, scan);
	}
	printf("�޸���ϵ�˳ɹ�!\n");
}

void PrintAllcontactinfo() {
	printf("��ӡͨѶ¼.\n");
	if (addressbook.size == 0) {
		printf("ͨѶ¼Ϊ��!\n");
	}
	else {
		for(int i = 0; i < addressbook.size; ++i){
		printf("[%d] %s %s %s %s %s\n", i + 1, addressbook.contactinfo[i].name,
			addressbook.contactinfo[i].sex, addressbook.contactinfo[i].age,
			addressbook.contactinfo[i].phonenum, addressbook.contactinfo[i].address);
		}
		printf("��ӡͨѶ¼�ɹ�!\n");
	}
}

void ClearAllcontactinfo() {
	printf("���������ϵ��.\n");
	int num;
	printf("��ȷ��Ҫ���������ϵ��?\n������,������'1'\n");
	scanf("%d", &num);
	if (num != 1) {
		printf("���������ϵ��ȡ��.\n");
		return;
	}
	addressbook.size = 0;
	printf("�����ϵ�˳ɹ�!\n");
}

void Sortcontactinfo() {
	printf("����������������ϵ��.\n");
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
	printf("����ȫ����ϵ�˳ɹ�!\n");
}

void Savecontactinfo_tofile() {
	printf("������ϵ�˵��ļ�.\n");
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
	FILE* fp = fopen("../��ϵ����Ϣ.txt","w");
	if (fp == NULL) {
		return;
	}
	//fprintf(fp, "���\t����\t�Ա�\t����\t�绰\tסַ\n");
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
	printf("������ϵ�˵��ļ��ɹ�!\n");
}
void Loadcontactinfo() {
	printf("������ϵ��.\n");
	int str[500][5] = { 0 };
	FILE* fp1 = fopen("../write-read.txt", "w");
	if (fp1 == NULL) {
		return;
	}
	for (int i = 1; i < 10; ++i) {
		fread(str, 4, 5, fp1);
	}
	fclose(fp1);
	FILE* fp = fopen("../��ϵ����Ϣ.txt", "r");
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

	printf("������ϵ�˳ɹ�!\n");
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
			printf("�������ָ������,����������:");
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