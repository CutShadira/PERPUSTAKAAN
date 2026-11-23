#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"

// Inisialisasi variabel global untuk menyimpan data buku, user, dan peminjaman di memori
Buku *dataBuku = NULL;
int jumlahBuku = 0;

User *dataUser = NULL;
int jumlahUser = 0;

Peminjaman *dataPinjam = NULL;
int jumlahPinjam = 0;