#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 10
#define FILMS 3
#define MAX_KODE_LEN 4
#define MAX_BUFFER 256
#define HARGA_TIKET 35000
#define MAX_SEATS 50

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
