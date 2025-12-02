#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include "fitur.h"

int main() {
    initKursiLabel();
    memset(status, 0, sizeof(status));

    int menu;
    printf("=== PROGRAM BOOKING BIOSKOP ===\n");
    do {
        printf("\n--- MENU UTAMA ---\n");
        printf("1. Tampilkan kursi untuk sebuah film\n");
        printf("2. Cari kursi kosong\n");
        printf("3. Hitung jumlah kursi kosong\n");
        printf("4. Booking kursi\n");
        printf("5. Simpan status kursi ke file\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        if (scanf("%d", &menu) != 1) {
            printf("Input tidak valid!\n");
            while (getchar() != '\n');
            menu = -1;
            continue;
        }

        int fidx;
        switch (menu) {
            case 1:
                fidx = pilihFilm();
                if (fidx >= 0) tampilkanKursiFilm(fidx);
                break;
            case 2:
                fidx = pilihFilm();
                if (fidx >= 0) cariKursiKosongFilm(fidx);
                break;
            case 3:
                fidx = pilihFilm();
                if (fidx >= 0) {
                    int total = hitungKosongFilm(fidx);
                    printf("Total kursi kosong untuk '%s' = %d\n", filmNama[fidx], total);
                }
                break;
            case 4:
                fidx = pilihFilm();
                if (fidx >= 0) bookingKursiFilm(fidx);
                break;
            case 5:
                fidx = pilihFilm();
                if (fidx >= 0) simpanStatusKeFile(fidx);
                break;
            case 0:
                printf("Keluar...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (menu != 0);

    return 0;
}
