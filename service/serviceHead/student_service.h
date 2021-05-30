//
// Created by 86189 on 2021/5/18.
//

#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H
#include "utils/tool.h"
#include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#include "operate_file.h"
#include "entity/student.h"
enum SELECT{
    NUMBER,
    NAME,
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

enum OPERATE update_student(stu_head_p headP, enum SELECT select);
enum OPERATE update_student_by_number(stu_head_p headP);
enum OPERATE update_student_by_name(stu_head_p headP);
void input_information(student_p target_student);

#endif //STUDENT_SERVICE_H
