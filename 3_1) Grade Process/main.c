#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;

struct student {
	char name[20];
	int number, midterm, final, attend, practice;
	float total;
	char grade;
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
	fp = fopen("file.txt", "r");

	for (i = 0; i < 8; i++) {
		fscanf(fp, "%d %s %d %d %d %d", &sts[i].number, sts[i].name, &sts[i].midterm, &sts[i].final, &sts[i].attend, &sts[i].practice);
	}
	fclose(fp);
}

void printfile() {
	for (i = 0; i < 8; i++) {
		printf("%d %s %d %d %d %d\n", sts[i].number, sts[i].name, sts[i].midterm, sts[i].final, sts[i].attend, sts[i].practice);
	}
}

void total_calculate(float a, float b, float c, float d) {
	int x, y;

	for (i = 0; i < 8; i++) {
		sts[i].total = ((sts[i].midterm * a) + (sts[i].final * b) + (sts[i].attend * c) + (sts[i].practice * d));
	}

	for (x = 0; x < 8 - 1; x++) {
		for (y = 0; y < 8 - x -1; y++) {
			if (sts[y].total < sts[y + 1].total) {
				swap(&sts[y], &sts[y + 1]);
			}
		}
	}

	for (i = 0; i < 8; i++) {
		printf("%4d %4s %3d %3d %3d %3d 총점 : %.2lf\n", sts[i].number, sts[i].name, sts[i].midterm, sts[i].final, sts[i].attend, sts[i].practice, sts[i].total);
	}
}

void setPortion() {
	for (i = 0; i < 8; i++) {
		if (sts[i].total >= 85)
			sts[i].grade = 'A';
		else if (sts[i].total >= 75)
			sts[i].grade = 'B';
		else if (sts[i].total >= 65)
			sts[i].grade = 'C';
		else if (sts[i].total >= 55)
			sts[i].grade = 'D';
		else if (sts[i].total >= 45)
			sts[i].grade = 'E';
		else
			sts[i].grade = 'F';
	}
	for (i = 0; i < 8; i++) {
		printf("%4d %4s %3d %3d %3d %3d 총점 : %.2lf 등급 : %2c\n", sts[i].number, sts[i].name, sts[i].midterm, sts[i].final, sts[i].attend, sts[i].practice, sts[i].total, sts[i].grade);
	}
}

void name_sort() {
	int x, y;

	for (x = 0; x < 8 - 1; x++) {
		for (y = 0; y < 8 - x - 1; y++) {
			if (strcmp(sts[y].name, sts[y + 1].name) > 0) {
				swap(&sts[y], &sts[y + 1]);
			}
		}
	}

	for (i = 0; i < 8; i++) {
		printf("%4d %4s %3d %3d %3d %3d 총점 : %.2lf 등급 : %2c\n", sts[i].number, sts[i].name, sts[i].midterm, sts[i].final, sts[i].attend, sts[i].practice, sts[i].total, sts[i].grade);
	}

}



int main() {
	// 파일 입력
	callfile();

	// 파일 출력
	printf("------------- 파일 출력 -------------\n");
	printfile();
	printf("\n");

	// 총점 계산 (총점 순으로 정렬)
	printf("------------- 총점순으로 출력 -------------\n");
	total_calculate(0.3, 0.4, 0.1, 0.2);
	printf("\n");

	// 점수에 따라 등급을 매김 ( 그 후 출력 )
	printf("------------- 등급을 매긴 후 출력 -------------\n");
	setPortion();
	printf("\n");

	// 이름 순으로 정렬 ( 그 후 출력 )
	printf("------------- 이름순으로 출력 -------------\n");
	name_sort();
	printf("\n");
}
