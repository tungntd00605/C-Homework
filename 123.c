//
// Created by tungntd00605 on 8/31/2017.
//

#include <stdio.h>
#include <ctype.h>

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
    if(b == 0){
        printf("The divisor cannot be zero, please input another number \n");
        scanf("%d", &b);
    }
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
    return b;
}

main() {
    int a, b;
    a = inputa();
    b = inputb();
    printf("Sum of total: %d\n", plus(a, b));
    printf("Difference: %d\n", minus(a, b));
    printf("Product: %d\n", multi(a, b));
    printf("Quotient: %f\n", division(a, b));
}
// còn phần xét nếu a,b có phải số hay là chuỗi nhưng chưa tìm được cách hợp lý để sử dụng với kiến thức từ session 6 trờ xuống