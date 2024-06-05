#ifndef LIST_BUKU_H
#define LIST_BUKU_H

#include <iostream>

using namespace std;

// Define struct buku
// Data Buku:

// id (6 digit angka)
// judul
// penulis
// penerbit
// tahun terbit
// deskripsi singkat
// harga

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

buku list_buku[10] = {
    {1, "Buku 1", "Penulis 1", "Penerbit 1", 2020, "Deskripsi 1", 10000},
    {2, "Buku 2", "Penulis", "Penerbit 2", 2021, "Deskripsi 2", 20000},
    {3, "Buku 3", "Penulis 3", "Penerbit 3", 2022, "Deskripsi 3", 30000},
    {4, "Buku 4", "Penulis 4", "Penerbit 4", 2023, "Deskripsi 4", 40000},
    {5, "Buku 5", "Penulis 5", "Penerbit 5", 2024, "Deskripsi 5", 50000},
    {6, "Buku 6", "Penulis 6", "Penerbit 6", 2025, "Deskripsi 6", 60000},
    {7, "Buku 7", "Penulis 7", "Penerbit 7", 2026, "Deskripsi 7", 70000},
    {8, "Buku 8", "Penulis 8", "Penerbit 8", 2027, "Deskripsi 8", 80000},
    {9, "Buku 9", "Penulis 9", "Penerbit 9", 2028, "Deskripsi 9", 90000},
    {10, "Buku 10", "Penulis 10", "Penerbit 10", 2029, "Deskripsi 10", 100000}};

void show_buku(buku list_buku[], int n, int i)
{
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n)
    {
        show_buku(list_buku, n, left);
    }

    cout << "ID: " << list_buku[root].id << endl;
    cout << "Judul: " << list_buku[root].judul << endl;
    cout << "Penulis: " << list_buku[root].penulis << endl;
    cout << "Penerbit: " << list_buku[root].penerbit << endl;
    cout << "Tahun Terbit: " << list_buku[root].tahun_terbit << endl;
    cout << "Deskripsi: " << list_buku[root].deskripsi << endl;
    cout << "Harga: " << list_buku[root].harga << endl;
    cout << endl;

    if (right < n)
    {
        show_buku(list_buku, n, right);
    }
}

#endif