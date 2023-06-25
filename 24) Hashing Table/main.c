#include <stdio.h>
#include <time.h>

#define BUCKET_SIZE (2000)
#define INIT (-1)
#define FALSE (-1)
#define TRUE (1)

/* �ؽ÷� ������ִ� �Լ� */
int hash(int value)
{
    int hs;

    hs = value % BUCKET_SIZE;
    if (hs < 0)
        hs += BUCKET_SIZE;

    return (hs);
}

/* �ؽ����̺��� �ʱ�ȭ�����ִ� �Լ� */
void init_hashtable(int* hashtable)
{
    for (int i = 0; i < BUCKET_SIZE; i++)
        hashtable[i] = INIT;
}

/* �ؽ����̺��� ���� ã�� �Լ� */
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

/* �ؽ����̺� ���� �߰��ϴ� �Լ� */
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

    printf("������ 2000���� ���� hashtable\n");

    // ������ 1000���� ��´�.
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
