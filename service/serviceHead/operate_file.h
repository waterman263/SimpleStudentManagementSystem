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

#ifndef _OPERATE_FILE_H
#define _OPERATE_FILE_H
#include <stdio.h>
#include "setting.h"
#define USER_DATA "../data/users_data.json"

enum OPERATE_FILE {
    SUCCESS = 200,
    FAILED = 404
};

enum FILE_TYPE {
    USERS_DATA
};

enum OPERATE_FILE open_file(enum FILE_TYPE file_type);
enum OPERATE_FILE close_file(enum FILE_TYPE file_type, FILE **fp);
enum OPERATE_FILE read_file_data(enum FILE_TYPE file_type, FILE *fp);
#endif
