/**
 * @file tools.h
 * @author provides interface for checking numbers or string
 * @brief
 * @version 0.1
 * @date 2021-03-14
 *
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef TOOL_H
#define TOOL_H
#include <stdlib.h>
#include <time.h>
#include "service/serviceHead/operate_file.h"
#include "service/serviceHead/setting.h"

enum OPERATE check_string(int string_type, char *string);
enum OPERATE check_numbers(int string_type, long numbers);

// create uid for struct
void create_uid(char *target_uid);
#endif
