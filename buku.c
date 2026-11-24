#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "buku.h"
#include "algoritma/bubble_sort.h"
#include "algoritma/selection_sort.h"
#include "algoritma/insertion_sort.h"

// BAGIAN BANTUAN
// Mengambil tanggal hari ini
static void tanggalHariIni(char *hasil) {
    time_t sekarang = time(NULL);
    struct tm *waktu = localtime(&sekarang);

    strftime(hasil, 20, "%d-%m-%Y", waktu);
}

// Memeriksa apakah kata terdapat dalam teks
static int mengandung(const char *teks, const char *kata) {
    int i, j;

    for (i = 0; teks[i] != '\0'; i++) {
        j = 0;
        while (kata[j] != '\0' && teks[i + j] != '\0'
               && tolower((unsigned char) teks[i + j]) == tolower((unsigned char) kata[j])) {
            j++;
        }
        if (kata[j] == '\0') {
            return 1;
        }
    }
    return 0;
}
//Mencari transaksi peminjaman yang masih aktif
static int cariPinjamanAktif(const char *username, const char *ocaid) {
    int i;

    for (i = 0; i < jumlahPinjam; i++) {
        if (strcmp(dataPinjam[i].username, username) == 0
            && strcmp(dataPinjam[i].ocaid, ocaid) == 0
            && strcmp(dataPinjam[i].status, "DIPINJAM") == 0) {
            return i;
        }
    }
    return -1;
}
//Menentukan ID peminjaman berikutnya
static unsigned int idPinjamBerikutnya(void) {
    unsigned int terbesar = 0;
    int i;

    for (i = 0; i < jumlahPinjam; i++) {
        if (dataPinjam[i].id_peminjaman > terbesar) {
            terbesar = dataPinjam[i].id_peminjaman;
        }
    }
    return terbesar + 1;
}
//Mencetak garis horizontal
static void cetakGaris(int panjang) {
    int i;

    for (i = 0; i < panjang; i++) {
        putchar('-');
    }
    putchar('\n');
}
// BAGIAN KATALOG BUKU 
// Mencari posisi buku berdasarkan ID
int cariIndexBuku(const char *ocaid) {
    int i;

    for (i = 0; i < jumlahBuku; i++) {
        if (strcmp(dataBuku[i].ocaid, ocaid) == 0) {
            return i;
        }
    }
    return -1;
}

// Menambahkan buku ke katalog
int tambahBuku(Buku b) {
    if (cariIndexBuku(b.ocaid) != -1) {
        return 0;
    }
    if (!tambahBukuKeMemori(b)) {
        return 0;
    }
    simpanBuku();
    return 1;
}

// Menghapus buku dari katalog
int hapusBuku(int index) {
    int i;

    for (i = 0; i < jumlahPinjam; i++) {
        if (strcmp(dataPinjam[i].ocaid, dataBuku[index].ocaid) == 0
            && strcmp(dataPinjam[i].status, "DIPINJAM") == 0) {
            return 0;
        }
    }

    for (i = index; i < jumlahBuku - 1; i++) {
        dataBuku[i] = dataBuku[i + 1];
    }
    jumlahBuku--;
    simpanBuku();
    return 1;
}
// Menyiapkan dan mengurutkan daftar buku
Buku **siapkanKatalog(int hanyaTersedia, int *jumlah, int kriteria, int arah, int algoritma) {
    Buku **daftar;
    int i, n = 0;

    for (i = 0; i < jumlahBuku; i++) {
        if (!hanyaTersedia || dataBuku[i].stok > 0) {
            n++;
        }
    }
    *jumlah = 0;
    if (n == 0) {
        return NULL;
    }

    daftar = malloc(n * sizeof(Buku *));
    if (daftar == NULL) {
        return NULL;
    }

    n = 0;
    for (i = 0; i < jumlahBuku; i++) {
        if (!hanyaTersedia || dataBuku[i].stok > 0) {
            daftar[n] = &dataBuku[i];
            n++;
        }
    }

    if (algoritma == 1) {
        bubbleSort(daftar, n, kriteria, arah);
    } else if (algoritma == 2) {
        selectionSort(daftar, n, kriteria, arah);
    } else {
        insertionSort(daftar, n, kriteria, arah);
    }

    *jumlah = n;
    return daftar;
}
// Menampilkan header tabel buku
void cetakHeaderBuku(void) {
    printf("%-4s %-30s %-34s %-22s %-5s %-5s %-4s\n",
           "No", "ID (ocaid)", "Judul", "Pengarang", "Tahun", "Hal", "Stok");
    cetakGaris(110);
}
// Menampilkan satu baris informasi buku
void cetakBarisBuku(int no, const Buku *b) {
    printf("%-4d %-30.30s %-34.34s %-22.22s %-5d %-5d %-4d\n",
           no, b->ocaid, b->title, b->author, b->year, b->page_count, b->stok);
}
// Menampilkan detail lengkap buku
void cetakDetailBuku(const Buku *b) {
    printf("\nID        : %s\n", b->ocaid);
    printf("Judul     : %s\n", b->title);
    printf("Pengarang : %s\n", b->author);
    printf("Tahun     : %d\n", b->year);
    printf("Halaman   : %d\n", b->page_count);
    printf("Stok      : %d\n", b->stok);
    printf("Link      : %s\n", b->full_text_url);
}
// Mencari buku berdasarkan ID atau judul
int cariBuku(const char *kataKunci) {
    int i, ketemu = 0;

    for (i = 0; i < jumlahBuku; i++) {
        if (mengandung(dataBuku[i].ocaid, kataKunci)
            || mengandung(dataBuku[i].title, kataKunci)) {
            cetakDetailBuku(&dataBuku[i]);
            ketemu++;
        }
    }
    return ketemu;
}
// BAGIAN PEMINJAMAN
// Memproses transaksi peminjaman buku
int pinjamBuku(const char *username, const char *ocaid) {
    int idx = cariIndexBuku(ocaid);
    Peminjaman p;

    if (idx == -1) {
        return PINJAM_BUKU_TIDAK_ADA;
    }
    if (dataBuku[idx].stok <= 0) {
        return PINJAM_STOK_HABIS;
    }
    if (cariPinjamanAktif(username, ocaid) != -1) {
        return PINJAM_SUDAH_DIPINJAM;
    }

    p.id_peminjaman = idPinjamBerikutnya();
    snprintf(p.username, sizeof(p.username), "%s", username);
    snprintf(p.ocaid, sizeof(p.ocaid), "%s", ocaid);
    tanggalHariIni(p.tanggal_pinjam);
    snprintf(p.status, sizeof(p.status), "%s", "DIPINJAM");

    if (!tambahPinjamKeMemori(p)) {
        return PINJAM_GAGAL;
    }
    dataBuku[idx].stok--;

    simpanBuku();
    simpanPinjam();
    return PINJAM_OK;
}

//Memproses pengembalian buku
int kembalikanBuku(const char *username, const char *ocaid) {
    int idxPinjam = cariPinjamanAktif(username, ocaid);
    int idxBuku;

    if (idxPinjam == -1) {
        return 0;
    }
    snprintf(dataPinjam[idxPinjam].status, sizeof(dataPinjam[idxPinjam].status),
             "%s", "KEMBALI");

    idxBuku = cariIndexBuku(ocaid);
    if (idxBuku != -1) {
        dataBuku[idxBuku].stok++;
    }

    simpanBuku();
    simpanPinjam();
    return 1;
}