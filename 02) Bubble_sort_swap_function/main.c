// Bubble Sort
#define _CRT_SECURE_NO_WRANINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int i, j, l;
	int tmp;
	int data[5];

	l = sizeof(data) / sizeof(data[0]);

	srand((int)time(NULL));

	// ������ �Է�
	for (i = 0; i < l; i++) {
		data[i] = (rand() % 100) + 1; // ������ ���� 1 ~ 100
	}

	// �Է� ������ ���
	for (i = 0; i < l; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	// Bubble Sort
	for (i = 0; i < l - 1; i++) {
		for (j = 0; j < l - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				swap(&data[j], &data[j + 1]);
			}
		}
	}

	// ���� ��  ������ ���
	for (i = 0; i < l; i++) {
		printf("%d ", data[i]);
	}

	return 0;
}
