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

// Mengambil satu kata dari baris, kata bisa berupa teks biasa atau teks yang diapit tanda petik
static int ambilKata(char *teks, int *pos, char *hasil, int maks)
{
    int i = 0;
 
    // Lewati spasi dan tab
    while (teks[*pos] == ' ' || teks[*pos] == '\t')
    {
        (*pos)++;
    }

    // Periksa apakah teks sudah habis
    if (teks[*pos] == '\0' || teks[*pos] == '\n')
    {
        return 0;
    }

    // Periksa apakah kata menggunakan tanda petik
    if (teks[*pos] == '"')
    {
        // untuk melewati tanda "
        (*pos)++;

        // Ambil teks sampai menemukan tanda petik penutup
        while (teks[*pos] != '"' && teks[*pos] != '\0' &&
               teks[*pos] != '\n' && teks[*pos] != '\r')
        {

            if (i < maks - 1)
            {
                // buku.ocaid[32] w w _ _ _
                hasil[i++] = teks[*pos];
            }

            (*pos)++;
        }

        // Lewati tanda petik penutup
        if (teks[*pos] == '"')
        {
            (*pos)++;
        }
    }
//Memeriksa apakah teks menggunakan tanda petik untuk membaca kalimat atau kata yang mengandung spasi
    else
    {

        // Ambil kata biasa sampai menemukan spasi
        while (teks[*pos] != ' ' && teks[*pos] != '\t' &&
               teks[*pos] != '\0' && teks[*pos] != '\n' &&
               teks[*pos] != '\r')
        {

            if (i < maks - 1)  
            {
                // w w _ 
                // 0 1 2
                hasil[i++] = teks[*pos];
            }

            (*pos)++;
        }
    }

    // Akhiri string
    hasil[i] = '\0'; 

    return 1;
}