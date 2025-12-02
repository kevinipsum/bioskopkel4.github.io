#include "define.h"

void bookingKursiFilm(int filmIdx) {
    int jumlah;
    printf("Masukkan jumlah tiket yang ingin dibeli (1-%d): ", MAX_SEATS);
    if (scanf("%d", &jumlah) != 1 || jumlah < 1 || jumlah > MAX_SEATS) {
        printf("Jumlah tiket tidak valid\n");
        while (getchar() != '\n');
        return;
    }

    char kodeKursi[MAX_SEATS][MAX_KODE_LEN];
    int indices[MAX_SEATS][2];

    printf("Masukkan kode kursi (misal a1 c3 c4):\n");
    for (int i = 0; i < jumlah; i++) {
        printf("Kursi %d: ", i + 1);
        if (scanf("%3s", kodeKursi[i]) != 1) {
            printf("Input tidak valid\n");
            while (getchar() != '\n');
            return;
        }
        toUppercase(kodeKursi[i]);
        int r, c;
        if (!kodeToIndex(kodeKursi[i], &r, &c)) {
            printf("Kode kursi %s invalid\n", kodeKursi[i]);
            return;
        }
        if (status[filmIdx][r][c] == 1) {
            printf("Kursi %s sudah terisi\n", kodeKursi[i]);
            return;
        }
        indices[i][0] = r;
        indices[i][1] = c;
    }

    printf("Kursi dipilih: ");
    for (int i = 0; i < jumlah; i++) {
        printf("%s", kodeKursi[i]);
        if (i < jumlah - 1) printf(", ");
    }
    printf("\nKonfirmasi booking? (y/n): ");
    char konfir;
    scanf(" %c", &konfir);
    if (tolower(konfir) != 'y') {
        printf("Booking dibatalkan\n");
        return;
    }

    int totalHarga = jumlah * HARGA_TIKET;
    printf("Total harga: Rp %d\n", totalHarga);
    printf("Masukkan jumlah uang: Rp ");
    int bayar;
    if (scanf("%d", &bayar) != 1 || bayar < totalHarga) {
        printf("Uang tidak cukup\n");
        while (getchar() != '\n');
        return;
    }
    int kembalian = bayar - totalHarga;
    for (int i = 0; i < jumlah; i++) {
        status[filmIdx][indices[i][0]][indices[i][1]] = 1;
    }

    simpanTiketDanBill(filmIdx, kodeKursi, jumlah, bayar, kembalian);

    printf("Booking BERHASIL. Tiket tersimpan di tiket.txt\nKembalian: Rp %d\n", kembalian);
}