#include <ctype.h>
#include "pembanding.h"

// Membandingkan dua string tanpa membedakan huruf besar/kecil (case-insensitive).
// Return: negatif jika a < b, 0 jika sama, positif jika a> b.
int bandingkanTeks(const char *a, const char *b) {
    // Lanjutkan selama kedua a < b, 0 jika sama, positif jka a > b.
    while (*a != '\0' && *b != '\0') {
        // Ubah karakter ke huruf kecil dulu agar 'A' dan 'a' dianggap sama.
        // Cast ke unsigned char supaya aman untuk tolower()
        int x = tolower((unsigned char) *a);
        int y = tolower((unsigned char) *b);

        //  jika ada karakter yang berbeda, selisihnya jadi hashil perbandingan
        if (x != y) {
            return x - y;
        }
        // Karakter sama, lanjut ke karakter berikutnya
        a++;
        b++;
    }
    // Salah satu string sudah habis (atau keduanya).
    // Bandingkan karakter terakhir: string yang lebih pendek dianggap lebih kecil
    return tolower((unsigned char) *a) - tolower((unsigned char) *b);
}

// Hasil negatif: a lebih kecil dari b, positif: a lebih besar
// Membandingkan dua buku berdasarkan kriteria pengurutan yang dipilih.
// Fungsi ini hanya dipakai di file ini (static).
static int bandingkan(const Buku *a, const Buku *b, int kriteria) {
    switch (kriteria) {
        case URUT_ID:
            // Bandingkan ID (ocaid) sebagai teks
            return bandingkanTeks(a->ocaid, b->ocaid);
        case URUT_JUDUL:
            // Bandingkan judul sebagai teks
            return bandingkanTeks(a->title, b->title);
        case URUT_TAHUN:
            // Bandingkan tahun terbit (angka)
            return a->year - b->year;
        case URUT_HALAMAN:
            // Bandingkan jumlah halaman(angka)
            return a->page_count - b->page_count;
        case URUT_STOK:
            // Bandingkan jumlah stok (angka)
            return a->stok - b->stok;

        // jika a - b hasilnya negatif, maka a lebih kecil dari b, artinya tidak perlu ditukar
        // jika a - b hasilnya positif, maka a lebih besar dari b, artinya perlu ditukar
    }
    //Kriteria tidak dikenal: anggap kedua buku sama 
    return 0;
}