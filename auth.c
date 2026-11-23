#include <string.h>
#include "auth.h"

// Mencari user yang cocok dengan username dan password yang diberikan.
User *login(const char *username, const char *password) {

    int i; // indeks untuk perulangan

    // Telusuri semua user yang terdaftar di dataUser
    for (i = 0; i < jumlahUser; i++) {
                if (strcmp(dataUser[i].username, username) == 0
            && strcmp(dataUser[i].password, password) == 0) {
            // Login berhasil: kembalikan alamat data user tersebut
            return &dataUser[i];
        }
    }
    // Jika tidak ada user yang cocok: login gagal
    return NULL;
}