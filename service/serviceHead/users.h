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
#ifndef USERS_H
#define USERS_H
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
    char password[33];
    long work_number;
    enum USER_ROLE USER_ROLE;
    struct users *next;
}users, *USER;

typedef struct users_head_pointer{
    enum BOOLEAN_USE isHead;
    struct users *next;
}users_head, *users_head_p;

USER create_user(USER user, users_head_p head, enum BOOLEAN_USE is_first);
USER set_user(USER user, users_head_p head, enum BOOLEAN_USE is_first);

// todo: check_account
enum USER_ROLE check_account(long account, char password[]);

// check data
_Bool check_exist_account(users_head_p head, long long account_input);
_Bool check_exist_work_number(users_head_p head, long work_number_input);

// initialize the users_head
users_head_p initial_User_List();

// convert data to objects
void convert_user(users_head_p head, FILE *user_data);

#endif