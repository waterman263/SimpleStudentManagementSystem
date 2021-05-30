/**
 * @file operate_file.c
 * @author @Loritas
 * @brief implement operate_file.h
 * @version 0.1
 * @date 2021-03-14
 *
 * @copyright Copyright (c) 2021
 * 
 */

#include "serviceHead/operate_file.h"


/**
 * @author Loritas
 * @brief read data from json
 * @date 2021-5-16
 *
 * @param file_type  target struct json type
 * @param struct_pointer  target struct head pointer
 * @return whether the operate success
 */
enum OPERATE open_file(enum FILE_TYPE file_type, void *struct_pointer){
    char *path;
    if (file_type == USERS_DATA){
        path = USER_DATA;
    }

    if (file_type == GRADES_DATA){
        path = GRADE_DATA;
    }

    FILE *file_check = fopen(path, "rt");
    if (file_check == NULL){
        printf("Warning: The system data file is missing."
               " A new data file will be created. Please pay attention to the data problem.\n");
        fclose(file_check);
        FILE *file = fopen(path, "wt");
        fclose(file);
        return FAILED;
    } else {
        char json[1001000], temp[101];

        while (fgets(temp, 100, file_check)){
            // printf("%s", temp);
            strcat(json, temp);
        }
        // printf("%s", json);

        fclose(file_check);
        if (read_file_data(file_type, json, struct_pointer) != SUCCESS){
            printf("Warning: an error occurred while the system was reading data."
                   " This will cause the system to create a new file and clear the old file.\n");
            printf("Press any key to continue.\n");
            getchar();
            FILE *file = fopen(path, "wt");
            fclose(file);
            return FAILED;
        }
    }

    return SUCCESS;
}

enum OPERATE save_file(enum FILE_TYPE file_type, void *struct_pointer){
    char *path;
    if (file_type == USERS_DATA){
        path = USER_DATA;
    }

    if (file_type == GRADES_DATA){
        path = GRADE_DATA;
    }

    char data[1001000];
    char *target_data = data;
    FILE *file = fopen(path, "wt");

    save_file_data(file_type, target_data, struct_pointer);
    fputs(data, file);

    fclose(file);

    return SUCCESS;
}

enum OPERATE read_file_data(enum FILE_TYPE file_type, char *json_data, void *struct_pointer){
    if (file_type == USERS_DATA) return parsing_users_data(json_data, struct_pointer);

    else return FAILED;
}

enum OPERATE parsing_users_data(char *json_data, void *struct_pointer){
    return parsing_user_data(json_data, struct_pointer);
}

enum OPERATE parsing_grades_data(char *json_data, void *struct_pointer){
    return parsing_grade_data(json_data, struct_pointer);
}

enum OPERATE save_file_data(enum FILE_TYPE file_type, char  *target_data, void *struct_pointer){
    if (file_type == USERS_DATA) return save_users_data(target_data, struct_pointer);
    if (file_type == GRADES_DATA) return save_grades_data(target_data, struct_pointer);

    else return FAILED;
}

enum OPERATE save_users_data(char *target_data, void *struct_pointer){
    return save_user_data(target_data, struct_pointer);
}

enum OPERATE save_grades_data(char *target_data, void *struct_pointer){
    return save_grade_data(target_data, struct_pointer);
}

