#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuanHoa(char s[]) {
    int i = 0, j = 0;
    while (s[i] == ' ') i++;
    while (s[i] != '\0') {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            i++;
            continue;
        }
        s[j++] = s[i++];
    }
    s[j] = '\0';

    for (i = 0; i < strlen(s); i++) {
        if (i == 0 || s[i - 1] == ' ') s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
}

int main() {
    FILE *f1, *f2;
    f1 = fopen("sinhvien.txt", "r");
    f2 = fopen("sinhvien_out.txt", "w");

    int n;
    fscanf(f1, "%d\n", &n);
    fprintf(f2, "%d\n", n);

    for (int i = 0; i < n; i++) {
        char s[100];
        fgets(s, sizeof(s), f1);
        chuanHoa(s);
        fputs(s, f2);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
