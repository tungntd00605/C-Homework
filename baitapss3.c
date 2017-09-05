#include <stdio.h>
#include <ctype.h>
// In ra menu
void printmenu(){
    printf("1.Excute addtion\n2.Excute subtraction\n3.Excute multiplication\n4.Excute divination\n5.Exit\nPlease tell me what you want to do by enter the number:");
}
// tính tổng a + b
int plus(int a, int b){
    return a + b;
}
// tính hiệu a - b
int minus(int a, int b){
    return a - b;
}
// tính tích a*b
int multi(int a, int b){
    return a * b;
}
// chuyển a về dạng số thực (float) tính thương a/b và kiểm tra nếu b=0 thì nhập lại số b
float division(int a, int b){
    float c;
    c = a;
    return c / b;
}
// nhập số a
int inputa(){
    int a;
    printf("Enter number a: ");
    scanf("%d", &a);
    return a;
}
// nhập số b
int inputb(){
    int b;
    printf("Enter number b: ");
    scanf("%d", &b);
    if(b == 0){
        printf("The number b cannot be zero, please input another number \n");
        scanf("%d", &b);
    }
    return b;
}
// Nhập số yêu cầu chọn hành động
int inputx() {
    int x;
    scanf("%c", &x);
    // xét nếu x có phải là chữ và x ngoài khoảng 1-5
    if (!isdigit(x)){
        printf("This is not a number please try again");
        scanf("%d", &x);
    }
    if(x < 1 && x > 5){
        printf("This is not a correct command please try again");
        scanf("%d", &x);
    }
    return x;
}

int main() {
    int x, a, b;
    a = inputa();
    b = inputb();
    printmenu();
    x = inputx();
    while(x != 5){
        switch(x){
            case 1:
                printf("Sum of total: %d\n\n", plus(a, b));
                break;
            case 2:
                printf("Difference: %d\n\n", minus(a, b));
                break;
            case 3:
                printf("Product: %d\n\n", multi(a, b));
                break;
            case 4:
                printf("Quotient: %f\n\n", division(a, b));
                break;
            default:
                printf("");
        }
        printmenu();
        x = inputx();
    }
    return 0;
}