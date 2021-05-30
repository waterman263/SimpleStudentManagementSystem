/**
 * @file teacher_director_service.c
 * @author @Little-Red-Riding-Hood
 * @brief check, delete and update the messages of teacher
 * @version 0.1
 * @date 2021-05-19
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "serviceHead/teacher_service.h"

teach_head_p initial_Teacher_List(){
    teach_head_p head_point = (teach_head_p)malloc(sizeof(teacher_head_p));

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
 * @brief create new teacher
 * @date 2021-5-30
 *
 * @param teach_head_p head
 * @return  new teacher
 */
teacher_p create_teacher(teach_head_p head) {

    if (head == NULL) {
        printf("An unexpected error has been created,");
        printf(" please save your work and exit this program.\n");
        return NULL;
    }

    teacher_p temp_teacher = head->next;
    teacher_p new_teacher = (teacher_p)malloc(sizeof(teacher));
    if (new_teacher == NULL) {
        printf("Warning: Your computer has not enough free memory,");
        printf("Please save your work and exit this program.\n");
        return NULL;
    }

    new_teacher->next = NULL;
    new_teacher = set_teacher(new_teacher, head);
    if (temp_teacher == NULL) head->next = new_teacher;
    else {
        while(temp_teacher->next != NULL){
            temp_teacher = temp_teacher->next;
        }
        temp_teacher->next = new_teacher;
    }

    printf("That's alright.Returning to the main menu\n");
    return new_teacher;
}

/**
 * @author Little-Red-Riding-Hood
 * @brief set the properties of teacher
 * @date 2021-5-30
 *
 * @param teacher_p teacher, teach_head_p head
 *
 * @return teacher entity
 */
teacher_p set_teacher(teacher_p teacher, teach_head_p head){
    char name[21];
    char *get_name = name;

    char work_number[10];
    char *get_number = work_number;

    char email[31];
    char *get_email = email;

    char cell_phone[12];
    char *phone_number = cell_phone;

    char my_uid[24];
    char *uid = my_uid;

    char switch_number;

    printf("Please enter your name\n");
    fgets(get_name, 20, stdin);
    fflush(stdin);

    int i = 0;
    while (*get_name != '\n') {
        teacher->name[i] = *get_name;
        get_name++;
        i++;
    }
    teacher->name[i] = '\0';

    printf("Please enter your work number\n");
    fgets(get_number, 10, stdin);
    fflush(stdin);
    while (true){
        if(check_string(ACCOUNT, work_number) == SUCCESS && atol(work_number) > 0){
            teacher->work_number = atol(work_number);
            break;
        }else{
            printf("The number you input must be a 9-digit number. \nPlease enter again!\n");
            fgets(get_number, 10, stdin);
            fflush(stdin);
        }
    }


    printf("Please enter your email\n");
    fgets(get_email,30,stdin);
    fflush(stdin);
    while (true){
        if(check_string(EMAIL, email) == SUCCESS ){
            strcpy(teacher->email, email);
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
        if(check_string(TELEPHONE_NUMBER, cell_phone) == SUCCESS){
            strcpy(teacher->phone_number, cell_phone);
            printf("Enter successfully\n");
            break;
        }else{
            printf("The number you input must be a 11-digit number. \nPlease enter again!\n");
            fgets(phone_number, 12, stdin);
            fflush(stdin);
        }
    }


    while(true) {
        loop:    printf("Please enter the subject you teach\n");
        printf("0.ADVANCED_MATHEMATICS      1.ENGLISH\n");
        printf("2.C_PROGRAM_LANGUAGE        3.PHYSICAL_EDUCATION\n");
        printf("4.PYTHON\n");
        scanf("%c", &switch_number);
        fflush(stdin);
        switch (switch_number) {
            case '0':
                teacher->subject = ADVANCED_MATHEMATICS;
                break;
            case '1':
                teacher->subject = ENGLISH;
                break;
            case '2':
                teacher->subject = C_PROGRAM_LANGUAGE;
                break;
            case '3':
                teacher->subject = PHYSICAL_EDUCATION;
                break;
            case '4':
                teacher->subject = PYTHON;
                break;
            default:
                printf("Please input a legal serial.\n");
                printf("Press any key to continue.\n");
                getchar();
                goto loop;
        }
        break;
    }
    create_uid(uid);
    strcpy(teacher->uid, my_uid);
    return teacher;
}

/**
 * @author Little-Red-Riding-Hood
 * @brief query the message of the teaching class
 * @date 2021-5-30
 *
 * @param teacher_p teacher, class_head_p head
 *
 */
void query_class(teacher_p teacher, class_head_p head){
    if(head == NULL)
    {
        printf("Error press any key to exit\n");
        getchar();
        exit(0);
    }

    char class_uid[24];
    char* uid = class_uid;

    class_p class = head->next;

    if(class == NULL)
    {
        printf("There isn't any class to query. Press any key to exit\n");
        getchar();
        exit(0);
    }


    while (class != NULL){
        class = class->next;
        if(strcmp(class->uid, teacher->classes_uid) == 0)
        break;
    }

    printf("The class number %ld\n", class->class_number);
    printf("The ADVANCED_MATHEMATICS aver :%f\n", class->subject_aver[ADVANCED_MATHEMATICS][0]);
    printf("The ENGLISH aver :%f\n", class->subject_aver[ENGLISH][0]);
    printf("The C_PROGRAM_LANGUAGE aver :%f\n", class->subject_aver[C_PROGRAM_LANGUAGE][0]);
    printf("The PHYSICAL_EDUCATION aver :%f\n", class->subject_aver[PHYSICAL_EDUCATION][0]);
    printf("The PYTHON aver :%f\n", class->subject_aver[PYTHON][0]);
    printf("The class general aver %f\n", class->general_aver);
    printf("The class general gpa %f\n", class->general_gpa);
}

/**
 * @author Little-Red-Riding-Hood
 * @brief query the message of teacher
 * @date 2021-5-30
 *
 * @param teach_head_p head
 *
 */

void query_my_data(teach_head_p head){
    teacher_p data = head->next;

    char name[21];
    char *get_name = name;

    char *subject[] = {"ADVANCED_MATHEMATICS","ENGLISH","C_PROGRAM_LANGUAGE","PHYSICAL_EDUCATION","PYTHON"};


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
        get_name++;
        i++;
    }
    name[i] = '\0';

    while(data != NULL)
    {
        if(strcmp(data->name, name) == 0) {
            printf("Name: %s\n", data->name);
            printf("Subject: %s\n",subject[data->subject]);
            printf("Work number: %ld\n", data->work_number);
            printf("Phone number: %s\n", data->phone_number);
            printf("Email: %s\n", data->email);
            break;
        }
        data = data->next;
    }
}



