#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "auth.h"
#include "buku.h"
#include "algoritma/pembanding.h"

// Menentukan jumlah maksimal buku yang ditampilkan dalam satu halaman
#define PER_HALAMAN 20

// Menyimpan nama algoritma pengurutan dan kriteria yang tersedia
static const char *NAMA_ALGORITMA[] = {"", "Bubble Sort"};
static const char *NAMA_KRITERIA[] = {"", "ID Buku", "Judul", "Tahun Terbit", "Jumlah Halaman", "Stok"};