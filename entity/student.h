/**
 * @file student_service.h
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
#ifndef STUDENT_H
#define STUDENT_H
#include "classes.h"

typedef struct student{
    char uid[24];
    long class_number;
    long long student_number;
    char name[22];
    char email[33];
    char phone_number[12];
    float subject_score[5][1];
    float gpa;
    enum BOOLEAN_USE HAS_SCORE_INPUT;
    struct student *next;
}student, *student_p;

typedef struct student_head_pointer{
    struct student *next;
}student_head_p, *stu_head_p;

#endif //_STUDENT_H
