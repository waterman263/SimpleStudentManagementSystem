/**
 * @file users.c
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

void input_chg_information(counsellor_head_p headP) {

    counsellor_p temp_check = headP->next;
    while (true) {
        printf("请输入修改后的姓名：");
        char counsellor_name_chg[20];
        char *accounts_name_chg = counsellor_name_chg;
        fgets(accounts_name_chg, 11, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, counsellor_name_chg) == SUCCESS && atoll(counsellor_name_chg) != 0) {
            strcpy(counsellor_name_chg, temp_check->name);
        } else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        printf("请输入修改后的工号：");
        char counsellor_work_number_chg[20];
        char *accounts_work_number_chg = counsellor_work_number_chg;
        fgets(accounts_work_number_chg, 20, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, counsellor_work_number_chg) == SUCCESS && atoll(counsellor_work_number_chg) != 0) {
            temp_check->work_number = atol(counsellor_work_number_chg);
        } else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        printf("请输入修改后的电话：");
        char counsellor_phone_number_chg[12];
        char *accounts_phone_number_chg = counsellor_phone_number_chg;
        fgets(accounts_phone_number_chg, 12, stdin);
        fflush(stdin);
        if (check_string(ACCOUNT, counsellor_phone_number_chg) == SUCCESS && atoll(counsellor_phone_number_chg) != 0) {
            strcpy(counsellor_phone_number_chg, temp_check->phone_number);
        } else {
            printf("Wrong input!");
            printf("Input against!");
            continue;
        }
        //   email 函数//

        //            //
        break;

    }
}


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
 */


enum OPERATE find_counsellor(counsellor_head_p headP, enum SELECT select){
    if(select == NAME) return find_counsellor_by_name(headP);
    if (select == WORK_NUMBER) return find_counsellor_by_work_number(headP);
    return SUCCESS;
}




/**
 * @file users.c
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
    char counsellor_name[20];
    char *accounts = counsellor_name;
    fgets(accounts, 20, stdin);
    fflush(stdin);
   counsellor_p temp_check = headP->next;
    if(check_string(ACCOUNT, counsellor_name) == SUCCESS ){
        while(temp_check != NULL){
            if(strcmp(temp_check->name,accounts)==0){
                printf("%s  \n",temp_check->name);
                printf("%ld  \n",temp_check->work_number);
                printf("%s  \n",temp_check->phone_number);
                printf("%s  \n",temp_check->email);
                break;
            }
            temp_check = temp_check->next;
        }
    }
    return SUCCESS;
}



/**
 * @file users.c
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
    char counsellor_number[20];
    char *accounts = counsellor_number;
    fgets(accounts, 20, stdin);
    fflush(stdin);
    counsellor_p temp_check = headP->next;
    if(check_string(ACCOUNT, counsellor_number) == SUCCESS && atoll(counsellor_number) != 0){
        while(temp_check != NULL){
            if(temp_check->work_number == atoll(accounts)){
                printf("%s  \n",temp_check->name);
                printf("%ld  \n",temp_check->work_number);
                printf("%s  \n",temp_check->phone_number);
                printf("%s  \n",temp_check->email);
                break;
            }
            temp_check = temp_check->next;
        }
    }
    return SUCCESS;
}



/**
 * @file users.c
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
* @file users.c
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
     char counsellor_name[20];
     char *accounts = counsellor_name;
     fgets(accounts, 20, stdin);
     fflush(stdin);
     counsellor_p temp_check = headP->next;
     counsellor_p temp_check_ano = headP->next;
     if (check_string(ACCOUNT, counsellor_name) == SUCCESS && atoll(counsellor_name) != 0) {
         while (temp_check != NULL) {
             temp_check_ano = temp_check;
             temp_check = temp_check->next;
             if (strcmp(temp_check->name, accounts) == 0) {
                 temp_check_ano->next = temp_check->next;
                 free(temp_check);
                 break;
             }
         }
     }
     return  SUCCESS;
 }




/**
* @file users.c
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
     char counsellor_work_number[20];
     char *accounts = counsellor_work_number;
     fgets(accounts, 20, stdin);
     fflush(stdin);
     counsellor_p temp_check = headP->next;
     counsellor_p temp_check_ano = headP->next;
     if (check_string(ACCOUNT, counsellor_work_number) == SUCCESS && atoll(counsellor_work_number) != 0) {
         while (temp_check != NULL) {
             temp_check_ano = temp_check;
             temp_check = temp_check->next;
             if (strcmp(temp_check->name, accounts) == 0) {
                 temp_check_ano->next = temp_check->next;
                 free(temp_check);
                 break;
             }
         }
     }
     return  SUCCESS;
 }




/**
* @file users.c
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
     char work_number[20];
     char *accounts = work_number;
     fgets(accounts, 20, stdin);
     fflush(stdin);
     counsellor_p temp_check = headP->next;
     if(check_string(ACCOUNT, work_number) == SUCCESS && atoll(accounts) != 0){
         while(temp_check != NULL){
             if(temp_check->work_number == atoll(accounts)){
                 printf("This student saved!");
                 break;
             }
             temp_check = temp_check->next;
         }
         if(temp_check == NULL){
             counsellor_p new_counsellor = (counsellor_p)malloc(sizeof(counsellor_p));
             while(true){
                 printf("请输入姓名：");
                 char counsellor_name_add[20];
                 char *accounts_name_add = counsellor_name_add;
                 fgets(accounts_name_add, 11, stdin);
                 fflush(stdin);
                 if(check_string(ACCOUNT, counsellor_name_add) == SUCCESS && atoll(counsellor_name_add) != 0) {
                    strcpy(counsellor_name_add,new_counsellor->name);
                 }
                 else{
                     printf("Wrong input!");
                     printf("Input against!");
                     continue;
                 }
                 printf("请输入工号：");
                 char counsellor_work_number_add[20];
                 char *accounts_work_number_add=counsellor_work_number_add;
                 fgets(accounts_work_number_add, 20, stdin);
                 fflush(stdin);
                 if(check_string(ACCOUNT, counsellor_work_number_add) == SUCCESS && atoll(counsellor_work_number_add) != 0) {
                     new_counsellor->work_number = atol(counsellor_work_number_add);
                 }
                 else{
                     printf("Wrong input!");
                     printf("Input against!");
                     continue;
                 }
                 printf("请输入电话：");
                 char counsellor_phone_number_add[12];
                 char *accounts_phone_number_add=counsellor_phone_number_add;
                 fgets(accounts_phone_number_add, 12, stdin);
                 fflush(stdin);
                 if(check_string(ACCOUNT, counsellor_phone_number_add) == SUCCESS && atoll(counsellor_phone_number_add) != 0) {
                     strcpy(counsellor_phone_number_add,new_counsellor->phone_number);
                  }
                 else{
                     printf("Wrong input!");
                     printf("Input against!");
                     continue;
                 }
                 //   email 函数//

                 //            //
                  break;
             }
         }
     }
     return SUCCESS;
 }



/**
* @file users.c
* @author @waterman263
* @brief    change information of counsellor
* @version 0.1
* @date 2021-05-17
*
*
* @copyright Copyright (c) 2021
*
*/

 enum OPERATE chg_counsellor(counsellor_head_p headP){
     char counsellor_work_number[20];
     char *accounts=counsellor_work_number;
     fgets(accounts, 11, stdin);
     fflush(stdin);
     counsellor_p temp_check = headP->next;
     if(check_string(ACCOUNT, counsellor_work_number) == SUCCESS && atoll(counsellor_work_number) != 0){
         while(temp_check!= NULL){
             if(temp_check->work_number == atol(accounts)){
                 input_chg_information(headP);
             }
         }
     }
     return SUCCESS;
 }

