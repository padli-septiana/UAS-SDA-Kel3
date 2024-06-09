#include <iostream>

#include "data/buku.h"
#include "modul/buku_controller.h"
#include "modul/utils.h"
#include "data/transaksi.h"
#include "modul/transaksi_controller.h"
#include "data/antria.h"
// #include "modul/pengembalian.cpp"
// #include "modul/peminjaman.cpp"
// #include "modul/cek_denda.cpp"

using namespace std;

void menuPeminjaman(Transaksi data_transaksi[100], treeBuku *pohonBuku)
{
    int bukuPinjam, konfirmPinjam;
    string dapatPinjam;
    cout << "\nDaftar seluruh buku: \n"
         << endl;
    cout << "0. Kembali" << endl;
    show_list_buku(pohonBuku);

    cout << "\nPilih Buku mana yang ingin dipinjam (masukkan ID buku): ";
    if (bukuPinjam != 0)
    {
        cin >> bukuPinjam;

        Buku bukuhasil = find_id_buku(&pohonBuku, bukuPinjam);
        if (bukuhasil.id != 0)
        {
            dapatPinjam = bukuhasil.status;

            cout << "\n Detil buku yang dipinjam: \n";
            cout << "id: " << bukuhasil.id << endl;
            cout << "judul: " << bukuhasil.judul << endl;
            cout << "penulis: " << bukuhasil.penulis << endl;
            cout << "tahun terbit: " << bukuhasil.tahun_terbit << endl;
            cout << "deskripsi: " << bukuhasil.deskripsi << endl;

            if (dapatPinjam == "Tersedia")
            {
                cout << "status: " << bukuhasil.status << endl;
                cout << "\nKonfirmasi peminjaman buku? (1: ya, 0: tidak): ";
                cin >> konfirmPinjam;
            }
            else
            {
                cout << "Buku sedang tidak tersedia" << endl;
                int menuPinjamAntri;

                cout << "Apakah anda ingin mengambil antrian peminjaman buku ini? (1: ya, 0: tidak): ";
                cin >> menuPinjamAntri;

                if (menuPinjamAntri == 1)
                {
                    // antriannya disini
                }
            }

            if (konfirmPinjam == 1)
            {
                pinjam_buku(data_transaksi, bukuhasil);
            }
        }
    }
}

void menuPengembalian(Transaksi data_transaksi[100], treeBuku *pohonBuku)
{
    int id_peminjaman;
    cout << "Masukkan id peminjaman: ";
    cin >> id_peminjaman;
    Transaksi transaksi = find_id_transaksi(data_transaksi, id_peminjaman);
    cout << "id: " << transaksi.id << endl;
    cout << "hari pengembalian: " << transaksi.hari_pengembalian << endl;
    if (transaksi.id != 0 && transaksi.hari_pengembalian == "")
    {
        kembalikan_buku(data_transaksi, transaksi, pohonBuku);
    }
    else
    {
        cout << "ID peminjaman tidak ditemukan" << endl;
    }
    enterToContinue();
}

int main()
{
    int menu1, runApps = 1;

    pohonBuku, rootBuku = NULL;
    insert_books();
    Transaksi data_transaksi[100] = {
        {123, "Rizky", "Jl. Kebon Jeruk", "08123456789", "email", 9, "2024-06-01", "2024-06-08", "", 0}};

    while (runApps == 1)
    {
        clearTerminal();

        cout << "=============================================" << endl;
        cout << "Selamat datang di perpustakaan online" << endl;
        cout << "=============================================\n"
             << endl;

        cout << "1. Peminjaman Buku" << endl;
        cout << "2. Pengembalian Buku" << endl;
        cout << "Pilih menu: ";
        cin >> menu1;

        switch (menu1)
        {
        case 1:
            menuPeminjaman(data_transaksi, pohonBuku);
            break;
        case 2:
            menuPengembalian(data_transaksi, pohonBuku);
            break;
        case 3:
        case 9:
            runApps = 0;
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
    }

    return 0;
}