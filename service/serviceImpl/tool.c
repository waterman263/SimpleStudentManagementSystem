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

    char *check_target = string;
    // boolean,to simplify the if expression
    _Bool is_lowercase_letter = false;
    _Bool is_uppercase_letter = false;
    _Bool is_number = false;
    // at == @
    _Bool is_at = false;

    if (string_type == PASSWORD )
    {
        // check check_target when it is password
        // password must be number and letter
        while (*check_target != '\0' && *check_target != '\n') {
            is_lowercase_letter = (*check_target >= 'a') && (*check_target <= 'z');
            is_uppercase_letter = (*check_target >= 'A') && (*check_target <= 'Z');
            is_number = (*check_target >= '0') && (*check_target <= '9');

            if (is_lowercase_letter || is_uppercase_letter || is_number){
                check_target++;
            }else {
                return FAILED;
            }

        }   
    }

    if (string_type == ACCOUNT) {
        // check check_target when it is account
        // account must be number
        while (*check_target != '\0' && *check_target != '\n') {
            is_number = (*check_target >= '0') && (*check_target <= '9');
            if (is_number) {
                check_target++;
            }else {
                return FAILED;
            }
        }
    }
    return SUCCESS;
}

enum OPERATE_FILE check_numbers(int string_type, long numbers){
    
    return SUCCESS;
}