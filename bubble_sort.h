// Header guard: mencegah file bubble_sort.h ter-include lebih dari sekali
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

// Memuat fungsi pembanding dan konstanta kriteria/arah pengurutan
#include "pembanding.h"

// Deklarasi fungsi untuk mengurutkan array pointer Buku menggunakan Bubble Sort
void bubbleSort(Buku **arr, int n, int kriteria, int arah);

// Akhir dari header guard
#endif