#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

int graph[SIZE][SIZE] = {
   {0,0,0,0,0,0,0,0,0},
   {0,0,2,8,0,0,0,0,0},
   {0,2,0,7,9,0,0,0,0},
   {0,8,7,0,4,10,12,0,0},
   {0,0,9,4,0,0,0,0,0},
   {0,0,0,10,0,0,6,14,0},
   {0,0,0,12,0,6,0,0,0},
   {0,0,0,0,0,14,0,0,3},
   {0,0,0,0,0,0,0,3,0}
};

int sum = 0;
int visited[SIZE] = {0};
int visited2[SIZE] = {0};

typedef struct edge* eptr;
typedef struct edge
{
   int src,dst,cost;
   eptr next;
}edge;
eptr tree = NULL;
int allVisited(int i)
{
    if(visited[i]==1)
        return 1;
    else
        return 0;
}

void addtree(int src, int dst, int cost)
{
   eptr newnode = (eptr)malloc(sizeof(edge));
   eptr lead = tree;
   eptr temp = NULL;
   newnode->src = src;
   newnode->dst = dst;
   newnode->cost = cost;
   newnode->next = NULL;


   if (tree == NULL)
   {
      tree = newnode;
   }

   else
   {
      while (lead->next != NULL)
        lead = lead->next;
    newnode->next = lead->next;
    lead->next = newnode;
   }
}

void step1()
{
   int i, j;
   for (i = 1; i < SIZE; i++)
   {
    int k = 100;
      for (j = 1; j < SIZE; j++)
      {
         if (graph[j][i] != 0 && graph[j][i] < k && visited[i]!=1 && visited[j]!=1)
         {
            k = graph[j][i];
            visited[i]=1;
            visited[j]=1;
            addtree(i,j,k);
         }
      }
   }
}

void step2(eptr head)
{
    int i, j;
    eptr lead = head;
   for (i = 1; i < SIZE; i++)
   {
    int k = lead->cost;
      for (j = 1; j < SIZE; j++)
      {
         if (graph[j][i] != 0 && graph[j][i] != k && i<j)
            k = graph[j][i];
         visited2[j] = 1;
      }

   }
}
void print(eptr head)
{

    eptr lead = head;

    while (lead != NULL)
    {
        printf("(%d->%d) cost: %d\n", lead->src, lead->dst, lead->cost);
        lead = lead->next;
    }
    printf("\n");

}
int main()
{
    step1();
    step2(tree);
    print(tree);
}
