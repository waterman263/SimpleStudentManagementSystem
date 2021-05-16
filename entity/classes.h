/**
 * @file classes.h
 * @author @Little-Red-Riding-Hood
 * @brief provides interface for creating a list about classes
 * @version 0.1
 * @date 2021-05-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef _CLASSES_H
#define _CLASSES_H
#include "service/serviceHead/setting.h"

typedef struct classes{
    struct grade *current_grade;
    struct counsellors *counsellor;
    long class_number;
    char *subject_aver[5][1];
    float general_aver;
    float general_gpa;
    enum BOOLEAN_USE HAS_STUDENT_INPUT;
    struct classes *next;
}classes, *class_p;

typedef struct classes_head_pointer{
    struct classes *next;
}classes_head_p, *class_head_p;

#endif //_CLASSES_H
