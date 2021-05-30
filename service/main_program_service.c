/**
 * @file main_program_service.c
 * @author @Loritas
 * @brief implements the main program function interface
 * @version 0.1
 * @date 2021-05-18
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "serviceHead/main_program_service.h"

const char identity[4][20] = {"Administrator", "Teacher", "Counsellor", "Guidance-director"};

enum OPERATE login_account(users_head_p head, USER *user){
    return login(head, user);
}

enum OPERATE administrator_system(users_head_p head, USER user) {
    printf("==================================================================\n");
    printf("======================Administrator Backstage=====================\n");
    printf("==================================================================\n");
    teach_head_p teacherHeadP = initial_Teacher_List();
    director_head_p directorHeadPointer = initial_Director_List();
    counsellor_head_p counsellorHeadP = initial_counsellor_List();
    class_head_p classHeadP = initial_class_List();
    stu_head_p stuHeadP = initial_student_List();
    grade_head_p gradeHeadP = initial_Grade_List();

    _Bool choose_function = false;
    while (!choose_function){
        printf("==Hello %s %s, you can now choose which functions you want to use.\n",
               identity[user->USER_ROLE+5], user->name);
        printf("\t1.User Functions\t\t2.Grade Functions\n");
        printf("\t3.Class Functions\t\t4.Student Functions\n");
        printf("\t5.Teacher Functions\t\t6.Log out\n");

        char choice = '0';
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case '1':
                printf("==Moving to User Function now...\n");
                users_function(head, user);
                break;
            case '2':
                printf("==Moving to Grade Function now...\n");
                grade_function(gradeHeadP, user);
                break;
            case '3':
                printf("==Moving to Class Function now...\n");
                class_function(classHeadP, user, gradeHeadP);
                break;
            case '4':
                printf("==Moving to Student Function now...\n");
                student_function(stuHeadP, user);
                break;
            case '6':
                choose_function = true;
                printf("==Alright. Goodbye %s %s\n", identity[user->USER_ROLE+5], user->name);
                break;
            case '5':
                printf("==Moving to Teacher Function now...\n");
                teacher_function(teacherHeadP, user);
                break;
            default:
                printf("==Please enter the correct number!\n");
        }
    }

    return SUCCESS;
}
enum OPERATE teacher_system(users_head_p head, USER user){
    printf("==================================================================\n");
    printf("=========================Teacher Backstage========================\n");
    printf("==================================================================\n");
    _Bool choose_function = false;
    while (!choose_function){
        printf("==Hello %s %s, you can now choose which functions you want to use.\n",
               identity[user->USER_ROLE+5], user->name);
        printf("\t1.View information about your class\t\t2.View your class's score\n");
        printf("\t3.Update your information\t\t4.View your information\n");
        printf("\t5.Log out\n");

        char choice = '0';
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case '1':
                printf("==Moving now...\n");
                break;
            case '2':
                printf("==Moving now...\n");
                break;
            case '3':
                printf("==Moving now...\n");
                break;
            case '4':
                printf("==Moving now...\n");
                break;
            case '5':
                choose_function = true;
                printf("==Alright. Goodbye %s %s\n", identity[user->USER_ROLE+5], user->name);
                break;
            default:
                printf("==Please enter the correct number!\n");
        }
    }
    return SUCCESS;
}
enum OPERATE counsellor_system(users_head_p head, USER user){
    printf("==================================================================\n");
    printf("========================counselor Backstage=======================\n");
    printf("==================================================================\n");
    _Bool choose_function = false;
    while (!choose_function){
        printf("==Hello %s %s, you can now choose which functions you want to use.\n",
               identity[user->USER_ROLE+5], user->name);
        printf("\t1.View information about your class\t\t2.View your class's score\n");
        printf("\t3.Update your information\t\t4.View your information\n");
        printf("\t5.Update your class information\t\t6.Log out\n");

        char choice = '0';
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case '1':
                printf("==Moving now...\n");
                break;
            case '2':
                printf("==Moving now...\n");
                break;
            case '3':
                printf("==Moving now...\n");
                break;
            case '4':
                printf("==Moving now...\n");
                break;
            case '5':
                printf("==Moving now...\n");
                break;
            case '6':
                choose_function = true;
                printf("==Alright. Goodbye %s %s\n", identity[user->USER_ROLE+5], user->name);
                break;
            default:
                printf("==Please enter the correct number!\n");
        }
    }
    return SUCCESS;
}
enum OPERATE guidance_director_system(users_head_p head, USER user){
    printf("==================================================================\n");
    printf("====================guidance-director Backstage===================\n");
    printf("==================================================================\n");
    _Bool choose_function = false;
    while (!choose_function){
        printf("==Hello %s %s, you can now choose which functions you want to use.\n",
               identity[user->USER_ROLE+5], user->name);
        printf("\t1.View information about grades\t\t2.View grades' score\n");
        printf("\t3.Update your information\t\t4.View your information\n");
        printf("\t5.Update grade information\t\t6.Log out\n");

        char choice = '0';
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case '1':
                printf("==Moving now...\n");
                break;
            case '2':
                printf("==Moving now...\n");
                break;
            case '3':
                printf("==Moving now...\n");
                break;
            case '4':
                printf("==Moving now...\n");
                break;
            case '5':
                printf("==Moving now...\n");
                break;
            case '6':
                choose_function = true;
                printf("==Alright. Goodbye %s %s\n", identity[user->USER_ROLE+5], user->name);
                break;
            default:
                printf("==Please enter the correct number!\n");
        }
    }
    return SUCCESS;
}

enum OPERATE users_function(users_head_p head, USER user){
    printf("========================================================\n");
    printf("======================User Function=====================\n");
    printf("========================================================\n");
    printf("==Welcome to the User Function! %s %s.\n", identity[user->USER_ROLE+5], user->name);
    _Bool exist_system = false;

    while (!exist_system){
        char choice = '0';
        printf("==What would you like to do next? \n");
        printf("\t1.Create a new user\t\t2.Query Users\n");
        printf("\t3.Update user information\t\t4.Delete user\n");
        printf("\t6.Back to the previous System\n");

        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case '1':
                printf("==Got it! \n");
                printf("==Moving to create a new user now...\n");
                create_user(head, NOT_FIRST_USER);
                break;
            case '2':
                printf("==Got it! \n");
                printf("==Moving to query users now...\n");
                printf("==Do you want to query all users? (y/n) \n");
                char query_all = 'n';
                scanf("%c", &query_all);
                fflush(stdin);
                if (query_all == 'y'){
                    printf("==Alright, the system will query all users' information...\n");
                    query_user(head, TRUE_RES);
                }else query_user(head, FALSE_RES);
                break;
            case '3':
                printf("==Got it! \n");
                printf("==Moving to update users now...\n");
                update_user(head);
                break;
            case '4':
                printf("==Got it! \n");
                printf("==Moving to delete users now...\n");
                delete_user(head, user);
                break;
            case '5':
                printf("==Saving...Please hold on...\n");
                save_file(USERS_DATA, head);
                printf("==OK, the data was saved successfully.\n");
                break;

            case '6':
                exist_system = true;
                printf("==Got it! The system will save your work now, please hold on...\n");
                save_file(USERS_DATA, head);
                printf("==OK, the data was saved successfully.\n");
                printf("==Goodbye %s %s\n", identity[user->USER_ROLE+5], user->name);
                break;
            default:
                printf("==Please enter the correct number!\n");
        }
    }

    return SUCCESS;
}

enum OPERATE grade_function(grade_head_p head, USER user){
    printf("=========================================================\n");
    printf("======================Grade Function=====================\n");
    printf("=========================================================\n");
    printf("==Welcome to the User Function! %s %s.\n", identity[user->USER_ROLE+5], user->name);
    _Bool exist_system = false;

    while (!exist_system){
        char choice = '0';
        printf("==What would you like to do next? \n");
        printf("\t1.Create a New Grade\t\t2.Query Grades\n");
        printf("\t3.Update Grade Information\t\t4.Delete Grade\n");
        printf("\t5.Back to the previous System\n");

        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case '1':
                printf("==Got it! \n");
                printf("==Moving to create a new grade now...\n");
                create_grade(head);
                break;
            case '2':
                printf("==Got it! \n");
                printf("==Moving to query grades now...\n");
                printf("==Do you want to query all users? (y/n) \n");
                char query_all = 'n';
                scanf("%c", &query_all);
                fflush(stdin);
                if (query_all == 'y'){
                    printf("==Alright, the system will query all grades' information...\n");
                    query_grade(head, TRUE_RES);
                }else query_grade(head, FALSE_RES);
                break;
            case '3':
                printf("==Got it! \n");
                printf("==Moving to update grades now...\n");
                update_grade(head);
                break;
            case '4':
                printf("==Got it! \n");
                printf("==Moving to delete grades now...\n");
                delete_grade(head);
                break;
            case '6':
                printf("==Saving...Please hold on...\n");
                save_file(GRADES_DATA, head);
                printf("==OK, the data was saved successfully.\n");
                break;
            case '5':
                exist_system = true;
                printf("==Got it! The system will save your work now, please hold on...\n");
                save_file(GRADES_DATA, head);
                printf("==OK, the data was saved successfully.\n");
                printf("==Goodbye %s %s\n", identity[user->USER_ROLE+5], user->name);
                break;
            default:
                printf("==Please enter the correct number!\n");
        }
    }

    return SUCCESS;
}
enum OPERATE class_function(class_head_p head, USER user, grade_head_p grade_h) {
    printf("=========================================================\n");
    printf("======================Class Function=====================\n");
    printf("=========================================================\n");
    printf("==Welcome to the User Function! %s %s.\n", identity[user->USER_ROLE+5], user->name);
    _Bool exist_system = false;

    while (!exist_system){
        char choice = '0';
        printf("==What would you like to do next? \n");
        printf("\t1.Create A New Class\t\t2.Query Class\n");
        printf("\t3.Update Class Information\t\t4.Delete Class\n");
        printf("\t6.Back to the previous System\n");

        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case '1':
                printf("==Got it! \n");
                printf("==Moving to create a new class now...\n");
                add_class(head, grade_h);
                break;
            case '2':
                printf("==Got it! \n");
                printf("==Moving to query class now...\n");
                printf("==Do you want to query all classes? (y/n) \n");
                char query_all = 'n';
                scanf("%c", &query_all);
                fflush(stdin);
                if (query_all == 'y'){
                    printf("==Alright, the system will query all classes' information...\n");
                    find_class(head, ALL);
                }else find_class(head, ONE);
                break;
            case '3':
                printf("==Got it! \n");
                printf("==Moving to update class now...\n");
                update_class(head, grade_h);
                break;
            case '4':
                printf("==Got it! \n");
                printf("==Moving to delete class now...\n");
                delete_class(head, grade_h);
                break;
            case '5':
                printf("==Saving...Please hold on...\n");
                save_file(CLASS_DATA, head);
                printf("==OK, the data was saved successfully.\n");
                break;

            case '6':
                exist_system = true;
                printf("==Got it! The system will save your work now, please hold on...\n");
                save_file(CLASS_DATA, head);
                printf("==OK, the data was saved successfully.\n");
                printf("==Goodbye %s %s\n", identity[user->USER_ROLE+5], user->name);
                break;
            default:
                printf("==Please enter the correct number!\n");
        }
    }
    return SUCCESS;
}
enum OPERATE student_function(stu_head_p head, USER user){
    return SUCCESS;
}
enum OPERATE teacher_function(teach_head_p head, USER user){
    return SUCCESS;
}