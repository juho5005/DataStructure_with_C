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
    printf("\n\n--- 출구인 (8, 14)를 제외하고 모든 값을 -1로 초기화 ---\n");
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

//왼쪽, 오른쪽, 위, 아래 로 이동 -행열을 생각하면 되요
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
    // maze.txt의 파일을 불러온다.
    callfile();

    // 주어진 파일의 maze를 만든다.
    make_maze();

    // 만들어진 maze를 출력한다.
    printf("------- 주어진 maze 코드 -------\n");
    print_maze();

    // 출구 (8,14) = 0 을 reward로 주고 나머지는 -1로 초기화
    reward_init_maze();

    // 이전 값을 0으로 초기화
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 15; j++)
        {
            value_prev[i][j] = 0;

        }
    }

    //현재 값을 0으로 초기화
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 15; j++)
        {
            value_now[i][j] = 0;

        }
    }

    // 시작점은 (1,1) => maze[0][0]
    // 종료점은 (7,13) => maze[7][13]

    float sum = 0;
    float p = 0;
    int l;
    int num = 0;

    //업데이트 50번 시행.
    for (l = 0; l < 50; l++)
    {
        num += 1;
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 15; j++)
            {
                // 벽이면 패스한다. (0)인 경우
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

                //초기화
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
        printf("\n\n--- %d번째 반복 완료 ---\n\n", num);
    }

    // 50번의 반복을 마쳤을 때의 미로 상태
    printf("----- 50번의 반복을 마친 후 미로 상태 -----\n");
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 15; j++)
        {
            printf("%.2f ", value_now[i][j]);

        }
        printf("\n");
    }
    printf("\n");


    // 0을 경로로 지나가면 된다.
    int current[2] = { 1,1 }; //시작
    char direction;
    float val = -100000;
    int u = 0;

    printf("-------미로의 이동 경로-------\n");
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
