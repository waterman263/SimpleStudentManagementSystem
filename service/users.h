/**
 * @file users.h
 * @author @Loritas
 * @brief provides interface for operating users
 * @version 0.1
 * @date 2021-03-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _USERS_H
#define _USERS_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "entity/administrator.h"
#include "utils/tool.h"
enum USER_ROLE {
    ADMINISTRATOR = -5,
    SUBJECT_TEACHER,
    COUNSELLOR,
    GUIDANCE_DIRECTOR
};

typedef struct users
{
    long long account;
    char password[32];
    long work_number;
    enum USER_ROLE USER_ROLE;
    struct users *next;
}users, *USER;

typedef struct head_pointer{
    enum BOOLEAN_USE isHead;
    struct users *next;
}head, *head_p;

USER create_user(USER user, enum BOOLEAN_USE is_first);
USER set_user(USER user, enum BOOLEAN_USE is_first);

enum USER_ROLE check_account(long account, char password[]);

// initialize the head
head_p initial_List();

#endif