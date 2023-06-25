#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10

#include <stdio.h>

int length(int array[], int size)
{
    int i;
    for (i=0; i<size; i++) {
        if (array[i] == '\0')
                break;
    }
    return i;
}

int indexof(int array[], int size, int find) {
    int i;
    int f = -1;

    for (i = 0; i < size; i++) {
        if (array[i] == find) {
            f = i;
            break;
        }
    }

    return f;
}

int main() {
	int data[SIZE] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };
	int lens;
    int idx1, idx2;

    lens = length(data, SIZE);
	printf("배열의 길이 : %d\n", lens);

    idx1 = indexof(data, SIZE, 77);
    idx2 = indexof(data, SIZE, 393);

    printf("idx1의 인덱스 : %d\n", idx1);
    printf("idx2의 인덱스 : %d\n", idx2);

	return 0;
}
