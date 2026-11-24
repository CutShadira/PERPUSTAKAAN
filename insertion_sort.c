#include "insertion_sort.h"


void insertionSort(Buku **arr, int jumlah_buku, int kriteria, int arah) {

    int i, j;
    Buku *kunci;

    // Mengurutkan buku mulai dari indeks kedua
        for (i = 1; i < jumlah_buku; i++) {

        // Menyimpan buku yang akan dipindahkan
        kunci = arr[i];
        j = i - 1;

        // Menggeser buku yang posisinya belum sesuai
        while (j >= 0 && harusTukar(arr[j], kunci, kriteria, arah)) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Menempatkan buku pada posisi yang tepat
        arr[j + 1] = kunci;
    }
}