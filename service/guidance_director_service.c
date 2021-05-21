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
    head_point->isHead = TRUE_RES;
    head_point->next = NULL;
    return head_point;
}
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
    while (temp_director->next != NULL){
        temp_director = temp_director->next;
    }

    temp_director->next = new_director;
    printf("That's alright. Returning to the menu \n");
    return new_director;
}
director_p set_director(director_p director, director_head_p head){
    char name[21];
    char *get_name = name;

    char work_number[12];
    char *get_number = work_number;

    char email[30];
    char *get_email = email;

    char cell_phone[10];
    char *phone_number = cell_phone;

    char my_uid[24];
    char *uid = my_uid;

    printf("Please enter your name \n");
    fgets(get_name, 20, stdin);
    fflush(stdin);

    int i = 0;
    while (*get_name != '\n') {
        director->name[i] = *get_name;
        get_name++;
        i++;
    }
    name[i] = '\0';

    printf("Please enter your work number\n");
    fgets(get_number, 9, stdin);
    fflush(stdin);
    while (true){
        if(check_string(ACCOUNT, work_number) == SUCCESS && atol(work_number) != 0){
            printf("Enter successfully\n Please press any key to continue\n");
            getchar();
            break;
        }else{
            printf("The number you input must be a 9-digit number. \nPlease enter again! \n");
            fgets(get_number, 10, stdin);
            fflush(stdin);
        }
    }
    director->work_number = atol(work_number);

    printf("Please enter your email\n");
    fgets(get_email,30,stdin);
    fflush(stdin);
    strcpy(director->email, email);

    printf("Please enter your cell-phone number\n");
    fgets(phone_number,10,stdin);
    fflush(stdin);
    while (true){
        if(check_string(ACCOUNT, cell_phone) == SUCCESS && atol(cell_phone) != 0){
            printf("Enter successfully\n Please press any key to continue\n");
            getchar();
            break;
        }else{
            printf("The number you input must be a 11-digit number. \nPlease enter again!\n");
            fgets(phone_number, 11, stdin);
            fflush(stdin);
        }
    }
    strcpy(director->phone_number, cell_phone);

    create_uid(char *uid);
    strcpy(director->uid, my_uid);
    return director;
}
void query_my_own_data(director_head_p head){
    director_p data = head->next;
    char name[21];
    char *get_name = name;

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
    if(data == NULL)
        printf("The message you query hasn't existed");
}
void update_my_own_data(director_head_p head){
    director_p data = head->next;
    char name[10];
    char *get_name = name;

    char email[10];
    char *get_email = email;

    char cell_phone[10];
    char *phone_number = cell_phone;

    int choose;
    fgets(get_name,10,stdin);
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
            printf("3.Name\n");
            printf("Press any serial to continue\n");

            scanf("%d", &choose);
            switch (choose) {
                case 1:
                    printf("Please input your new email\n");
                    fgets(get_mail,30,stdin);
                    fflush(stdin);
                    while (true){
                        if(check_string(PASSWORD, email) == SUCCESS ){
                            printf("Enter successfully\n Please press any key to continue\n");
                            getchar();
                            break;
                        }else{
                            printf("Your enter is illegal! \nPlease enter again! \n");
                            fgets(get_mail, 30, stdin);
                            fflush(stdin);
                        }
                    }
                    strcpy(data->email, email);
                    printf("Update successfully\n");
                    break;
                case 2:
                    printf("Please input your new Phone number\n");
                    fgets(phone_number,10,stdin);
                    fflush(stdin);
                    while (true){
                        if(check_string(ACCOUNT, phone_number) == SUCCESS && atol(phone_number) != 0){
                            printf("Enter successfully\n Please press any key to continue\n");
                            getchar();
                            break;
                        }else{
                            printf("The number you input must be a 9-digit number. \nPlease enter again! ");
                            fgets(phone_number, 10, stdin);
                            fflush(stdin);
                        }
                    }
                    strcpy(data->phone_number, cell_phone);
                    printf("Update successfully\n");
                    break;
                case 3:
                    printf("Please input your new name\n");
                    fgets(get_name, 10, stdin);
                    fflush(stdin);
                    int i = 0;
                    while (*get_name != '\n') {
                        data->name[i] = *get_name;
                        get_name++;
                        i++;
                    }
                    printf("Update successfully\n");
                    break;
                default:
                    printf("Please input the legal serial\n");
                    break;
            }
        }
    }
    if(data == NULL)
        printf("The message you want to update hasn't existed!");
}
void query_single_grade(grade_head_p head){
    grade_p grade = head->next;
    char grade_number[5];
    char *get_number = grade_number;

    fgets(get_number,4,stdin);
    fflush(stdin);
    while (grade != NULL)
    {
        if(strcmp(grade_number, grade->grade_nmuber) == 0)
        {
            printf("The class amount :%d", grade->class_total);
            for(int i = 0; i < 5; i++) {
                printf("The %d aver :%f", i, grade->subject_aver[i][0]);
            }
            printf("The general_aver_score :%f", grade->general_aver_score);
            printf("The general_aver_gpa :%f", grade->general_aver_gpa);
            break;
        }
        grade = grade->next;
    }
    if(grade == NULL)
        printf("The grade you query hasn't existed");
}
void query_all_grades(grade_head_p head){
    grade_p grade = head->next;
    if(grade == NULL)
    {
        printf("There isn't any grade to query!");
        return;
    }
    while (grade)
    {
            printf("The class amount :%d", grade->class_total);
            for(int i = 0;i < 5;i++) {
                printf("The %d aver :%f",i, grade->subject_aver[i][0]);
            }
            printf("The general_aver_score :%f", grade->general_aver_score);
            printf("The general_aver_gpa :%f", grade->general_aver_gpa);
            grade = grade->next;
    }
}

