//
// Created by TVD1104 on 9/12/2017.
//
#include <stdio.h>

main(){
    char name[30], email[50];
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("\nPlease enter your email: ");
    fgets(email, sizeof(email), stdin);
    writeToFile(name, email);
    readfromFile();
}
void writeToFile(char name[30], char email [50]){
    FILE *std;
    std = fopen("E:\\students.txt", "a");
    fprintf(std, "Students name : %s", name);
    fprintf(std, "Students email : %s", email);
    fclose(std);
}
void readfromFile(){
    char buff[100];
    int i = 1;
    FILE *std;
    std = fopen("E:\\students.txt", "r");
    while(fgets(buff, sizeof(buff), std)){
        printf("%d. %s", i, buff);
        i++;
    }
    fclose(std);
}