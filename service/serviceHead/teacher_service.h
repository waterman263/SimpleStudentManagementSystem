//
// Created by 86182 on 2021/5/19.
//

#ifndef _TEACHER_SERVICE_H
#define _TEACHER_SERVICE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "utils/tool.h"
#include "entity/grade.h"
#include "entity/classes.h"
#include "entity/teacher.h"
teach_head_p initial_Teacher_List();
teacher_p create_teacher(teach_head_p head);
teacher_p set_teacher(teacher_p teacher, teach_head_p head);
void query_class(teacher_p teacher, class_head_p head);
void query_my_data(teach_head_p head);
#endif //_TEACHER_SERVICE_H
