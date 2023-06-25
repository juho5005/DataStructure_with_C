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
	printf("--------- 경로 ---------\n");
	printf("출발지 : (%d, %d)\n", max_x, max_y);

	// 왼쪽, 오른쪽, 위쪽, 아래
	int directX[] = { -1, 1, 0, 0 };
	int directY[] = { 0, 0, -1, 1 };

	// 시작 지점 초기화
	rear++;
	Q[rear].x = 2;
	Q[rear].y = 5;

	// 시작 지점 방문표시
	visited[2][5] = 1;

	// 미로를 탐색해본다.
	while (front < rear) {
		front++;
		int x = Q[front].x;
		int y = Q[front].y;

		// 도착 지점에 온 경우
		if (x == 5 && y == 6) {
			printf("도착지 : (%d, %d)\n", 5, 6);
			return;
		}

		// 4방향 체크 시작
		for (int i = 0; i < 4; i++) {
			// 이동 좌표 계산
			int nextX = directX[i] + x;
			int nextY = directY[i] + y;

			// 이동 좌표 유효성 검사
			if (nextX < 0 || nextX >= max_x || nextY < 0 || nextY >= max_y) {
				continue;
			}

			// 현재 맵에서 이동 가능한지?
			if (maze[nextY][nextX] == 0) {
				// 큐에 추가
				rear++;
				Q[rear].x = nextX;
				Q[rear].y = nextY;

				// 방문 표시
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
	printf("도착지 : (%d, %d)\n", 5, 6);
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

	// 파일을 불러온다.
	callfile();

	// 불러온 파일로 maze를 생성
	make_maze();

	// 만든 maze를 출력해본다.
	printf("--------- Queuemap 파일 출력 ---------\n");
	print_maze();
	printf("\n");

	// queue를 이용하여 맵을 탐색해본다.
	find_map_queue(2,5);
	visited_q();
	printf("------- 미로 탈출 성공 -------\n");

	return 0;
}
