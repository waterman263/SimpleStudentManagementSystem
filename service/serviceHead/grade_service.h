//
// Created by 86182 on 2021/5/19.
//

#ifndef GRADE_SERVICE_H
#define GRADE_SERVICE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "utils/tool.h"
#include "setting.h"
#include "entity/grade.h"

grade_head_p initial_Grade_List();
grade_p create_grade( grade_head_p head);
grade_p set_grade(grade_p grade);
void update_grade (grade_head_p head);
void delete_grade(grade_head_p head);
void query_grade(grade_head_p head, int query_all);
void query_grade_all(grade_head_p head);
void query_grade_one(grade_head_p head);

#endif //GRADE_SERVICE_H
