#ifndef MENU_H
#define MENU_H

#include "models.h"

// Deklarasi fungsi untuk menampilkan halaman login dan mengembalikan data user yang berhasil masuk
// Mengembalikan NULL jika pengguna memilih keluar
User *menuLogin(void);

// Deklarasi fungsi untuk menjalankan menu utama berdasarkan role user yang berhasil login
// Proses menu berakhir ketika user memilih logout
void jalankanMenu(User *user);

#endif