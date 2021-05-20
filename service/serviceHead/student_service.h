//
// Created by 86189 on 2021/5/18.
//

#ifndef CODEFIELD_STUDENT_SERVICE_H
#define CODEFIELD_STUDENT_SERVICE_H
#include "utils/tool.h"
#include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#include "serviceHead/operate_file.h"
#include "entity/student.h"
enum SELECT{
    NUMBER,
    NAME,
    PHONE_NUMBER,
    SCORE_ONE,
    SCORE,
    GPA,
    ALL
};

enum OPERATE find_student(stu_head_p headP, enum SELECT select);
enum OPERATE find_student_by_number(stu_head_p headP);
enum OPERATE find_student_by_name(stu_head_p headP);
enum OPERATE find_student_all(stu_head_p headP);



enum OPERATE delete_student(stu_head_p headP, enum SELECT select);
enum OPERATE delete_student_by_number(stu_head_p headP);
enum OPERATE delete_student_by_name(stu_head_p headP);

enum OPERATE add_student(stu_head_p headP);

enum OPERATE chg_student(stu_head_p headP,enum SELECT select);
enum OPERATE chg_student_by_number(stu_head_p headP,enum SELECT);
enum OPERATE chg_student_by_name(stu_head_p headP,enum SELECT);

#endif //CODEFIELD_STUDENT_SERVICE_H
