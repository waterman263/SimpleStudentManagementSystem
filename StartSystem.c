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
//    users_head_p user_head_pointer = initial_User_List();
//    printf("Reading data files, please hold on......\n");
//    open_file(USERS_DATA, user_head_pointer);
//    USER user = user_head_pointer->next;
//    while (user != NULL){
//        printf("%lld %ld %s\n", user->account, user->work_number, user->password);
//        user = user->next;
//    }
    char test_uid[24];
    create_uid(test_uid);
    printf("%s", test_uid);
    return 0;
}

