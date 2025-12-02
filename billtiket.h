#include "define.h"

void simpanTiketDanBill(int filmIdx, char kodeKursi[][MAX_KODE_LEN], int jumlah, int bayar, int kembalian) {
    FILE *fp = fopen("tiket.txt", "a");
    if (!fp) {
        printf("Error membuka tiket.txt\n");
        return;
    }

    char tanggal[20];
    sekarangTanggal(tanggal, sizeof(tanggal));
    int totalHarga = jumlah * HARGA_TIKET;

    fprintf(fp, "==================== TIKET BIOSKOP ====================\n");
    fprintf(fp, "|| Film            : %-31s||\n", filmNama[filmIdx]);
    fprintf(fp, "|| Studio          : %-31d||\n", filmStudio[filmIdx]);
    fprintf(fp, "|| Jam             : %-31s||\n", filmJam[filmIdx]);
    fprintf(fp, "|| Tanggal         : %-31s||\n", tanggal);
    fprintf(fp, "|| Jumlah Tiket    : %-31d||\n", jumlah);
    fprintf(fp, "|| Harga per Tiket : Rp %-28d||\n", HARGA_TIKET);
    fprintf(fp, "|| Total Harga     : Rp %-28d||\n", totalHarga);
    fprintf(fp, "|| Bayar           : Rp %-28d||\n", bayar);
    fprintf(fp, "|| Kembalian       : Rp %-28d||\n", kembalian);

    char kursiStr[MAX_BUFFER];
    formatKursiRapi(kodeKursi, jumlah, kursiStr, sizeof(kursiStr));

    char *token = strtok(kursiStr, ",");
    int count = 0;
    fprintf(fp, "|| Kursi           : ");
    while (token) {
        while (*token == ' ') token++;
        fprintf(fp, "%s", token);
        count++;
        token = strtok(NULL, ",");
        if (token && count < 5) {
            fprintf(fp, ", ");
        } else {
            int padding = 35 - (count * 8);  
            if (padding < 0) padding = 0;
            for (int i = 0; i < padding; i++) fputc(' ', fp);
            fprintf(fp, "||\n");
            if (token) {
                fprintf(fp, "|| %-16s: ", "");
            }
            count = 0;
        }
    }
    fprintf(fp, "=======================================================\n\n");
    fclose(fp);
}