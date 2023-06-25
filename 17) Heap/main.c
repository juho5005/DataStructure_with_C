#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heap[20];
int heapindex = 0;

void insertHeap(int item)
{
    int i = ++heapindex;
    heap[i] = item;
    while (i/2 >= 1)
    {
        if (heap[i] < heap[i/2])
        {
            int temp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = temp;
            i = i / 2;
        }
        else
            break;
    }
}

int deleteHeap()
{
    int result = heap[1];
    int i=1;
    heap[1] = heap[heapindex--];
    while (i <= heapindex/2)
    {
        if (heap[i] > heap[2*i] || heap[i] > heap[2*i+1])
        {
            if (heap[2*i] < heap[2*i+1])
            {
                int temp = heap[i];
                heap[i] = heap[2*i];
                heap[2*i] = temp;
                i = i * 2;
            }
            else
            {
                int temp = heap[i];
                heap[i] = heap[2*i+1];
                heap[2*i+1] = temp;
                i = i * 2 + 1;
            }
        }
        else
            break;
    }

    return result;
}


int main()
{
    srand((int)time(NULL));
    int i;
    int data;
    printf("---------- 0~9 사이의 data 20개 min-heap를 이용하여 insert한 결과 ----------\n");
    printf("data : ");
    for(i=0;i<20;i++)
    {
        data = rand() % 10;
        printf("%d ", data);
        insertHeap(data);
    }
    printf("\n\n");

    printf("---------- 0~9 사이의 data 20개를 delete한 결과 ----------\n");
    for(i=0;i<20;i++) {
        printf("%d ",deleteHeap());
    }

    return 0;
}
