#include <iostream>

#include "data/buku.h"
#include "modul/buku_controller.h"
// #include "data/transaksi.h"
// #include "modul/utils.h"
// #include "modul/pengembalian.cpp"
// #include "modul/peminjaman.cpp"
// #include "modul/cek_denda.cpp"

using namespace std;

void menuPeminjaman() {
    int bukuPinjam, konfirmPinjam;
    cout << "\nDaftar seluruh buku: \n" << endl;
    show_list_buku(pohonBuku);

    cout << "\nPilih Buku mana yang ingin dipinjam (masukkan ID buku): ";
    cin >> bukuPinjam;

    Buku bukuhasil = find_id_buku(&pohonBuku, bukuPinjam);
    if (bukuhasil.id != 0) {
        cout << "\n Detil buku yang dipinjam: \n";
        cout << "id: " << bukuhasil.id << endl;
        cout << "judul: " << bukuhasil.judul << endl;
        cout << "penulis: " << bukuhasil.penulis << endl;
        cout << "tahun terbit: " << bukuhasil.tahun_terbit << endl;
        cout << "deskripsi: " << bukuhasil.deskripsi << endl;
        cout << "status: " << bukuhasil.status << endl;
        cout << "\nKonfirmasi peminjaman buku? (1: ya, 0: tidak): ";
        cin >> konfirmPinjam;

        if (konfirmPinjam == 1)
        {
            cout << "Peminjaman berhasil" << endl; //Ganti ke function pemunjaman
        }
    }

    

}

int main()
{
    int menu1;
    
    declare_buku();
    insert_books();
    
    cout << "Selamat datang di perpustakaan bla bla bla" << endl;
    cout << "=============================================\n" << endl;
    
    cout << "1. Peminjaman Buku" << endl;
    cout << "2. Pengembalian Buku" << endl;
    cout << "Pilih menu: ";
    cin >> menu1;

    switch (menu1)
    {
    case 1:
        menuPeminjaman();
        break;
    
    default:
        cout << "Menu tidak tersedia" << endl;
        break;
    }
    return 0;
}