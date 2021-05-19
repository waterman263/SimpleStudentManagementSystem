//
// Created by 86189 on 2021/5/19.
//

#ifndef CODEFIELD_CLASS_SERVICE_H
#define CODEFIELD_CLASS_SERVICE_H
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
enum OPERATE find_class(classes_head_p headP, enum SELECT select);
enum OPERATE find_class_one(classes_head_p headP);
enum OPERATE find_class_all(classes_head_p  headP);



enum OPERATE delete_class(classes_head_p headP);

enum OPERATE add_class(classes_head_p headP);

enum OPERATE chg_class(classes_head_p headP);

#endif //CODEFIELD_CLASS_SERVICE_H
