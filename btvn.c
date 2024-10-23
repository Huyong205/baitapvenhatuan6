#include <stdio.h>

#define MAX_YEAR 5 // Số năm từ 1920 đến 1970
#define START_YEAR 1920

struct element {
    int soNguoiSinh;
    int year;
};

typedef struct element element;

// Hàm hoán đổi 
void swap(element *a, element *b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

// Sắp xếp nổi bọt
void bubbleSort(element arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].soNguoiSinh > arr[j + 1].soNguoiSinh) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Hàm tìm kiếm nhị phân
int binarySearch(element arr[], int l, int r, int x) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m].soNguoiSinh == x) {
            return m;
        }
        else if (arr[m].soNguoiSinh < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    element population[MAX_YEAR];

    // Input
    printf("Nhap so luong nguoi sinh ra cho tung nam tu 1920 den 1970:\n");
    for (int i = 0; i < MAX_YEAR; i++) {
        printf("Nam %d: ", START_YEAR + i);
        scanf("%d", &population[i].soNguoiSinh);
        population[i].year = START_YEAR + i;
    }

    // Tìm năm có số lượng người sinh lớn nhất và nhỏ nhất
    int maxYear = 0, minYear = 0;
    for (int i = 1; i < MAX_YEAR; i++) {
        if (population[i].soNguoiSinh > population[maxYear].soNguoiSinh) {
            maxYear = i;
        }
        if (population[i].soNguoiSinh < population[minYear].soNguoiSinh) {
            minYear = i;
        }
    }

    printf("Nam co so luong nguoi sinh lon nhat: %d (%d nguoi)\n", population[maxYear].year, population[maxYear].soNguoiSinh);
    printf("Nam co so luong nguoi sinh nho nhat: %d (%d nguoi)\n", population[minYear].year, population[minYear].soNguoiSinh);

    // Sắp xếp mảng
    bubbleSort(population, MAX_YEAR);

    // Tìm các năm có cùng số lượng người sinh
    printf("Cac nam co cung so luong nguoi sinh:\n");
    for (int i = 0; i < MAX_YEAR; i++) {
        for (int j = i + 1; j < MAX_YEAR; j++) {
            if (population[i].soNguoiSinh == population[j].soNguoiSinh) {
                printf("%d %d\n", population[i].year, population[j].year);
            }
        }
    }

    return 0;
}
