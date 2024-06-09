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
    int buku;
    string tanggal_pinjam;
    int batas_pengembalian;
    string hari_pengembalian;
    int denda;
};

#endif