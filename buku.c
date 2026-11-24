#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "buku.h"
#include "algoritma/bubble_sort.h"
#include "algoritma/selection_sort.h"
#include "algoritma/insertion_sort.h"

// BAGIAN BANTUAN
// Mengambil tanggal hari ini
static void tanggalHariIni(char *hasil) {
    time_t sekarang = time(NULL);
    struct tm *waktu = localtime(&sekarang);

    strftime(hasil, 20, "%d-%m-%Y", waktu);
}

// Memeriksa apakah kata terdapat dalam teks
static int mengandung(const char *teks, const char *kata) {
    int i, j;

    for (i = 0; teks[i] != '\0'; i++) {
        j = 0;
        while (kata[j] != '\0' && teks[i + j] != '\0'
               && tolower((unsigned char) teks[i + j]) == tolower((unsigned char) kata[j])) {
            j++;
        }
        if (kata[j] == '\0') {
            return 1;
        }
    }
    return 0;
}
//Mencari transaksi peminjaman yang masih aktif
static int cariPinjamanAktif(const char *username, const char *ocaid) {
    int i;

    for (i = 0; i < jumlahPinjam; i++) {
        if (strcmp(dataPinjam[i].username, username) == 0
            && strcmp(dataPinjam[i].ocaid, ocaid) == 0
            && strcmp(dataPinjam[i].status, "DIPINJAM") == 0) {
            return i;
        }
    }
    return -1;
}
//Menentukan ID peminjaman berikutnya
static unsigned int idPinjamBerikutnya(void) {
    unsigned int terbesar = 0;
    int i;

    for (i = 0; i < jumlahPinjam; i++) {
        if (dataPinjam[i].id_peminjaman > terbesar) {
            terbesar = dataPinjam[i].id_peminjaman;
        }
    }
    return terbesar + 1;
}
//Mencetak garis horizontal
static void cetakGaris(int panjang) {
    int i;

    for (i = 0; i < panjang; i++) {
        putchar('-');
    }
    putchar('\n');
}
