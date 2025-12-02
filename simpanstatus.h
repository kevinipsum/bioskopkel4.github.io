#include "define.h"

void simpanStatusKeFile(int filmIdx) {
    char filename[MAX_BUFFER];
    char safeName[50];
    int k = 0;
    for (size_t i = 0; filmNama[filmIdx][i] != '\0' && k < sizeof(safeName) - 1; i++) {
        char c = filmNama[filmIdx][i];
        if (c == ' ') safeName[k++] = '_';
        else safeName[k++] = c;
    }
    safeName[k] = '\0';
    snprintf(filename, sizeof(filename), "status_%s.txt", safeName);

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Gagal membuka %s untuk menulis.\n", filename);
        return;
    }

    fprintf(fp, "Status kursi untuk film: %s\n", filmNama[filmIdx]);
    fprintf(fp, "Format: A1[K] = kosong, A1[T] = terisi\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char kursiStr[8];
            snprintf(kursiStr, sizeof(kursiStr), "%s[%c]", kursiLabel[i][j], status[filmIdx][i][j] ? 'T' : 'K');
            fprintf(fp, "%-7s", kursiStr);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Status disimpan ke file: %s\n", filename);
}