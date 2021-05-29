/**
 * @file tools.c
 * @author @Loritas
 * @brief implement tools.h
 * @version 0.1
 * @date 2021-03-14
 *
 *
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdbool.h>
#include "tool.h"

/**
 * @author Loritas
 * @brief check string as target type
 * @date 2021-3-14
 *
 * @param string_type  target string type
 * @param string  target string
 * @return whether the operate success
 */
enum OPERATE check_string(int string_type, char *string){

    char *check_target = string;
    // boolean,to simplify the if expression
    _Bool is_lowercase_letter = false;
    _Bool is_uppercase_letter = false;
    _Bool is_number = false;
    // at == @
    _Bool is_at = false;

    // point == .
    _Bool is_point = false;

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

    if (string_type == EMAIL) {
        // check check_target when it is email
        // ep: eh123q.top@email.com
        // no validation is done on the domain name, only basic length validation is done
        int len = 0;
        while (*check_target != '@' && *check_target != '\n') {
            is_lowercase_letter = (*check_target >= 'a') && (*check_target <= 'z');
            is_uppercase_letter = (*check_target >= 'A') && (*check_target <= 'Z');
            is_number = (*check_target >= '0') && (*check_target <= '9');
            is_point = *check_target == '.';

            if (is_lowercase_letter || is_uppercase_letter || is_number || is_point){
                len++;
                if (len > 28) return FAILED;
                check_target++;
            }else {
                return FAILED;
            }
        }

        if (*check_target == '@') check_target++;
        else return FAILED;

        while (*check_target != '.' && *check_target != '\n'){
            is_lowercase_letter = (*check_target >= 'a') && (*check_target <= 'z');
            is_uppercase_letter = (*check_target >= 'A') && (*check_target <= 'Z');
            is_number = (*check_target >= '0') && (*check_target <= '9');

            if (is_lowercase_letter || is_uppercase_letter || is_number){
                len++;
                if (len > 30) return FAILED;
                check_target++;
            }else {
                return FAILED;
            }
        }

        if (*check_target == '.') check_target++;
        else return FAILED;

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

    if (string_type == TELEPHONE_NUMBER) {
        // check check_target when it is phone_number
        // phone_number must be number and its length must be 11
        int len = 0;
        while (*check_target != '\0' && *check_target != '\n') {
            is_number = (*check_target >= '0') && (*check_target <= '9');
            if (is_number) {
                len++;
                if (len > 11) return FAILED;
                check_target++;
            }else {
                return FAILED;
            }
        }

        if (len != 11) return FAILED;
    }
    return SUCCESS;
}

enum OPERATE check_numbers(int string_type, long numbers){
    
    return SUCCESS;
}

/**
 * @author Loritas
 * @brief create uid for struct. it's a pseudo-random number generator
 * @date 2021-5-17
 *
 * @param target_uid struct uid, it is a string of length 24
 */
void create_uid(char *target_uid){
    // use time_stamp as front tag
    time_t current_time = time(NULL);
    lltoa(current_time, target_uid, 10);

    // random generation of eight digits (with a tendency to increase)
    srand(time(NULL));
    long temp_number = 10000000 + rand() % 90000000;

    char temp[9];
    ltoa(temp_number, temp, 10);
    strcat(target_uid, temp);
}