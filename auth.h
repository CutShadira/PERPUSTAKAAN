#ifndef AUTH_H
#define AUTH_H

#include "models.h"

// Verifikasi username dan password. Return: pointer user jika cocok, NULL jika gagal.
User *login(const char *username, const char *password);

#endif