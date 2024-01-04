#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ten[50];
    char lop[10];
    char ngaySinh[15];
    float gpa;
} SinhVien;

int compare(const void *a, const void *b) {
    SinhVien *sv1 = (SinhVien *)a;
    SinhVien *sv2 = (SinhVien *)b;
    if (sv1->gpa < sv2->gpa) return 1;
    if (sv1->gpa > sv2->gpa) return -1;
    return 0;
}

int main() {
    FILE *fileIn, *fileOut;
    SinhVien sv[100];
    int i = 0;
    char buffer[100];

    fileIn = fopen("sinhvien.txt", "r");
    if (fileIn == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buffer, 100, fileIn)) {
        sscanf(buffer, "%[^,],%[^,],%[^,],%f", sv[i].ten, sv[i].lop, sv[i].ngaySinh, &sv[i].gpa);
        i++;
    }
    fclose(fileIn);

    int n = i;

    qsort(sv, n, sizeof(SinhVien), compare);

    fileOut = fopen("sinhvien_out.txt", "w");
    if (fileOut == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(fileOut, "%s,%s,%s,%.2f", sv[i].ten, sv[i].lop, sv[i].ngaySinh, sv[i].gpa);
    }
    fclose(fileOut);

    return 0;
}