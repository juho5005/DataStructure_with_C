#define _CRT_SECURE_NO_WARNINGS

// 0 -> 길
// 1 -> 벽


#include <stdio.h>
#include <stdlib.h>

//아직 한 번도 가보지 못한 cell
const int PATHWAY_COLOUR = 0;

//벽이라고 정해진 cell
const int WALL_COLOUR = 1;

//visited이며 출구까지의 경로가 있지 않음이 밝혀진 cell
const int BLOCKED_COLOUR = 3;

//visited이며 아직 출구로 가는 경로가 될 가능성이 있는 cell
const int PATH_COLOUR = 2;


int i, j;

char map1_string[15][15];
char map2_string[15][15];

int maze1[15][15];
int maze2[15][15];

void callfile1() {
    FILE* fp;
    fp = fopen("map1.txt", "r");

    for (i = 0; i < 15; i++) {
        fscanf(fp, "%s", map1_string[i]);
    }
    fclose(fp);
}

void callfile2() {
    FILE* fp;
    fp = fopen("map2.txt", "r");

    for (i = 0; i < 15; i++) {
        fscanf(fp, "%s", map2_string[i]);
    }
    fclose(fp);
}


void maze1_make() {
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            maze1[i][j] = map1_string[i][j] - '0';
        }
    }
}

void maze2_make() {
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            maze2[i][j] = map2_string[i][j] - '0';
        }
    }
}

void maze1_print() {
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            printf("%d ", maze1[i][j]);
        }
        printf("\n");
    }
}

void maze2_print() {
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            printf("%d ", maze2[i][j]);
        }
        printf("\n");
    }
}


int findMap1(int x, int y) {
    if (x < 0 || y < 0 || x >= 15 || y >= 15)
        return 0;
    else if (maze1[x][y] != PATHWAY_COLOUR)
        return 0;
    else if (x == 15 - 1 && y == 15 - 1) {
        maze1[x][y] = PATH_COLOUR;
        return 1;
    }
    else {
        maze1[x][y] = PATH_COLOUR;
        if (findMap1(x - 1, y) || findMap1(x, y + 1) || findMap1(x + 1, y) || findMap1(x, y - 1)) {
            return 1;
        }
        maze1[x][y] = BLOCKED_COLOUR;
        return 0;
    }
}

int findMap2(int x, int y) {
    if (x < 0 || y < 0 || x >= 15 || y >= 15)
        return 0;
    else if (maze2[x][y] != PATHWAY_COLOUR)
        return 0;
    else if (x == 15 - 1 && y == 15 - 1) {
        maze2[x][y] = PATH_COLOUR;
        return 1;
    }
    else {
        maze2[x][y] = PATH_COLOUR;
        if (findMap2(x - 1, y) || findMap2(x, y + 1) || findMap2(x + 1, y) || findMap2(x, y - 1)) {
            return 1;
        }
        maze2[x][y] = BLOCKED_COLOUR;
        return 0;
    }
}

int main()
{
    int map1_check;
    int map2_check;
    // map1의 파일을 불러오기
    callfile1();

    // maze1에 map1의 2차원 배열을 대입하여 초기화
    maze1_make();

    // 입력된 map1 출력
    printf("---------------------------------------------------------------\n");
    printf("---------- map 1 출력 ----------\n");
    maze1_print();
    printf("\n");

    printf("---------- map1 의 이동 후 맵의 숫자 ----------\n");
    printf("0 : 가보지 못한 칸\n");
    printf("1 : 벽\n");
    printf("2,3 : 지나간 길 \n\n");
    map1_check = findMap1(0, 0);

    printf("------------ map1의 경로 ------------\n");
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            printf("%d ", maze1[i][j]);
        }
        printf("\n");
    }

    if (maze1[14][14] != 0) {
        printf("\n정답 : map1.txt는 미로에 대해서 탈출이 가능하다.\n");
    }
    printf("---------------------------------------------------------------\n");

    printf("\n\n");
    // map2의 파일을 불러오기
    callfile2();

    // maze2에 map1의 2차원 배열을 대입하여 초기화
    maze2_make();

    // 입력된 map2 출력
    printf("---------- map2 출력 ----------\n");
    maze2_print();
    printf("\n");


    printf("---------- map2 의 이동 후 맵의 숫자 ----------\n");
    printf("0 : 가보지 못한 칸\n");
    printf("1 : 벽\n");
    printf("2,3 : 지나간 길 \n\n");
    map2_check = findMap2(0, 0);

    printf("------------ map2의 경로 ------------\n");
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            printf("%d ", maze2[i][j]);
        }
        printf("\n");
    }

    if (maze2[14][14] != 0) {
        printf("\n정답 : map2.txt는 미로에 대해서 탈출이 가능하다.\n");
    }
    printf("---------------------------------------------------------------\n");


    return 0;
}
