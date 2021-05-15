/**
 * @file teacher.h
 * @author @waterman263
 * @brief 老师的结构体（执教学科（用科目编号）
			  执教班级（一维数组存储指针）
			  工号（唯一）
			  姓名
			  电话
			  邮箱）
 * @version 0.1
 * @date 2021-05-15
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef _TEACHER_H
#define _TEACHER_H
typedef struct teacher
{
    int project;
    struct teancher *teach;
    int work_number;
    char name[20];
    int phone_number;
    char email[30];
    struct teacher*next;
}teacher,*tea;


#endif //_TEACHER_H
