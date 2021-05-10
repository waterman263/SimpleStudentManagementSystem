/**
 * @file main.c
 * @author @Loritas
 * @brief system main program
 * @version 0.1
 * @date 2021-03-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "service/users.h"

int main(){
    printf("==========Welcome to Student Management System==========\n");
    head_p user_head_pointer = initial_List();
    enum BOOLEAN_USE is_first = IS_FIRST_USER;
    USER users = create_user(user_head_pointer->next, is_first);
    printf("%ld", users->work_number);

    return 0;
}
