#include "define.h"

void tampilkanKursiFilm(int filmIdx) {
    printf("\n== Kursi untuk film: %s (Studio %d, Jam %s) ==\n",
           filmNama[filmIdx], filmStudio[filmIdx], filmJam[filmIdx]);
    for (int i = 0; i < ROWS; i++) {
        printf("%c: ", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            char buf[8];
            snprintf(buf, sizeof(buf), "%s[%c]", kursiLabel[i][j], status[filmIdx][i][j] ? 'T' : 'K');
            printf("%-7s", buf);
        }
        printf("\n");
    }
}