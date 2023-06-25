#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct student {
    char name[10];
    int midterm;
    int finalscore;
    int attend;
    int practice;
    int practice2;
    int total;
    char grade[20];
    char alpha;
}student;

struct student std[50];

void swap(student *a, student *b){

    student temp;
    temp = *b;
    *b= *a;
    *a=temp;
}

void total_sort(int a){

    for(int i=0;i<a;i++)
        for(int j=0;j<a-1;j++)
            if(std[j].total<std[j+1].total)
            {
               swap(&std[j],&std[j+1]);
            }
}

void name_sort(int a){

    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a-1;j++)
        {
            if(strcmp(std[j].name, std[j+1].name)>0)
              {
                swap(&std[j],&std[j+1]);
              }
        }
    }
}

int readdata(char Filename[])
{
    FILE *fp;
    fp = fopen("file.txt","r");

    int i=0;

    while(!feof(fp))
    {
        fscanf(fp,"%d %s %d %d %d %d ",&std[i].attend,std[i].name,&std[i].practice,&std[i].practice2,&std[i].midterm,&std[i].finalscore);
        std[i].total = (std[i].practice + std[i].practice2 + std[i].midterm + std[i].finalscore);
        i++;
    }
    fclose(fp);
    return i;
}

void Printdata(int num)
{
   int i;
   for(int i=0; i<num;i++)
   {
       printf("%2d %2s %2d %2d %2d %2d 총점:%2d 등급:%2c \n",std[i].attend, std[i].name, std[i].practice,std[i].practice2, std[i].midterm, std[i].finalscore, std[i].total, std[i].grade);
   }
   printf("\n");

}

void setPortion(int A, int B,int C, int D, int num){

    int i,j=0;

    j = num*A;

    for(i=0;i<j;i++){
        strcpy(std[i].grade, "A");
        //std[i].grade = "A"
    }


    j += num*B;
    for(i;i<j;i++){
        strcpy(std[i].grade, "B");
        //std[i].grade = "B"
    }

    j += num*C;
    for(i; i<j;i++){
        strcpy(std[i].grade, "C");
        //std[i].grade = "C"
    }

    j += num*D;

    for(i; i<j;i++){
        strcpy(std[i].grade, "D");
        //std[i].grade = "D"
    }
}


int main()
{
    int num;

    num = readdata("file.text");
    printf("---------------처음 데이터 출력---------------\n\n");
    Printdata(num);


    total_sort(num);
    setPortion(0.3,0.4,0.1,0.2,num);

    printf("---------------총점 순 정렬---------------\n\n");
    Printdata(num);

    name_sort(num);
    printf("---------------이름 순 정렬---------------\n\n");
    Printdata(num);


}
