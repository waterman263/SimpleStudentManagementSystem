//
// Created by 86189 on 2021/5/19.
//

#ifndef CLASS_SERVICE_H
#define CLASS_SERVICE_H
#include "utils/tool.h"
#include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#include "serviceHead/operate_file.h"
#include "entity/classes.h"


enum SELECT{
    CLASS_NUMBER,
    ONE,
    ALL
};
enum OPERATE find_class(class_head_p headP, enum SELECT select);
enum OPERATE find_class_one(class_head_p headP);
enum OPERATE find_class_all(class_head_p  headP);



enum OPERATE delete_class(class_head_p headP);

enum OPERATE add_class(class_head_p headP);

enum OPERATE update_class(class_head_p headP);

#endif //CLASS_SERVICE_H
