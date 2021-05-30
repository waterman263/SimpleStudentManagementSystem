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

#ifndef SETTING_H
#define SETTING_H
#define RED_FRONT_COLOR "\033[0;32;31m"
#define COLOR_NONE  "\033[m"

enum SELECT{
    CLASS_NUMBER,
    ONE,
    ALL,
    NAME,
    NUMBER,
    WORK_NUMBER
};

enum STRING_TYPE{
    PASSWORD,
    TELEPHONE_NUMBER,
    EMAIL,
    ACCOUNT
};

enum BOOLEAN_USE{
    TRUE_RES,
    FALSE_RES,
    IS_FIRST_USER,
    NOT_FIRST_USER,
};

enum SUBJECT{
    ADVANCED_MATHEMATICS = 0,
    ENGLISH,
    C_PROGRAM_LANGUAGE,
    PHYSICAL_EDUCATION,
    PYTHON
};
#endif