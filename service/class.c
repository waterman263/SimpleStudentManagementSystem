/**
 * @file users.c
 * @author @waterman263
 * @brief    find information of class
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

enum OPERATE find_class(class_head_p headP,enum SELECT select){
    if(select == ONE) return find_class_one(headP);
    if(select == ALL) return find_class_all(headP);
    return SUCCESS;
}
enum OPERATE find_class_one(class_head_p headP){
    char class_number[20];
    char *accounts=class_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    class_p temp_check = headP->next;
    if(check_string(ACCOUNT, class_number) == SUCCESS && atoll(class_number) != 0){
        while(temp_check!=NULL){
            if(temp_check->class_number == atol(accounts)){
                printf("班级号：%ld  ",temp_check->class_number);
                printf("数学平均分：%p  ",temp_check->subject_aver[0][0]);
                printf("英语平均分：%p  ",temp_check->subject_aver[1][0]);
                printf("C语言平均分：%p  ",temp_check->subject_aver[2][0]);
                printf("物理平均分：%p  ",temp_check->subject_aver[3][0]);
                printf("python平均分：%p  ",temp_check->subject_aver[4][0]);
                printf("平均总分：%f  ",temp_check->general_aver);
                printf("平均绩点：%f\n",temp_check->general_gpa);
            }
            temp_check = temp_check->next;
        }
    }
    return  SUCCESS;
}
enum OPERATE find_class_all(class_head_p headP){
     class_p temp_check = headP->next;
    while(temp_check!=NULL){
        printf("班级号：%ld  ",temp_check->class_number);
        printf("数学平均分：%p  ",temp_check->subject_aver[0][0]);
        printf("英语平均分：%p  ",temp_check->subject_aver[1][0]);
        printf("C语言平均分：%p  ",temp_check->subject_aver[2][0]);
        printf("物理平均分：%p  ",temp_check->subject_aver[3][0]);
        printf("python平均分：%p  ",temp_check->subject_aver[4][0]);
        printf("平均总分：%f  ",temp_check->general_aver);
        printf("平均绩点：%f\n",temp_check->general_gpa);
        temp_check = temp_check->next;
    }
    return SUCCESS;
}


enum OPERATE delete_class(class_head_p headP){
    char class_number[20];
    char *accounts=class_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    class_p temp_check = headP->next;
    class_p temp_check_ano = headP->next;
    if(check_string(ACCOUNT, class_number) == SUCCESS && atoll(class_number) != 0){
        while(temp_check!=NULL){
            temp_check_ano = temp_check;
            if(temp_check ->class_number == atol(accounts)){
                temp_check_ano->next = temp_check->next;
            }
            temp_check ->next;
        }
    }
    return SUCCESS;
}


enum OPERATE add_class(class_head_p headP){
    char class_number[20];
    char *accounts=class_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    class_p temp_check = headP->next;
    if(check_string(ACCOUNT, class_number) == SUCCESS && atoll(accounts) != 0){
        while(temp_check != NULL){
            if(temp_check->class_number == atol(accounts)){
                printf("this student saved");
                break;
            }
            temp_check = temp_check->next;
        }
        if(temp_check == NULL){
            class_p new_class = (class_p)malloc(sizeof(class_p));
            printf("请输入班级号：");
            char class_number_add[20];
            char *accounts_number=class_number_add;
            fgets(accounts_number, 11, stdin);
            fflush(stdin);
            if(check_string(ACCOUNT, class_number_add) == SUCCESS && atoll(class_number_add) != 0) {
                scanf("%ld",&new_class->class_number);
            }
            printf("请输入辅导员号：");
            char class_counsellor_add[20];
            char *accounts_counsellor=class_counsellor_add;
            fgets(accounts_counsellor, 11, stdin);
            fflush(stdin);
            if(check_string(ACCOUNT, class_counsellor_add) == SUCCESS && atoll(class_counsellor_add) != 0) {
                scanf("%s",new_class->counsellor_uid);
            }
            printf("请输入总体平均分：");
            char class_score_avg_add[20];
            char *accounts_all_avg=class_score_avg_add;
            fgets(accounts_all_avg, 11, stdin);
            fflush(stdin);
            if(check_string(ACCOUNT, class_score_avg_add) == SUCCESS && atoll(class_score_avg_add) != 0) {
                scanf("%f",&new_class->general_aver);
            }
            printf("请输入总体平均绩点：");
            char class_gpa_avg_add[20];
            char *accounts_gpa_avg=class_gpa_avg_add;
            fgets(accounts_gpa_avg, 11, stdin);
            fflush(stdin);
            if(check_string(ACCOUNT, class_gpa_avg_add) == SUCCESS && atoll(class_gpa_avg_add) != 0) {
                scanf("%f",&new_class->general_gpa);
            }
        }
    }
    return SUCCESS;
}
enum OPERATE chg_class(class_head_p headP){
    char student_name[20];
    int choose;
    char *accounts=student_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    class_p temp_check = headP->next;
    if(check_string(ACCOUNT, student_name) == SUCCESS && atoll(student_name) != 0){
        while(temp_check!= NULL){
            if(temp_check->class_number == atol(accounts)){
                scanf("%d",&choose);
                switch(choose){
                    case 1:
                        printf("请输入修改的班级号：");
                        char class_number_chg[20];
                        char *accounts_number=class_number_chg;
                        fgets(accounts_number, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, class_number_chg) == SUCCESS && atoll(class_number_chg) != 0) {
                            scanf("%ld",&temp_check->class_number);
                        }
                        break;
                    case 2:
                        printf("请输入修改的平均绩点：");
                        char class_gpa_chg[20];
                        char *accounts_gpa=class_gpa_chg;
                        fgets(accounts_gpa, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, class_gpa_chg) == SUCCESS && atoll(class_gpa_chg) != 0) {
                            scanf("%f",&temp_check->general_gpa);
                        }
                        break;
                    case 3:
                        printf("请输入修改的平均分：");
                        char class_score_chg[20];
                        char *accounts_score=class_score_chg;
                        fgets(accounts_score, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, class_score_chg) == SUCCESS && atoll(class_score_chg) != 0) {
                            scanf("%f",&temp_check->general_aver);
                        }
                        break;
                    case 4:
                        printf("请输入修改的辅导员信息：");
                        char class_counsellor_chg[20];
                        char *accounts_counsellor=class_counsellor_chg;
                        fgets(accounts_counsellor, 11, stdin);
                        fflush(stdin);
                        if(check_string(ACCOUNT, class_counsellor_chg) == SUCCESS && atoll(class_counsellor_chg) != 0) {
                            scanf("%s",temp_check->counsellor_uid);
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