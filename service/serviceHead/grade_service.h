//
// Created by 86182 on 2021/5/19.
//

#ifndef _GRADE_SERVICE_H
#define _GRADE_SERVICE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "utils/tool.h"
#include "serviceHead/setting.h"
#include "entity/grade.h"
grade_head_p initial_Grade_List();
grade_p create_grade( grade_head_p head,enum BOOLEAN_USE HAS_CLASSES_INPUT);
grade_p set_grade(grade_p grade, grade_head_p head);
void update_grade (grade_head_p head);
void delete_grade(grade_head_p head);
#endif //CLASSDESIGN1_GRADE_SERVICE_H
