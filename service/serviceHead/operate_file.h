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
#define TEACHER_DATA "../data/teacher_data.json"
#define STUDENT_DATA "../data/student_data.json"
#define GUIDANCE_DIRECTOR_DATA "../data/guidance_director_data.json"
#define GRADE_DATA "../data/grade_data.json"
#define COUNSELLOR_DATA "../data/counsellor_data.json"
#define CLASSES_DATA "../data/classes_data.json"
#define ADMINISTRATOR_DATA "../data/administrator_data.json"

enum OPERATE {
    SUCCESS = 200,
    FAILED = 404
};

enum FILE_TYPE {
    USERS_DATA
};

enum OPERATE open_file(enum FILE_TYPE file_type, void *struct_pointer);
enum OPERATE save_file(enum FILE_TYPE file_type, void *struct_pointer);
enum OPERATE read_file_data(enum FILE_TYPE file_type, char  *json_data, void *struct_pointer);
enum OPERATE save_file_data(enum FILE_TYPE file_type, char  *target_data, void *struct_pointer);

enum OPERATE parsing_users_data(char *json_data, void *struct_pointer);

enum OPERATE save_users_data(char *target_data, void *struct_pointer);
#endif
