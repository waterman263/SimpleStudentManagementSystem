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

#ifndef OPERATE_FILE_H
#define OPERATE_FILE_H
#include <stdio.h>
#include "setting.h"
#include <string.h>
#include <stdlib.h>
#include "utils/cjson_utils.h"
#define USER_DATA "../data/users_data.json"

enum OPERATE {
    SUCCESS = 200,
    FAILED = 404
};

enum FILE_TYPE {
    USERS_DATA
};

enum OPERATE open_file(enum FILE_TYPE file_type, void *struct_pointer);
enum OPERATE close_file(enum FILE_TYPE file_type, FILE **fp);
enum OPERATE read_file_data(enum FILE_TYPE file_type, char  *json_data, void *struct_pointer);
enum OPERATE parsing_users_data(char *json_data, void *struct_pointer);
#endif
