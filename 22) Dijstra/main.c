
#include <stdio.h>
#include <stdlib.h>
#define size 8

int graph[size][size];

int c=0;
int d[size]={0};
int p[size];
int visited[size]={0};
int stk[]; top=-1;
int find_shortest(int item)
{
    int min;
    int next;
    int j,k;
    while(1)
        {
            min=100;
    next;
    visited[item]=1;
    for(k=1; k<size; k++)
    {
            if((d[k]>=(d[item]+graph[item][k])||d[k]==0)&&graph[item][k])
            {
                d[k]=d[item]+graph[item][k];
                p[k]=item;
             }
    }
    for(j=1; j<size; j++)
        {
            if(!visited[j]&&min>d[j]&&d[j]!=0)
            {
                min=d[j];
                next=j;
            }
        }
    if(item==7)
        break;
    item=next;
        }
}

void callfile() {
    int i,j;
    int x, y;

    FILE* fp;
    fp = fopen("Dijkstra_graph.txt", "r");

	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
    fclose(fp);
}

void print_file() {
    int x,y;
   printf("------ 불러온 파일 출력 -----\n");
    for (x=0; x<8; x++) {
        for (y=0; y<8; y++) {
            printf("%d ", graph[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    // invoke file;
    callfile();

    // print file;
    print_file();

    int i,m=7;
    find_shortest(1);

    printf("\nPath from 1 to 7 : distance=%d\n",d[7]);
    stk[++top]=7;
    while(m!=1)
            {
                stk[++top]=p[m];
        m=p[m];
        }
        printf("the path is ");
        for(i=top;i>=0;i--)
            printf(" %d",stk[i]);


    return 0;
}

