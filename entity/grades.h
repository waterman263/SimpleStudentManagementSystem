/**
 * @file grades.h
 * @author @Little-Red-Riding-Hood
 * @brief provides interface for creating a list about grades
 * @version 0.1
 * @date 2021-05-16
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef _GRADES_H
#define _GRADES_H
typedef struct grades{
    char *grade;
    int class_amount;
    float single_aver[2][5];
    int total_aver;
    float total_gpa;
    bool class;
    struct grades *next;
}grades,*grade;
#endif
