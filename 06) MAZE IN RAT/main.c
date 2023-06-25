#define _CRT_SECURE_NO_WARNINGS

// 0 -> ��
// 1 -> ��


#include <stdio.h>
#include <stdlib.h>

//���� �� ���� ������ ���� cell
const int PATHWAY_COLOUR = 0;

//���̶�� ������ cell
const int WALL_COLOUR = 1;

//visited�̸� �ⱸ������ ��ΰ� ���� ������ ������ cell
const int BLOCKED_COLOUR = 3;

//visited�̸� ���� �ⱸ�� ���� ��ΰ� �� ���ɼ��� �ִ� cell
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
    // map1�� ������ �ҷ�����
    callfile1();

    // maze1�� map1�� 2���� �迭�� �����Ͽ� �ʱ�ȭ
    maze1_make();

    // �Էµ� map1 ���
    printf("---------------------------------------------------------------\n");
    printf("---------- map 1 ��� ----------\n");
    maze1_print();
    printf("\n");

    printf("---------- map1 �� �̵� �� ���� ���� ----------\n");
    printf("0 : ������ ���� ĭ\n");
    printf("1 : ��\n");
    printf("2,3 : ������ �� \n\n");
    map1_check = findMap1(0, 0);

    printf("------------ map1�� ��� ------------\n");
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            printf("%d ", maze1[i][j]);
        }
        printf("\n");
    }

    if (maze1[14][14] != 0) {
        printf("\n���� : map1.txt�� �̷ο� ���ؼ� Ż���� �����ϴ�.\n");
    }
    printf("---------------------------------------------------------------\n");

    printf("\n\n");
    // map2�� ������ �ҷ�����
    callfile2();

    // maze2�� map1�� 2���� �迭�� �����Ͽ� �ʱ�ȭ
    maze2_make();

    // �Էµ� map2 ���
    printf("---------- map2 ��� ----------\n");
    maze2_print();
    printf("\n");


    printf("---------- map2 �� �̵� �� ���� ���� ----------\n");
    printf("0 : ������ ���� ĭ\n");
    printf("1 : ��\n");
    printf("2,3 : ������ �� \n\n");
    map2_check = findMap2(0, 0);

    printf("------------ map2�� ��� ------------\n");
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            printf("%d ", maze2[i][j]);
        }
        printf("\n");
    }

    if (maze2[14][14] != 0) {
        printf("\n���� : map2.txt�� �̷ο� ���ؼ� Ż���� �����ϴ�.\n");
    }
    printf("---------------------------------------------------------------\n");


    return 0;
}
