#include <stdio.h>
#include <time.h>

#define BUCKET_SIZE (2000)
#define INIT (-1)
#define FALSE (-1)
#define TRUE (1)

/* 해시로 만들어주는 함수 */
int hash(int value)
{
    int hs;

    hs = value % BUCKET_SIZE;
    if (hs < 0)
        hs += BUCKET_SIZE;

    return (hs);
}

/* 해시테이블을 초기화시켜주는 함수 */
void init_hashtable(int* hashtable)
{
    for (int i = 0; i < BUCKET_SIZE; i++)
        hashtable[i] = INIT;
}

/* 해시테이블에서 값을 찾는 함수 */
int find_value(int value, int* hashtable)
{
    int i;
    int start_index;

    start_index = hash(value);
    i = start_index;

    do {
        if (hashtable[i] == value)
            return (i);
        else if (hashtable[i] == INIT)
            return (FALSE);
        i = (i + 1) % BUCKET_SIZE;
    } while (i != start_index);

    return (FALSE);
}

/* 해시테이블에 값을 추가하는 함수 */
int Insert(int value, int* hashtable)
{
    int i;
    int start_index;

    start_index = hash(value);
    i = start_index;

    do {
        if (hashtable[i] == value || hashtable[i] == INIT)
        {
            hashtable[i] = value;
            return (TRUE);
        }
        i = (i + 1) % BUCKET_SIZE;
    } while (i != start_index);

    return (FALSE);
}


int main(void)
{
    int i;
    int hashtable1[BUCKET_SIZE];
    srand((int)time(NULL));

    init_hashtable(hashtable1);

    printf("데이터 2000개를 담은 hashtable\n");

    // 데이터 1000개를 담는다.
    for (i = 0; i < 1000; i++) {
        Insert(rand() % 2000, hashtable1);
    }


    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        if (hashtable1[i] == INIT)
            continue;
        printf("%d: %d\n", i, hashtable1[i]);
    }
    printf("\n");
}
