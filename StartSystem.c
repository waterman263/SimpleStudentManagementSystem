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
#include "service/serviceHead/main_program_service.h"

int main(){
    printf("==============================================================================\n");
    printf("=====================Welcome to Student Management System=====================\n");
    printf("==============================================================================\n");
    printf("Reading data files, please hold on......\n");
    users_head_p user_head_pointer = initial_User_List();
    open_file(USERS_DATA, user_head_pointer);
    USER user = NULL;
    const char roles[4][20] = {"Administrator", "Teacher", "Counsellor", "Guidance-director"};

    // login system
    login:
    while (true){
        char select_login;
        _Bool login_OK = false;
        while (!login_OK){
            printf("==Hello! What do you want to do next?\n");
            printf("==Please enter the corresponding option.\n");
            printf("\t1.Login\t\t2.Exit\n");
            scanf("%c", &select_login);
            fflush(stdin);
            switch (select_login) {
                case '1':
                    printf("==Now the system will turn to the login page.\n");
                    if (login_account(user_head_pointer, &user) == SUCCESS){
                        printf("==Welcome back! %s %s\n", roles[user->USER_ROLE+5], user->name);
                        printf("==Loading your system resources, please hold on.\n");
                        login_OK = true;
                    }
                    break;
                case '2':
                    printf("==Thank you for using the system. Goodbye!\n");
                    return 0;

                default:
                    printf("==Please enter the correct option!\n\n");
            }
        }
        break;
    }

    // enter the system corresponding to the role
    switch (user->USER_ROLE) {
        case -5:
            administrator_system(user_head_pointer, user);
            goto login;
        case -4:
            teacher_system(user_head_pointer, user);
            goto login;
        case -3:
            counsellor_system(user_head_pointer, user);
             goto login;
        case -2:
            guidance_director_system(user_head_pointer, user);
            goto login;
        }

    return 0;
}

