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
#include <stdio.h>
#include "administrator.h"
#include "tool.h"

enum USER_ROLE {
    ADMINISTRATOR = -5,
    SUBJECT_TEACHER,
    CONSELLOR,
    GUIDANCE_DIRECTOR
};

typedef struct users
{
    long account;
    char password[32];
    long work_number;
    enum USER_ROLE USER_ROLE;
    struct users *next;
}users, *USER;

typedef struct head_poionter{
    enum BOOLEAN_USE ishead;
    struct users *next;
}head, *head_p;

// TODO: finish create_user
// TODO: finish check_account
USER create_user(USER user, enum BOOLEAN_USE is_first);
USER set_user(USER user, enum BOOLEAN_USE is_first);

enum USER_ROLE check_account(long account, char password[]);

// initialize the head
head_p initial_List();