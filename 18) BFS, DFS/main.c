#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

int i,j;
int N= 9;

int graph[10][10];
char map1_string[10][10];

int visit[1001] = {0, }, queue[1001];
int visit1[1001] = {0, };


void dfs(int V) {
    visit[V] = 1;
    printf("%d ", V);
    for(int i=1; i<=N; i++) if(graph[V][i] && !visit[i]) dfs(i);
}

void bfs(int V) {
    int front = 0, rear = 1, pop;
    visit1[V] = 1;
    printf("%d ", V);
    queue[0] = V;
    while(front < rear) {
        pop = queue[front++];
        for(int i=1; i<=N; i++)
            if(graph[pop][i] && !visit[i]) {
                visit1[i] = 1;
                printf("%d ", i);
                queue[rear++] = i;
            }
    }
}

void callfile() {
    FILE* fp;
    fp = fopen("matrix_graph.txt", "r");

    for (i = 0; i < 10; i++) {
        fscanf(fp, "%s", map1_string[i]);
    }
    fclose(fp);
}

void make_graph() {
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            graph[i][j] = map1_string[i][j] - '0';
        }
    }
}

void print_graph() {
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    // download file
    callfile();

    // make graph
    make_graph();

    // show file
    printf("------ 텍스트 파일을 다운 받아서 matrix 생성-----\n");
    print_graph();

    visit[0] = 1;

    // DFS Search
    printf("\n ------ (0, 0)으로 시작했을 때 깊이 탐색 구현 경로 ------\n");
    dfs(0);

    // BFS Search
    printf("\n ------ (0, 0)으로 시작했을 때 너비 탐색 구현 경로 ------\n");
    visit1[0] = 1;
    bfs(0);

    return 0;
}
