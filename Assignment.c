#include <stdio.h>
#include <mem.h>
#include <stdbool.h>

     // In ra menu
void PrintMenu() {
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
    bool isValidName = false;
    while (!isValidName) {
        printf("Enter student's name:");
        fgets(student.name, sizeof(student.name), stdin);
        int lengthName = strlen(student.name) - 1;
        if (lengthName < 3) {
            printf("The name is too short, please enter name's length between 3-15 characters\n");
        } else if (lengthName > 15) {
            printf("The name is too long, please enter name's length between 3-15 characters\n");
        } else {
            isValidName = true;
        }
    }
    printf("Enter student's birthday:");
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

    // Open file and print students profile
void ShowProfile() {
    char buff[100];
    FILE *pf;
    pf = fopen("profile.txt", "r");
    printf("All students profile:\n");
    while (fgets(buff, sizeof(buff), pf)) {
        printf("%s", buff);
    }
    fclose(pf);
}

void main() {
    int choice;
    PrintMenu();
    scanf("%d", &choice);
    fflush(stdin);
    while (choice != 3) {
        switch (choice) {
            case 1:
                AddStudent();
                break;
            case 2:
                ShowProfile();
                break;
            default:
                printf("This is not a correct action, please try again:\n");
        }
        PrintMenu();
        scanf("%d", &choice);
        fflush(stdin);
    }
}