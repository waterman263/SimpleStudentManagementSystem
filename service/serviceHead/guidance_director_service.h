//
// Created by 86182 on 2021/5/19.
//

#ifndef _GUIDANCE_DIRECTOR_SERVICE_H
#define _GUIDANCE_DIRECTOR_SERVICE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "utils/tool.h"
#include "entity/guidance_director.h"
#include "entity/grade.h"
director_head_p initial_Director_List();
director_p create_director(director_head_p head);
director_p set_director(director_p director, director_head_p head);
void query_my_own_data(director_head_p director);
void update_my_own_data(director_head_p director);
void query_single_grade(grade_head_p head);
void query_all_grades(grade_head_p head);
#endif //_GUIDANCE_DIRECTOR_SERVICE_H
