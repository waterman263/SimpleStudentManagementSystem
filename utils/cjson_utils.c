/**
 * @file cjson_utils.c
 * @author @Loritas
 * @brief cjson tools
 * @version 0.1
 * @date 2021-05-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "cjson_utils.h"

/**
 * @author Loritas
 * @brief parsing data from json
 *
 * @param json_data  origin string data
 * @param struct_pointer  target_head_pointer
 * @return tag for whether operate success
 */
enum OPERATE parsing_user_data(char *json_data, void *struct_pointer){
    users_head_p usersHeadP = (users_head_p) struct_pointer;
    USER temp;
    cJSON *root = cJSON_Parse(json_data);
    if (root == NULL){
        cJSON_Delete(root);
        return FAILED;
    }
    cJSON *users_item = cJSON_GetObjectItem(root, "users");
    if (users_item == NULL){
        cJSON_Delete(users_item);
        return FAILED;
    }
    int len = cJSON_GetArraySize(users_item);
    for (int i = 0; i < len; i++){
        cJSON *get_user = cJSON_GetArrayItem(users_item, i);
        USER user = (USER) malloc(sizeof(users));
        if (get_user == NULL){
            cJSON_Delete(get_user);
            return FAILED;
        }
        if (user == NULL){
            printf("Warning: System memory is low, please check your computer memory.\n");
            return FAILED;
        }

        cJSON *account = cJSON_GetObjectItem(get_user, "account");
        cJSON *work_number = cJSON_GetObjectItem(get_user, "work_number");
        cJSON *password = cJSON_GetObjectItem(get_user, "password");
        cJSON *user_role = cJSON_GetObjectItem(get_user, "user_role");
        cJSON *user_name = cJSON_GetObjectItem(get_user, "name");
        if (account == NULL || work_number == NULL || password == NULL || user_role == NULL || user_name == NULL){
            cJSON_Delete(account);
            cJSON_Delete(work_number);
            cJSON_Delete(password);
            cJSON_Delete(user_role);
            cJSON_Delete(user_name);
            return FAILED;
        }

        char *user_account = cJSON_Print(account);
        char *user_work_number = cJSON_Print(work_number);
        char *user_password = cJSON_Print(password);
        char *users_role = cJSON_Print(user_role);
        char *users_name = cJSON_Print(user_name);

//        printf("%s\n%s\n%s\n%s\n", user_account, user_password, user_work_number, users_role);

        char *check_1 = NULL;
        char *check_2 = NULL;

        user->account = strtoll(user_account, &check_1, 10);
        if (strcmp(check_1, "\0") != 0){
            printf("Warning: The data read is illegal, please check your data file!\n");
            printf("Target: users_data.json - account\n");
            return FAILED;
        }

        user->work_number = strtol(user_work_number, &check_2, 10);
        if (strcmp(check_2, "\0") != 0){
            printf("Warning: The data read is illegal, please check your data file!\n");
            printf("Target: users_data.json - work_number\n");
            return FAILED;
        }

        user->USER_ROLE = atoi(users_role);
        if (user->USER_ROLE > -2 || user->USER_ROLE < -5){
            printf("Warning: The data read is illegal, please check your data file!\n");
            printf("Target: users_data.json - user_role\n");
            return FAILED;
        }

        if (user->USER_ROLE == ADMINISTRATOR) usersHeadP->administrator_number++;

        int k = 0, l = 1;
        while (user_password[l] != '\"' && k < 33){
            user->password[k++] = user_password[l++];
        }
        if (user_password[l] != '\"'){
            printf("Warning: The data read is illegal, please check your data file!\n");
            printf("Target: users_data.json - password\n");
            return FAILED;
        }else user->password[k] = '\0';

        int m = 0, n = 1;
        while (users_name[n] != '\"' && m < 21){
            user->name[m++] = users_name[n++];
        }
        if (users_name[n] != '\"'){
            printf("Warning: The data read is illegal, please check your data file!\n");
            printf("Target: users_data.json - password\n");
            return FAILED;
        }else user->name[m] = '\0';

        if (i == 0){
            usersHeadP->next = user;
            user->next = NULL;
            temp = user;
        } else{
            temp->next = user;
            user->next = NULL;
            temp = temp->next;
        }

//        cJSON_Delete(account);
//        cJSON_Delete(work_number);
//        cJSON_Delete(password);
//        cJSON_Delete(user_role);
//        cJSON_Delete(get_user);
    }
    return SUCCESS;
}
//todo
enum OPERATE parsing_grade_data(char *json_data, void *struct_pointer){
    grade_head_p gradeHeadP = (grade_head_p) struct_pointer;
    grade_p temp_grade = gradeHeadP->next;

    cJSON *root = cJSON_Parse(json_data);

    return SUCCESS;
}


enum OPERATE save_user_data(char *target_data, void *struct_pointer){
    users_head_p usersHeadP = (users_head_p) struct_pointer;
    USER temp_user = usersHeadP->next;

    cJSON *root = NULL;
    cJSON *users_array = NULL;
    cJSON *users = NULL;
    cJSON *user_name = NULL;
    cJSON *user_work_number = NULL;
    cJSON *user_account = NULL;
    cJSON *user_role = NULL;
    cJSON *user_password = NULL;

    root = cJSON_CreateObject();

    users_array = cJSON_CreateArray();
    cJSON_AddItemToObject(root, "users", users_array);

    while (temp_user != NULL){
        users = cJSON_CreateObject();
        cJSON_AddItemToArray(users_array, users);

        user_name = cJSON_CreateString(temp_user->name);
        cJSON_AddItemToObject(users, "name", user_name);

        user_account = cJSON_CreateNumber(temp_user->account);
        cJSON_AddItemToObject(users, "account",user_account);

        user_password = cJSON_CreateString(temp_user->password);
        cJSON_AddItemToObject(users, "password", user_password);

        user_work_number = cJSON_CreateNumber(temp_user->work_number);
        cJSON_AddItemToObject(users, "work_number", user_work_number);

        user_role = cJSON_CreateNumber(temp_user->USER_ROLE);
        cJSON_AddItemToObject(users, "user_role", user_role);

        temp_user = temp_user->next;
    }

    //printf("\n%s\n", cJSON_Print(root));
    strcpy(target_data, cJSON_Print(root));
    return SUCCESS;
}

enum OPERATE save_grade_data(char *target_data, void *struct_pointer){
    char subjects[5][30] = {"ADVANCED_MATHEMATICS",
            "ENGLISH",
            "C_PROGRAM_LANGUAGE",
            "PHYSICAL_EDUCATION",
            "PYTHON"};

    grade_head_p gradeHeadP = (grade_head_p) struct_pointer;
    grade_p temp_grade = gradeHeadP->next;

    cJSON *root = NULL;
    cJSON *grade_array = NULL;
    cJSON *grades = NULL;
    cJSON *grades_number = NULL;
    cJSON *grades_subject_array = NULL;
    cJSON *grades_subject_score = NULL;
    cJSON *grades_aver_score = NULL;
    cJSON *grades_aver_gpa = NULL;
    cJSON *grades_uid = NULL;
    cJSON *grades_class = NULL;
    cJSON *grades_has_class = NULL;

    root = cJSON_CreateObject();

    grade_array = cJSON_CreateArray();
    cJSON_AddItemToObject(root, "grades", grade_array);

    while (temp_grade != NULL){
        grades = cJSON_CreateObject();
        cJSON_AddItemToArray(grade_array, grades);

        grades_uid = cJSON_CreateString(temp_grade->uid);
        cJSON_AddItemToObject(grades, "uid", grades_uid);

        grades_number = cJSON_CreateNumber(temp_grade->grade_number);
        cJSON_AddItemToObject(grades, "grade_number", grades_number);

        grades_class= cJSON_CreateNumber(temp_grade->class_total);
        cJSON_AddItemToObject(grades, "class_total", grades_class);

        grades_aver_score = cJSON_CreateNumber(temp_grade->general_aver_score);
        cJSON_AddItemToObject(grades, "average_score", grades_aver_score);

        grades_aver_gpa = cJSON_CreateNumber(temp_grade->general_aver_gpa);
        cJSON_AddItemToObject(grades, "average_gpa", grades_aver_gpa);

        grades_subject_array = cJSON_CreateArray();
        cJSON_AddItemToObject(grades, "subject_score", grades_subject_array);
        for (int i = 0; i < 5; i++){
            grades_subject_score = cJSON_CreateNumber(temp_grade->subject_aver[i][0]);
            cJSON_AddItemToObject(grades_subject_array, subjects[i], grades_subject_score);
        }

        grades_has_class = cJSON_CreateNumber(temp_grade->HAS_CLASSES_INPUT);
        cJSON_AddItemToObject(grades, "has_class_input", grades_has_class);

        temp_grade = temp_grade->next;
    }

    //printf("\n%s\n", cJSON_Print(root));
    strcpy(target_data, cJSON_Print(root));
    return SUCCESS;
}

enum OPERATE save_class_data(char *target_data, void *struct_pointer){
    users_head_p usersHeadP = (users_head_p) struct_pointer;
    USER temp_user = usersHeadP->next;

    cJSON *root = NULL;
    cJSON *users_array = NULL;
    cJSON *users = NULL;
    cJSON *user_name = NULL;
    cJSON *user_work_number = NULL;
    cJSON *user_account = NULL;
    cJSON *user_role = NULL;
    cJSON *user_password = NULL;

    root = cJSON_CreateObject();

    users_array = cJSON_CreateArray();
    cJSON_AddItemToObject(root, "users", users_array);

    while (temp_user != NULL){
        users = cJSON_CreateObject();
        cJSON_AddItemToArray(users_array, users);

        printf("%s ", temp_user->name);
        user_name = cJSON_CreateString(temp_user->name);
        cJSON_AddItemToObject(users, "name", user_name);

        printf("%lld ", temp_user->account);
        char account[12];
        char *temp_account = account;
        lltoa(temp_user->account, temp_account, 10);
        user_account = cJSON_CreateNumber(temp_user->account);
        cJSON_AddItemToObject(users, "account",user_account);

        printf("%s ", temp_user->password);
        user_password = cJSON_CreateString(temp_user->password);
        cJSON_AddItemToObject(users, "password", user_password);

        printf("%ld ", temp_user->work_number);
        user_work_number = cJSON_CreateNumber(temp_user->work_number);
        cJSON_AddItemToObject(users, "work_number", user_work_number);

        printf("%d ", temp_user->USER_ROLE);
        user_role = cJSON_CreateNumber(temp_user->USER_ROLE);
        cJSON_AddItemToObject(users, "user_role", user_role);

        temp_user = temp_user->next;
    }

    //printf("\n%s\n", cJSON_Print(root));
    strcpy(target_data, cJSON_Print(root));
    return SUCCESS;
}
enum OPERATE save_student_data(char *target_data, void *struct_pointer){
    users_head_p usersHeadP = (users_head_p) struct_pointer;
    USER temp_user = usersHeadP->next;

    cJSON *root = NULL;
    cJSON *users_array = NULL;
    cJSON *users = NULL;
    cJSON *user_name = NULL;
    cJSON *user_work_number = NULL;
    cJSON *user_account = NULL;
    cJSON *user_role = NULL;
    cJSON *user_password = NULL;

    root = cJSON_CreateObject();

    users_array = cJSON_CreateArray();
    cJSON_AddItemToObject(root, "users", users_array);

    while (temp_user != NULL){
        users = cJSON_CreateObject();
        cJSON_AddItemToArray(users_array, users);

        printf("%s ", temp_user->name);
        user_name = cJSON_CreateString(temp_user->name);
        cJSON_AddItemToObject(users, "name", user_name);

        printf("%lld ", temp_user->account);
        char account[12];
        char *temp_account = account;
        lltoa(temp_user->account, temp_account, 10);
        user_account = cJSON_CreateNumber(temp_user->account);
        cJSON_AddItemToObject(users, "account",user_account);

        printf("%s ", temp_user->password);
        user_password = cJSON_CreateString(temp_user->password);
        cJSON_AddItemToObject(users, "password", user_password);

        printf("%ld ", temp_user->work_number);
        user_work_number = cJSON_CreateNumber(temp_user->work_number);
        cJSON_AddItemToObject(users, "work_number", user_work_number);

        printf("%d ", temp_user->USER_ROLE);
        user_role = cJSON_CreateNumber(temp_user->USER_ROLE);
        cJSON_AddItemToObject(users, "user_role", user_role);

        temp_user = temp_user->next;
    }

    //printf("\n%s\n", cJSON_Print(root));
    strcpy(target_data, cJSON_Print(root));
    return SUCCESS;
}