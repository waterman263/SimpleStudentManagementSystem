/**
 * @file users.c
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



void  input_information(stu_head_p headP, char accounts) {

    student_p temp_check = headP->next;
    while (strcmp(temp_check->name, &accounts) == 0) {
        printf("请输入要修改的姓名：");
        char student_name_chg[12];
        char *accounts_name = student_name_chg;
        fgets(accounts_name, 11, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, student_name_chg) == SUCCESS) {
            strcpy(student_name_chg, temp_check->name);
        } else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        printf("请输入要修改的电话：");
        char student_phone_number_chg[12];
        char *accounts_phone_number = student_phone_number_chg;
        fgets(accounts_phone_number, 12, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, student_phone_number_chg) == SUCCESS && atoll(student_phone_number_chg) != 0) {
            strcpy(student_phone_number_chg, temp_check->phone_number);
        } else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        printf("请输入要修改的学号：");
        char student_number_chg[20];
        char *accounts_student_number = student_number_chg;
        fgets(accounts_student_number, 20, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, student_number_chg) == SUCCESS && atoll(student_number_chg) != 0) {
            temp_check->student_number = atoll(student_number_chg);
        }
        else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        printf("请输入要修改的高数成绩：");
        char student_math_chg[8];
        char *accounts_math = student_math_chg;
        fgets(accounts_math, 8, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, student_math_chg) == SUCCESS) {
            temp_check->subject_score[ADVANCED_MATHEMATICS][0] = atof(student_math_chg);
        } else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        printf("请输入要修改的英语成绩：");
        char student_english_chg[8];
        char *accounts_english = student_english_chg;
        fgets(accounts_english, 8, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, student_english_chg) == SUCCESS) {
            temp_check->subject_score[ENGLISH][0] = atof(student_english_chg);
        }
        else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        printf("请输入要修改的C语言成绩：");
        char student_c_chg[8];
        char *accounts_c = student_c_chg;
        fgets(accounts_c, 8, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, student_c_chg) == SUCCESS) {
            temp_check->subject_score[C_PROGRAM_LANGUAGE][0] = atof(student_c_chg);
        } else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        printf("请输入要修改的物理成绩：");
        char student_physics_chg[20];
        char *accounts_physics = student_physics_chg;
        fgets(accounts_physics, 11, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, student_physics_chg) == SUCCESS) {
            temp_check->subject_score[PHYSICAL_EDUCATION][0] = atof(student_physics_chg);
        }
        else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        printf("请输入要修改的python成绩：");
        char student_python_chg[20];
        char *accounts_python = student_python_chg;
        fgets(accounts_python, 11, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, student_python_chg) == SUCCESS && atoll(student_python_chg) != 0) {
            temp_check->subject_score[PYTHON][0] = atof(student_python_chg);
        }
        else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
    }
}
stu_head_p  initial_student_List(stu_head_p headP){
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
 * @file users.c
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
 * @file users.c
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
    char student_number[20];
    char *accounts = student_number;
    fgets(accounts, 20, stdin);
    fflush(stdin);
    student_p temp_check = headP ->next;
    if(check_string(ACCOUNT, accounts) == SUCCESS && atoll(student_number) != 0){
        while(temp_check != NULL){
            if(temp_check -> student_number == atoll(accounts)==0){
                printf("姓名：%s  \n", temp_check->name);
                printf("邮箱：%s  \n", temp_check->email);
                printf("电话：%s  \n", temp_check->phone_number);
                printf("数学分数：%f  \n", temp_check->subject_score[ADVANCED_MATHEMATICS][0]);
                printf("英语分数：%f  \n", temp_check->subject_score[ENGLISH][0]);
                printf("C语言分数：%f  \n", temp_check->subject_score[C_PROGRAM_LANGUAGE][0]);
                printf("物理分数：%f  \n", temp_check->subject_score[PHYSICAL_EDUCATION][0]);
                printf("python分数：%f  \n", temp_check->subject_score[PYTHON][0]);
                printf("绩点：%f\n", temp_check->gpa);
                break;
            }
            temp_check = temp_check ->next;
            }
        }
    else{
        return find_student_by_number(headP);
    }
    return SUCCESS;
    }


/**
 * @file users.c
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
    char student_name[12];
    char *accounts = student_name;
    fgets(accounts, 12, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    if(check_string(ACCOUNT, accounts) == SUCCESS ){
        while(temp_check != NULL){
            if(strcmp(temp_check -> name , accounts)){
                printf("姓名：%s  \n", temp_check->name);
                printf("邮箱：%s  \n", temp_check->email);
                printf("电话：%s  \n", temp_check->phone_number);
                printf("数学分数：%f  \n", temp_check->subject_score[ADVANCED_MATHEMATICS][0]);
                printf("英语分数：%f  \n", temp_check->subject_score[ENGLISH][0]);
                printf("C语言分数：%f  \n", temp_check->subject_score[C_PROGRAM_LANGUAGE][0]);
                printf("物理分数：%f  \n", temp_check->subject_score[PHYSICAL_EDUCATION][0]);
                printf("python分数：%f  \n", temp_check->subject_score[PYTHON][0]);
                printf("绩点：%f\n", temp_check->gpa);
                break;
            }
            temp_check = temp_check ->next;
        }
    }
    else{
        return find_student_by_name(headP);
    }
    return SUCCESS;
    }


/**
 * @file users.c
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
 * @file users.c
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
    char student_number[20];
    char *accounts = student_number;
    fgets(accounts, 20, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    student_p temp_check_ano = headP->next;
    if(check_string(ACCOUNT, accounts) == SUCCESS && atoll(student_number) != 0){
        while(temp_check != NULL){
            temp_check = temp_check_ano;
            temp_check = temp_check -> next;
            if(temp_check->student_number == atoll(accounts) ){
                temp_check_ano->next = temp_check->next;
                free(temp_check);
                break;
            }
        }
    }
    else{
        return delete_student_by_number(headP);
    }
    return SUCCESS;
}



/**
* @file users.c
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
    char student_name[20];
    char *accounts = student_name;
    fgets(accounts, 20, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    student_p temp_check_ano = headP->next;
    if(check_string(ACCOUNT, accounts) == SUCCESS ){
        while(temp_check != NULL){
            temp_check_ano = temp_check;
            temp_check = temp_check->next;
            if(strcmp(temp_check->name, accounts) == 0){
                temp_check_ano->next = temp_check->next;
                free(temp_check);
                break;
            }
        }
    }
    else{
        return delete_student_by_name(headP);
    }
    return SUCCESS;
}



/**
* @file users.c
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
    char student_number[20];
    char *accounts = student_number;
    fgets(accounts, 20, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    if(check_string(ACCOUNT, accounts) == SUCCESS && atoll(student_number) != 0){
    while(temp_check != NULL){
        if(temp_check->student_number == atoll(accounts)){
            printf("This student saved!");
            break;
    }
        temp_check = temp_check->next;
    }
    while(temp_check == NULL){
        student_p new_student = (student_p)malloc(sizeof(student_p));
        printf("请输入姓名：");
        char student_name_save[12];
        char *accounts_name=student_name_save;
        fgets(accounts_name, 12, stdin);
        fflush(stdin);
        while(true) {
            if (check_string(ACCOUNT, student_name_save) == SUCCESS) {
                strcpy(student_name_save, new_student->name);
            } else {
                printf("Wrong input!");
                printf("Input against!");
                continue;
            }
            printf("请输入学号：");
            char student_number_save[20];
            char *accounts_number = student_number_save;
            fgets(accounts_number, 20, stdin);
            fflush(stdin);
            if (check_string(ACCOUNT, student_number_save) == SUCCESS && atoll(student_number_save) != 0) {
                new_student->student_number = atoll(student_number_save);
            } else {
                printf("Wrong input!");
                printf("Input against!");
                continue;
            }
            //email 的函数//
            scanf("%s", new_student->email);
            //           //
            printf("请输入电话号码：");
            char student_phone_number_save[12];
            char *accounts_phone_number = student_phone_number_save;
            fgets(accounts_phone_number, 12, stdin);
            fflush(stdin);
            if (check_string(ACCOUNT, student_phone_number_save) == SUCCESS) {
                strcmp(new_student->phone_number, student_phone_number_save);
            } else {
                printf("Wrong input!");
                printf("Input against!");
                continue;
            }
            printf("请输入高数成绩：");
            char student_math_save[8];
            char *accounts_math = student_math_save;
            fgets(accounts_math, 8, stdin);
            fflush(stdin);
            if (check_string(ACCOUNT, student_math_save) == SUCCESS) {
                new_student->subject_score[ADVANCED_MATHEMATICS][0] = atof(student_math_save);
            } else {
                printf("Wrong input!");
                printf("Input against!");
                continue;
            }
            printf("请输入英语成绩：");
            char student_english_save[8];
            char *accounts_english = student_english_save;
            fgets(accounts_english, 8, stdin);
            fflush(stdin);
            if (check_string(ACCOUNT, student_english_save) == SUCCESS) {
                new_student->subject_score[ENGLISH][0] = atof(student_english_save);
            } else {
                printf("Wrong input!");
                printf("Input against!");
                continue;
            }
            printf("请输入C语言成绩：");
            char student_c_save[20];
            char *accounts_c = student_c_save;
            fgets(accounts_c, 11, stdin);
            fflush(stdin);
            if (check_string(ACCOUNT, student_c_save) == SUCCESS) {
                new_student->subject_score[C_PROGRAM_LANGUAGE][0] = atof(student_english_save);
            } else {
                printf("Wrong input!");
                printf("Input against!");
                continue;
            }
            printf("请输入物理成绩：");
            char student_physics_save[20];
            char *accounts_physics = student_physics_save;
            fgets(accounts_physics, 11, stdin);
            fflush(stdin);
            if (check_string(ACCOUNT, student_physics_save) == SUCCESS) {
                new_student->subject_score[PHYSICAL_EDUCATION][0] = atof(student_physics_save);
            } else {
                printf("Wrong input!");
                printf("Input against!");
                continue;
            }
            printf("请输入python成绩：");
            char student_python_save[20];
            char *accounts_python = student_python_save;
            fgets(accounts_python, 11, stdin);
            fflush(stdin);
            if (check_string(ACCOUNT, student_python_save) == SUCCESS) {
                new_student->subject_score[PYTHON][0] = atof(student_python_save);
            } else {
                printf("Wrong input!");
                printf("Input against!");
                continue;
            }
            break;
        }
    }
}
    return SUCCESS;
}





/**
* @file users.c
* @author @waterman263
* @brief change information of student
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/
enum OPERATE chg_student(stu_head_p headP,enum SELECT select){
    if(select == NUMBER) return chg_student_by_number(headP);
    if(select == NAME)   return chg_student_by_name(headP);
    return SUCCESS;
}



/**
* @file users.c
* @author @waterman263
* @brief change information of student by name
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/
enum OPERATE chg_student_by_name(stu_head_p headP){
    char student_name[12];
    char *accounts = student_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    if(check_string(ACCOUNT, accounts) == SUCCESS ){
        while(temp_check != NULL){
            input_information(headP,*accounts);
            temp_check = temp_check->next;
        }
    }
    else{
        return chg_student_by_name(headP);
    }

    return SUCCESS;
}




/**
* @file users.c
* @author @waterman263
* @brief change information of student by number
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/
enum OPERATE chg_student_by_number(stu_head_p headP){
    char student_number[20];
    char *accounts=student_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    if(check_string(ACCOUNT, student_number) == SUCCESS && atoll(student_number) != 0){
        while(temp_check!= NULL){
            input_information(headP,*accounts);
            temp_check = temp_check->next;
        }
    }
    return SUCCESS;
}



