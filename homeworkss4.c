#include <stdio.h>
#include <mem.h>

// Bài tập trên lớp buổi 4, thứ năm ngày 07/09/2017
char addstudent() {
    char ten[30];
    char ngaysinh[30];
    char phone[20];
    // Thêm tên sinh viên
    getchar();
    printf("Nhap vao ten sinh vien:");
    scanf("%[^\n]s", ten);                 // Lúc nhập tên và bấm enter thì enter bị coi như 1 ký tự và ký tự này ko đc đọc
    getchar();                             // nên sẽ cần 1 cái getchar() để "hứng" ký tự này ko cho nó bị đọc ở lệnh scanf ở dưới
    // Xét điều kiện về độ dài tên
    while (strlen(ten) < 4) {
        printf("Ten qua ngan, xin vui long nhap lai ten trong khoang 4-15 ky tu:");
        scanf("%[^\n]s", ten);
        getchar();
    }
    while (strlen(ten) > 15) {
        printf("Ten qua dai, xin vui long nhap lai ten trong khoang 4-15 ky tu:");
        scanf("%[^\n]s", ten);
        getchar();
    }

    // Thêm ngày tháng năm sinh
    printf("Nhap vao ngay thang nam sinh:");
    scanf("%[^\n]s", ngaysinh);
    getchar();

    // Thêm số điện thoại
    printf("Nhap so dien thoai:");
    scanf("%[^\n]s", phone);
    getchar();

    // In ra thong tin sinh vien và trở về menu chính
    printf("De in thong tin sinh vien bam Enter:");
    getchar();
    printf("Thong tin sinh vien:");
    printf("\nTen: %s", ten);
    printf("\nNgay thang nam sinh: %s", ngaysinh);
    printf("\nPhone: %s\n\n", phone);
    printf("Bam enter de tro ve menu:");
    getchar();
}

// In ra menu chính
void printmenu() {
    printf("-----Menu-----\n");
    printf("1. Them moi sinh vien\n");
    printf("2. Hien thi danh sach sinh vien\n");
    printf("3. Sua sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Thoat\n");
    printf("Nhap lua chon cua ban:");
}

int inputx() {
    int x;
    scanf("%d", &x);
    if (x < 1 || x > 5){
        printf("Ban da nhap lenh khong chinh xac, vui long nhap lai:");
        scanf("%d", &x);
    }
    return x;
}

int main() {
    int choice;
    printmenu();
    choice = inputx();
    while (choice != 5) {
        switch (choice) {
            case 1:
                addstudent();
                break;
            case 2:
            case 3:
            case 4:
                printf("Chuc nang nay chua duoc hoan thien, vui long thu lai sau\n\n");
                break;
            default:
                printf("Chuc nang nay chua duoc hoan thien, vui long thu lai sau\n\n");
        }
        printmenu();
        choice = inputx();
    }
    return 0;
}