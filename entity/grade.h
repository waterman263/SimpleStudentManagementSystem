/**
 * @file grade.h
 * @author @waterman263
 * @brief 年级的结构体（当前年级（指针）
			  班级总数
			  单科平均分（二维数组）
			  总体平均分
			  总体平均绩点
			  是否已录入班级作为下属（boolean））
 * @version 0.1
 * @date 2021-05-15
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef CODEFIELD_GRADE_H
#define CODEFIELD_GRADE_H
typedef struct grade
{
    int *grade;
    int class_number;
    char average_score_only[5][];
    int average_score;
    int average_point;
    struct grade *next;
};

#endif //CODEFIELD_GRADE_H
