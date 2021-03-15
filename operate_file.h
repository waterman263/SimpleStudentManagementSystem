/**
 * @file operate_file.h
 * @author @Loritas
 * @brief provides interface for operating files
 * @version 0.1
 * @date 2021-03-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

#define USER_ACCOUNT_DATA "settings/user_accounts.ini"

enum OPERATE_FILE {
    SUCCESS = 200,
    FAILED = 404
};

enum OPERATE_FILE open_file(int file_type, FILE **fp);
enum OPERATE_FILE close_file(int file_type, FILE **fp);
