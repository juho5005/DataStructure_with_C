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
typedef struct edge* eptr;
typedef struct edge
{
   int src,dst,cost;
   eptr next;
}edge;
eptr setE = NULL;
eptr setT = NULL;


int allVisited(int i)
{
    if(visited[i]==1)
        return 0;
    else
        return 1;
}

void sortE(int src, int dst, int cost)
{
   eptr newnode = (eptr)malloc(sizeof(edge));
   eptr lead = setE;
   eptr temp = NULL;
   newnode->src = src;
   newnode->dst = dst;
   newnode->cost = cost ;
   newnode->next = NULL;

   if (setE == NULL)
   {
      setE = newnode;

   }
   else if (cost < lead->cost)
   {
      newnode->next = lead;
      setE = newnode;
   }
   else
   {
      while (lead->next != NULL && lead->next->cost < newnode->cost)
         lead = lead->next;
      newnode->next = lead->next;
      lead->next = newnode;
   }
}


void insertE()
{
   int i, j;
   for (i = 1; i < SIZE; i++)
   {
      for (j = 1; j < i; j++)
      {
         if (graph[j][i] != 0)
         {
            sortE(j, i, graph[i][j]);
         }

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


int absT()
{
   int i = 0;
   eptr counting = NULL;

   if (setT != NULL)
   {
      while (counting != NULL)
      {
        i++;
        counting = setT->next;
      }
      return i;
   }
   else
   {
      return 0;
   }
}

void addT(int src, int dst, int cost)
{
   eptr newnode = (eptr)malloc(sizeof(edge));
   eptr lead = setT;
   eptr temp = NULL;
   newnode->src = src;
   newnode->dst = dst;
   newnode->cost = cost;
   newnode->next = NULL;


   if (setT == NULL)
   {
      setT = newnode;

   }

   else
   {
      while (lead->next != NULL)
         lead = lead->next;
      newnode->next = lead->next;
      lead->next = newnode;
   }
}

void insertT()
{


   while (setE != NULL && absT() != SIZE-1)
   {
        if (allVisited(setE->dst) != 0)
        {
            addT(setE->src, setE->dst, setE->cost);
            sum = sum+setE->cost;
        }
        visited[setE->dst]=1;
        setE = setE->next;

   }
}


int main()
{
    insertE();
    printf("-------------E------------\n");
    print(setE);
    insertT();
    printf("-------------T------------\n");
    print(setT);

    printf("\nTOTAL COST: %d\n",sum);
}
