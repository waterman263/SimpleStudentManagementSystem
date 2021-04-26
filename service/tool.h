/**
 * @file tools.h
 * @author provides interface for checking numbers or string
 * @brief 
 * @version 0.1
 * @date 2021-03-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _TOOL_H
#define _TOOL_H
#include "operate_file.h"
#include "setting.h"
enum OPERATE_FILE check_string(int string_type, char *string);
enum OPERATE_FILE check_numbers(int string_type, long numbers);
#endif
