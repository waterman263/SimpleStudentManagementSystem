/**
 * @file grade.c
 * @author @Little-Red-Riding-Hood
 * @brief check, delete and update the messages of grade
 * @version 0.1
 * @date 2021-05-17
 *
 * @copyright Copyright (c) 2021
 *
 */

/**
 * @author @Little-Red-Riding-Hood
 * @brief Function for initial grade list
 * @date 2021-3-14
 *
 * @return head_point for grade list
 */
#include "serviceHead/grade_service.h"

grade_head_p initial_Grade_List(){
    grade_head_p head_point = (grade_head_p)malloc(sizeof(grade_head_pointer));

    if (head_point == NULL)
    {
        printf("Warning: Your computer has not enough free memory,");
        printf("please press any key to exit this program.\n");
        getchar();
        exit(0);
    }

    head_point->next = NULL;
    return head_point;
}

/**
 * @author Little-Red-Riding-Hood
 * @brief set the properties of grade
 * @date 2021-5-18
 *
 * @param HAS_CLASSES_INPUT whether it is the first time to create grade
 *
 * @return GRADE entity
 */
grade_p create_grade(grade_head_p head){

    if (head == NULL)
    {
        printf("An unexpected error has been created,");
        printf(" please save your work and exit this program.\n");
        return NULL;
    }

    grade_p temp_grade = head->next;
    grade_p new_grade = (grade_p)malloc(sizeof(grade));

    if (new_grade == NULL)
    {
        printf("Warning: Your computer has not enough free memory,");
        printf("Please save your work and exit this program.\n");
        return NULL;
    }
    new_grade->next = NULL;

    new_grade = set_grade(new_grade);

    if (temp_grade == NULL) temp_grade = new_grade;
    else {
        while(temp_grade->next != NULL){
            temp_grade = temp_grade->next;
        }
        temp_grade->next = new_grade;
    }
    printf("That's alright.Returning to the main menu\n");
    return new_grade;
}

/**
 * @author Little-Red-Riding-Hood
 * @brief set the properties of grade
 * @date 2021-5-30
 *
 * @param grade_p new_grade
 *
 *
 * @return grade entity
 */
grade_p set_grade(grade_p grade){
    char grade_number[5];
    char *temp_grade_number = grade_number;

    char grade_uid[24];
    char *uid = grade_uid;


    printf("==Please input the grade number.It should be a four-digit-number.\n");
    printf("==Grade number:");
    fgets(temp_grade_number, 5, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, grade_number) == SUCCESS && atol(grade_number) != 0) {
            grade->grade_number = atol(grade_number);
            printf("==Ok. There's nothing wrong with your grade number.\n");
            break;
        } else{
            printf("==The grade number you enter must be a four-digit-number and positive number. "
                   "\n==Please enter it again!\n");
            printf("Grade number:");
            fgets(temp_grade_number, 4, stdin);
            fflush(stdin);
        }
    }

    create_uid(uid);
    strcpy(grade->uid, grade_uid);

    grade->class_total = 0;
    grade->HAS_CLASSES_INPUT = FALSE_RES;

    return grade;
}

/**
 * @author Little-Red-Riding-Hood
 * @brief update the properties of grade
 * @date 2021-5-30
 *
 * @param grade_head_p head
 *
 *
 * @return grade entity
 */
void update_grade (grade_head_p head){

    char target_grade[5];
    char *temp_target_grade = target_grade;

    char update_grade_number[5];
    char *temp_update_grade_number = update_grade_number;

    grade_p temp_grade = head->next;

    printf("==Please input the number of the grade you want to change.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than the grade number.\n");
    printf("==Target grade number:");
    fgets(temp_target_grade, 4, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, target_grade) == SUCCESS){
            if (atol(target_grade) == 0){
                printf("==Alright, returning menu...\n");
                return;
            }

            while (temp_grade != NULL){
                if (temp_grade->grade_number == atol(target_grade)) break;
            }
            if (temp_grade == NULL){
                printf("==The grade number is not exist yet. Please check your grade number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than the grade number.\n");
                printf("==Target grade number:");
                fgets(temp_target_grade, 4, stdin);
                fflush(stdin);
            } else break;

        }else{
            printf("==The number you input must be a four-digit and positive number. "
                   "\n==Please enter it again!\n");
            printf("==If you want to cancel the operate, just enter 0 rather than the grade number.\n");
            printf("==Target grade number:");
            fgets(temp_target_grade, 4, stdin);
            fflush(stdin);
        }
    }


    printf("==Please enter the grade number you want to replace the old one.\n");
    printf("==If you want to cancel the operate, just enter 0 rather than the grade number.\n");
    printf("==New grade number:");
    fgets(temp_update_grade_number, 4, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, target_grade) == SUCCESS){
            if (atol(target_grade) == 0){
                printf("==Alright, returning menu...\n");
                return;
            }
            break;
        }else{
            printf("==The number you input must be a four-digit and positive number. "
                   "\n==Please enter again! \n");
            printf("==If you want to cancel the operate, just enter 0 rather than the grade number.\n");
            printf("==New grade number:");
            fgets(temp_target_grade, 4, stdin);
            fflush(stdin);
        }
    }

    temp_grade->grade_number = atol(update_grade_number);
    printf("==Change successfully!\n");
    printf("==Returning menu now...\n");
}

/**
 * @author Little-Red-Riding-Hood
 * @brief delete the properties of grade
 * @date 2021-5-30
 *
 * @param grade_head_p head
 *
 */
void delete_grade(grade_head_p head){
    grade_p pre_grade, target_grade;
    int judge = 0;
    char grade_number[5];
    char *temp_grade_number = grade_number;

    if(head->next == NULL){
        printf("==There isn't any grade to delete!\n");
        return;
    }

    pre_grade = head->next;
    target_grade = pre_grade;

    printf("==Please input the number of the grade you want to delete\n");
    printf("==If you want to cancel the operate, just enter 0 rather than the grade number.\n");
    printf("==Target grade number:");
    fgets(temp_grade_number, 4, stdin);
    fflush(stdin);

    while (true){
        if(check_string(ACCOUNT, grade_number) == SUCCESS) {
            if (atol(temp_grade_number) == 0){
                printf("==Alright, returning menu...\n");
                return;
            }

            while (target_grade != NULL){
                if (target_grade->grade_number == atol(temp_grade_number)) break;
            }
            if (target_grade == NULL){
                printf("==The grade number is not exist yet. Please check your grade number!\n");
                printf("==If you want to cancel the operate, just enter 0 rather than the grade number.\n");
                printf("==Target grade number:");
                fgets(temp_grade_number, 4, stdin);
                fflush(stdin);
            } else break;
        } else{
            printf("==The grade number you enter must be a four-digit-number and positive number. "
                   "\n==Please enter it again!\n");
            printf("==If you want to cancel the operate, just enter 0 rather than the grade number.\n");
            printf("==Target grade number:");
            fgets(temp_grade_number, 4, stdin);
            fflush(stdin);
        }
    }

    if (target_grade == head->next){
        head->next = target_grade->next;
    } else{
        while (pre_grade->next->grade_number != target_grade->grade_number){
            pre_grade = pre_grade->next;
        }
        pre_grade->next = target_grade->next;
    }

    free(target_grade);

    printf("==Delete successfully!\n");
    printf("==Returning menu now...\n");

}
