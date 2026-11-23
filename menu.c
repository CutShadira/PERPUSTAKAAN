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

// BAGIAN INPUT
// fungsi untuk membaca input pengguna dan menghapus karakter Enter di akhir input
static void bacaBaris(const char *label, char *hasil, int ukuran)
{
    int panjang;

    printf("%s", label);
    if (fgets(hasil, ukuran, stdin) == NULL)
    {
        /* input habis, keluar dengan rapi */
        printf("\n");
        bebaskanSemuaData();
        exit(0); // menghentikan program secara normal
    }
 // menghitung panjang input dan mengganti karakter Enter dengan penanda akhir string
    panjang = strlen(hasil); // menghitung panjang string/teks
    // Mengganti karakter Enter dengan karakter akhir string.
    if (panjang > 0 && hasil[panjang - 1] == '\n')
    {
        hasil[panjang - 1] = '\0';
    }
}

// baca inputan yang wajib, dimana jika tidak diisi itu bakalan muncul teks peringatan tigak boleh kosong
static void bacaTeksWajib(const char *label, char *hasil, int ukuran)
{
    do
    {
        bacaBaris(label, hasil, ukuran);
        if (hasil[0] == '\0')
        {
            printf("Tidak boleh kosong.\n");
        }
    } while (hasil[0] == '\0');
}

// untuk isian yang tidak boleh kosong dan tidak boleh ada spasi (ID, url, dll)
static void bacaTanpaSpasi(const char *label, char *hasil, int ukuran)
{
    do
    {
        bacaTeksWajib(label, hasil, ukuran);
        if (strchr(hasil, ' ') != NULL) // digunakan untuk mengecek apakah ada spasi
        {
            printf("Tidak boleh mengandung spasi.\n");
            hasil[0] = '\0';
        }
    } while (hasil[0] == '\0');
}
// Membaca input angka dari pengguna dan memastikan angka berada dalam rentang yang ditentukan
static int bacaAngka(const char *label, int min, int max)
{
    char teks[32];
    char *akhir;
    long nilai;

    while (1)
    {
        bacaBaris(label, teks, sizeof(teks));
        nilai = strtol(teks, &akhir, 10); // mengubah string menjadi bilangan bulat bertipe long.
        if (teks[0] != '\0' && *akhir == '\0' && nilai >= min && nilai <= max)
        {
            return (int)nilai;
        }
        printf("Input tidak valid, masukkan angka %d sampai %d.\n", min, max);
    }
}

// tanda petik dua dipakai sebagai pemisah di file, jadi diganti
static void gantiPetik(char *teks)
{
    int i;

    for (i = 0; teks[i] != '\0'; i++)
    {
        if (teks[i] == '"')
        {
            teks[i] = '\'';
        }
    }
}