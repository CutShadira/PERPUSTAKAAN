#include "bubble_sort.h"

// Fungsi untuk mengurutkan data buku menggunakan algoritma Bubble Sort.
void bubbleSort(Buku **arr, int jumlah_buku, int kriteria, int arah) { // ** artinya arr adalah pointer ke pointer Buku.
    int i, j, ada_tukar;
    Buku *temp;
    // Perulangan utama untuk mengatur jumlah proses pengurutan.
    for (i = 0; i < jumlah_buku - 1; i++) {
        ada_tukar = 0;
        // Membandingkan dua data buku yang bersebelahan.
        for (j = 0; j < jumlah_buku - i - 1; j++) {
            if (harusTukar(arr[j], arr[j + 1], kriteria, arah)) {
            }
        }
    }
}