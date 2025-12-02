#include "define.h"

int hitungKosongRekursif(int filmIdx, int row, int col) {
    if (row >= ROWS) return 0;
    if (col >= COLS) return hitungKosongRekursif(filmIdx, row + 1, 0);
    int count = (status[filmIdx][row][col] == 0) ? 1 : 0;
    return count + hitungKosongRekursif(filmIdx, row, col + 1);
}

int hitungKosongFilm(int filmIdx) {
    return hitungKosongRekursif(filmIdx, 0, 0);
}