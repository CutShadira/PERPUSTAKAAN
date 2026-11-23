#ifndef MODELS_H 
#define MODELS_H

// Menentukan lokasi file penyimpanan data
#define FILE_BUKU "data/Books.txt"
#define FILE_USER "data/User.txt"
#define FILE_PINJAM "data/Peminjaman.txt"

// Stok default jika baris buku di file tidak punya kolom stok
#define STOK_AWAL 5

// Struktur untuk menyimpan seluruh informasi buku
typedef struct {
    char ocaid[64];
    char title[256];
    char author[256];
    int year;
    int page_count;
    char openlibrary_edition[32];
    char openlibrary_work[32];
    char full_text_url[256];
    int stok;
} Buku;

// Struktur untuk menyimpan informasi akun pengguna
typedef struct {
    char username[32];
    char password[32];
    char role[12];
} User;

// Struktur untuk menyimpan informasi transaksi peminjaman buku oleh pengguna
typedef struct {
    unsigned int id_peminjaman;
    char username[32];
    char ocaid[64];
    char tanggal_pinjam[20];
    char status[20];
} Peminjaman;