#include "define.h"

void cariKursiKosongFilm(int filmIdx) {
    printf("\n== Kursi kosong untuk film: %s ==\n", filmNama[filmIdx]);
    int adaKosong = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (status[filmIdx][i][j] == 0) {
                printf("%s ", kursiLabel[i][j]);
                adaKosong = 1;
            }
        }
        printf("\n");
    }
    if (!adaKosong) {
        printf("Tidak ada kursi kosong.\n");
    }
}