/**
 * @file counsellor_service.c
 * @author @waterman263
 * @brief    counsellor setting
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 *///
// Created by 86189 on 2021/5/19.
//
#include "serviceHead/counsellor_service.h"


 counsellor_head_p initial_counsellor_List(){
    counsellor_head_p head_point = (counsellor_head_p)malloc(sizeof(counsellor_head_p));
    if(head_point == NULL)
    {
        printf("Warning: Your computer has not enough free memory,\n");
        printf("please press any key to exit this program.");
        getchar();
        exit(0);
    }
    head_point ->next = NULL;
    return head_point;
}



/**
 * @file counsellor_service.c
 * @author @waterman263
 * @brief    find information of counsellor
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */


enum OPERATE find_counsellor(counsellor_head_p headP, enum SELECT select){
    if(select == NAME) return find_counsellor_by_name(headP);
    if (select == WORK_NUMBER) return find_counsellor_by_work_number(headP);
    return SUCCESS;
}




/**
 * @file counsellor_service.c
 * @author @waterman263
 * @brief    find information of counsellor by name
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */

enum OPERATE find_counsellor_by_name(counsellor_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char target_counsellor_name[21];
    char *temp_target_counsellor = target_counsellor_name;

    counsellor_p temp_check = headP ->next;

    printf("==Please enter the target counsellor name."
           "It has to be made of pure name and the maxsize is 20\n");
    printf("==If you want to cancel the operate, just enter 0 rather than counsellor name.\n");
    printf("==Target counsellor name:");
    fgets(temp_target_counsellor, 20, stdin);
    fflush(stdin);

    while (true){
        if (target_counsellor_name[0] == '0'){
            printf("==Alright, returning menu...\n");
            return FAILED;
        }

        while(temp_check != NULL){
            if (strcmp(temp_target_counsellor, temp_check->name) == 0) break;
            temp_check = temp_check ->next;
        }

        if (temp_check == NULL){
            printf("==The student is not exist yet! Please check your counsellor name!\n");
            printf("==If you want to cancel the operate, just enter 0 rather than counsellor name.\n");
            printf("==Target counsellor name:");
            fgets(temp_target_counsellor, 20, stdin);
            fflush(stdin);
            temp_check = headP->next;
        } else break;
    }
    printf("姓名： %s\n" , temp_check->name);
    printf("工号： %ld\n" , temp_check->work_number);
    printf("电话： %s\n" , temp_check->phone_number);
    printf("邮箱： %s\n" , temp_check->email);

    return SUCCESS;
}



/**
 * @file counsellor_service.c
 * @author @waterman263
 * @brief    find information of counsellor by work number
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */

enum OPERATE find_counsellor_by_work_number(counsellor_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char target_counsellor_number[12];
    char *temp_target_counsellor = target_counsellor_number;

    counsellor_p temp_check = headP ->next;

    printf("==Please enter the target counsellor number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
    printf("==Target counsellor number:");
    fgets(temp_target_counsellor, 11, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, temp_target_counsellor) == SUCCESS){
            if (atoll(target_counsellor_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            }

            while(temp_check != NULL){
                if (temp_check->work_number == atol(temp_target_counsellor)) break;
                temp_check = temp_check ->next;
            }

            if (temp_check == NULL){
                printf("==The student number is not exist yet! Please check your counsellor number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
                printf("==Target counsellor number:");
                fgets(temp_target_counsellor, 11, stdin);
                fflush(stdin);
                temp_check = headP->next;
            } else break;
        }
        else{
            printf("==You can only enter numbers! Please enter the target counsellor number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
            printf("Target counsellor number:");
            fgets(temp_target_counsellor, 11, stdin);
            fflush(stdin);
        }
    }

    printf("姓名： %s\n" , temp_check->name);
    printf("工号： %ld\n" , temp_check->work_number);
    printf("电话： %s\n" , temp_check->phone_number);
    printf("邮箱： %s\n" , temp_check->email);

    return SUCCESS;
}



/**
 * @file counsellor_service.c
 * @author @waterman263
 * @brief    delete information of counsellor
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */
enum OPERATE delete_counsellor(counsellor_head_p headP,enum SELECT select){
    if(select == NAME )  return delete_counsellor_by_name(headP);
    if(select == WORK_NUMBER)  return delete_counsellor_by_work_number(headP);
    return SUCCESS;
 }



/**
* @file counsellor_service.c
* @author @waterman263
* @brief    delete information of counsellor by name
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/

 enum OPERATE delete_counsellor_by_name(counsellor_head_p headP) {
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char target_counsellor_name[22];
    char *temp_target_counsellor = target_counsellor_name;

    counsellor_p target = headP->next;
    counsellor_p pre_target = headP->next;

    printf("==Please enter the target counsellor name.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than counsellor name.\n");
    printf("==Target counsellor name:");
    fgets(temp_target_counsellor, 21, stdin);
    fflush(stdin);

    while (true){
        if (target_counsellor_name[0] == '0'){
            printf("==Alright, returning menu...\n");
            return FAILED;
        }

        while(target != NULL){
            if (strcmp(temp_target_counsellor, target->name) == 0) break;
            target = target ->next;
        }

        if (target == NULL){
            printf("==The student is not exist yet! Please check your counsellor name!\n");
            printf("==If you want to cancel the operate, just enter 0 rather than counsellor name.\n");
            printf("==Target counsellor name:");
            fgets(temp_target_counsellor, 20, stdin);
            fflush(stdin);
            target = headP->next;
        } else break;
    }

    if (target->work_number == pre_target->work_number){
        headP->next = target->next;
    } else{
        while (pre_target->next->work_number != target->work_number){
            pre_target = pre_target->next;
        }
        pre_target->next = target->next;
    }
    free(target);

    return SUCCESS;
 }




/**
* @file counsellor_service.c
* @author @waterman263
* @brief    delete information of counsellor by number
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/

 enum OPERATE delete_counsellor_by_work_number(counsellor_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char counsellor_work_number[12];
    char *temp_counsellor_work_number = counsellor_work_number;

    counsellor_p target = headP->next;
    counsellor_p pre_target = headP->next;

    printf("==Please enter the target counsellor number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
    printf("==Target counsellor number:");
    fgets(temp_counsellor_work_number, 11, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, temp_counsellor_work_number) == SUCCESS){
            if (atoll(counsellor_work_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            }

            while(target != NULL){
                if (target->work_number == atol(temp_counsellor_work_number)) break;
                target = target ->next;
            }

            if (target == NULL){
                printf("==The student number is not exist yet! Please check your counsellor number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
                printf("==Target counsellor number:");
                fgets(temp_counsellor_work_number, 11, stdin);
                fflush(stdin);
                target = headP->next;
            } else break;
        }
        else{
            printf("==You can only enter numbers! Please enter the target counsellor number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
            printf("Target counsellor number:");
            fgets(temp_counsellor_work_number, 11, stdin);
            fflush(stdin);
        }
    }

    if (target->work_number == pre_target->work_number){
        headP->next = target->next;
    } else{
        while (pre_target->next->work_number != target->work_number){
            pre_target = pre_target->next;
        }
        pre_target->next = target->next;
    }
    free(target);

    return SUCCESS;
 }




/**
* @file counsellor_service.c
* @author @waterman263
* @brief    add information of counsellor
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/
 enum OPERATE add_counsellor(counsellor_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    counsellor_p end_counsellor = headP->next;
    counsellor_p new_counsellor = (counsellor_p ) malloc(sizeof(counsellor_p ));
    if(end_counsellor == NULL){
        end_counsellor = new_counsellor;
    }else{
        while (end_counsellor->next != NULL){
            end_counsellor = end_counsellor->next;
        }

        end_counsellor->next = new_counsellor;
    }
    char uid[24];
    char *temp_uid = uid;

    create_uid(temp_uid);
    strcpy(new_counsellor->uid, uid);

    //char class_uid[20];//

    char work_number[12];
    char *temp_counsellor_number = work_number;
    printf("==Please enter the target counsellor number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
    printf("==Target counsellor number:");
    fgets(temp_counsellor_number, 11, stdin);
    fflush(stdin);
    while (true){
        if (check_string(ACCOUNT, temp_counsellor_number) == SUCCESS){
            if (atol(work_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            } else{
                new_counsellor->  work_number = atol(work_number);
                printf("==OK, the counsellor has been set successfully.\n");
                break;
            }
        } else{
            printf("==You can only enter numbers! Please enter the  counsellor number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
            printf("The counsellor number:");
            fgets(temp_counsellor_number, 11, stdin);
            fflush(stdin);
        }
    }

    char counsellor_name[22];
    char *temp_counsellor_name = counsellor_name;
    printf("==Please enter the target counsellor name."
           "It has to be made of pure name and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than counsellor name.\n");
    printf("==Target counsellor name:");
    fgets(temp_counsellor_number, 21, stdin);
    fflush(stdin);
    strcpy(new_counsellor->name , counsellor_name);



    char email[33];
    char *temp_email = email;
    printf("==Please enter the target counsellor email."
           "It has to be made of pure email and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than counsellor email.\n");
    printf("==Target counsellor email:");
    fgets(temp_email, 32, stdin);
    fflush(stdin);

    while (true){
        if (check_string(EMAIL, temp_email) == SUCCESS){
            strcpy(new_counsellor->email , email);
            printf("==OK, the counsellor email has been set successfully.\n");
            break;
        } else{
            printf("==You can only enter email! Please enter the  counsellor email again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than counsellor email.\n");
            printf("The counsellor email:");
            fgets(temp_email, 32, stdin);
            fflush(stdin);
        }
    }

    char phone_number[12];
    char *temp_phone = phone_number;
    printf("==Please enter the target phone number."
           "It has to be made of pure phone number and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than phone number.\n");
    printf("==Target phone number:");
    fgets(temp_phone, 12, stdin);
    fflush(stdin);

    while (true){
        if (check_string(TELEPHONE_NUMBER, temp_phone) == SUCCESS){
            if (atol(phone_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            } else{
                strcpy(new_counsellor->phone_number , phone_number);
                printf("==OK, the counsellor has been set successfully.\n");
                break;
            }
        } else{
            printf("==You can only enter numbers! Please enter the  phone number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than phone number.\n");
            printf("The phone number:");
            fgets(temp_phone, 12, stdin);
            fflush(stdin);
        }
    }

    new_counsellor->HAS_MAX_CLASS = FALSE_RES;


    return SUCCESS;
 }



/**
* @file counsellor_service.c
* @author @waterman263
* @brief    change information of counsellor
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/

 enum OPERATE update_counsellor(counsellor_head_p headP , enum SELECT select){
    if(select == NAME) return update_counsellor_by_name(headP);
    if(select == WORK_NUMBER) return update_counsellor_by_work_number(headP);
    return SUCCESS;
 }


 enum OPERATE update_counsellor_by_name(counsellor_head_p headP){
     if (headP == NULL){
         printf("Fata Error: An unexpected error has been created, "
                "please save your work and exit the system.\n");
         return FAILED;
     }

     char counsellor_name[22];
     char *target_counsellor_name = counsellor_name;

     counsellor_p temp_check = headP->next;

     printf("==Please enter the target counsellor name.\n");
     printf("==If you want to cancel the operate, just enter 0 rather than counsellor name.\n");
     printf("==Target counsellor name:");
     fgets(target_counsellor_name, 21, stdin);
     fflush(stdin);

     while (true){
         if (target_counsellor_name[0] == '0'){
             printf("==Alright, returning menu...\n");
             return FAILED;
         }

         while(temp_check != NULL){
             if (strcmp(counsellor_name, temp_check->name) == 0) break;
             temp_check = temp_check ->next;
         }

         if (temp_check == NULL){
             printf("==The student is not exist yet! Please check your counsellor name!\n");
             printf("==If you want to cancel the operate, just enter 0 rather than counsellor name.\n");
             printf("==Target counsellor name:");
             fgets(target_counsellor_name, 21, stdin);
             fflush(stdin);
             temp_check = headP->next;
         } else break;
     }
     printf("==Please enter the target counsellor name."
            "It has to be made of pure name and the maxsize is 20.\n");
     printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
     printf("==Target counsellor name:");
     fgets(target_counsellor_name, 21, stdin);
     fflush(stdin);

     while (true){
         if (check_string(ACCOUNT, target_counsellor_name) == SUCCESS){
             strcpy(temp_check->name , target_counsellor_name);
             printf("==OK, the counsellor name has been set successfully.\n");
             break;
         }
         else{
             printf("==You can only enter name! Please enter the  counsellor name again.\n");
             printf("==If you want to cancel the operate, just enter 0 rather than counsellor name.\n");
             printf("The counsellor name:");
             fgets(target_counsellor_name, 21, stdin);
             fflush(stdin);
         }
     }

     return SUCCESS;
 }

enum OPERATE update_counsellor_by_work_number(counsellor_head_p headP){
    char counsellor_work_number[12];
    char *temp_counsellor_work_number = counsellor_work_number;

    counsellor_p target = headP->next;

    printf("==Please enter the target counsellor number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
    printf("==Target counsellor number:");
    fgets(temp_counsellor_work_number, 11, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, temp_counsellor_work_number) == SUCCESS){
            if (atoll(counsellor_work_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            }

            while(target != NULL){
                if (target->work_number == atol(temp_counsellor_work_number)) break;
                target = target ->next;
            }

            if (target == NULL){
                printf("==The counsellor number is not exist yet! Please check your counsellor number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
                printf("==Target counsellor number:");
                fgets(temp_counsellor_work_number, 11, stdin);
                fflush(stdin);
                target = headP->next;
            } else break;
        }
        else{
            printf("==You can only enter numbers! Please enter the target counsellor number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
            printf("Target counsellor number:");
            fgets(temp_counsellor_work_number, 11, stdin);
            fflush(stdin);
        }
    }

    printf("==Please enter the target counsellor number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
    printf("==Target counsellor number:");
    fgets(temp_counsellor_work_number, 11, stdin);
    fflush(stdin);
    while (true){
        if (check_string(ACCOUNT, temp_counsellor_work_number) == SUCCESS){
            if (atol(counsellor_work_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            } else{
                target->work_number = atol(counsellor_work_number);
                printf("==OK, the counsellor has been set successfully.\n");
                break;
            }
        } else{
            printf("==You can only enter numbers! Please enter the  counsellor number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than counsellor number.\n");
            printf("The counsellor number:");
            fgets(temp_counsellor_work_number, 11, stdin);
            fflush(stdin);
        }
    }

    return SUCCESS;
 }


