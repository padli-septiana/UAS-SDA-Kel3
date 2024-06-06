#ifndef LIST_TRANSAKSI_H
#define LIST_TRANSAKSI_H

#include <iostream>

using namespace std;

struct transaksi
{
    int id;
    string nama;
    string alamat;
    string no_telp;
    string email;
    string buku;
    string tanggal_pinjam;
    string tanggal_kembali;
    int denda = 0;
}

#endif