#include <stdio.h>
#include <mem.h>

void printmenu() {
    printf("-----Menu-----\n");
    printf("1. Add student\n");
    printf("2. Show students profile\n");
    printf("3. Exit\n");
    printf("Please enter your choice:");
}

struct Profile {
    char name[30];
    char birthday[30];
    char phone[20];
} student;

void AddStudent() {
    // Add student's profile
    printf("Enter student's name:");
    fgets(student.name, sizeof(student.name), stdin);
    while (strlen(student.name) < 4) {
        fgets(student.name, sizeof(student.name), stdin);
        getchar();
    }
    while (strlen(student.name) > 15) {
        printf("The name is too long, please enter name's length between 4-15 characters:");
        fgets(student.name, sizeof(student.name), stdin);
    }
    printf("Enter student's birthday");
    fgets(student.birthday, sizeof(student.birthday), stdin);
    printf("Enter student's phone number:");
    fgets(student.phone, sizeof(student.phone), stdin);

    // Write to file
    FILE *pf;
    pf = fopen("profile.txt", "a");
    fprintf(pf, "Student's name: %s", student.name);
    fprintf(pf, "Student's birthday: %s", student.birthday);
    fprintf(pf, "Student's phone number: %s\n", student.phone);
    fclose(pf);
}

void ShowProfile(){
    char buff[100];
    FILE *pf;
    pf = fopen("profile.txt", "r");
    printf("All students profile:\n");
    while(fgets(buff, sizeof(buff), pf)){
        printf("%s", buff);
    }
    fclose(pf);
}

void main() {
    int choice;
    printmenu();
    scanf("%d", &choice);
    getchar();
    if (choice > 3 || choice < 1) {
        printf("This is not a correct action, please try again");
        scanf("%d", &choice);
        getchar();
    }
    while (choice != 3) {
        switch (choice) {
            case 1:
                AddStudent();
                break;
            case 2:
                ShowProfile();
                break;
            default:
                printf("This is not a correct action, please try again:");
        }
        printmenu();
        scanf("%d", &choice);
        getchar();
    }
}