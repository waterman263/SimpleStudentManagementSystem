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
#include "serviceHead/users_service.h"


/**
 * @author Loritas
 * @brief Function for initial user list
 * @date 2021-3-14
 *
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
    head_point->administrator_number = 0;
    head_point->next = NULL;
    return head_point;
}


/**
 * @author Loritas
 * @brief create new user
 * @date 2021-3-14
 *
 * @param user
 * @param head  head pointer
 * @param is_first  whether the first to create user
 * @return  new user
 */
USER create_user(users_head_p head, enum BOOLEAN_USE is_first){

    // if the pointer has a value, return an error
    if (head == NULL){
        printf(RED_FRONT_COLOR"An unexpected error has been created,"COLOR_NONE);
        printf(RED_FRONT_COLOR" please save your work and exit this program.\n"COLOR_NONE);
        return NULL;
    }

    USER temp_user = head->next;

    USER new_user = (USER)malloc(sizeof(users));

    if (new_user == NULL){
        printf(RED_FRONT_COLOR"Warning: Your computer has not enough free memory,"COLOR_NONE);
        printf(RED_FRONT_COLOR" please save your work and exit this program.\n"COLOR_NONE);
        return NULL;
    }
    new_user->next = NULL;
    new_user = set_user(new_user, head, is_first);

     while (temp_user->next != NULL){
         temp_user = temp_user->next;
     }

     temp_user->next = new_user;

    printf("That's alright.Returning to the menu\n");
    return new_user;
}

/**
 * @author Loritas
 * @brief set the properties of user
 * @date 2021-3-14
 *
 * @param user new user
 * @param is_first whether it is the first time to create user
 *
 * @return USER entity
 */
USER set_user(USER user, users_head_p head, enum BOOLEAN_USE is_first){

    char user_account[12];

    char user_password[33];
    char *password_save = user_password;

    char user_work_number [10];
    char *work_number = user_work_number;

    char user_name[21];
    char *get_name = user_name;

    // If it is the first time to create a user
    if (is_first == IS_FIRST_USER)
    {
        printf("==This is the first time you create a user, it must be an administrator.\n");
        user->USER_ROLE = ADMINISTRATOR;
        head->administrator_number++;
        printf("==Please enter your account.It has to be made of pure numbers and the maxsize is 10.\n");
        printf("==In addition, the leading zero of the account will be truncated.\n");
        printf("==If you type more than 10 characters, the extra characters will be truncated.\n");
        printf("==Your account:");
        fgets(user_account, 11, stdin);
        fflush(stdin);

        while (true) {
            if (check_string(ACCOUNT, user_account) == SUCCESS && atoll(user_account) != 0) {
                user->account = atoll(user_account);
                printf("==OK. There's nothing wrong with your account number.\n");
                break;
            }else {
                printf("==You can only enter numbers and at least one number other than 0! Please enter your account again.\n");
                printf("==Your account:");
                fgets(user_account, 11, stdin);
                fflush(stdin);
            }
        }

        printf("==Please enter your password, it consists of letters and numbers and the length is between 6 and 32\n");
        printf("==Your password:");
        fgets(password_save, 33, stdin);
        fflush(stdin);

        while (true) {
            if (strlen(password_save) == 1){
                printf("==Your password cannot be empty! Please enter your password again.\n");
                printf("==Your password:");
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
                user->password[i] = '\0';
                printf("==OK. There's nothing wrong with your password.\n");
                break;
            }
            else {
                printf("==You can only enter numbers or letters! Please enter your password again.\n");
                printf("==Your password:");
                fgets(password_save, 33, stdin);
                fflush(stdin);
            }
        }

        printf("==Please enter your work number.It has to be made of pure numbers and the maxsize is 8.\n");
        printf("==In addition, the leading zero of the work number will be truncated.\n");
        printf("==Your work number:");
        fgets(work_number, 9, stdin);
        fflush(stdin);

        while (true) {
            if (check_string(ACCOUNT, user_work_number)==SUCCESS && atol(user_work_number) != 0) {
                user->work_number = atol(user_work_number);
                printf("==OK. There's nothing wrong with your work number.\n");
                break;
            }else {
                printf("==You can only enter numbers and at least one number other than 0! Please enter your work number again.\n");
                printf("==Your work number:");
                fgets(work_number, 9, stdin);
                fflush(stdin);
            }
        }
    }

    // if not the first time to create a user
    else if (is_first == NOT_FIRST_USER) {

        printf("==Now you are creating a new user, please select his role.\n");
        _Bool select_right = false;
        while (!select_right) {
            char switch_number = '0';
            printf("==Enter your select: \n");
            printf("\t\t1: Subject Teacher\t\t\t2: Counsellor\n");
            printf("\t\t3: Guidance director\t\t\t4: Administrator\n");
            scanf("%c",&switch_number);
            fflush(stdin);
            switch (switch_number) {
                case '1':
                    user->USER_ROLE = SUBJECT_TEACHER;
                    printf("==OK, his role will be that of a Subject Teacher.\n");
                    select_right = true;
                    break;
                case '2':
                    user->USER_ROLE = COUNSELLOR;
                    printf("==OK,his role will be that of a Counsellor.\n");
                    select_right = true;
                    break;
                case '3':
                    user->USER_ROLE = GUIDANCE_DIRECTOR;
                    printf("==OK, his role will be that of a Guidance director.\n");
                    select_right = true;
                    break;
                case '4':
                    user->USER_ROLE = ADMINISTRATOR;
                    head->administrator_number++;
                    printf("==OK, his role will be that of a Administrator.\n");
                    select_right = true;
                    break;
                default:
                    printf("==You must enter a number between 1 and 4!\n");
                    printf("==Please enter your select again.\n");
            }
        }

        printf("==Please enter your account.It has to be made of pure numbers and the maxsize is 10.\n");
        printf("==In addition, the leading zero of the account will be truncated.\n");
        printf("==If you type more than 10 characters, the extra characters will be truncated.\n");
        printf("==Your account:");
        fgets(user_account, 11, stdin);
        fflush(stdin);

        while (true) {
            if (check_string(ACCOUNT, user_account) == SUCCESS && atoll(user_account) != 0) {
                if (check_exist_account(head, atoll(user_account))){
                    printf("==The account you entered already exists, Please enter your account again.\n");
                    printf("==Your account:");
                    fgets(user_account, 11, stdin);
                    fflush(stdin);
                    continue;
                }
                user->account = atoll(user_account);
                printf("==OK. There's nothing wrong with your account number.\n");
                break;
            }
            else {
                printf("==You can only enter numbers and at least one number other than 0! Please enter your account again.\n");
                printf("==Your account:");
                fgets(user_account, 11, stdin);
                fflush(stdin);
            }
        }

        printf("==Please enter your password, it consists of letters and numbers and the maxsize is 32\n");
        printf("==Your password:");
        fgets(password_save, 33, stdin);
        fflush(stdin);

        while (true) {
            if (strlen(password_save) == 1){
                printf("==Your password cannot be empty! Please enter your password again.\n");
                printf("==Your password:");
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
                user->password[i] = '\0';
                printf("==OK. There's nothing wrong with your password.\n");
                break;
            }
            else {
                printf("==You can only enter numbers or letters! Please enter your password again.\n");
                printf("==Your password:");
                fgets(password_save, 33, stdin);
                fflush(stdin);
            }
        }

        printf("==Please enter your work number.It has to be made of pure numbers and the maxsize is 8.\n");
        printf("==In addition, the leading zero of the work number will be truncated.\n");
        printf("==Your work number:");
        fgets(work_number, 9, stdin);
        fflush(stdin);

        while (true) {
            if (check_string(ACCOUNT, user_work_number)==SUCCESS && atol(user_work_number) != 0) {
                if (check_exist_work_number(head, atol(user_work_number))){
                    printf("==The work number you entered already exists, Please enter your work number again.\n");
                    printf("==Your work number:");
                    fgets(work_number, 9, stdin);
                    fflush(stdin);
                    continue;
                }
                user->work_number = atol(user_work_number);
                printf("==OK. There's nothing wrong with your work number.\n");
                break;
            }
            else {
                printf("==You can only enter numbers and at least one number other than 0! Please enter your work number again.\n");
                printf("==Your work number:");
                fgets(work_number, 9, stdin);
                fflush(stdin);
            }
        }
    }

     printf("==Please enter your name, it's maxsize is 20\n");
     printf("==Your name:");
     fgets(get_name, 20, stdin);
     fflush(stdin);

     int i = 0;
     while (*get_name != '\n') {
         user->name[i] = *get_name;
         get_name++;
         i++;
     }
     user_name[i] = '\0';
     printf("==OK. Now we will return to the menu.\n");

     return user;
}

/**
 * @author Loritas
 * @brief delete target user, avoid deleting the currently active user
 * @date 2021-5-18
 *
 * @param head  user_list head pointer
 * @param current_user  check the information,
 * @return
 */
enum OPERATE delete_user(users_head_p head, USER current_user){
    if (head == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    long long account;
    char user_account[12];
    USER temp_for_check = head->next;
    printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
    printf("==Please enter the target account:\n");
    fgets(user_account, 11, stdin);
    fflush(stdin);

    while (true){
        if (atoll(user_account) == 0){
            printf("==OK, returning menu now...\n");
            return SUCCESS;
        }

        if (check_string(ACCOUNT, user_account) == SUCCESS) {
            account = atoll(user_account);
            if (current_user->account == account){
                printf("==You cannot delete yourself! Please check the target account!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
                printf("==Target account:");
                fgets(user_account, 11, stdin);
                fflush(stdin);
                continue;
            }

            while (temp_for_check != NULL){
                if (temp_for_check->account == account) break;
                temp_for_check = temp_for_check->next;
            }

            if (temp_for_check == NULL){
                printf("==The account is not exist yet, please check the target account!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
                printf("==Target account:");
                temp_for_check = head->next;
                fgets(user_account, 11, stdin);
                fflush(stdin);
            }else break;
        }else {
            printf("You can only enter numbers! Please enter the target account again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
            printf("Target account:");
            fgets(user_account, 11, stdin);
            fflush(stdin);
        }
    }

    if (temp_for_check->USER_ROLE == ADMINISTRATOR){
        head->administrator_number--;
    }

    if (temp_for_check->account == head->next->account){
        head->next = temp_for_check->next;
        free(temp_for_check);
    }else {
        USER front_user = head->next;
        while (front_user->next->account != temp_for_check->account){
            front_user = front_user->next;
        }
        front_user->next = temp_for_check->next;
        free(temp_for_check);
    }

    printf("==Got it! The user has been deleted successfully!\n");
    printf("==Returning menu now...\n");

    return SUCCESS;
}

/**
 * @author Loritas
 * @brief query users' information
 * @date 2021-5-18
 *
 * @param head  user_list head pointer
 * @param select_all_user  whether query all users' information
 * @return  whether the operate success
 */
enum OPERATE query_user(users_head_p head, int select_all_user){


    if (select_all_user == TRUE_RES) return query_all_user(head);
    if (select_all_user == FALSE_RES) return query_one_user(head);
    else {
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }
}
enum OPERATE query_all_user(users_head_p head){
    if (head == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }
    USER temp_user = head->next;
    char users_role[4][20] = {"ADMINISTRATOR", "SUBJECT_TEACHER", "COUNSELLOR", "GUIDANCE_DIRECTOR"};

    printf("\t\tNAME\t\t\tACCOUNT\t\t\tWORK_NUMBER\t\t\tROLE\n");
    while (temp_user != NULL){
        printf("%20s\t\t\t%10lld\t\t%8ld\t%20s\n", temp_user->name,
                                                       temp_user->account,
                                                       temp_user->work_number,
                                                       users_role[temp_user->USER_ROLE + 5]);
        temp_user = temp_user->next;
    }
    return SUCCESS;
}
enum OPERATE query_one_user(users_head_p head){
    if (head == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char users_role[4][20] = {"ADMINISTRATOR", "SUBJECT_TEACHER", "COUNSELLOR", "GUIDANCE_DIRECTOR"};

    long long account;
    char user_account[12];
    USER temp_for_check = head->next;
    printf("==Please enter the target account:\n");
    printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
    fgets(user_account, 11, stdin);
    fflush(stdin);

    while (true){
        if (check_string(ACCOUNT, user_account) == SUCCESS) {
            if (atoll(user_account) == 0){
                printf("==OK, returning menu now...\n");
                return SUCCESS;
            }

            account = atoll(user_account);
            while (temp_for_check != NULL){
                if (temp_for_check->account == account) break;
                temp_for_check = temp_for_check->next;
            }

            if (temp_for_check == NULL){
                printf("==The account is not exist yet, please check the target account!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
                printf("==Target account:");
                temp_for_check = head->next;
                fgets(user_account, 11, stdin);
                fflush(stdin);
            }else break;
        }else {
            printf("==You can only enter numbers! Please enter the target account again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
            printf("Target account:");
            fgets(user_account, 11, stdin);
            fflush(stdin);
        }
    }
    printf("\t\tNAME\t\t\tACCOUNT\t\t\tWORK_NUMBER\t\t\tROLE\n");
    printf("%20s\t\t\t%10lld\t\t%8ld\t%20s\n", temp_for_check->name,
                                                  temp_for_check->account,
                                                  temp_for_check->work_number,
                                                  users_role[temp_for_check->USER_ROLE + 5]);
    return SUCCESS;
}

/**
 * @author Loritas
 * @brief update user's information
 * @date 2021-5-18
 *
 * @param head  user_list head pointer
 * @return  whether the operate success
 */
enum OPERATE update_user(users_head_p head){
    if (head == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    long long account;
    char user_account[12];
    USER temp_for_check = head->next;
    printf("==Please enter the target account:\n");
    printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
    fgets(user_account, 11, stdin);
    fflush(stdin);

    while (true){
        if (atoll(user_account) == 0){
            printf("==OK, returning menu now...\n");
            return SUCCESS;
        }
        if (check_string(ACCOUNT, user_account) == SUCCESS) {
            account = atoll(user_account);

            while (temp_for_check != NULL){
                if (temp_for_check->account == account) break;
                temp_for_check = temp_for_check->next;
            }

            if (temp_for_check == NULL){
                printf("==The account is not exist yet, please check the target account!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
                printf("==Target account:");
                temp_for_check = head->next;
                fgets(user_account, 11, stdin);
                fflush(stdin);
            }else break;
        }else {
            printf("==You can only enter numbers! Please enter the target account again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than account.\n");
            printf("==Target account:");
            fgets(user_account, 11, stdin);
            fflush(stdin);
        }
    }

    char user_work_number [10];
    char *work_number = user_work_number;

    char user_name[21];
    char *get_name = user_name;

    printf("Please enter the new work number.It has to be made of pure numbers and the maxsize is 8.\n");
    printf("In addition, the leading zero of the work number will be truncated.\n");
    printf("New work number:");
    fgets(work_number, 9, stdin);
    fflush(stdin);

    while (true) {
        if (check_string(ACCOUNT, user_work_number) == SUCCESS && atol(user_work_number) != 0) {
            if (check_exist_work_number(head, atol(user_work_number))){
                printf("The work number you entered already exists, Please enter the new work number again.\n");
                printf("New work number:");
                fgets(work_number, 9, stdin);
                fflush(stdin);
                continue;
            }
            temp_for_check->work_number = atol(user_work_number);
            printf("OK. There's nothing wrong with your work number.\n");
            break;
        } else {
            printf("You can only enter numbers and at least one number other than 0! Please enter your work number again.\n");
            printf("New work number:");
            fgets(work_number, 9, stdin);
            fflush(stdin);
        }
    }

    printf("Please enter the new name, it's maxsize is 20\n");
    printf("New name:");
    fgets(get_name, 20, stdin);
    fflush(stdin);

    int i = 0;
    while (*get_name != '\n') {
        temp_for_check->name[i] = *get_name;
        get_name++;
        i++;
    }
    temp_for_check->name[i] = '\0';

    printf("Now you need to select the user's new identity.\n"
           "If you are changing your identity, please note that when you return to the menu, "
           "you will be taken to another action page.\n");
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
                if (temp_for_check->USER_ROLE == ADMINISTRATOR ){
                    if (head->administrator_number - 1 == 0){
                        printf("Note: at least one system administrator is required!"
                               "You cannot set this user as a non-administrator!\n");
                        break;
                    } else head->administrator_number--;
                }
                temp_for_check->USER_ROLE = SUBJECT_TEACHER;
                printf("OK, his role will be that of a Subject Teacher.\n");
                select_right = true;
                break;
            case '2':
                if (temp_for_check->USER_ROLE == ADMINISTRATOR ){
                    if (head->administrator_number - 1 == 0){
                        printf("Note: at least one system administrator is required!"
                               "You cannot set this user as a non-administrator!\n");
                        break;
                    } else head->administrator_number--;
                }
                temp_for_check->USER_ROLE = COUNSELLOR;
                printf("OK,his role will be that of a Counsellor.\n");
                select_right = true;
                break;
            case '3':
                if (temp_for_check->USER_ROLE == ADMINISTRATOR ){
                    if (head->administrator_number - 1 == 0){
                        printf("Note: at least one system administrator is required!"
                               "You cannot set this user as a non-administrator!\n");
                        break;
                    } else head->administrator_number--;
                }
                temp_for_check->USER_ROLE = GUIDANCE_DIRECTOR;
                printf("OK, his role will be that of a Guidance director.\n");
                select_right = true;
                break;
            case '4':
                if (temp_for_check->USER_ROLE != ADMINISTRATOR) head->administrator_number++;
                temp_for_check->USER_ROLE = ADMINISTRATOR;
                printf("OK, his role will be that of a Administrator.\n");
                select_right = true;
                break;
            default:
                printf("You must enter a number between 1 and 4!\n");
                printf("Please enter your select again.\n");
        }
    }

    printf("OK. Now we will return to the menu.\n");
    return SUCCESS;
}

/**
 * @author Loritas
 * @brief login in the program
 * @date 2021-5-17
 *
 * @param head  user_list head pointer
 * @param user  the user who will login in
 * @return
 */
enum OPERATE login(users_head_p head, USER *user){
    long long account;
    char user_account[12];
    char user_password[33];
    char *password = user_password;
    do {
        printf("==Please enter your account:\n");
        fgets(user_account, 11, stdin);
        fflush(stdin);

        while (true){
            if (check_string(ACCOUNT, user_account) == SUCCESS && atoll(user_account) != 0) {
                account = atoll(user_account);
                break;
            }else {
                printf("==You can only enter numbers and at least one number other than 0! Please enter your account again.\n");
                printf("==Your account:");
                fgets(user_account, 11, stdin);
                fflush(stdin);
            }
        }

        printf("==Now please enter your password:\n");
        fgets(password, 32, stdin);
        fflush(stdin);

        printf("==OK.If you want to return to the main menu, you can enter 1, "
               "or the system will check your account and password.\n");

        char switch_number = '0';
        scanf("%c",&switch_number);
        fflush(stdin);

        if (switch_number == '1'){
            printf("==OK, now you will return to the main menu.\n");
            return FAILED;
        }else {
            printf("==OK, now the system will check your account and password\n");
        }

    } while (check_account(account, password, head, user) != SUCCESS);

    return SUCCESS;
}

enum OPERATE check_account(long long account, char password[], users_head_p head, USER *user){
    char *temp_password = password;
    USER temp_for_check = head->next;
    while (temp_for_check != NULL){
        if (temp_for_check->account == account) break;
        temp_for_check = temp_for_check->next;
    }

    if (temp_for_check == NULL){
        printf("==The account is not exist yet, please check your account!\n");
        return FAILED;
    }

    if (temp_for_check->USER_ROLE != ADMINISTRATOR){
        printf("==Sorry, the system only allows administrator to log in, please change your account.\n");
        return FAILED;
    }

    int i = 0;
    while (temp_password[i] != '\n') i++;
    temp_password[i] = '\0';
    if (strcmp(temp_for_check->password, password) != 0){
        printf("==Your password is not correct, please check your password!\n");
        return FAILED;
    }
    *user = temp_for_check;
    return SUCCESS;
}

// check data
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