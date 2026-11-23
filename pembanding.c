#include <ctype.h>
#include "pembanding.h"

// Membandingkan dua string tanpa membedakan huruf besar/kecil (case-insensitive).
// Return: negatif jika a < b, 0 jika sama, positif jika a> b.
int bandingkanTeks(const char *a, const char *b) {
    // Lanjutkan selama kedua a < b, 0 jika sama, positif jka a > b.
    while (*a != '\0' && *b != '\0') {
        // Ubah karakter ke huruf kecil dulu agar 'A' dan 'a' dianggap sama.
        // Cast ke unsigned char supaya aman untuk tolower()
        int x = tolower((unsigned char) *a);
        int y = tolower((unsigned char) *b);
    }
}