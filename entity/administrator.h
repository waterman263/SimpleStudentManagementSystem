/**
 * @file administrator.h
 * @author @Loritas
 * @brief provides interface for creating a list about administrator
 * @version 0.1
 * @date 2021-03-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

typedef struct administrator
{
    char uid[24];
    long work_number;
    char phone_number[12];
    char email[33];
    char name[20];
    struct administrator *next;
}administrator, *admin;

typedef struct administrator_head_pointer{
    struct administrator *next;
}administrator_head_p, *admin_head_p;

#endif //_ADMINISTRATOR_H
