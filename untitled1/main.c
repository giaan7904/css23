#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char class[20];
    char dob[15];
    float gpa;
};

int compare(const void *a, const void *b) {return (*(struct Student*)b).gpa - (*(struct Student*)a).gpa;}

int main() {
    FILE *inputFile, *outputFile;
    struct Student students[100];
    int count = 0;


    inputFile = fopen("sv_in.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), inputFile)) {
        sscanf(line, "%[^,],%[^,],%[^,],%f", students[count].name, students[count].class, students[count].dob,&students[count].gpa);
        count++;
    }

    qsort(students, count, sizeof(struct Student), compare);

    outputFile = fopen("sv_out.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening file");
        return 1;
    }


    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%s,%s,%s,%.2f", students[i].name, students[i].class, students[i].dob, students[i].gpa);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
