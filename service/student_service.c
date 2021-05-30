/**
 * @file student_service.c
 * @author @waterman263
 * @brief implement student.h
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 *///
// Created by 86189 on 2021/5/17.
//
#include "serviceHead/student_service.h"

stu_head_p  initial_student_List(){
    stu_head_p head_point = (stu_head_p)malloc(sizeof(stu_head_p));
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
 * @file student_service.c
 * @author @waterman263
 * @brief    find information of student
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */


enum OPERATE find_student(stu_head_p headP , enum  SELECT select){
    if(select == NUMBER) return find_student_by_number(headP);
    if(select == NAME)   return find_student_by_name(headP);
    if(select == ALL)    return find_student_all(headP);
    return SUCCESS;
}


/**
 * @file student_service.c
 * @author @waterman263
 * @brief    find information of student by number
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */

enum OPERATE find_student_by_number(stu_head_p headP ){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char target_student_number[12];
    char *temp_target_student = target_student_number;

    student_p temp_check = headP ->next;

    printf("==Please enter the target student number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
    printf("==Target student number:");
    fgets(temp_target_student, 11, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, temp_target_student) == SUCCESS){
            if (atoll(target_student_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            }

            while(temp_check != NULL){
                if (temp_check->student_number == atoll(temp_target_student)) break;
                temp_check = temp_check ->next;
            }

            if (temp_check == NULL){
                printf("==The student number is not exist yet! Please check your student number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
                printf("==Target student number:");
                fgets(temp_target_student, 11, stdin);
                fflush(stdin);
                temp_check = headP->next;
            } else break;
        }
        else{
            printf("==You can only enter numbers! Please enter the target student number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
            printf("Target student number:");
            fgets(temp_target_student, 11, stdin);
            fflush(stdin);
        }
    }

    printf("姓名：%s  \n", temp_check->name);
    printf("邮箱：%s  \n", temp_check->email);
    printf("电话：%s  \n", temp_check->phone_number);
    printf("数学分数：%f  \n", temp_check->subject_score[ADVANCED_MATHEMATICS][0]);
    printf("英语分数：%f  \n", temp_check->subject_score[ENGLISH][0]);
    printf("C语言分数：%f  \n", temp_check->subject_score[C_PROGRAM_LANGUAGE][0]);
    printf("物理分数：%f  \n", temp_check->subject_score[PHYSICAL_EDUCATION][0]);
    printf("python分数：%f  \n", temp_check->subject_score[PYTHON][0]);
    printf("绩点：%f\n", temp_check->gpa);

    return SUCCESS;
}


/**
 * @file student_service.c
 * @author @waterman263
 * @brief    find information of student by name
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */


enum OPERATE find_student_by_name(stu_head_p headP ){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char target_student_name[22];
    char *temp_target_student = target_student_name;

    student_p temp_check = headP ->next;

    printf("==Please enter the target student name.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student name.\n");
    printf("==Target student name:");
    fgets(temp_target_student, 20, stdin);
    fflush(stdin);

    while (true){
        if (target_student_name[0] == '0'){
                printf("==Alright, returning menu...\n");
                return FAILED;
        }

        while(temp_check != NULL){
            if (strcmp(temp_target_student, temp_check->name) == 0) break;
            temp_check = temp_check ->next;
        }

        if (temp_check == NULL){
            printf("==The student is not exist yet! Please check your student name!\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student name.\n");
            printf("==Target student name:");
            fgets(temp_target_student, 20, stdin);
            fflush(stdin);
            temp_check = headP->next;
        } else break;
    }

    printf("姓名：%s  \n", temp_check->name);
    printf("邮箱：%s  \n", temp_check->email);
    printf("电话：%s  \n", temp_check->phone_number);
    printf("数学分数：%f  \n", temp_check->subject_score[ADVANCED_MATHEMATICS][0]);
    printf("英语分数：%f  \n", temp_check->subject_score[ENGLISH][0]);
    printf("C语言分数：%f  \n", temp_check->subject_score[C_PROGRAM_LANGUAGE][0]);
    printf("物理分数：%f  \n", temp_check->subject_score[PHYSICAL_EDUCATION][0]);
    printf("python分数：%f  \n", temp_check->subject_score[PYTHON][0]);
    printf("绩点：%f\n", temp_check->gpa);

    return SUCCESS;
}


/**
 * @file student_service.c
 * @author @waterman263
 * @brief    find information of  all student
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */

enum OPERATE find_student_all(stu_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    student_p temp_check = headP->next;

    while(temp_check != NULL) {
        printf("姓名：%s  \n", temp_check->name);
        printf("邮箱：%s  \n", temp_check->email);
        printf("电话：%s  \n", temp_check->phone_number);
        printf("数学分数：%f  \n", temp_check->subject_score[ADVANCED_MATHEMATICS][0]);
        printf("英语分数：%f  \n", temp_check->subject_score[ENGLISH][0]);
        printf("C语言分数：%f  \n", temp_check->subject_score[C_PROGRAM_LANGUAGE][0]);
        printf("物理分数：%f  \n", temp_check->subject_score[PHYSICAL_EDUCATION][0]);
        printf("python分数：%f  \n", temp_check->subject_score[PYTHON][0]);
        printf("绩点：%f\n", temp_check->gpa);
        temp_check = temp_check->next;
    }
    return SUCCESS;
}






    /**
 * @file student_service.c
 * @author @waterman263
 * @brief delete information of student
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */

enum OPERATE delete_student(stu_head_p headP, enum SELECT select){
    if(select == NUMBER)  return delete_student_by_number( headP);
    if(select == NAME)  return delete_student_by_name( headP);
    return SUCCESS;
}


/**
* @file users.c
* @author @waterman263
* @brief delete information of student by number
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/

enum OPERATE delete_student_by_number(stu_head_p headP ){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char student_number[12];
    char *temp_student_number = student_number;

    student_p target = headP->next;
    student_p pre_target = headP->next;

    printf("==Please enter the target student number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
    printf("==Target student number:");
    fgets(temp_student_number, 11, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, temp_student_number) == SUCCESS){
            if (atoll(student_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            }

            while(target != NULL){
                if (target->student_number == atoll(temp_student_number)) break;
                target = target ->next;
            }

            if (target == NULL){
                printf("==The student number is not exist yet! Please check your student number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
                printf("==Target student number:");
                fgets(temp_student_number, 11, stdin);
                fflush(stdin);
                target = headP->next;
            } else break;
        }
        else{
            printf("==You can only enter numbers! Please enter the target student number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
            printf("Target student number:");
            fgets(temp_student_number, 11, stdin);
            fflush(stdin);
        }
    }

    if (target->student_number == pre_target->student_number){
        headP->next = target->next;
    } else{
        while (pre_target->next->student_number != target->student_number){
            pre_target = pre_target->next;
        }
        pre_target->next = target->next;
    }
    free(target);

    return SUCCESS;
}



/**
* @file student_service.c
* @author @waterman263
* @brief delete information of student by name
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/
enum OPERATE delete_student_by_name(stu_head_p headP ){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char target_student_name[22];
    char *temp_target_student = target_student_name;

    student_p target = headP->next;
    student_p pre_target = headP->next;

    printf("==Please enter the target student name.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student name.\n");
    printf("==Target student name:");
    fgets(temp_target_student, 21, stdin);
    fflush(stdin);

    while (true){
        if (target_student_name[0] == '0'){
            printf("==Alright, returning menu...\n");
            return FAILED;
        }

        while(target != NULL){
            if (strcmp(temp_target_student, target->name) == 0) break;
            target = target ->next;
        }

        if (target == NULL){
            printf("==The student is not exist yet! Please check your student name!\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student name.\n");
            printf("==Target student name:");
            fgets(temp_target_student, 20, stdin);
            fflush(stdin);
            target = headP->next;
        } else break;
    }

    if (target->student_number == pre_target->student_number){
        headP->next = target->next;
    } else{
        while (pre_target->next->student_number != target->student_number){
            pre_target = pre_target->next;
        }
        pre_target->next = target->next;
    }
    free(target);

    return SUCCESS;
}



/**
* @file student_service.c
* @author @waterman263
* @brief add student information
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/
enum OPERATE add_student(stu_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    student_p end_student = headP->next;
    student_p new_student = (student_p) malloc(sizeof(student_p));
    if(end_student == NULL){
        end_student = new_student;
    }else{
        while (end_student->next != NULL){
            end_student = end_student->next;
        }

        end_student->next = new_student;
    }
    char uid[24];
    char *temp_uid = uid;

    create_uid(temp_uid);
    strcpy(new_student->uid, uid);

    //char class_uid[20];//

    char student_number[12];
    char *temp_student_number = student_number;
    printf("==Please enter the target student number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
    printf("==Target student number:");
    fgets(temp_student_number, 11, stdin);
    fflush(stdin);
    while (true){
        if (check_string(ACCOUNT, temp_student_number) == SUCCESS){
            if (atol(student_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            } else{
                new_student->  student_number = atol(student_number);
                printf("==OK, the student has been set successfully.\n");
                break;
            }
        } else{
            printf("==You can only enter numbers! Please enter the  student number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
            printf("The student number:");
            fgets(temp_student_number, 11, stdin);
            fflush(stdin);
        }
    }

    char student_name[22];
    char *temp_student_name = student_name;
    printf("==Please enter the target student name."
           "It has to be made of pure name and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student name.\n");
    printf("==Target student name:");
    fgets(temp_student_name, 21, stdin);
    fflush(stdin);
    strcpy(new_student->name , student_name);



    char email[33];
    char *temp_email = email;
    printf("==Please enter the target student email."
           "It has to be made of pure email and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student email.\n");
    printf("==Target student email:");
    fgets(temp_email, 32, stdin);
    fflush(stdin);

    while (true){
        if (check_string(EMAIL, temp_email) == SUCCESS){
                strcpy(new_student->email , email);
                printf("==OK, the student email has been set successfully.\n");
                break;
        } else{
            printf("==You can only enter email! Please enter the  student email again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student email.\n");
            printf("The student email:");
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
                strcpy(new_student->phone_number , phone_number);
                printf("==OK, the student has been set successfully.\n");
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

    new_student->HAS_SCORE_INPUT = FALSE_RES;


    return SUCCESS;
}

/**
* @file student_service.c
* @author @waterman263
* @brief change information of student
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/
enum OPERATE update_student(stu_head_p headP, enum SELECT select){
    if(select == NUMBER) return update_student_by_number(headP);
    if(select == NAME)   return update_student_by_name(headP);
    return SUCCESS;
}

/**
* @file student_service.c
* @author @waterman263
* @brief change information of student by name
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/
enum OPERATE update_student_by_name(stu_head_p headP){
    if (headP == NULL){
        printf("Fata Error: An unexpected error has been created, "
               "please save your work and exit the system.\n");
        return FAILED;
    }

    char student_name[22];
    char *target_student_name = student_name;

    student_p temp_check = headP->next;

    printf("==Please enter the target student name.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student name.\n");
    printf("==Target student name:");
    fgets(target_student_name, 21, stdin);
    fflush(stdin);

    while (true){
        if (target_student_name[0] == '0'){
            printf("==Alright, returning menu...\n");
            return FAILED;
        }

        while(temp_check != NULL){
            if (strcmp(student_name, temp_check->name) == 0) break;
            temp_check = temp_check ->next;
        }

        if (temp_check == NULL){
            printf("==The student is not exist yet! Please check your student name!\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student name.\n");
            printf("==Target student name:");
            fgets(target_student_name, 21, stdin);
            fflush(stdin);
            temp_check = headP->next;
        } else break;
    }
    printf("==Please enter the target student name."
           "It has to be made of pure name and the maxsize is 20.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student name.\n");
    printf("==Target student name:");
    fgets(target_student_name, 21, stdin);
    fflush(stdin);

    while (true){
        if (check_string(ACCOUNT, target_student_name) == SUCCESS){
            strcpy(temp_check->name , target_student_name);
            printf("==OK, the student name has been set successfully.\n");
            break;
        }
        else{
            printf("==You can only enter name! Please enter the  student name again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student name.\n");
            printf("The student name:");
            fgets(target_student_name, 21, stdin);
            fflush(stdin);
        }
    }

    return SUCCESS;
}

/**
* @file student_service.c
* @author @waterman263
* @brief change information of student by number
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/
enum OPERATE update_student_by_number(stu_head_p headP){
    char student_number[12];
    char *temp_student_number = student_number;

    student_p target = headP->next;

    printf("==Please enter the target student number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
    printf("==Target student number:");
    fgets(temp_student_number, 11, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, temp_student_number) == SUCCESS){
            if (atoll(student_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            }

            while(target != NULL){
                if (target->student_number == atoll(temp_student_number)) break;
                target = target ->next;
            }

            if (target == NULL){
                printf("==The student number is not exist yet! Please check your student number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
                printf("==Target student number:");
                fgets(temp_student_number, 11, stdin);
                fflush(stdin);
                target = headP->next;
            } else break;
        }
        else{
            printf("==You can only enter numbers! Please enter the target student number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
            printf("Target student number:");
            fgets(temp_student_number, 11, stdin);
            fflush(stdin);
        }
    }

    printf("==Please enter the target student number."
           "It has to be made of pure numbers and the maxsize is 10.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
    printf("==Target student number:");
    fgets(temp_student_number, 11, stdin);
    fflush(stdin);
    while (true){
        if (check_string(ACCOUNT, temp_student_number) == SUCCESS){
            if (atol(student_number) == 0){
                printf("==Alright, returning menu...\n");
                return FAILED;
            } else{
                target->student_number = atol(student_number);
                printf("==OK, the student has been set successfully.\n");
                break;
            }
        } else{
            printf("==You can only enter numbers! Please enter the  student number again.\n");
            printf("==If you want to cancel the operate, just enter 0 rather than student number.\n");
            printf("The student number:");
            fgets(temp_student_number, 11, stdin);
            fflush(stdin);
        }
    }

    return SUCCESS;
}
