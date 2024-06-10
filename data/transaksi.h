#ifndef LIST_TRANSAKSI_H
#define LIST_TRANSAKSI_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Transaksi
{
    int id;
    string nama;
    string alamat;
    string no_telp;
    string email;
    int buku;
    string tanggal_pinjam;
    string batas_pengembalian;
    string hari_pengembalian;
    int denda;
};

struct RiwayatTransaksi
{
    int top;
    Transaksi data[100];
};

void declare_dummy_late_transaksi()
{
    Transaksi data_transaksi[100] = {
        {123, "Rizky", "Jl. Kebon Jeruk", "08123456789", "email", 9, "2024-06-01", "2024-06-08", "", 0},
    };
};

#endif