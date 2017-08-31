//
// Created by tungntd00605 on 8/31/2017.
//

#include <stdio.h>
int plus(int a, int b){
    return a + b;
}
int minus(int a, int b){
    return a - b;
}
int multi(int a, int b){
    return a * b;
}

int divide(int a, int b){
    if(b == 0){
        printf("The divisor cannot be zero, please input another number \n");
        scanf("%d", &b);
    }
        return a / b;
}
main() {
    int a, b;
    printf("Nhap vao so a: ");
    scanf("%d", &a);
    printf("Nhap vao so b: ");
    scanf("%d", &b);
    printf("Tong hai so: %d\n", plus(a, b));
    printf("Hieu hai so: %d\n", minus(a, b));
    printf("Tich hai so: %d\n", multi(a, b));
    printf("Thuong hai so: %d\n", divide(a, b));
}