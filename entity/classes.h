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
typedef struct classes{
    grades *grade;
    counsellors *counsellor;
    long class_number;
    float single_aver[2][5];
    float total_aver;
    float total_gpa;
    bool student;
    struct classes *next;
}classes,*class;
#endif
