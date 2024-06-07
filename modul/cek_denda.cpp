#include <iostream>
#include <ctime>
#include "../data/transaksi.h"

using namespace std;

void cek_denda(const string& tanggal_terlambat, const string& id, const string& judul, int hari_terlambat, double harga_denda) 
{
    double denda = 0;

    if (hari_terlambat > 0)
    {
        denda = hari_terlambat * harga_denda;
    }

    cout << "ID: " << id <<endl;
    cout << "Judul: " << judul <<endl;
    cout << "Jumlah Hari Terlambat: " <<  hari_terlambat << " hari " <<endl;
    cout << " Harga Denda Perhari: Rp " << harga_denda << endl;
    cout << "Total Denda: Rp " << denda << endl;
}

int main()
{
    string tanggal_terlambat = "2024-06-11" ;
    string id;
    string judul;

    cout << "Masukan ID: ";
    cin >> id;
    cin.ignore();

    cout << "Judul: "
    getline (cin, judul);

    int hari_terlambat = 3; //masukan harinya terlambatnya disini ya:)

    double harga_denda = 500.0;

    cek_denda(tanggal_terlambat, id, judul, hari_terlambat, harga_denda);

    return 0;
}

