#ifndef BUKU_H
#define BUKU_H

#include "models.h"

#define PINJAM_OK 0
#define PINJAM_BUKU_TIDAK_ADA 1
#define PINJAM_STOK_HABIS 2
#define PINJAM_SUDAH_DIPINJAM 3
#define PINJAM_GAGAL 4

//BAGIAN KATALOG BUKU
int cariIndexBuku(const char *ocaid);
int tambahBuku(Buku b);
int hapusBuku(int index);

//Menyiapkan dan mengurutkan daftar buku
Buku **siapkanKatalog(int hanyaTersedia, int *jumlah, int kriteria, int arah, int algoritma);

void cetakHeaderBuku(void);
void cetakBarisBuku(int no, const Buku *b);
void cetakDetailBuku(const Buku *b);
//Mencari buku berdasarkan ID atau judul
int cariBuku(const char *kataKunci);

//BAGIAN PEMINJAMAN
//Memproses peminjaman dan pengembalian buku
int pinjamBuku(const char *username, const char *ocaid);
int kembalikanBuku(const char *username, const char *ocaid);

//Menampilkan daftar transaksi peminjaman
int tampilPinjaman(const char *username, int hanyaAktif);

#endif