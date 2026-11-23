#include <stdio.h>
#include "models.h"
#include "menu.h"

int main(void)
{
    User *user;
    // Memuat seluruh data dari file ke dalam program
    if (!muatSemuaData())
    {
        return 1;
    }

   // Mengulang proses login dan menu sampai pengguna memilih keluar
    while (1)
    {
        user = menuLogin();
        if (user == NULL)
        {
            break;
        }
        jalankanMenu(user);
    }
    // Membebaskan memori yang digunakan oleh seluruh data program
    bebaskanSemuaData();
    printf("Sampai jumpa.\n");
    return 0;
}