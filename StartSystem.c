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
#include "service/serviceHead/users.h"

int main(){
    printf("==========Welcome to Student Management System==========\n");
    users_head_p user_head_pointer = initial_User_List();

    enum BOOLEAN_USE is_first = IS_FIRST_USER;
    USER users = create_user(user_head_pointer->next, user_head_pointer, is_first);
    user_head_pointer->next = users;
    printf("%ld\n", users->work_number);
    USER second_user = create_user(users->next, user_head_pointer, NOT_FIRST_USER);
    users->next = second_user;
    printf("%ld %s\n", second_user->work_number, second_user->password);
    printf("Reading data files, please hold on......\n");


    return 0;
}
