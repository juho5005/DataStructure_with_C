#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j;

struct student {
	char name[20];
	char region[20];
	int age;
};

struct student sts[8];

void swap(struct student* a, struct student* b) {
	struct student tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void callfile() {
	FILE* fp;
	fp = fopen("Students.txt", "r");

	for (i = 0; i < 8; i++) {
		fscanf(fp, "%s %s %d", sts[i].name, sts[i].region, &sts[i].age);
	}
	fclose(fp);
}

void printfile() {
	for (i = 0; i < 8; i++) {
		printf("%s %s %d\n", sts[i].name, sts[i].region, sts[i].age);
	}
}

void insertion_sort_age() {
	for (i = 1; i < 8; i++) {
		for (j = i; j >= 1; j--) {
			if (sts[j - 1].age < sts[j].age) {
				swap(&sts[j - 1], &sts[j]);
			}
		}
	}
}

void insertion_sort_name() {
	for (i = 1; i < 8; i++) {
		for (j = i; j >= 1; j--) {
			if (strcmp(sts[j-1].name, sts[j].name) < 0) {
				swap(&sts[j - 1], &sts[j]);
			}
		}
	}
}

int main() {
	// ������ �ҷ��´�.
	callfile();

	// ������ ������ ����Ѵ�.
	printf("----------- ���� ���� ��� -----------\n");
	printfile();

	// ���̷� �������� ���� (��������)
	printf("----------- ���̷� ���� ���� ���� �� ��� -----------\n");
	insertion_sort_age();
	printfile();

	// �̸����� �������� ���� (��������)
	printf("----------- �̸����� ���� ���� ���� �� ��� -----------\n");
	insertion_sort_name();
	printfile();

	return 0;
}
