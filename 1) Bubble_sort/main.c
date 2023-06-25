// Bubble Sort

// srand((int)time(NULL))기억하기 !!
#define _CRT_SECURE_NO_WRANINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i, j, l;
	int tmp;
	int data[5];

	l = sizeof(data) / sizeof(data[0]);

	srand((int)time(NULL));

	// 데이터 입력
	for (i = 0; i < l; i++) {
		data[i] = (rand() % 100) + 1; // 데이터 범위 1 ~ 100
	}

	// 입력 데이터 출력
	for (i = 0; i < l; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	// Bubble Sort
	for (i = 0; i < l - 1; i++) {
		for (j = 0; j < l - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}

	// 정렬 후  데이터 출력
	for (i = 0; i < l; i++) {
		printf("%d ", data[i]);
	}

	return 0;
}
