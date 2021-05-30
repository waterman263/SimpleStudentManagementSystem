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
    char uid[24];
    long work_number;
    char name[21];
    char email[33];
    struct guidance_director *next;
    char phone_number[11];
}director, *director_p;

typedef struct guidance_director_head_pointer{
     director *next;
}director_head_pointer, *director_head_p;

#endif //_GUIDANCE_DIRECTOR_H
