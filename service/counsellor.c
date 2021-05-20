/**
 * @file users.c
 * @author @waterman263
 * @brief    find information of counsellor
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
 counsellor_head_p initial_class_List(){
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


enum OPERATE find_counsellor(counsellor_head_p headP, enum SELECT select){
    if(select == NAME) return find_counsellor_by_name(headP);
    if (select == WORK_NUMBER) return find_counsellor_by_work_number(headP);
    return SUCCESS;
}

enum OPERATE find_counsellor_by_name(counsellor_head_p headP){
    char counsellor_name[20];
    char *accounts = counsellor_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
   counsellor_p temp_check = headP->next;
    if(check_string(ACCOUNT, counsellor_name) == SUCCESS && atoll(counsellor_name) != 0){
        while(temp_check!=NULL){
            if(strcmp(temp_check->name,accounts)==0){
                printf("%s",temp_check->name);
                printf("%ld",temp_check->work_number);
                printf("%s",temp_check->phone_number);
                printf("%s",temp_check->email);
            }
            temp_check = temp_check->next;
        }
    }
    return SUCCESS;
}

enum OPERATE find_counsellor_by_work_number(counsellor_head_p headP){
    char counsellor_number[20];
    char *accounts=counsellor_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    counsellor_p temp_check = headP->next;
    if(check_string(ACCOUNT, counsellor_number) == SUCCESS && atoll(counsellor_number) != 0){
        while(temp_check!=NULL){
            if(temp_check->work_number == atol(accounts)){
                printf("%s",temp_check->name);
                printf("%ld",temp_check->work_number);
                printf("%s",temp_check->phone_number);
                printf("%s",temp_check->email);
            }
            temp_check = temp_check->next;
        }
    }
    return SUCCESS;
}
enum OPERATE delete_counsellor(counsellor_head_p headP,enum SELECT select){
    if(select == NAME )  return delete_counsellor_by_name(headP);
    if(select == WORK_NUMBER)  return delete_counsellor_by_work_number(headP);
    return SUCCESS;
 }

 enum OPERATE delete_counsellor_by_name(counsellor_head_p headP) {
     char counsellor_name[20];
     char *accounts = counsellor_name;
     fgets(accounts, 11, stdin);
     fflush(stdin);
     counsellor_p temp_check = headP->next;
     counsellor_p temp_check_ano = headP->next;
     if (check_string(ACCOUNT, counsellor_name) == SUCCESS && atoll(counsellor_name) != 0) {
         while (temp_check != NULL) {
             temp_check_ano = temp_check;
             if (strcmp(temp_check->name, accounts) == 0) {
                 temp_check_ano->next = temp_check->next;
             }
             temp_check->next;
         }
     }
     return  SUCCESS;
 }



 enum OPERATE delete_counsellor_by_work_number(counsellor_head_p headP){
     char counsellor_work_number[20];
     char *accounts = counsellor_work_number;
     fgets(accounts, 11, stdin);
     fflush(stdin);
     counsellor_p temp_check = headP->next;
     counsellor_p temp_check_ano = headP->next;
     if (check_string(ACCOUNT, counsellor_work_number) == SUCCESS && atoll(counsellor_work_number) != 0) {
         while (temp_check != NULL) {
             temp_check_ano = temp_check;
             if (temp_check->work_number == atol(accounts) ) {
                 temp_check_ano->next = temp_check->next;
             }
             temp_check->next;
         }
     }
     return  SUCCESS;
 }


 enum OPERATE add_counsellor(counsellor_head_p headP){
     char work_number[20];
     char *accounts=work_number;
     fgets(accounts, 11, stdin);
     fflush(stdin);
     counsellor_p temp_check = headP->next;
     if(check_string(ACCOUNT, work_number) == SUCCESS && atoll(accounts) != 0){
         while(temp_check != NULL){
             if(temp_check->work_number == atol(accounts)){
                 printf("this student saved");
                 break;
             }
             temp_check = temp_check->next;
         }
         if(temp_check == NULL){
             counsellor_p new_counsellor = (counsellor_p)malloc(sizeof(counsellor_p));
             printf("请输入姓名：");
             char counsellor_name_add[20];
             char *accounts_name=counsellor_name_add;
             fgets(accounts_name, 11, stdin);
             fflush(stdin);
             if(check_string(ACCOUNT, counsellor_name_add) == SUCCESS && atoll(counsellor_name_add) != 0) {
                 scanf("%s",new_counsellor->name);
             }
             printf("请输入工号：");
             char counsellor_work_number_add[20];
             char *accounts_work_number=counsellor_work_number_add;
             fgets(accounts_work_number, 11, stdin);
             fflush(stdin);
             if(check_string(ACCOUNT, counsellor_work_number_add) == SUCCESS && atoll(counsellor_work_number_add) != 0) {
                 scanf("%ld",&new_counsellor->work_number);
             }
             printf("请输入电话：");
             char counsellor_phone_number_add[20];
             char *accounts_phone_number=counsellor_phone_number_add;
             fgets(accounts_phone_number, 11, stdin);
             fflush(stdin);
             if(check_string(ACCOUNT, counsellor_phone_number_add) == SUCCESS && atoll(counsellor_phone_number_add) != 0) {
                 scanf("%s",new_counsellor->phone_number);
             }
             //   email 函数//
             scanf("%s",new_counsellor->email);
             //            //
         }
     }
     return SUCCESS;
 }



 enum OPERATE chg_counsellor(counsellor_head_p headP){
     char counsellor_work_number[20];
     int choose;
     char *accounts=counsellor_work_number;
     fgets(accounts, 11, stdin);
     fflush(stdin);
     counsellor_p temp_check = headP->next;
     if(check_string(ACCOUNT, counsellor_work_number) == SUCCESS && atoll(counsellor_work_number) != 0){
         while(temp_check!= NULL){
             if(temp_check->work_number == atol(accounts)){
                 scanf("%d",&choose);
                 switch(choose){
                     case 1:
                         printf("请输入您要修改的名字：");
                         char counsellor_name_chg[20];
                         char *accounts_name=counsellor_name_chg;
                         fgets(accounts_name, 11, stdin);
                         fflush(stdin);
                         if(check_string(ACCOUNT, counsellor_name_chg) == SUCCESS && atoll(counsellor_name_chg) != 0) {
                             scanf("%s",temp_check->name);
                         }
                         break;
                     case 2:
                         printf("请输入您要修改的电话：");
                         char counsellor_phone_number_chg[20];
                         char *accounts_phone_number=counsellor_phone_number_chg;
                         fgets(accounts_phone_number, 11, stdin);
                         fflush(stdin);
                         if(check_string(ACCOUNT, counsellor_phone_number_chg) == SUCCESS && atoll(counsellor_phone_number_chg) != 0) {
                             scanf("%s",temp_check->phone_number);
                         }
                         break;
                     case 3:
                         printf("请输入您要修改的工号：");
                         char *accounts_work_number=counsellor_work_number;
                         fgets(accounts_work_number, 11, stdin);
                         fflush(stdin);
                             if(check_string(ACCOUNT, counsellor_work_number) == SUCCESS && atoll(counsellor_work_number) != 0) {
                             scanf("%ld",&temp_check->work_number);
                         }
                         break;
                     case 4:
                         printf("请输入您能想要修改的地址");
                         //email   函数//
                         scanf("%s",temp_check->email);
                         //          //
                     default :
                         printf("请输入正确的选项\n");
                         break;
                 }
             }
         }
     }
     return SUCCESS;
 }

