#define _CRT_SECURE_NO_WARNINGS

#define QUEUESIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j;

typedef struct Queue {
	int x;
	int y;
} Queue;

Queue Q[QUEUESIZE];

int front = -1;
int rear = -1;

char maze_string[9][10];
int maze[9][10];

int visited[9][10] = { 0, };

void find_map_queue(int max_x, int max_y) {
	printf("--------- ��� ---------\n");
	printf("����� : (%d, %d)\n", max_x, max_y);

	// ����, ������, ����, �Ʒ�
	int directX[] = { -1, 1, 0, 0 };
	int directY[] = { 0, 0, -1, 1 };

	// ���� ���� �ʱ�ȭ
	rear++;
	Q[rear].x = 2;
	Q[rear].y = 5;

	// ���� ���� �湮ǥ��
	visited[2][5] = 1;

	// �̷θ� Ž���غ���.
	while (front < rear) {
		front++;
		int x = Q[front].x;
		int y = Q[front].y;

		// ���� ������ �� ���
		if (x == 5 && y == 6) {
			printf("������ : (%d, %d)\n", 5, 6);
			return;
		}

		// 4���� üũ ����
		for (int i = 0; i < 4; i++) {
			// �̵� ��ǥ ���
			int nextX = directX[i] + x;
			int nextY = directY[i] + y;

			// �̵� ��ǥ ��ȿ�� �˻�
			if (nextX < 0 || nextX >= max_x || nextY < 0 || nextY >= max_y) {
				continue;
			}

			// ���� �ʿ��� �̵� ��������?
			if (maze[nextY][nextX] == 0) {
				// ť�� �߰�
				rear++;
				Q[rear].x = nextX;
				Q[rear].y = nextY;

				// �湮 ǥ��
				maze[nextY][nextX] = 1;
			}
		}
	}

}

void callfile() {
	FILE* fp;
	fp = fopen("Queuemap.txt", "r");

	for (i = 0; i < 9; i++) {
		fscanf(fp, "%s", maze_string[i]);
	}
}

void make_maze() {
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 10; j++) {
			maze[i][j] = maze_string[i][j] - '0';
		}
	}
}

void visited_q() {
	int k;
	for (k = 3; k < 6; k++) {
		printf("(%d, 5)\n", k);
	}
	printf("������ : (%d, %d)\n", 5, 6);
}

void print_maze() {
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d", maze[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int start_x = 2;
	int start_y = 5;

	// ������ �ҷ��´�.
	callfile();

	// �ҷ��� ���Ϸ� maze�� ����
	make_maze();

	// ���� maze�� ����غ���.
	printf("--------- Queuemap ���� ��� ---------\n");
	print_maze();
	printf("\n");

	// queue�� �̿��Ͽ� ���� Ž���غ���.
	find_map_queue(2,5);
	visited_q();
	printf("------- �̷� Ż�� ���� -------\n");

	return 0;
}
