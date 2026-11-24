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
