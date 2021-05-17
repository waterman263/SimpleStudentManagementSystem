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

#ifndef CLASSES_H
#define CLASSES_H
#include "service/serviceHead/setting.h"

typedef struct classes{
    char uid[24];
    char grade_uid[20];
    char counsellor_uid[20];
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
