#include "define.h"

const char *filmNama[FILMS] = {
    "Avengers Endgame",
    "Wicked",
    "Pengabdi Setan"
};
const int filmStudio[FILMS] = {1, 2, 3};
const char *filmJam[FILMS] = {"13.20", "14.50", "16.00"};

char kursiLabel[ROWS][COLS][MAX_KODE_LEN];
int status[FILMS][ROWS][COLS];

int pilihFilm() {
    int pilihan;
    printf("\n=== PILIH FILM ===\n");
    for (int i = 0; i < FILMS; i++) {
        printf("%d. %s (Studio %d) - %s\n", i + 1, filmNama[i], filmStudio[i], filmJam[i]);
    }
    printf("Pilih film (1-%d): ", FILMS);
    if (scanf("%d", &pilihan) != 1) {
        printf("Input tidak valid!\n");
        while (getchar() != '\n');
        return -1;
    }
    if (pilihan < 1 || pilihan > FILMS) {
        printf("Pilihan film tidak valid\n");
        return -1;
    }
    return pilihan - 1;
}