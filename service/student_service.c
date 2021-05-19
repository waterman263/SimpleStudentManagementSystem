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
}
enum OPERATE find_student(student_head_p headP , enum  SELECT select){
    if(select == NUMBER) return find_student_by_number(headP);
    if(select == NAME)   return find_student_by_name(headP);
    if(select == ALL)    return find_student_all(headP);
    return SUCCESS;
}




enum OPERATE find_student_by_number(student_head_p headP ){
    char student_number[20];
    char *accounts=student_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP .next;
    if(check_string(ACCOUNT, student_number) == SUCCESS && atoll(student_number) != 0){
        while(temp_check != NULL){
            if(temp_check -> student_number == atol(accounts)==0){
                printf("%s  ",temp_check->name);
                printf("%s  ",temp_check->email);
                printf("%s  ",temp_check->phone_number);
                printf("%f  ",temp_check->subject_score);
                printf("%f  ",temp_check->average_score);
                printf("%f\n",temp_check->gpa);
            }
            temp_check = temp_check ->next;
            }
        }
    }





enum OPERATE find_student_by_name(student_head_p headP ){
    char student_name[20];
    char *accounts=student_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP.next;
    if(check_string(ACCOUNT, student_name) == SUCCESS && atoll(student_name) != 0){
        while(temp_check != NULL){
            if(strcmp(temp_check -> name , accounts)){
                printf("%s  ",temp_check->name);
                printf("%s  ",temp_check->email);
                printf("%s  ",temp_check->phone_number);
                printf("%f  ",temp_check->subject_score);
                printf("%f  ",temp_check->average_score);
                printf("%f\n",temp_check->gpa);
            }
            temp_check = temp_check ->next;
        }
        }
    }




enum OPERATE find_student_all(student_head_p headP){
    student_p temp_check = headP.next;
    while(temp_check != NULL){

            printf("%s  ",temp_check->name);
            printf("%s  ",temp_check->email);
            printf("%s  ",temp_check->phone_number);
            printf("%f  ",temp_check->subject_score);
            printf("%f  ",temp_check->average_score);
            printf("%f\n",temp_check->gpa);
        }
        temp_check = temp_check ->next;
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

enum OPERATE delete_student(student_head_p headP, enum SELECT select){
    if(select == NUMBER)  return delete_student_by_number( headP);
    if(select == NAME)  return delete_student_by_name( headP);
    return SUCCESS;
}

enum OPERATE delete_student_by_number(student_head_p headP ){
    char student_number[20];
    char *accounts=student_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP.next;
    student_p temp_check_ano = headP.next;
    if(check_string(ACCOUNT, student_number) == SUCCESS && atoll(student_number) != 0){
        while(temp_check != NULL){
            temp_check = temp_check_ano;
            if(temp_check->student_number == atol(accounts) ){
                temp_check_ano->next = temp_check->next;
            }
            temp_check -> next;
    }
    }
}

enum OPERATE delete_student_by_name(student_head_p headP ){
    char student_name[20];
    char *accounts=student_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP.next;
    student_p temp_check_ano = headP.next;
    if(check_string(ACCOUNT, student_name) == SUCCESS && atoll(student_name) != 0){
        while(temp_check!=NULL){
            temp_check = temp_check_ano;
            if(strcmp(temp_check->name, accounts) == 0){
                temp_check_ano->next = temp_check->next;
            }
            temp_check->next;
    }
    }
}

enum OPERATE add_student(student_head_p headP){
    char student_number[20];
    char *accounts=student_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP.next;
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
        scanf("%s",new_student->name);
        scanf("%ld",new_student->student_number);
        scanf("%s",new_student->email);
        scanf("%s",new_student->phone_number);
        scanf("%f",&new_student->average_score);
        scanf("%f",&new_student->gpa);
    }
}
}

enum OPERATE chg_student(student_head_p headP,enum SELECT select){
    if(select == NUMBER) return chg_student_by_number(headP,select);
    if(select == NAME)   return chg_student_by_name(headP, select);
    return SUCCESS;
}


enum OPERATE chg_student_by_name(student_head_p headP,enum SELECT select){
    char student_name[20];
    int choose;
    char *accounts=student_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    student_p temp_check = headP.next;
    if(check_string(ACCOUNT, student_name) == SUCCESS && atoll(student_name) != 0){
        while(temp_check!= NULL){
            if(strcmp(temp_check->name,accounts)== 0){
                scanf("%d",&choose);
                switch(choose){
                    case 1:
                        printf("请输入您要修改的名字：");
                        strcpy("%s",temp_check->name);
                        break;
                    case 2:
                        printf("请输入您要修改的平均分");
                        strcpy("%f",temp_check->average_score);
                        break;
                    case 3:
                        printf("请输入您要修改的电话：");
                        strcpy("%s",temp_check->phone_number);
                        break;
                    case 4:
                        printf("请输入学号");
                        strcpy("%ld",temp_check->student_number);
                    default :
                        printf("请输入正确的选项\n");
                        break;
                }
            }
        }
    }
}



