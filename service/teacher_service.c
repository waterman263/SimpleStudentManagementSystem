#include "serviceHead/teacher_service.h"
teache_head_p initial_Teacher_List(){
    teache_head_p head_point = (teach_head_p)malloc(sizeof(teacher_head_p));

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
teacher_p create_teacher(teach_head_p head, enum BOOLEAN_USE HAS_MAX_CLASSES) {

    if (head == NULL) {
        printf("An unexpected error has been created,");
        printf(" please save your work and exit this program.\n");
        return NULL;
    }

    teacher_p temp_teacher = head->next;
    teacher_p new_teacher = (teacher_p) malloc(sizeof(teacher));
    if (new_teacher == NULL) {
        printf("Warning: Your computer has not enough free memory,");
        printf("Please save your work and exit this program.\n");
        return NULL;
    }

    new_teacher->next = NULL;
    new_teacher = set_teacher(new_teacher, head, HAS_CLASSES_INPUT);
    while (temp_teacher->next != NULL) {
        temp_teacher = temp_teacher->next;
    }

    temp_teacher->next = new_teacher;
    printf("That's alright.Returning to the main menu\n");
    return new_teacher;
}
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
    while (true) {
        fgets(get_name, 20, stdin);
        fflush(stdin);
        int i = 0;
        while (*get_name != '\n') {
            teacher->name[i] = *get_name;
            get_name++;
            i++;
        }
        name[i] = '\0';
    }

    printf("Please enter your work number\n");
    fgets(number, 9, stdin);
    fflush(stdin);
    while (true){
        if(check_string(ACCOUNT, work_number) == SUCCESS && atol(work_number) > 0){
            printf("Enter successfully\n Please press any key to continue\n");
            getchar();
            break;
        }else{
            printf("The number you input must be a 9-digit number. \nPlease enter again!\n");
            fgets(get_number, 9, stdin);
            fflush(stdin);
        }
    }
    teacher->work_number = atol(work_number);

    printf("Please enter your email\n");
    fgets(Email,30,stdin);
    fflush(stdin);
    strcpy(teacher->email, email);

    printf("Please enter your cell-phone number\n");
    fgets(phone_number,11,stdin);
    fflush(stdin);
    while (true){
        if(check_string(ACCOUNT, cell_phone) == SUCCESS && strlen(cell_phone) == 11){
            printf("Enter successfully\n Please press any key to continue\n");
            getchar();
            break;
        }else{
            printf("The number you input must be a 11-digit number. \nPlease enter again!\n");
            fgets(phone_number, 11, stdin);
            fflush(stdin);
        }
    }
    strcpy(teacher->phone_number, cell_phone);

    while(true) {
        printf("Please enter the subject you teach\n");
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
                teacher->subject = PYHTON;
                break;
            default:
                printf("Please input a legal serial.\n");
                break;
        }
    }
    create_uid(char *uid);
    strcpy(teacher->uid, classes_uid);
    return teacher;
}
void query_class(teacher_p teacher, class_head_p head){
    if(head == NULL)
    {
        printf("Error press any key to exit\n")
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


    while (true){
        if(strcmp(class->uid, teacher->classes_uid) == 0)
        break;
        class = class->next;
    }

    printf("The class number %ld\n", class->class_number);
    for(int i =0;i < 5;i++)
    {
        printf("The class %d subject aver %f\n" ,i+1, class->subject_aver[i][0] );
    }
    printf("The class general aver %f\n", class->general_aver);
    printf("The class general gpa %f\n", class->general_gpa);
}




