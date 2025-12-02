#include "define.h"

void initKursiLabel() {
    char row = 'A';
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sprintf(kursiLabel[i][j], "%c%d", row, j + 1);
        }
        row++;
    }
}