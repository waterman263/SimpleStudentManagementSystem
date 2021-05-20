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
enum OPERATE open_file(enum FILE_TYPE file_type, void *struct_pointer) {
    char *path;
    if (file_type == USERS_DATA) {
        path = USER_DATA;
    }
    return SUCCESS;
}


enum OPERATE find_student(stu_head_p headP , enum  SELECT select){
    if(select == NUMBER) return find_student_by_number(headP);
    if(select == NAME)   return find_student_by_name(headP);
    if(select == ALL)    return find_student_all(headP);
    return SUCCESS;
}




enum OPERATE find_student_by_number(stu_head_p headP ){
    char student_number[20];
    char *accounts=student_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP ->next;
    if(check_string(ACCOUNT, student_number) == SUCCESS && atoll(student_number) != 0){
        while(temp_check != NULL){
            if(temp_check -> student_number == atol(accounts)==0){
                printf("姓名：%s  ", temp_check->name);
                printf("邮箱：%s  ", temp_check->email);
                printf("电话：%s  ", temp_check->phone_number);
                printf("数学分数：%f  ", temp_check->subject_score[0][0]);
                printf("英语分数：%f  ", temp_check->subject_score[1][0]);
                printf("C语言分数：%f  ", temp_check->subject_score[2][0]);
                printf("物理分数：%f  ", temp_check->subject_score[3][0]);
                printf("python分数：%f  ", temp_check->subject_score[4][0]);
                printf("绩点：%f\n", temp_check->gpa);
            }
            temp_check = temp_check ->next;
            }
        }
    return SUCCESS;
    }





enum OPERATE find_student_by_name(stu_head_p headP ){
    char student_name[20];
    char *accounts=student_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    if(check_string(ACCOUNT, student_name) == SUCCESS && atoll(student_name) != 0){
        while(temp_check != NULL){
            if(strcmp(temp_check -> name , accounts)){
                printf("姓名：%s  ", temp_check->name);
                printf("邮箱：%s  ", temp_check->email);
                printf("电话：%s  ", temp_check->phone_number);
                printf("数学分数：%f  ", temp_check->subject_score[0][0]);
                printf("英语分数：%f  ", temp_check->subject_score[1][0]);
                printf("C语言分数：%f  ", temp_check->subject_score[2][0]);
                printf("物理分数：%f  ", temp_check->subject_score[3][0]);
                printf("python分数：%f  ", temp_check->subject_score[4][0]);
                printf("绩点：%f\n", temp_check->gpa);
            }
            temp_check = temp_check ->next;
        }
        }
    return SUCCESS;
    }




enum OPERATE find_student_all(stu_head_p headP){
    student_p temp_check = headP->next;
    while(temp_check != NULL) {

        printf("姓名：%s  ", temp_check->name);
        printf("邮箱：%s  ", temp_check->email);
        printf("电话：%s  ", temp_check->phone_number);
        printf("数学分数：%f  ", temp_check->subject_score[0][0]);
        printf("英语分数：%f  ", temp_check->subject_score[1][0]);
        printf("C语言分数：%f  ", temp_check->subject_score[2][0]);
        printf("物理分数：%f  ", temp_check->subject_score[3][0]);
        printf("python分数：%f  ", temp_check->subject_score[4][0]);
        printf("绩点：%f\n", temp_check->gpa);
        temp_check = temp_check->next;
    }
    return SUCCESS;
}






    /**
 * @file users.c
 * @author @waterman263
 * @brief delete information
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

enum OPERATE delete_student_by_number(stu_head_p headP ){
    char student_number[20];
    char *accounts=student_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    student_p temp_check_ano = headP->next;
    if(check_string(ACCOUNT, student_number) == SUCCESS && atoll(student_number) != 0){
        while(temp_check != NULL){
            temp_check = temp_check_ano;
            if(temp_check->student_number == atol(accounts) ){
                temp_check_ano->next = temp_check->next;
            }
            temp_check -> next;
    }
    }
    return SUCCESS;
}

enum OPERATE delete_student_by_name(stu_head_p headP ){
    char student_name[20];
    char *accounts=student_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    student_p temp_check_ano = headP->next;
    if(check_string(ACCOUNT, student_name) == SUCCESS && atoll(student_name) != 0){
        while(temp_check!=NULL){
            temp_check = temp_check_ano;
            if(strcmp(temp_check->name, accounts) == 0){
                temp_check_ano->next = temp_check->next;
            }
            temp_check->next;
    }
    }
    return SUCCESS;
}

enum OPERATE add_student(stu_head_p headP){
    char student_number[20];
    char *accounts=student_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    if(check_string(ACCOUNT, student_number) == SUCCESS && atoll(student_number) != 0){
    while(temp_check != NULL){
        if(temp_check->student_number == atol(accounts)){
            printf("this student saved");
            break;
    }
        temp_check = temp_check->next;
    }
    if(temp_check == NULL){
        student_p new_student = (student_p)malloc(sizeof(student_p));
        printf("请输入姓名：");
        char student_name_save[20];
        char *accounts_name=student_name_save;
        fgets(accounts_name, 11, stdin);
        fflush(stdin);
        if(check_string(ACCOUNT, student_name_save) == SUCCESS && atoll(student_name_save) != 0) {
            strcpy(student_name_save,new_student->name);
        }
        printf("请输入学号：");
        char student_number_save[20];
        char *accounts_number=student_number_save;
        fgets(accounts_number, 11, stdin);
        fflush(stdin);
        if(check_string(ACCOUNT, student_number_save) == SUCCESS && atoll(student_number_save) != 0) {
            scanf("%lld",&new_student->student_number);
        }
        //email 的函数//
        scanf("%s", new_student->email);
        //           //
        printf("请输入电话号码：");
        char student_phone_number_save[20];
        char *accounts_phone_number=student_phone_number_save;
        fgets(accounts_phone_number, 11, stdin);
        fflush(stdin);
        if(check_string(ACCOUNT, student_phone_number_save) == SUCCESS && atoll(student_phone_number_save) != 0) {
            strcpy(student_phone_number_save,new_student->phone_number);
        }
        printf("请输入绩点：");
        char student_gpa_save[20];
        char *accounts_gpa=student_gpa_save;
        fgets(accounts_gpa, 11, stdin);
        fflush(stdin);
        if(check_string(ACCOUNT, student_gpa_save) == SUCCESS && atoll(student_gpa_save) != 0) {
            scanf("%f",&new_student->gpa);
        }
        printf("请输入高数成绩：");
        char student_math_chg[20];
        char *accounts_math=student_math_chg;
        fgets(accounts_math, 11, stdin);
        fflush(stdin);
        if(check_string(ACCOUNT, student_math_chg) == SUCCESS && atoll(student_math_chg) != 0) {
            scanf("%f",&new_student->subject_score[0][0]);
        }
        printf("请输入英语成绩：");
        char student_english_chg[20];
        char *accounts_english=student_english_chg;
        fgets(accounts_english, 11, stdin);
        fflush(stdin);
        if(check_string(ACCOUNT, student_english_chg) == SUCCESS && atoll(student_english_chg) != 0) {
            scanf("%f",&new_student->subject_score[1][0]);
        }
        printf("请输入C语言成绩：");
        char student_c_chg[20];
        char *accounts_c=student_c_chg;
        fgets(accounts_c   , 11, stdin);
        fflush(stdin);
        if(check_string(ACCOUNT, student_c_chg) == SUCCESS && atoll(student_c_chg) != 0) {
            scanf("%f",&new_student->subject_score[2][0]);
        }
        printf("请输入物理成绩：");
        char student_physics_chg[20];
        char *accounts_physics=student_physics_chg;
        fgets(accounts_physics, 11, stdin);
        fflush(stdin);
        if(check_string(ACCOUNT, student_physics_chg) == SUCCESS && atoll(student_physics_chg) != 0) {
            scanf("%f",&new_student->subject_score[3][0]);
        }
        printf("请输入python成绩：");
        char student_python_chg[20];
        char *accounts_python=student_python_chg;
        fgets(accounts_python, 11, stdin);
        fflush(stdin);
        if(check_string(ACCOUNT, student_python_chg) == SUCCESS && atoll(student_python_chg) != 0) {
            scanf("%f",&new_student->subject_score[4][0]);
        }
    }
}
    return SUCCESS;
}

enum OPERATE chg_student(stu_head_p headP,enum SELECT select){
    if(select == NUMBER) return chg_student_by_number(headP,select);
    if(select == NAME)   return chg_student_by_name(headP, select);
    return SUCCESS;
}


enum OPERATE chg_student_by_name(stu_head_p headP,enum SELECT select){
    char student_name[20];
    int choose;
    char *accounts=student_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    if(check_string(ACCOUNT, student_name) == SUCCESS && atoll(student_name) != 0){
        while(temp_check!= NULL){
            if(strcmp(temp_check->name,accounts)== 0){
                scanf("%d",&choose);
                switch(choose){
                    case 1:
                        printf("请输入要修改的姓名：");
                        char student_name_chg[20];
                        char *accounts_name=student_name_chg;
                        fgets(accounts_name, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_name_chg) == SUCCESS && atoll(student_name_chg) != 0) {
                            char student_temp[20];
                            scanf("%s",student_temp);
                            strcpy(student_temp,temp_check->name);
                        }
                        break;
                    case 2:
                        printf("请输入要修改的电话：");
                        char student_phone_number_chg[20];
                        char *accounts_phone_number=student_phone_number_chg;
                        fgets(accounts_phone_number, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_phone_number_chg) == SUCCESS && atoll(student_phone_number_chg) != 0) {
                            char student_temp[12];
                            strcpy(student_temp,temp_check->phone_number);
                        }
                        break;
                    case 3:
                        printf("请输入要修改的学号：");
                        char student_number_chg[20];
                        char *accounts_student_number=student_number_chg;
                        fgets(accounts_student_number, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_number_chg) == SUCCESS && atoll(student_number_chg) != 0) {
                            scanf("%lld",&temp_check->student_number);
                        }
                        break;
                    case 4:
                        printf("请输入要修改的绩点：");
                        char student_gpa_chg[20];
                        char *accounts_gpa=student_gpa_chg;
                        fgets(accounts_gpa, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_gpa_chg) == SUCCESS && atoll(student_gpa_chg) != 0) {
                            scanf("%f",&temp_check->gpa);
                        }
                        break;
                    case 5:
                        printf("请输入要修改的高数成绩：");
                        char student_math_chg[20];
                        char *accounts_math=student_math_chg;
                        fgets(accounts_math, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_math_chg) == SUCCESS && atoll(student_math_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[0][0]);
                        }
                        printf("请输入要修改的英语成绩：");
                        char student_english_chg[20];
                        char *accounts_english=student_english_chg;
                        fgets(accounts_english, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_english_chg) == SUCCESS && atoll(student_english_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[1][0]);
                        }
                        printf("请输入要修改的C语言成绩：");
                        char student_c_chg[20];
                        char *accounts_c=student_c_chg;
                        fgets(accounts_c   , 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_c_chg) == SUCCESS && atoll(student_c_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[2][0]);
                        }
                        printf("请输入要修改的物理成绩：");
                        char student_physics_chg[20];
                        char *accounts_physics=student_physics_chg;
                        fgets(accounts_physics, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_physics_chg) == SUCCESS && atoll(student_physics_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[3][0]);
                        }
                        printf("请输入要修改的python成绩：");
                        char student_python_chg[20];
                        char *accounts_python=student_python_chg;
                        fgets(accounts_python, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_python_chg) == SUCCESS && atoll(student_python_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[4][0]);
                        }
                        break;
                    default :
                        printf("请输入正确的选项\n");
                        break;
                }
            }
        }
    }
    return SUCCESS;
}
enum OPERATE chg_student_by_number(stu_head_p headP,enum SELECT select){
    char student_number[20];
    int choose;
    char *accounts=student_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP->next;
    if(check_string(ACCOUNT, student_number) == SUCCESS && atoll(student_number) != 0){
        while(temp_check!= NULL){
            if(temp_check->student_number == atoll(accounts)){
                scanf("%d",&choose);
                switch(choose){
                    case 1:
                        printf("请输入要修改的姓名：");
                        char student_name_chg[20];
                        char *accounts_name=student_name_chg;
                        fgets(accounts_name, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_name_chg) == SUCCESS && atoll(student_name_chg) != 0) {
                            char student_temp[20];
                            scanf("%s",student_temp);
                            strcpy(student_temp,temp_check->name);
                        }
                        break;
                    case 2:
                        printf("请输入要修改的电话：");
                        char student_phone_number_chg[20];
                        char *accounts_phone_number=student_phone_number_chg;
                        fgets(accounts_phone_number, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_phone_number_chg) == SUCCESS && atoll(student_phone_number_chg) != 0) {
                            char student_temp[12];
                            strcpy(student_temp,temp_check->phone_number);
                        }
                        break;
                    case 3:
                        printf("请输入要修改的学号：");
                        char student_number_chg[20];
                        char *accounts_student_number=student_number_chg;
                        fgets(accounts_student_number, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_number_chg) == SUCCESS && atoll(student_number_chg) != 0) {
                            scanf("%lld",&temp_check->student_number);
                        }
                        break;
                    case 4:
                        printf("请输入要修改的绩点：");
                        char student_gpa_chg[20];
                        char *accounts_gpa=student_gpa_chg;
                        fgets(accounts_gpa, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_gpa_chg) == SUCCESS && atoll(student_gpa_chg) != 0) {
                            scanf("%f",&temp_check->gpa);
                        }
                        break;
                    case 5:
                        printf("请输入要修改的高数成绩：");
                        char student_math_chg[20];
                        char *accounts_math=student_math_chg;
                        fgets(accounts_math, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_math_chg) == SUCCESS && atoll(student_math_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[0][0]);
                        }
                        printf("请输入要修改的英语成绩：");
                        char student_english_chg[20];
                        char *accounts_english=student_english_chg;
                        fgets(accounts_english, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_english_chg) == SUCCESS && atoll(student_english_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[1][0]);
                        }
                        printf("请输入要修改的C语言成绩：");
                        char student_c_chg[20];
                        char *accounts_c=student_c_chg;
                        fgets(accounts_c   , 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_c_chg) == SUCCESS && atoll(student_c_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[2][0]);
                        }
                        printf("请输入要修改的物理成绩：");
                        char student_physics_chg[20];
                        char *accounts_physics=student_physics_chg;
                        fgets(accounts_physics, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_physics_chg) == SUCCESS && atoll(student_physics_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[3][0]);
                        }
                        printf("请输入要修改的python成绩：");
                        char student_python_chg[20];
                        char *accounts_python=student_python_chg;
                        fgets(accounts_python, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, student_python_chg) == SUCCESS && atoll(student_python_chg) != 0) {
                            scanf("%f",&temp_check->subject_score[4][0]);
                        }
                        break;
                    default :
                        printf("请输入正确的选项\n");
                        break;
                }
            }
        }
    }
    return SUCCESS;
}



