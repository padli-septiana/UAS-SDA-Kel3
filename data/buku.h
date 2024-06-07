#ifndef LIST_BUKU_H
#define LIST_BUKU_H

#include <iostream>

using namespace std;

struct buku
{
    int id;
    string judul;
    string penulis;
    string penerbit;
    int tahun_terbit;
    string deskripsi;
    int harga;
};

// void show_buku(buku list_buku[], int n, int i)
// {
//     int root = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n)
//     {
//         show_buku(list_buku, n, left);
//     }

//     cout << "ID: " << list_buku[root].id << endl;
//     cout << "Judul: " << list_buku[root].judul << endl;
//     cout << "Penulis: " << list_buku[root].penulis << endl;
//     cout << "Penerbit: " << list_buku[root].penerbit << endl;
//     cout << "Tahun Terbit: " << list_buku[root].tahun_terbit << endl;
//     cout << "Deskripsi: " << list_buku[root].deskripsi << endl;
//     cout << "Harga: " << list_buku[root].harga << endl;
//     cout << endl;

//     if (right < n)
//     {
//         show_buku(list_buku, n, right);
//     }
// }

// void cekDenda(string tanggal_kembali, string tanggal_sekarang)
// {
//     int denda = 0;
//     int hari_keterlambatan = 0;

//     int tahun_kembali = stoi(tanggal_kembali.substr(0, 4));
//     int bulan_kembali = stoi(tanggal_kembali.substr(5, 2));
//     int hari_kembali = stoi(tanggal_kembali.substr(8, 2));

//     int tahun_sekarang = stoi(tanggal_sekarang.substr(0, 4));
//     int bulan_sekarang = stoi(tanggal_sekarang.substr(5, 2));
//     int hari_sekarang = stoi(tanggal_sekarang.substr(8, 2));

//     if (tahun_sekarang > tahun_kembali)
//     {
//         hari_keterlambatan += (tahun_sekarang - tahun_kembali) * 365;
//     }

//     if (bulan_sekarang > bulan_kembali)
//     {
//         hari_keterlambatan += (bulan_sekarang - bulan_kembali) * 30;
//     }

//     if (hari_sekarang > hari_kembali)
//     {
//         hari_keterlambatan += hari_sekarang - hari_kembali;
//     }

//     if (hari_keterlambatan > 7)
//     {
//         denda = (hari_keterlambatan - 7) * 1000;
//     }

//     cout << "Denda: " << denda << endl;
// }

#endif