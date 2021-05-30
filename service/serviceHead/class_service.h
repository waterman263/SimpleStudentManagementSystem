//
// Created by 86189 on 2021/5/19.
//

#ifndef CLASS_SERVICE_H
#define CLASS_SERVICE_H
#include "utils/tool.h"
#include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#include "operate_file.h"
#include "entity/classes.h"
#include "grade_service.h"

enum OPERATE find_class(class_head_p headP, enum SELECT select);
enum OPERATE find_class_one(class_head_p headP);
enum OPERATE find_class_all(class_head_p  headP);



enum OPERATE delete_class(class_head_p headP, grade_head_p grade_h);

enum OPERATE add_class(class_head_p headP, grade_head_p grade_h);

enum OPERATE update_class(class_head_p headP, grade_head_p grade_h);
class_head_p initial_class_List();

#endif //CLASS_SERVICE_H
