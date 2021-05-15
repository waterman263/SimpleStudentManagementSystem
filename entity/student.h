/**
 * @file student.h
 * @author @waterman263
 * @brief 学生的结构体（所属班级（指针）
	 		  学号（唯一）
			  姓名
			  邮箱
			  电话号码
			  各科成绩（二维数组）
			  总分
			  绩点
			  是否已录入成绩信息（boolean））
 * @version 0.1
 * @date 2021-05-15
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef CODEFIELD_STUDENT_H
#define CODEFIELD_STUDENT_H
typedef struct student
{
    int *class;
    int number;
    char name[20];
    char email[30];
    int phone_number;
    int total;
    int point;
    bool test;
    score sco;
    struct student *next;
}student,*stu;

#endif //CODEFIELD_STUDENT_H
