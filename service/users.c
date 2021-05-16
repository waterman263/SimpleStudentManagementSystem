/**
 * @file users.c
 * @author @Loritas
 * @brief implement user.h
 * @version 0.1
 * @date 2021-03-14
 *
 *
 * @copyright Copyright (c) 2021
 * 
 */
#include "serviceHead/users.h"
#define RED_FRONT_COLOR "\033[0;32;31m"
#define COLOR_NONE  "\033[m"

USER create_user(USER user, users_head_p head, enum BOOLEAN_USE is_first){

    // if the pointer has a value, return an error
    if (user != NULL)
    {
        printf(RED_FRONT_COLOR"An unexpected error has been created,"COLOR_NONE);
        printf(RED_FRONT_COLOR" please save your work and exit this program.\n"COLOR_NONE);
        return NULL;
    }

    USER new_user = (USER)malloc(sizeof(users));

    if (!new_user)
    {
        printf(RED_FRONT_COLOR"Warning: Your computer has not enough free memory,"COLOR_NONE);
        printf(RED_FRONT_COLOR" please save your work and exit this program.\n"COLOR_NONE);
        return NULL;
    }
    new_user->next = NULL;
    new_user = set_user(new_user, head, is_first);
    user = new_user;

    printf("That's alright.Returning to the main menu\n");
    return new_user;
}

enum USER_ROLE check_account(long account, char password[]){
    enum USER_ROLE result = ADMINISTRATOR;
    return result;
}


/**
 * @brief Function for initial list
 * @return head_point for user list
 */
users_head_p initial_User_List(){
    users_head_p head_point = (users_head_p)malloc(sizeof(users_head));

    if (head_point == NULL)
    {
        printf(RED_FRONT_COLOR"Warning: Your computer has not enough free memory,\n"COLOR_NONE);
        printf(RED_FRONT_COLOR"please press any key to exit this program."COLOR_NONE);
        getchar();
        exit(0);
    }

    head_point->isHead = TRUE_RES;
    head_point->next = NULL;
    return head_point;
}

/**
 * @brief set the properties of user
 *
 * @param user new user
 * @param is_first whether it is the first time to create user
 *
 * @return USER entity
 */
USER set_user(USER user, users_head_p head, enum BOOLEAN_USE is_first){

    char user_account[11];
    char *accounts = user_account;

    char user_password[33];
    char *password_save = user_password;

    char user_work_number [10];
    char *work_number = user_work_number;

    // If it is the first time to create a user
    if (is_first == IS_FIRST_USER)
    {
        printf("This is the first time you create a user, it must be an administrator.\n");
        user->USER_ROLE = ADMINISTRATOR;
        printf("Please enter your account.It has to be made of pure numbers and the maxsize is 10.\n");
        printf("In addition, the leading zero of the account will be truncated.\n");
        printf("If you type more than 10 characters, the extra characters will be truncated.\n");
        printf("Your account:");
        fgets(user_account, 11, stdin);
        fflush(stdin);

        while (true) {
            if (check_string(ACCOUNT, user_account) == SUCCESS && atol(user_account) != 0) {
                user->account = atol(user_account);
                printf("OK. There's nothing wrong with your account number.\n");
                break;
            }else {
                printf("You can only enter numbers and at least one number other than 0! Please enter your account again.\n");
                printf("Your account:");
                fgets(user_account, 11, stdin);
                fflush(stdin);
            }
        }

        printf("Please enter your password, it consists of letters and numbers and the length is between 6 and 32\n");
        printf("Your password:");
        fgets(password_save, 33, stdin);
        fflush(stdin);

        while (true) {
            if (strlen(password_save) == 1){
                printf("Your password cannot be empty! Please enter your password again.\n");
                printf("Your password:");
                fgets(password_save, 33, stdin);
                fflush(stdin);
            }
            else if (check_string(PASSWORD, user_password)==SUCCESS) {
                int i = 0;
                while (*password_save != '\n') {
                    user->password[i] = *password_save;
                    password_save++;
                    i++;
                }
                printf("OK. There's nothing wrong with your password.\n");
                break;
            }
            else {
                printf("You can only enter numbers or letters! Please enter your password again.\n");
                printf("Your password:");
                fgets(password_save, 33, stdin);
                fflush(stdin);
            }
        }

        printf("Please enter your work number.It has to be made of pure numbers and the maxsize is 8.\n");
        printf("In addition, the leading zero of the work number will be truncated.\n");
        printf("Your work number:");
        fgets(work_number, 9, stdin);
        fflush(stdin);

        while (true) {
            if (check_string(ACCOUNT, user_work_number)==SUCCESS && atol(user_work_number) != 0) {
                user->work_number = atol(user_work_number);
                printf("OK. There's nothing wrong with your work number.\n");
                break;
            }else {
                printf("You can only enter numbers and at least one number other than 0! Please enter your work number again.\n");
                printf("Your work number:");
                fgets(work_number, 9, stdin);
                fflush(stdin);
            }
        }
    }

    // if not the first time to create a user
    else if (is_first == NOT_FIRST_USER) {

        printf("Now you are creating a new user, please select his role.\n");
        _Bool select_right = false;
        while (!select_right) {
            char switch_number = '0';
            printf("Enter your select: \n");
            printf("\t\t1: Subject Teacher\t\t\t2: Counsellor\n");
            printf("\t\t3: Guidance director\t\t\t4: Administrator\n");
            scanf("%c",&switch_number);
            fflush(stdin);
            switch (switch_number) {
                case '1':
                    user->USER_ROLE = SUBJECT_TEACHER;
                    printf("OK, his role will be that of a Subject Teacher.\n");
                    select_right = true;
                    break;
                case '2':
                    user->USER_ROLE = COUNSELLOR;
                    printf("OK,his role will be that of a Counsellor.\n");
                    select_right = true;
                    break;
                case '3':
                    user->USER_ROLE = GUIDANCE_DIRECTOR;
                    printf("OK, his role will be that of a Guidance director.\n");
                    select_right = true;
                    break;
                case '4':
                    user->USER_ROLE = ADMINISTRATOR;
                    printf("OK, his role will be that of a Administrator.\n");
                    select_right = true;
                    break;
                default:
                    printf("You must enter a number between 1 and 4!\n");
                    printf("Please enter your select again.\n");
            }
        }

        printf("Please enter your account.It has to be made of pure numbers and the maxsize is 10.\n");
        printf("In addition, the leading zero of the account will be truncated.\n");
        printf("If you type more than 10 characters, the extra characters will be truncated.\n");
        printf("Your account:");
        fgets(user_account, 11, stdin);
        fflush(stdin);

        while (true) {
            if (check_string(ACCOUNT, user_account) == SUCCESS && atol(user_account) != 0) {
                if (check_exist_account(head, atol(user_account))){
                    printf("The account you entered already exists, Please enter your account again.\n");
                    printf("Your account:");
                    fgets(user_account, 11, stdin);
                    fflush(stdin);
                    continue;
                }
                user->account = atol(user_account);
                printf("OK. There's nothing wrong with your account number.\n");
                break;
            }
            else {
                printf("You can only enter numbers and at least one number other than 0! Please enter your account again.\n");
                printf("Your account:");
                fgets(user_account, 11, stdin);
                fflush(stdin);
            }
        }

        printf("Please enter your password, it consists of letters and numbers and the maxsize is 32\n");
        printf("Your password:");
        fgets(password_save, 33, stdin);
        fflush(stdin);

        while (true) {
            if (strlen(password_save) == 1){
                printf("Your password cannot be empty! Please enter your password again.\n");
                printf("Your password:");
                fgets(accounts, 33, stdin);
                fflush(stdin);
            }
            else if (check_string(PASSWORD, user_password)==SUCCESS) {
                int i = 0;
                while (*password_save != '\n') {
                    user->password[i] = *password_save;
                    password_save++;
                    i++;
                }
                printf("OK. There's nothing wrong with your password.\n");
                break;
            }
            else {
                printf("You can only enter numbers or letters! Please enter your password again.\n");
                printf("Your password:");
                fgets(password_save, 33, stdin);
                fflush(stdin);
            }
        }

        printf("Please enter your work number.It has to be made of pure numbers and the maxsize is 8.\n");
        printf("In addition, the leading zero of the work number will be truncated.\n");
        printf("Your work number:");
        fgets(work_number, 9, stdin);
        fflush(stdin);

        while (true) {
            if (check_string(ACCOUNT, user_work_number)==SUCCESS && atol(user_work_number) != 0) {
                if (check_exist_work_number(head, atol(user_work_number))){
                    printf("The work number you entered already exists, Please enter your work number again.\n");
                    printf("Your work number:");
                    fgets(work_number, 9, stdin);
                    fflush(stdin);
                    continue;
                }
                user->work_number = atol(user_work_number);
                printf("OK. There's nothing wrong with your work number.\n");
                break;
            }
            else {
                printf("You can only enter numbers and at least one number other than 0! Please enter your work number again.\n");
                printf("Your work number:");
                fgets(work_number, 9, stdin);
                fflush(stdin);
            }
        }
    }
    return user;
}

_Bool check_exist_account(users_head_p head, long long account_input) {
    USER users = head->next;
    while (users != NULL){
        if (users->account == account_input){
            return true;
        } else{
            users = users->next;
        }
    }
    return false;
}
_Bool check_exist_work_number(users_head_p head, long work_number_input){
    USER users = head->next;
    while (users != NULL){
        if (users->work_number == work_number_input){
            return true;
        } else{
            users = users->next;
        }
    }
    return false;
}