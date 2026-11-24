# SISTEM-PERPUSTAKAAN 
## Anggota Kelompok
1.⁠ ⁠Cut Shadira Alifa Risty  - 260810701100006 
2.⁠ ⁠M. Khalish Al Ghazie - 260810701100076 
3.⁠ ⁠Muhammad Alexandria Kemal Pasha - 260810701100009 
4.⁠ ⁠Rihadatul Marsya - 260810701100051 
---

## Deskripsi Aplikasi
Aplikasi *Sistem Manajemen Perpustakaan* berbasis bahasa C yang berjalan di terminal (CLI) untuk membantu pengelolaan data dan operasional perpustakaan secara digital. Fitur utama aplikasi ini meliputi:
•⁠  ⁠Manajemen data buku (tambah, tampilkan, edit, dan hapus buku).
•⁠  ⁠Pencarian serta pengurutan (sorting) katalog buku menggunakan algoritma Bubble Sort, Selection Sort, dan Insertion Sort berdasarkan ID, judul, tahun terbit, jumlah halaman, dan jumlah stok secara naik (ascending) maupun turun (descending).
•⁠  ⁠Sistem peminjaman dan pengembalian buku oleh anggota.
•⁠  ⁠Sistem autentikasi akun untuk membedakan hak akses antara Admin/Pustakawan dan Anggota.

---

## Struktur File (⁠ .c ⁠ dan ⁠ .h ⁠)

Berikut adalah daftar file kode sumber dan header beserta kegunaannya masing-masing:

| Nama File | Kegunaan |
| :--- | :--- |
| *⁠ main.c ⁠* | Titik masuk utama (entry point) program yang mengintegrasikan seluruh modul dan menjalankan alur utama aplikasi. |
| *⁠ models.h ⁠ & ⁠ models.c ⁠* | Mendefinisikan struktur data (⁠ struct ⁠) utama seperti ⁠ Buku ⁠ dan ⁠ User ⁠, serta fungsi dasar pengelolaan model data. |
| *⁠ menu.h ⁠ & ⁠ menu.c ⁠* | Mengatur tampilan antarmuka menu di terminal serta menangani navigasi pilihan pengguna (menu admin maupun menu anggota). |
| *⁠ auth.h ⁠ & ⁠ auth.c ⁠* | Mengelola sistem autentikasi, validasi login, registrasi, dan pengaturan hak akses pengguna. |
| *⁠ buku.h ⁠ & ⁠ buku.c ⁠* | Menangani operasi pengelolaan katalog buku (CRUD) serta pencatatan transaksi peminjaman dan pengembalian buku. |
| *⁠ algoritma/pembanding.h ⁠ & ⁠ algoritma/pembanding.c ⁠* | Menyediakan konstanta kriteria/arah pengurutan serta fungsi perbandingan teks (case-insensitive) dan perbandingan data antar buku (⁠ bandingkanTeks ⁠, ⁠ harusTukar ⁠). |
| *⁠ algoritma/bubble_sort.h ⁠ & ⁠ algoritma/bubble_sort.c ⁠* | Mengimplementasikan algoritma pengurutan Bubble Sort untuk mengurutkan daftar buku berdasarkan kriteria dan arah yang dipilih. |
| *⁠ algoritma/selection_sort.h ⁠ & ⁠ algoritma/selection_sort.c ⁠* | Mengimplementasikan algoritma pengurutan Selection Sort untuk mengurutkan daftar buku berdasarkan kriteria dan arah yang dipilih. |
| *⁠ algoritma/insertion_sort.h ⁠ & ⁠ algoritma/insertion_sort.c ⁠* | Mengimplementasikan algoritma pengurutan Insertion Sort untuk mengurutkan daftar buku berdasarkan kriteria dan arah yang dipilih. |

---

## File Data (⁠ .txt ⁠)

Aplikasi ini menggunakan penyimpanan berbasis berkas teks (⁠ .txt ⁠) agar data tetap tersimpan meskipun program ditutup:

•⁠  ⁠*⁠ books.txt ⁠*: Menyimpan seluruh daftar katalog buku perpustakaan beserta detailnya (ID/OCAID, judul, penulis, tahun terbit, jumlah halaman, dan stok tersedia).
•⁠  ⁠*⁠ user.txt ⁠*: Menyimpan data akun pengguna (username, password, dan role/peran akun) untuk keperluan proses login.
•⁠  ⁠*⁠ peminjaman.txt ⁠*: Menyimpan riwayat dan status transaksi peminjaman serta pengembalian buku oleh anggota.

## Cara Menjalankan Program (Compile & Run)

1.⁠ ⁠Persyaratan Sistem
Sebelum menjalankan aplikasi, pastikan:
•⁠  ⁠GCC (GNU Compiler Collection) sudah terinstal.
•⁠  ⁠Terminal atau Command Prompt tersedia.
•⁠  ⁠Seluruh file proyek berada dalam satu folder dengan struktur yang sesuai.

## Windows
Buka terminal (PowerShell) pada folder utama proyek, kemudian lakukan kompilasi menggunakan perintah:
gcc -Wall -Wextra -o perpustakaan.exe main.c models.c auth.c buku.c menu.c algoritma/pembanding.c algoritma/bubble_sort.c algoritma/selection_sort.c algoritma/insertion_sort.c

Jika proses kompilasi berhasil, jalankan program dengan perintah:
.\perpustakaan.exe

## Mac (macOS)
Buka Terminal pada folder utama proyek, kemudian lakukan kompilasi menggunakan perintah:
gcc -Wall -Wextra -o perpustakaan main.c models.c auth.c buku.c menu.c algoritma/pembanding.c algoritma/bubble_sort.c algoritma/selection_sort.c algoritma/insertion_sort.c

Jika proses kompilasi berhasil, jalankan program dengan perintah:
./perpustakaan

Catatan : 
•⁠ Pastikan seluruh file .c dan .h tersedia sesuai struktur folder proyek.
•⁠ Pastikan folder data/ beserta file penyimpanan .txt tersedia.
•⁠ Jalankan program dari direktori utama proyek agar lokasi penyimpanan data dapat ditemukan dengan benar.
•⁠ Jika terjadi kesalahan saat kompilasi, periksa kembali nama file dan lokasi direktori.
