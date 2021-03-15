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
#include <stdio.h>

typedef struct administrator
{
    long work_number;
    int phone_number;
    char email[30];
    char name[10];
    struct administrator *next;
}administrator, *admin;
