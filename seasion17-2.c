#include <stdio.h>

void nhapChuoi(char *chuoi) {
    printf("Nhap vao chuoi: ");
    fgets(chuoi, 100, stdin);
}

void inChuoi(const char *chuoi) {
    printf("Chuoi ban da nhap la: %s", chuoi);
}

int demChuCai(const char *chuoi) {
    int dem = 0;
    while (*chuoi) {
        if ((*chuoi >= 'A' && *chuoi <= 'Z') || (*chuoi >= 'a' && *chuoi <= 'z')) {
            dem++;
        }
        chuoi++;
    }
    return dem;
}

int demChuSo(const char *chuoi) {
    int dem = 0;
    while (*chuoi) {
        if (*chuoi >= '0' && *chuoi <= '9') {
            dem++;
        }
        chuoi++;
    }
    return dem;
}

int demKyTuDacBiet(const char *chuoi) {
    int dem = 0;
    while (*chuoi) {
        if (!((*chuoi >= 'A' && *chuoi <= 'Z') || (*chuoi >= 'a' && *chuoi <= 'z') || (*chuoi >= '0' && *chuoi <= '9'))) {
            dem++;
        }
        chuoi++;
    }
    return dem;
}

int main() {
    char chuoi[100];
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon) {
            case 1:
                nhapChuoi(chuoi);
                break;
            case 2:
                inChuoi(chuoi);
                break;
            case 3:
                printf("So luong chu cai trong chuoi la: %d\n", demChuCai(chuoi));
                break;
            case 4:
                printf("So luong chu so trong chuoi la: %d\n", demChuSo(chuoi));
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi la: %d\n", demKyTuDacBiet(chuoi));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (luaChon != 6);

    return 0;
}

