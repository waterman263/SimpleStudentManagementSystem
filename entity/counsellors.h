/**
 * @file counsellors.h
 * @author @Little-Red-Riding-Hood
 * @brief provides interface for creating a list about counsellor
 * @version 0.1
 * @date 2021-05-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef _COUNSELLORS_H
#define _COUNSELLORS_H
typedef struct counsellors{
    long *class[20];
    long work_number;
    int phone_number;
    char email[30];
    char name[10];
    struct counsellors *next;
}counsellors,*counsellor;
#endif
