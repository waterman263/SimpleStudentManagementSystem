/**
 * @file setting.h
 * @author @Loritas
 * @brief provides an interface for each setting
 * @version 0.1
 * @date 2021-03-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _SETTING_H
#define _SETTING_H
#define RED_FRONT_COLOR "\033[0;32;31m"
#define COLOR_NONE  "\033[m"
enum STRING_TYPE{
    PASSWORD,
    TELEPHONE_NUMBER,
    EMAIL,
    WORK_NUMBER,
    ACCOUNT
};

enum BOOLEAN_USE{
    TRUE_RES,
    FALSE_RES,
    IS_FIRST_USER,
    NOT_FIRST_USER
};
#endif