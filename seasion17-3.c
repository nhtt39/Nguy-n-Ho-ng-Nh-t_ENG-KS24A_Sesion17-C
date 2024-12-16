#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char *chuoi) {
    printf("Nhap vao chuoi: ");
    fgets(chuoi, 100, stdin); 
}

void inChuoiDaoNguoc(char *chuoi) {
    int n = strlen(chuoi);
    printf("Chuoi dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%c", chuoi[i]);
    }
    printf("\n");
}

int demSoLuongTu(char *chuoi) {
    int dem = 0;
    int i = 0;
    
    while (chuoi[i] == ' ' || chuoi[i] == '\t') {
        i++;
    }
    
    while (chuoi[i] != '\0') {
        if (chuoi[i] == ' ' || chuoi[i] == '\t') {
            dem++;
            while (chuoi[i] == ' ' || chuoi[i] == '\t') {
                i++;
            }
        } else {
            i++;
        }
    }

    if (i > 0 && chuoi[i-1] != ' ' && chuoi[i-1] != '\t') {
        dem++;
    }
    
    return dem;
}

void soSanhChuoi(char *chuoi) {
    char chuoiKhac[100];
    printf("Nhap vao chuoi khac de so sanh: ");
    fgets(chuoiKhac, 100, stdin);

    if (strlen(chuoi) < strlen(chuoiKhac)) {
        printf("Chuoi khac dai hon chuoi ban dau.\n");
    } else if (strlen(chuoi) > strlen(chuoiKhac)) {
        printf("Chuoi khac ngan hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void inHoaChuoi(char *chuoi) {
    printf("Chuoi in hoa: ");
    while (*chuoi) {
        putchar(toupper(*chuoi));
        chuoi++;
    }
    printf("\n");
}

void noiChuoi(char *chuoi) {
    char chuoiKhac[100];
    printf("Nhap vao chuoi khac de them vao chuoi ban dau: ");
    fgets(chuoiKhac, 100, stdin);

    strcat(chuoi, chuoiKhac); 
    printf("Chuoi sau khi them: %s\n", chuoi);
}

int main() {
    char chuoi[200];
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar(); 

        switch (luaChon) {
            case 1:
                nhapChuoi(chuoi);
                break;
            case 2:
                inChuoiDaoNguoc(chuoi);
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", demSoLuongTu(chuoi));
                break;
            case 4:
                soSanhChuoi(chuoi);
                break;
            case 5:
                inHoaChuoi(chuoi);
                break;
            case 6:
                noiChuoi(chuoi);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (luaChon != 7);
    return 0;
}

