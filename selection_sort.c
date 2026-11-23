#include "selection_sort.h"

// Mengurutkan buku menggunakan metode Selection Sort.
void selectionSort(Buku **arr, int jumlah_buku, int kriteria, int arah)
{
    int i, j, terpilih;
    Buku *temp;

    // Mencari data yang paling tepat untuk setiap posisi.
    for (i = 0; i < jumlah_buku - 1; i++)
    {
        terpilih = i;

        // Mencari data terkecil atau terbesar dari sisa data.
        for (j = i + 1; j < jumlah_buku; j++)
        {
            if (harusTukar(arr[terpilih], arr[j], kriteria, arah))
            {
                terpilih = j;
            }
        }

        // Menukar data jika ditemukan posisi yang lebih tepat.
        if (terpilih != i)
        {
            temp = arr[i];
            arr[i] = arr[terpilih];
            arr[terpilih] = temp;
        }
    }
}