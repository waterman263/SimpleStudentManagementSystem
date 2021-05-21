/**
 * @file users.c
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
 * @file users.c
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
    char class_number[20];
    char *date = class_number;
    fgets(date, 21, stdin);
    fflush(stdin);
    class_p temp_check = headP->next;
    if(check_string(ACCOUNT, class_number) == SUCCESS && atol(class_number) != 0){
        while(temp_check != NULL){
            if(temp_check->class_number == atol(date)){
                printf("班级号：%ld  \n",temp_check->class_number);
                printf("数学平均分：%f  \n",temp_check->subject_aver[ADVANCED_MATHEMATICS][0]);
                printf("英语平均分：%f  \n",temp_check->subject_aver[ENGLISH][0]);
                printf("C语言平均分：%f  \n",temp_check->subject_aver[C_PROGRAM_LANGUAGE][0]);
                printf("物理平均分：%f  \n",temp_check->subject_aver[PHYSICAL_EDUCATION][0]);
                printf("python平均分：%f  \n",temp_check->subject_aver[PYTHON][0]);
                printf("平均总分：%f  \n",temp_check->general_aver);
                printf("平均绩点：%f\n",temp_check->general_gpa);
                break;
            }
            temp_check = temp_check->next;
        }
    }
    else{
        printf("Wrong number!");
        printf("Input against");
        return find_class_one(headP);
    }
    return  SUCCESS;
}




/**
 * @file users.c
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
     class_p temp_check = headP->next;
    while(temp_check!=NULL){
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
 * @file users.c
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
    char class_number[20];
    char *date = class_number;
    fgets(date, 21, stdin);
    fflush(stdin);
    class_p temp_check = headP->next;
    class_p temp_check_ano = headP->next;
    if(check_string(ACCOUNT, class_number) == SUCCESS && atol(class_number) != 0){

        while(temp_check_ano->next != NULL) {
            while (temp_check != NULL) {
                temp_check_ano = temp_check;
                temp_check = temp_check_ano->next;
                if (temp_check->class_number == atol(date)) {
                    temp_check_ano->next = temp_check->next;
                    free(temp_check);
                    break;
                }
            }
        }
    }
    else{
        return delete_class(headP);
    }
    return SUCCESS;
}




/**
 * @file users.c
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
    char class_number[20];
    char *date_input = class_number;
    fgets(date_input, 21, stdin);
    fflush(stdin);
    class_p temp_check = headP->next;
    if(check_string(ACCOUNT, class_number) == SUCCESS && atol(date_input) != 0){
        while(temp_check != NULL){
            if(temp_check->class_number == atol(date_input)){
                printf("This class saved!");
                break;
            }
            temp_check = temp_check->next;
        }
        if(temp_check == NULL){
            class_p new_class = (class_p)malloc(sizeof(class_p));
            printf("请输入班级号：");
            char class_number_add[20];
            char *date_number = class_number_add;
            fgets(date_number, 21, stdin);
            fflush(stdin);
            while(true){
                if(check_string(ACCOUNT, class_number_add) == SUCCESS && atol(date_number) != 0) {
                    new_class->class_number = atol(date_number);
                }
                else{
                    printf("Wrong input!");
                    printf("Input against!");
                    continue;
                }
                    break;
            }
        }
    }
    else{
        printf("Wrong number!");
        printf("Input against!");
        return add_class(headP);
    }
    return SUCCESS;
}




/**
 * @file users.c
 * @author @waterman263
 * @brief    change information of class
 * @version 0.1
 * @date 2021-05-17
 *
 *
 * @copyright Copyright (c) 2021
 *
 */
enum OPERATE chg_class(class_head_p headP){
    char class_number[20];
    char *date=class_number;
    fgets(date, 21, stdin);
    fflush(stdin);
    class_p temp_check = headP->next;
    if(check_string(ACCOUNT, class_number) == SUCCESS && atoll(class_number) != 0){
        while(temp_check!= NULL){
            if(temp_check->class_number == atol(date)){
                printf("请输入修改后的班级号：");
                char class_number_chg[20];
                char *accounts_number_chg = class_number_chg;
                fgets(accounts_number_chg, 21, stdin);
                fflush(stdin);
                while(true){
                    if(check_string(ACCOUNT, class_number_chg) == SUCCESS && atol(class_number_chg) != 0) {
                        temp_check->class_number = atol(class_number_chg);
                    }
                    else{
                        printf("Wrong input!");
                        printf("Input against!");
                        continue;
                    }
                    break;
                }
            }
            temp_check = temp_check->next;
        }
    }
    else{
        printf("Wrong input!");
        printf("Input against!");
        return chg_class(headP);
    }
    return SUCCESS;
}