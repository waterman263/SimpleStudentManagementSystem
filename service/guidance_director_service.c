/**
 * @file guidance_director_service.c
 * @author @Little-Red-Riding-Hood
 * @brief check, delete and update the messages of guidance_directors
 * @version 0.1
 * @date 2021-05-19
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "serviceHead/guidance_director_service.h"

director_head_p initial_Director_List(){

    director_head_p head_point = (director_head_p)malloc(sizeof(director_head_pointer));
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
 * @author Little-Red-Ridding-Hood
 * @brief create new director
 * @date 2021-5-30
 *
 * @param director_head_p head
 * @return  new director
 */
director_p create_director(director_head_p head){
    if (head == NULL){
        printf("An unexpected error has been created,");
        printf(" please save your work and exit this program.\n");
        return NULL;
    }

    director_p temp_director = head->next;
    director_p new_director = (director_p)malloc(sizeof(director));

    if (new_director == NULL){
        printf("Warning: Your computer has not enough free memory,");
        printf(" please save your work and exit this program.\n");
        return NULL;
    }
    new_director->next = NULL;
    new_director = set_director(new_director, head);

    if (temp_director == NULL) head->next = new_director;
    else {
        while(temp_director->next != NULL){
            temp_director = temp_director->next;
        }
        temp_director->next = new_director;
    }

    printf("That's alright. Returning to the menu \n");
    return new_director;
}

/**
 * @author Little-Red-Riding-Hood
 * @brief set the properties of director
 * @date 2021-5-30
 *
 * @param director_p director, director_head_p head
 *
 * @return director entity
 */
director_p set_director(director_p director, director_head_p head){
    char name[21];
    char *get_name = name;

    char work_number[10];
    char *get_number = work_number;

    char email[33];
    char *get_email = email;

    char cell_phone[12];
    char *phone_number = cell_phone;

    char my_uid[24];
    char *uid = my_uid;

    printf("Please enter your name \n");
    fgets(get_name, 21, stdin);
    fflush(stdin);

    int i = 0;
    while (*get_name != '\n') {
        director->name[i] = *get_name;
        get_name++;
        i++;
    }
    director->name[i] = '\0';

    printf("Please enter your work number\n");
    fgets(get_number, 10, stdin);
    fflush(stdin);
    while (true){
        if(check_string(ACCOUNT, work_number) == SUCCESS && atol(work_number) != 0){
            director->work_number = atol(work_number);
            break;
        }else{
            printf("The number you input must be a 9-digit number. \nPlease enter again! \n");
            fgets(get_number, 10, stdin);
            fflush(stdin);
        }
    }


    printf("Please enter your email\n");
    fgets(get_email,30,stdin);
    fflush(stdin);
    while (true){
        if(check_string(EMAIL, get_email) == SUCCESS ){
            i = 0;
            while (*get_email != '\n') {
                director->email[i] = *get_email;
                get_email++;
                i++;
            }
            director->email[i] = '\0';
            break;
        }else{
            printf("Your enter is illegal! \nPlease enter again! \n");
            fgets(get_email, 30, stdin);
            fflush(stdin);
        }
    }

    printf("Please enter your cell-phone number\n");
    fgets(phone_number,12,stdin);
    fflush(stdin);
    while (true){
        if(check_string(TELEPHONE_NUMBER, cell_phone) == SUCCESS && atol(cell_phone) != 0){
            strcpy(director->phone_number, cell_phone);
            break;
        }else{
            printf("The number you input must be a 11-digit number. \nPlease enter again!\n");
            fgets(phone_number, 12, stdin);
            fflush(stdin);
        }
    }

    create_uid(uid);
    strcpy(director->uid, my_uid);
    return director;
}

/**
 * @author Little-Red-Riding-Hood
 * @brief query the message of the director
 * @date 2021-5-30
 *
 * @param director_head_p head
 *
 */
void query_my_own_data(director_head_p head){
    director_p data = head->next;

    char name[21];
    char *get_name = name;

    if(data == NULL) {
        printf("The message you query hasn't existed\n");
        printf("Please press any key to exit this program.\n");
        getchar();
        exit(0);
    }

    printf("Please enter your name\n");
    fgets(get_name, 21, stdin);
    fflush(stdin);

    int i = 0;
    while (*get_name != '\n') {
        name[i] = *get_name;
        get_name++;
        i++;
    }
    name[i] = '\0';

    while(data != NULL)
    {
        if(strcmp(data->name, name) == 0) {
            printf("Name: %s\n", data->name);
            printf("Work number: %ld\n", data->work_number);
            printf("Phone number: %s\n", data->phone_number);
            printf("Email: %s\n", data->email);
            break;
        }
        data = data->next;
    }
}

/**
 * @author Little-Red-Riding-Hood
 * @brief update the properties of director
 * @date 2021-5-30
 *
 * @param director_head_p head
 *
 */
void update_my_own_data(director_head_p head){
    director_p data = head->next;

    char name[21];
    char *get_name = name;

    char email[31];
    char *get_email = email;

    char cell_phone[12];
    char *phone_number = cell_phone;

    if(data == NULL) {
        printf("The message you query hasn't existed\n");
        printf("Please press any key to exit this program.\n");
        getchar();
        exit(0);
    }

    printf("==Please enter your name.\n");
    fgets(get_name,21,stdin);
    fflush(stdin);

    int i = 0;
    while (*get_name != '\n') {
        name[i] = *get_name;
        get_name++;
        i++;
    }
    name[i] = '\0';

    while(data != NULL){
        if(strcmp(data->name, name) == 0)
        {
            printf("Which message do you want to update?\n");
            printf("1.Email      2.Phone number\n");
            printf("3.Name       4.Exit \n");
            printf("Press any serial to continue\n");

            int choose;
            scanf("%d", &choose);
            fflush(stdin);
            while (true){
                if(choose <5 && choose>0)
                    break;
                else{
                    printf("Please input the legal serial.\n");
                    scanf("%d", &choose);
                    fflush(stdin);
                }
            }
            switch (choose) {
                case 1:
                    printf("Please input your new email\n");
                    fgets(get_email,30,stdin);
                    fflush(stdin);
                    while (true){
                        if(check_string(EMAIL, email) == SUCCESS ){
                            strcpy(data->email, email);
                            break;
                        }else{
                            printf("Your enter is illegal! \nPlease enter again! \n");
                            fgets(get_email, 30, stdin);
                            fflush(stdin);
                        }
                    }
                    printf("Update successfully\n");
                    printf("Soon will return to the menu.\n");
                    break;
                case 2:
                    printf("Please input your new Phone number\n");
                    fgets(phone_number,12,stdin);
                    fflush(stdin);
                    while (true){
                        if(check_string(TELEPHONE_NUMBER, phone_number) == SUCCESS && atol(phone_number) != 0){
                            strcpy(data->phone_number, cell_phone);
                            break;
                        }else{
                            printf("The number you input must be a 11-digit number. \nPlease enter again! ");
                            fgets(phone_number, 12, stdin);
                            fflush(stdin);
                        }
                    }
                    printf("Update successfully\n");
                    printf("Soon will return to the menu.\n");
                    break;
                case 3:
                    printf("Please input your new name\n");
                    fgets(get_name, 21, stdin);
                    fflush(stdin);
                     i = 0;
                    while (*get_name != '\n') {
                        data->name[i] = *get_name;
                        get_name++;
                        i++;
                    }
                    data->name[i] = '\0';
                    printf("Update successfully\n");
                    printf("Soon will return to the menu.\n");
                    break;
                case 4:
                    printf("OK, you will exit soon.");
                    exit(0);
            }
        }
    }
}

/**
 * @author Little-Red-Riding-Hood
 * @brief query the message of the single grade
 * @date 2021-5-30
 *
 * @param grade_head_p head
 *
 */
void query_single_grade(grade_head_p head){
    grade_p grade = head->next;
    char grade_number[5];
    char *get_number = grade_number;

    if(grade == NULL) {
        printf("The grade you query hasn't existed\n");
        printf("Please press any key to exit this program.\n");
        getchar();
        exit(0);
    }
    fgets(get_number,4,stdin);
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
            fgets(get_number, 4, stdin);
            fflush(stdin);
        }
    }

    while (grade != NULL)
    {
        if(atol(grade_number) == grade->grade_number)
        {
            printf("The class amount :%d\n", grade->class_total);
            printf("The ADVANCED_MATHEMATICS aver :%f\n", grade->subject_aver[ADVANCED_MATHEMATICS][0]);
            printf("The ENGLISH aver :%f\n", grade->subject_aver[ENGLISH][0]);
            printf("The C_PROGRAM_LANGUAGE aver :%f\n", grade->subject_aver[C_PROGRAM_LANGUAGE][0]);
            printf("The PHYSICAL_EDUCATION aver :%f\n", grade->subject_aver[PHYSICAL_EDUCATION][0]);
            printf("The PYTHON aver :%f\n", grade->subject_aver[PYTHON][0]);
            printf("The general_aver_score :%f\n", grade->general_aver_score);
            printf("The general_aver_gpa :%f\n", grade->general_aver_gpa);
            break;
        }
        grade = grade->next;
    }
}

/**
 * @author Little-Red-Riding-Hood
 * @brief query the message of the single grade
 * @date 2021-5-30
 *
 * @param grade_head_p head
 *
 */
void query_all_grades(grade_head_p head){
    grade_p grade = head->next;

    if(grade == NULL)
    {
        printf("There isn't any grade to query!");
        printf("Please press any key to exit this program.");
        getchar();
        exit(0);
    }

    while (grade != NULL)
    {
        printf("The class amount :%d\n", grade->class_total);
        printf("The ADVANCED_MATHEMATICS aver :%f\n", grade->subject_aver[ADVANCED_MATHEMATICS][0]);
        printf("The ENGLISH aver :%f\n", grade->subject_aver[ENGLISH][0]);
        printf("The C_PROGRAM_LANGUAGE aver :%f\n", grade->subject_aver[C_PROGRAM_LANGUAGE][0]);
        printf("The PHYSICAL_EDUCATION aver :%f\n", grade->subject_aver[PHYSICAL_EDUCATION][0]);
        printf("The PYTHON aver :%f\n", grade->subject_aver[PYTHON][0]);
        printf("The general_aver_score :%f\n", grade->general_aver_score);
        printf("The general_aver_gpa :%f\n", grade->general_aver_gpa);
        grade = grade->next;
    }
}

