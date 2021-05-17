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
#ifndef GUIDANCE_DIRECTOR_H
#define GUIDANCE_DIRECTOR_H
#include "service/serviceHead/setting.h"

typedef struct guidance_director{
    long work_number;
    char phone_number[11];
    char email[30];
    char name[10];
    struct guidance_director *next;
}director, *director_p;

typedef struct guidance_director_head_pointer{
    struct director *next;
}director_head_pointer, *director_head_p;

#endif //_GUIDANCE_DIRECTOR_H
