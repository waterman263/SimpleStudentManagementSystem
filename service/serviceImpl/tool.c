/**
 * @file tools.c
 * @author @Loritas
 * @brief implement tools.h
 * @version 0.1
 * @date 2021-03-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdbool.h>
#include "service/tool.h"

enum OPERATE_FILE check_string(int string_type, char *string){
    // boolean,to simplify the if expression
    _Bool is_lowercase_letter = false;
    _Bool is_uppercase_letter = false;
    _Bool is_number = false;
    // at == @
    _Bool is_at = false;

    if (string_type == PASSWORD )
    {
        // check string when it is password
        // password must be number and letter
        while (*string != '\0') {
            is_lowercase_letter = (*string >= 'a') && (*string <= 'z');
            is_uppercase_letter = (*string >= 'A') && (*string <= 'Z');
            is_number = (*string >= '0') && (*string <= '9');

            if (is_lowercase_letter || is_uppercase_letter || is_number)
            {
                string++;
            }else {
                return FAILED;
            }

        }   
    }

    if (string_type == ACCOUNT) {
        // check string when it is account
        // acount must be number
        while (*string != '0') {
            is_number = (*string >= '0') && (*string <= '9');
            if (is_number) {
                string++;
            }else
            {
                return FAILED;
            }
        }
    }
    return SUCCESS;
}

enum OPERATE_FILE check_numbers(int string_type, long numbers){
    
    return SUCCESS;
}