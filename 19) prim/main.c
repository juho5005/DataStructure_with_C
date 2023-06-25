#include <stdio.h>
#include <stdlib.h>
#define VERTICES 9

int graph[VERTICES][VERTICES] = {	{0,0,0,0,0,0,0,0,0},
									{0,0,2,8,0,0,0,0,0},
									{0,2,0,7,9,0,0,0,0},
									{0,8,7,0,4,10,12,0,0},
									{0,0,9,4,0,0,0,0,0},
									{0,0,0,10,0,0,6,14,0},
									{0,0,0,12,0,6,0,0},
									{0,0,0,0,0,14,0,0,3},
									{0,0,0,0,0,0,0,3,0}};


int visited[9] = {0};
int arr[9] = {0};
int rear = 1;
int result = 0;

int Find_Shortest_Edge()
{
    int i, j, v, shortest, k;

    shortest = 1000;
    for (i=1; i<rear; i++)
    {
        v = arr[i];
        for (j=1;j<9;j++)
        {
            if (graph[v][j] != 0&&!visited[j]&& shortest > graph[v][j])
            {
                k = j;
                shortest = graph[v][j];
            }
        }
    }
    result += shortest;
    return k;
}

int allVisited()
{
    int i;
    for(i=1;i<9;i++)
        if (visited[i]==0)
            return 0;
    return 1;
}

void prim(int item)
{
    int i;
    int m;

    visited[item] = 1;
    printf("visit order: %d", item);
    arr[rear++] = item;
    while (allVisited()!= 1)
    {
        m = Find_Shortest_Edge();
        arr[rear++] = m;
        visited[m] = 1;
        printf(" %d", m);
    }
}


int main()
{
    puts("Minimum Spanning Tree");
    puts("Prim's method");

    prim(5);
    puts("");
    printf("total cost = %d ", result);
    return 0;
}
