#include <stdio.h>
#include <stdbool.h>

void nhapMang(int *arr, int *n) {
    printf("Nhap vao so phan tu: ");
    scanf("%d", n);
    
    printf("Nhap vao cac phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inSoChan(int *arr, int n) {
    printf("Cac phan tu la so chan:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void inSoNguyenTo(int *arr, int n) {
    printf("Cac phan tu la so nguyen to:\n");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void daoNguocMang(int *arr, int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    printf("Mang sau khi dao nguoc:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepTangDan(int *arr, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep tang dan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepGiamDan(int *arr, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep giam dan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void timKiemPhanTu(int *arr, int n, int x) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d ton tai tai vi tri %d.\n", x, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Phan tu %d khong ton tai trong mang.\n", x);
    }
}

int main() {
    int arr[100];
    int n, luaChon, phanTu;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   5.1 Tang dan\n");
        printf("   5.2 Giam dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inSoChan(arr, n);
                break;
            case 3:
                inSoNguyenTo(arr, n);
                break;
            case 4:
                daoNguocMang(arr, n);
                break;
            case 5:
                printf("Chon phuong an sap xep:\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon cua ban: ");
                int chonSapXep;
                scanf("%d", &chonSapXep);
                if (chonSapXep == 1) {
                    sapXepTangDan(arr, n);
                } else if (chonSapXep == 2) {
                    sapXepGiamDan(arr, n);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 6:
                printf("Nhap vao phan tu can tim: ");
                scanf("%d", &phanTu);
                timKiemPhanTu(arr, n, phanTu);
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

