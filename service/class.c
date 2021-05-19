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

void input_array(char a[5][1]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<1;j++){
            printf("%s",&a[i][j]);
        }
    }

}


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

enum OPERATE find_class(classes_head_p headP,enum SELECT select){
    if(select == ONE) return find_class_one(headP);
    if(select == ALL) return find_class_all(headP);
}
enum OPERATE find_class_one(classes_head_p headP){
    char class_number[20];
    char *accounts=class_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    class_p temp_check = headP.next;
    if(check_string(ACCOUNT, class_number) == SUCCESS && atoll(class_number) != 0){
        while(temp_check!=NULL){
            if(temp_check->class_number == atol(accounts)){
                printf("%ld  ",temp_check->class_number);
                printf("%f  ",temp_check->subject_aver);
                printf("%f  ",temp_check->general_aver);
                printf("%f\n",temp_check->general_gpa);
            }
            temp_check = temp_check->next;
        }
    }
}
enum OPERATE find_class_all(classes_head_p headP){
     class_p temp_check = headP.next;
    while(temp_check!=NULL){
        printf("%ld  ",temp_check->class_number);
        input_array(temp_check->subject_aver);
        printf("%f  ",temp_check->general_aver);
        printf("%f\n",temp_check->general_gpa);
        temp_check = temp_check->next;
    }
}


enum OPERATE delete_class(classes_head_p headP){
    char class_number[20];
    char *accounts=class_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    class_p temp_check = headP.next;
    class_p temp_check_ano = headP.next;
    if(check_string(ACCOUNT, class_number) == SUCCESS && atoll(class_number) != 0){
        while(temp_check!=NULL){
            temp_check_ano = temp_check;
            if(temp_check ->class_number == atol(accounts)){
                temp_check_ano->next = temp_check->next;
            }
            temp_check ->next;
        }
    }
}


enum OPERATE add_class(classes_head_p headP){
    char class_number[20];
    char *accounts=class_number;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    class_p temp_check = headP.next;
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
            scanf("%s",new_class->class_number);
            scanf("%s",new_class->counsellor_uid);
            scanf("%lf",new_class->general_aver);
            scanf("%lf",new_class->general_gpa);
        }
    }
}
enum OPERATE chg_class(classes_head_p headP){
    char student_name[20];
    int choose;
    char *accounts=student_name;
    fgets(accounts, 11, stdin);
    fflush(stdin);
    class_p temp_check = headP.next;
    if(check_string(ACCOUNT, student_name) == SUCCESS && atoll(student_name) != 0){
        while(temp_check!= NULL){
            if(temp_check->class_number == atol(accounts)){
                scanf("%d",&choose);
                switch(choose){
                    case 1:
                        printf("请输入您要修改的名字：");
                        strcpy("%ld",temp_check->class_number);
                        break;
                    case 2:
                        printf("请输入您要修改的平均绩点");
                        strcpy("%f",temp_check->general_gpa);
                        break;
                    case 3:
                        printf("请输入您要修改的平均分");
                        strcpy("%f",temp_check->general_aver);
                        break;
                    default :
                        printf("请输入正确的选项\n");
                        break;
                }
            }
        }
    }
}