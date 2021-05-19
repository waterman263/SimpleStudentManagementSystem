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

enum OPERATE find_student(student_head_p headP, enum SELECT select);
enum OPERATE find_student_by_number(student_head_p headP);
enum OPERATE find_student_by_name(student_head_p headP);
enum OPERATE find_student_all(student_head_p headP);



enum OPERATE delete_student(student_head_p headP, enum SELECT select);
enum OPERATE delete_student_by_number(student_head_p headP);
enum OPERATE delete_student_by_name(student_head_p headP);

enum OPERATE add_student(student_head_p headP);

enum OPERATE chg_student(student_head_p headP,enum SELECT select);
enum OPERATE chg_student_by_number(student_head_p headP,enum SELECT);
enum OPERATE chg_student_by_name(student_head_p headP,enum SELECT);
enum OPERATE chg_student_by(student_head_p headP,enum SELECT select);
enum OPERATE chg_student_name(student_head_p headP);
enum OPERATE chg_student_number(student_head_p headP);
enum OPERATE chg_student_phone(student_head_p headP);
enum OPERATE chg_student_score_one(student_head_p headP);
enum OPERATE chg_student_score(student_head_p headP);
enum OPERATE chg_student_gpa(student_head_p headP);
#endif //CODEFIELD_STUDENT_SERVICE_H
