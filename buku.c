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