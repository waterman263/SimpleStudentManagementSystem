/**
 * @file head_teachers.h
 * @author @Little-Red-Riding-Hood
 * @brief provides interface for creating a list about head_teachers
 * @version 0.1
 * @date 2021-05-17
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef _HEAD_TEACHERS_H
#define _HEAD_TEACHERS_H
typedef struct head_teachers{
    long work_number;
    int phone_number;
    char email[30];
    char name[10];
    struct head_teachers *next;
}headteachers,*headteacher;
#endif
