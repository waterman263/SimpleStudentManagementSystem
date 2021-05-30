/**
 * @file class_service.c
 * @author @waterman263
 * @brief    class  setting
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */
//
// Created by 86189 on 2021/5/19.
//

#include "serviceHead/class_service.h"

 class_head_p initial_class_List(){
    class_head_p head_point = (class_head_p)malloc(sizeof(class_head_p));
    if(head_point == NULL){
        printf("Warning: Your computer has not enough free memory,\n");
        printf("please press any key to exit this program.");
        getchar();
        exit(0);
    }
    head_point ->next = NULL;

    return head_point;
}


/**
 * @file class_service.c
 * @author @waterman263
 * @brief    find information of class
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */


enum OPERATE find_class(class_head_p headP,enum SELECT select){
    if(select == ONE) return find_class_one(headP);
    if(select == ALL) return find_class_all(headP);
    return SUCCESS;
}


/**
 * @file class_service.c
 * @author @waterman263
 * @brief    find information of one class
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */
enum OPERATE find_class_one(class_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char class_number[12];
    char *temp_class_number = class_number;

    printf("==Please enter the target class number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
    printf("==Target class number:");
    fgets(temp_class_number, 11, stdin);
    fflush(stdin);

    class_p temp_check = headP->next;
    while (true){
        if(check_string(ACCOUNT, class_number) == SUCCESS){
            if (atol(class_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            }

            while (temp_check != NULL){
                if (temp_check->class_number == atol(class_number)) break;
                temp_check = temp_check->next;
            }

            if (temp_check == NULL){
                printf("==The class number is not exist yet! Please check your class number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
                printf("==Target class number:");
                fgets(temp_class_number, 11, stdin);
                fflush(stdin);
                temp_check = headP->next;
                continue;
            } else{
                break;
            }
        } else{
            printf("==You can only enter numbers! Please enter the target class number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
            printf("Target class number:");
            fgets(temp_class_number, 11, stdin);
            fflush(stdin);
        }
    }

    printf("班级号：%ld  \n",temp_check->class_number);
    printf("数学平均分：%f  \n",temp_check->subject_aver[ADVANCED_MATHEMATICS][0]);
    printf("英语平均分：%f  \n",temp_check->subject_aver[ENGLISH][0]);
    printf("C语言平均分：%f  \n",temp_check->subject_aver[C_PROGRAM_LANGUAGE][0]);
    printf("物理平均分：%f  \n",temp_check->subject_aver[PHYSICAL_EDUCATION][0]);
    printf("python平均分：%f  \n",temp_check->subject_aver[PYTHON][0]);
    printf("平均总分：%f  \n",temp_check->general_aver);
    printf("平均绩点：%f\n",temp_check->general_gpa);

    return  SUCCESS;
}


/**
 * * @file class_service.c
 * @author @waterman263
 * @brief    find information of all class
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */
enum OPERATE find_class_all(class_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

     class_p temp_check = headP->next;
    while(temp_check != NULL){
        printf("班级号：%ld  \n",temp_check->class_number);
        printf("数学平均分：%f  \n",temp_check->subject_aver[ADVANCED_MATHEMATICS][0]);
        printf("英语平均分：%f  \n",temp_check->subject_aver[ENGLISH][0]);
        printf("C语言平均分：%f  \n",temp_check->subject_aver[C_PROGRAM_LANGUAGE][0]);
        printf("物理平均分：%f  \n",temp_check->subject_aver[PHYSICAL_EDUCATION][0]);
        printf("python平均分：%f  \n",temp_check->subject_aver[PYTHON][0]);
        printf("平均总分：%f  \n",temp_check->general_aver);
        printf("平均绩点：%f\n",temp_check->general_gpa);
        temp_check = temp_check->next;
    }

    return SUCCESS;
}




/**
 * @file class_service.c
 * @author @waterman263
 * @brief    delete information of class
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */
enum OPERATE delete_class(class_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char class_number[12];
    char *temp_class_number = class_number;

    printf("==Please enter the target class number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
    printf("==Target class number:");
    fgets(temp_class_number, 11, stdin);
    fflush(stdin);

    class_p temp_check = headP->next;
    class_p temp_check_ano = headP->next;
    _Bool is_head = false;

    while (true){
        if(check_string(ACCOUNT, class_number) == SUCCESS){
            if (atol(class_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            }

            while (temp_check != NULL){
                if (temp_check->class_number == atol(class_number)) break;
                temp_check = temp_check->next;
            }

            if (temp_check == NULL){
                printf("==The class number is not exist yet! Please check your class number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
                printf("==Target class number:");
                fgets(temp_class_number, 11, stdin);
                fflush(stdin);
                temp_check = headP->next;
                continue;
            } else if (temp_check->class_number == headP->next->class_number){
                is_head = true;
            } else{
                while (temp_check_ano->next->class_number != temp_check->class_number){
                    temp_check_ano = temp_check_ano->next;
                }
                break;
            }

        } else{
            printf("==You can only enter numbers! Please enter the target class number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
            printf("Target class number:");
            fgets(temp_class_number, 11, stdin);
            fflush(stdin);
        }
    }

    if (is_head == true){
        headP->next = temp_check->next;
        free(temp_check);
    } else{
        temp_check_ano->next = temp_check->next;
        free(temp_check);
    }

    return SUCCESS;
}




/**
 * @file class_service.c
 * @author @waterman263
 * @brief    add information of class
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */


enum OPERATE add_class(class_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    class_p tail_node = headP->next;
    class_p new_class = (class_p) malloc(sizeof(classes));

    while (tail_node->next != NULL) tail_node = tail_node->next;

    tail_node->next = new_class;

    char class_number[12];
    char *temp_class_number = class_number;

    printf("==Please enter the target class number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
    printf("==Target class number:");
    fgets(temp_class_number, 11, stdin);
    fflush(stdin);

    while (true){
        if (check_string(ACCOUNT, temp_class_number) == SUCCESS){
            if (atol(class_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            } else{
                new_class->class_number = atol(class_number);
                printf("==OK, the class has been set successfully.\n");
                break;
            }
        } else{
            printf("==You can only enter numbers! Please enter the  class number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
            printf("The class number:");
            fgets(temp_class_number, 11, stdin);
            fflush(stdin);
        }
    }

    char class_uid[24];
    char *temp_uid = class_uid;
    create_uid(temp_uid);

    int i = 0;
    while (*temp_uid != '\0'){
        new_class->uid[i++] = *temp_uid++;
    }
    new_class->uid[i] = '\0';

    printf("==Remember: you should add students to the class first.\n");
    printf("==Returning menu now...\n");

    return SUCCESS;
}

/**
 * @file class_service.c
 * @author @waterman263
 * @brief    change information of class
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */
enum OPERATE update_class(class_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    class_p temp_check = headP->next;

    char class_number[12];
    char *temp_class_number = class_number;

    printf("==Please enter the target class number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
    printf("==Target class number:");
    fgets(temp_class_number, 11, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, class_number) == SUCCESS){
            if (atol(class_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            }

            while (temp_check != NULL){
                if (temp_check->class_number == atol(class_number)) break;
                temp_check = temp_check->next;
            }

            if (temp_check == NULL){
                printf("==The class number is not exist yet! Please check your class number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
                printf("==Target class number:");
                fgets(temp_class_number, 11, stdin);
                fflush(stdin);
                temp_check = headP->next;
                continue;
            } else break;

        } else{
            printf("==You can only enter numbers! Please enter the target class number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
            printf("Target class number:");
            fgets(temp_class_number, 11, stdin);
            fflush(stdin);
        }
    }

    char new_class_number[12];
    char *temp_new_class_number = new_class_number;

    printf("==Please enter the new class number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
    printf("==New class number:");
    fgets(temp_class_number, 11, stdin);
    fflush(stdin);

    while (true){
        if (check_string(ACCOUNT, temp_new_class_number) == SUCCESS){
            if (atol(new_class_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            } else{
                temp_check->class_number = atol(new_class_number);
                printf("==OK, the class has been updated successfully.\n");
                printf("==That's alright. Returning menu now...\n");
                break;
            }
        } else{
            printf("==You can only enter numbers! Please enter the new class number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than class number.\n");
            printf("New class number:");
            fgets(temp_new_class_number, 11, stdin);
            fflush(stdin);
        }
    }

    return SUCCESS;
}
