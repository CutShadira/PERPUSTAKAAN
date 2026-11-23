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
// BAGIAN LOGIN
// Fungsi untuk menampilkan halaman login dan mengembalikan data user yang berhasil masuk
User *menuLogin(void)
{
    char username[32], password[32];
    User *user;
    int pilihan;
// Menampilkan pilihan login atau keluar dari program
    printf("\n=== SISTEM PERPUSTAKAAN ===\n");
    printf("1. Login\n");
    printf("0. Keluar\n");
    pilihan = bacaAngka("Pilihan: ", 0, 1);
    if (pilihan == 0)
    {
        return NULL;
    }

    // ulangi terus sampai username dan password benar
    while (1)
    {
        bacaBaris("Username: ", username, sizeof(username));
        bacaBaris("Password: ", password, sizeof(password));
        user = login(username, password);
        if (user != NULL)
        {
            // kalau ada
            return user;
        }
        // kalau gak ada
        printf("Username atau password salah, coba lagi.\n");
    }
}
// BAGIAN KATALOG
static void pilihPengurutan(int *kriteria, int *arah, int *algoritma)
{
    *algoritma = 1; // Selalu menggunakan Bubble Sort
 // Menampilkan pilihan kriteria pengurutan buku
    printf("\nUrutkan berdasarkan:\n");
    printf("1. ID Buku\n2. Judul\n3. Tahun Terbit\n4. Jumlah Halaman\n5. Stok\n");
    *kriteria = bacaAngka("Pilih kriteria: ", 1, 5);
 // Menentukan urutan data secara menaik atau menurun
    printf("\n1. Naik (A-Z / terlama / terkecil)\n");
    printf("2. Turun (Z-A / terbaru / terbesar)\n");
    *arah = bacaAngka("Pilih arah: ", 1, 2);
}
// Fungsi untuk menampilkan katalog buku berdasarkan kriteria pengurutan dan ketersediaan stok
static void tampilkanKatalog(int hanyaTersedia)
{
    int kriteria, arah, algoritma, jumlah, i;
    char jawab[8];
    Buku **daftar;
 // Memilih pengurutan dan menyiapkan daftar buku sesuai kriteria
    pilihPengurutan(&kriteria, &arah, &algoritma);
    daftar = siapkanKatalog(hanyaTersedia, &jumlah, kriteria, arah, algoritma);
 // Memeriksa apakah terdapat buku yang dapat ditampilkan
    if (daftar == NULL)
    {
        printf("\nTidak ada buku untuk ditampilkan.\n");
        return;
    }
 // Menampilkan informasi pengurutan dan jumlah buku dalam katalog
    printf("\nDiurutkan: %s (%s) memakai %s, total %d buku\n\n",
           NAMA_KRITERIA[kriteria], arah == NAIK ? "naik" : "turun",
           NAMA_ALGORITMA[algoritma], jumlah);
// Menampilkan daftar buku dengan sistem halaman maksimal 20 buku
    cetakHeaderBuku();
    for (i = 0; i < jumlah; i++)
    {
        cetakBarisBuku(i + 1, daftar[i]);

        if ((i + 1) % PER_HALAMAN == 0 && i + 1 < jumlah)
        {
            bacaBaris("-- Enter untuk lanjut, q untuk berhenti: ", jawab, sizeof(jawab));
            if (jawab[0] == 'q' || jawab[0] == 'Q')
            {
                break;
            }
        }
    }
    free(daftar);
}
// Fungsi untuk mencari buku berdasarkan ID atau judul
static void menuCariBuku(void)
{
    char kata[64];

    bacaTeksWajib("Masukkan ID atau judul buku: ", kata, sizeof(kata));
    if (cariBuku(kata) == 0)
    {
        printf("Buku tidak ditemukan.\n");
    }
}