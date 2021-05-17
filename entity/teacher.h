/**
 * @file teacher.h
 * @author @waterman263
 * @brief 老师的结构体（执教学科（用科目编号）
			  执教班级（最多3个班级）
			  工号（唯一）
			  姓名
			  电话
			  邮箱
			  是否已经达到执教上限）
 * @version 0.1
 * @date 2021-05-15
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef TEACHER_H
#define TEACHER_H
#include "service/serviceHead/setting.h"

typedef struct teacher
{
    char uid[24];
    enum SUBJECT subject;
    char classes_uid[20];
    long work_number;
    char name[20];
    char phone_number[12];
    char email[33];
    enum BOOLEAN_USE HAS_MAX_CLASSES;
    struct teacher *next;
}teacher, *teacher_p;

typedef struct teacher_head_pointer{
    struct teacher *next;
}teacher_head_p, *teach_head_p;

#endif //_TEACHER_H
