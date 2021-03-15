/**
 * @file users.c
 * @author @Loritas
 * @brief implement user.h
 * @version 0.1
 * @date 2021-03-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "users.h"
#include "Windows.h"


#define RED_FRONT_COLOR "\033[0;32;31m"
#define COLOR_NONE  "\033[m" 


USER create_user(USER user, enum BOOLEAN_USE is_first){

    // if the pointer has a value, return an error
    if (user->next)
    {
        printf(RED_FRONT_COLOR"An unexpected error has been created,"COLOR_NONE);
        printf(RED_FRONT_COLOR" please save your work and exit this program.\n"COLOR_NONE);
        return NULL;
    }
    USER new_user = NULL;
    new_user = (USER)malloc(sizeof(users));

    if (!new_user)
    {
        printf(RED_FRONT_COLOR"Warning: Your computer has not enough free memory,"COLOR_NONE);
        printf(RED_FRONT_COLOR" please save your work and exit this program.\n"COLOR_NONE);
        return NULL;
    }
    user->next = new_user;

    if (is_first == IS_FIRST_USER)
    {
        new_user = set_user(new_user, is_first);
    }else {
        new_user = set_user(new_user, is_first);
    }

    printf("That's alright.Returing to the main menu\n");
    return new_user;
}

enum USER_ROLE check_account(long account, char password[]){
    enum USER_ROLE result = ADMINISTRATOR;
    return result;
}



head_p initial_List(){
    head_p head_poin = NULL;
    head_poin = (head_p)malloc(sizeof(head));

    if (head_poin == NULL)
    {
        printf(RED_FRONT_COLOR"Warning: Your computer has not enough free memory,\n"COLOR_NONE);
        printf(RED_FRONT_COLOR" please press any key to exit this program."COLOR_NONE);
        getchar();
        exit(0);
    }

    head_poin->ishead=TRUE_RES;
    head_poin->next = NULL;
    return head_poin;
}

/**
 * @brief set the properties of user
 * 
 * @param user new user
 * @param is_first whether it is the first time to create user
 * @param user_role user's identity
 * @return USER 
 */
USER set_user(USER user, enum BOOLEAN_USE is_first){
    // get user
    USER new_user = user;

    // use a char pointer to check account
    char *accounts = NULL;
    // use a char pointer to save password
    char *password_save = NULL;
    // use a char pointer to check work number
    char *work_number = NULL;

    // if it is the first time to create a user
    if (is_first == IS_FIRST_USER)
    {
        printf("This is the first time you create a user, it must be an administrator.\n");
        new_user->USER_ROLE = ADMINISTRATOR;
        printf("Please enter your account.It has to be made of pure numbers and the maxsize is 20.\n");
        printf("Your account: ");
        fgets(accounts, 20, stdin);

        while (true) {
            if (check_string(ACCOUNT, accounts)==SUCCESS) {
                new_user->account = atol(accounts);
                printf("OK. There's nothing wrong with your account number.\n");
                break;
            }else {
                printf("You can only enter numbers! Please enter your account again.\n");
                accounts = NULL;
                printf("Your account: ");
                fgets(accounts, 20, stdin);
            }
        }

        printf("Please enter your password, it consists of letters and numbers and the maxsize is 32\n");
        printf("Your password: ");
        fgets(password_save, 32, stdin);

        while (true) {
            if (check_string(PASSWORD, password_save)==SUCCESS) {
                int i = 0;
                while (password_save) {
                    new_user->password[i] = *password_save;
                    password_save++;
                    i++;
                }
                printf("OK. There's nothing wrong with your password.\n");
                break;
            }else {
                printf("You can only enter numbers! Please enter your account again.\n");
                password_save = NULL;
                printf("Your password: ");
                fgets(accounts, 20, stdin);
            }
        }

        printf("Please enter your work number.It has to be made of pure numbers and the maxsize is 12.\n");
        printf("Your work number: ");
        fgets(work_number, 12, stdin);

        while (true) {
            if (check_string(ACCOUNT, work_number)==SUCCESS) {
                new_user->account = atol(work_number);
                printf("OK. There's nothing wrong with your work number.\n");
                break;
            }else {
                printf("You can only enter numbers! Please enter your work number again.\n");
                work_number = NULL;
                printf("Your work number: ");
                fgets(work_number, 12, stdin);
            }
        }
    }



    // if not the first time to create a user
    else if (is_first == NOT_FIRST_USER) {

        printf("Now you are creating a new user, please select his role.\n");
        _Bool select_right = false;
        while (!select_right) {
            int switch_number = 0;
            printf("Enter your select: \n");
            printf("\t\t1: Subject Teacher\t\t\t2: Consellor\n");
            printf("\t\t3: Guidence director\t\t\t4: Administrator\n");
            scanf("%d",&switch_number);
            getchar();
            switch (switch_number) {
                case 1:
                    new_user->USER_ROLE = SUBJECT_TEACHER;
                    printf("OK, his role will be that of a Subject Teacher.\n");
                    select_right = true;
                    break;
                case 2:
                    new_user->USER_ROLE = CONSELLOR;
                    printf("OK,his role will be that of a Consellor.\n");
                    select_right = true;
                    break;
                case 3:
                    new_user->USER_ROLE = GUIDANCE_DIRECTOR;
                    printf("OK, his role will be that of a Guidence director.\n");
                    select_right = true;
                    break;
                case 4:
                    new_user->USER_ROLE = ADMINISTRATOR;
                    printf("OK, his role will be that of a Administrator.\n");
                    select_right = true;
                    break;
                default:
                    printf("You must enter a number between 1 and 4!\n");
                    printf("Please enter your select again.\n");
            }
        }

        printf("Please enter your account.It has to be made of pure numbers and the maxsize is 20.\n");
        printf("Your account: ");
        fgets(accounts, 20, stdin);

        while (true) {
            if (check_string(ACCOUNT, accounts)==SUCCESS) {
                new_user->account = atol(accounts);
                printf("OK. There's nothing wrong with your account number.\n");
                break;
            }else {
                printf("You can only enter numbers! Please enter your account again.\n");
                accounts = NULL;
                printf("Your account: ");
                fgets(accounts, 20, stdin);
            }
        }


        printf("Please enter your password, it consists of letters and numbers and the maxsize is 32\n");
        printf("Your password: ");
        fgets(password_save, 32, stdin);

        while (true) {
            if (check_string(PASSWORD, password_save)==SUCCESS) {
                int i = 0;
                while (password_save) {
                    new_user->password[i] = *password_save;
                    password_save++;
                    i++;
                }
                printf("OK. There's nothing wrong with your password.\n");
                break;
            }else {
                printf("You can only enter numbers! Please enter your account again.\n");
                password_save = NULL;
                printf("Your password: ");
                fgets(accounts, 20, stdin);
            }
        }

        printf("Please enter your work number.It has to be made of pure numbers and the maxsize is 12.\n");
        printf("Your work number: ");
        fgets(work_number, 12, stdin);

        while (true) {
            if (check_string(ACCOUNT, work_number)==SUCCESS) {
                new_user->account = atol(work_number);
                printf("OK. There's nothing wrong with your work number.\n");
                break;
            }else {
                printf("You can only enter numbers! Please enter your work number again.\n");
                work_number = NULL;
                printf("Your work number: ");
                fgets(work_number, 12, stdin);
            }
        }
    }
    return new_user;
}