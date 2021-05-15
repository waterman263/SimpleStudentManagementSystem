#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


 typedef struct score
    {
        int score1;
        int score2;
        int score3;
        int score4;
        int score5;
    }score;
typedef struct student
    {
        int *class;
        int number;
        char name[20];
        char email[30];
        int phonenumber;
        int total;
        int point;
        bool test;
        score sco;
    }stu;
typedef struct teacher
    {
        int project;
        struct teancher *teach;
        int jobnumber;
        char name[20];
        int phonenumber;
        char email[30];
    }teacher;
main()
{

}
