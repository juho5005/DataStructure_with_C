#include <stdio.h>
#include <stdlib.h>
#define DATANUM 20

int main()
{
    int i, j, number;
    int data[DATANUM];
    int radixTable1[10][DATANUM];
    int radixTable2[10][DATANUM];
    int radixTable3[10][DATANUM];
    int count1[10] = {0};
    int count2[10] = {0};
    int count3[10] = {0};

    srand((int)time(NULL));

    // input data
    printf("20개의 3자리 수 (0~999) : ");
    for (i=0; i<DATANUM; i++){
        data[i] = rand() % 1000;
        printf("%d ", data[i]);
    }

    // sorting 1
    for (i=0; i<DATANUM; i++){
        number = data[i] % 10;
        radixTable1[number][count1[number]++] = data[i];
    }

    // sorting 2
    for (i=0; i<10; i++)
        for (j=0; j<count1[i]; j++){
            number = radixTable1[i][j] / 10 % 10;
            radixTable2[number][count2[number]++] = radixTable1[i][j];
        }

    // sorting 3
    for (i=0; i<10; i++)
        for (j=0; j<count2[i]; j++){
            number = radixTable2[i][j] / 100;
            radixTable3[number][count3[number]++] = radixTable2[i][j];
        }
    printf("\n\n");
    printf("정렬된 결과(오름차순) : ");
    for (i=0; i<10; i++)
        for (j=0; j<count3[i]; j++)
            printf("%d ",  radixTable3[i][j]);
    return 0;
}
