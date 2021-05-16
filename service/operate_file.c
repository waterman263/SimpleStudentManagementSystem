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

enum OPERATE_FILE open_file(enum FILE_TYPE file_type){
    char *path;
    if (file_type == USERS_DATA){
        path = USER_DATA;
    }

    FILE *file_check = fopen(path, "r");
    if (file_check == NULL){
        printf("Warning: The system data file is missing."
               " A new data file will be created. Please pay attention to the data problem.\n");
        fclose(file_check);
        FILE *file = fopen(path, "w");
        fclose(file);
    } else if (read_file_data(file_type, file_check) != SUCCESS){
            printf("Warning: an error occurred while the system was reading data."
                    " This will cause the system to create a new file and clear the old file.\n");
            printf("Press any key to continue.");
            fclose(file_check);
            getchar();
            FILE *file = fopen(path, "w");
            fclose(file);
    } else{
        fclose(file_check);
    }
    return SUCCESS;
}

enum OPERATE_FILE read_file_data(enum FILE_TYPE file_type, FILE *fp){

    return SUCCESS;
}

