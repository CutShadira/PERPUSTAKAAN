// Header guard: mencegah file ini ter-include lebih dari sekali  
#ifndef PEMBANDING_H
#define PEMBANDING_H

// Memuat definisi struct Buku dan data model lainnya
#include "../models.h"

// kriteria pengurutan
// Kode angka untuk menetukan buku diurutkan berdasarkan apa
#define URUT_ID 1       // urut berdasarkan ID (ocaid)
#define URUT_JUDUL 2    // urut berdasarkan judul
#define URUT_TAHUN 3    // urut berdasarkan tahun terbit
#define URUT_HALAMAN 4  // urut berdasarkan jumlah halaman
#define URUT_STOK 5     // urut berdasarkan jumlah stok

// arah pengurutan
// kode angka untuk menentukan urutan naik atau turun
#define NAIK 1  // ascendng (kecil ke besar, A ke Z)
#define TURUN 2 // descending (besar ke kecil, Z ke A)

// Akhir dari header guard
#endif