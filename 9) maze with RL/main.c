#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int i, j;

struct position {
    int x;
    int y;
};

struct position current_cell;
struct position stack[30];

char maze_string[9][15];

int maze[9][15];
float reward[9][15];
float value_prev[9][15];
float value_now[9][15];



void callfile() {
    FILE* fp;
    fp = fopen("maze.txt", "r");

    for (i = 0; i < 9; i++) {
        fscanf(fp, "%s", maze_string[i]);
    }
    fclose(fp);
}

void make_maze() {
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 15; j++) {
            maze[i][j] = maze_string[i][j] - '0';
        }
    }
}

void print_maze() {
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 15; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void print__() {
    int l = 1;
    int k;

    for (k = 2; k < 15; k++) {
        printf("[%d %d] => ", l, k);
    }
    k = 14;
    for (l = 1; l < 8; l++) {
        printf("[%d %d] => ", l, k);
    }
    l = 8;
    k = 14;
    printf("[%d %d] ", l, k);
}

void reward_init_maze() {
    printf("\n\n--- �ⱸ�� (8, 14)�� �����ϰ� ��� ���� -1�� �ʱ�ȭ ---\n");
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 15; j++)
        {
            reward[i][j] = -1;

            if (i == 8 && j == 14)
            {
                reward[i][j] = 0;
            }
        }
    }

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 15; j++)
        {
            printf("%2.f", reward[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

}

//����, ������, ��, �Ʒ� �� �̵� -�࿭�� �����ϸ� �ǿ�
void move(int arr[], char c)
{
    if (c == 'l')
    {
        arr[1] = arr[1] - 1;
    }
    else if (c == 'r')
    {
        arr[1] = arr[1] + 1;
    }
    else if (c == 'u')
    {
        arr[0] = arr[0] - 1;
    }
    else if (c == 'd')
    {
        arr[0] = arr[0] + 1;
    }

}

int main() {
    // maze.txt�� ������ �ҷ��´�.
    callfile();

    // �־��� ������ maze�� �����.
    make_maze();

    // ������� maze�� ����Ѵ�.
    printf("------- �־��� maze �ڵ� -------\n");
    print_maze();

    // �ⱸ (8,14) = 0 �� reward�� �ְ� �������� -1�� �ʱ�ȭ
    reward_init_maze();

    // ���� ���� 0���� �ʱ�ȭ
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 15; j++)
        {
            value_prev[i][j] = 0;

        }
    }

    //���� ���� 0���� �ʱ�ȭ
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 15; j++)
        {
            value_now[i][j] = 0;

        }
    }

    // �������� (1,1) => maze[0][0]
    // �������� (7,13) => maze[7][13]

    float sum = 0;
    float p = 0;
    int l;
    int num = 0;

    //������Ʈ 50�� ����.
    for (l = 0; l < 50; l++)
    {
        num += 1;
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 15; j++)
            {
                // ���̸� �н��Ѵ�. (0)�� ���
                if (maze[i][j] == 1)
                    continue;

                if (maze[i - 1][j] == 1)
                {
                    sum = sum + reward[i - 1][j] + value_prev[i - 1][j];
                    p++;
                }
                else {}
                if (maze[i + 1][j] == 0)
                {
                    sum = sum + reward[i + 1][j] + value_prev[i + 1][j];
                    p++;
                }
                else {}
                if (maze[i][j - 1] == 0)
                {
                    sum = sum + reward[i][j - 1] + value_prev[i][j - 1];
                    p++;
                }
                else {}
                if (maze[i][j + 1] == 0)
                {
                    sum = sum + reward[i][j + 1] + value_prev[i][j + 1];
                    p++;
                }
                else {}

                sum = sum + reward[i][j] + value_prev[i][j];
                p++;
                value_now[i][j] = sum / p;
                printf("%5.2f  ", value_now[i][j]);

                //�ʱ�ȭ
                p = 0;
                sum = 0;
                value_prev[8][14] = 0;
                value_now[8][14] = 0;

            }
            printf("\n");
        }
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 15; j++)
            {
                value_prev[i][j] = value_now[i][j];

            }
        }
        printf("\n\n--- %d��° �ݺ� �Ϸ� ---\n\n", num);
    }

    // 50���� �ݺ��� ������ ���� �̷� ����
    printf("----- 50���� �ݺ��� ��ģ �� �̷� ���� -----\n");
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 15; j++)
        {
            printf("%.2f ", value_now[i][j]);

        }
        printf("\n");
    }
    printf("\n");


    // 0�� ��η� �������� �ȴ�.
    int current[2] = { 1,1 }; //����
    char direction;
    float val = -100000;
    int u = 0;

    printf("-------�̷��� �̵� ���-------\n");
    printf("[%d %d] => ", current[0], current[1]);
    print__();

    while (u < 50)
    {
        //left,right,up,down
        direction = 'n';
        val = -100000;
        //left
        if (maze[current[0]][current[1] - 1] == 0)
        {
            if (value_now[current[0]][current[1] - 1] > val)
            {
                direction = 'l';
                val = value_now[current[0]][current[1] - 1];
            }
        }
        //right
        if (maze[current[0]][current[1] + 1] == 0)
        {
            if (value_now[current[0]][current[1] + 1] > val)
            {
                direction = 'r';
                val = value_now[current[0]][current[1] + 1];
            }

        }
        //up
        if (maze[current[0] - 1][current[1]] == 0)
        {
            if (value_now[current[0] - 1][current[1]] > val)
            {
                direction = 'u';
                val = value_now[current[0] - 1][current[1]];
            }
        }
        //down
        if (maze[current[0] + 1][current[1]] == 0)
        {
            if (value_now[current[0] + 1][current[1]] > val)
            {
                direction = 'd';
                val = value_now[current[0] + 1][current[1]];
            }

        }

        move(current, direction);

        if (current[0] == 8 && current[1] == 13) {
            break;
        }
        u++;
    }

    return 0;
}
