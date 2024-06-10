#ifndef CONTROLLER_TRANSAKSI_H
#define CONTROLLER_TRANSAKSI_H

#include <string>
using namespace std;

#include "../data/transaksi.h"
// #include "../data/antrian.h"
#include "../data/buku.h"
#include "utils.h"
#include "buku_controller.h"

int kapasitas = 100;

bool isTransaksiFull(RiwayatTransaksi &riwayat)
{
    if (riwayat.top == kapasitas - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isTransaksiEmpty(RiwayatTransaksi &riwayat)
{
    if (riwayat.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void insert_transaksi(RiwayatTransaksi &riwayat, Transaksi transaksi)
{
    if (isTransaksiFull(riwayat))
    {
        cout << "telah penuh" << endl;
    }
    else
    {
        riwayat.top++;
        riwayat.data[riwayat.top] = transaksi;
    }
}

// void show_transaksi(RiwayatTransaksi &riwayat)
// {
//     for (int i = riwayat.top; i >= 0; i--)
//     {
//         cout << "ID: " << riwayat.data[i].id << endl;
//         cout << "Nama: " << riwayat.data[i].nama << endl;
//         cout << "Alamat: " << riwayat.data[i].alamat << endl;
//         cout << "No. Telp: " << riwayat.data[i].no_telp << endl;
//         cout << "Email: " << riwayat.data[i].email << endl;
//         cout << "ID Buku: " << riwayat.data[i].buku << endl;
//         cout << "Tanggal Pinjam: " << riwayat.data[i].tanggal_pinjam << endl;
//         cout << "Batas Pengembalian: " << riwayat.data[i].batas_pengembalian << endl;
//         cout << "Hari Pengembalian: " << riwayat.data[i].hari_pengembalian << endl;
//         cout << "Denda: " << riwayat.data[i].denda << endl;
//         cout << endl;
//     }
// }

// function show all stack
void show_transaksi(RiwayatTransaksi &riwayat)
{
    for (int i = riwayat.top; i >= 0; i--)
    {
        cout << "ID: " << riwayat.data[i].id << endl;
        cout << "Nama: " << riwayat.data[i].nama << endl;
        cout << "Alamat: " << riwayat.data[i].alamat << endl;
        cout << "No. Telp: " << riwayat.data[i].no_telp << endl;
        cout << "Email: " << riwayat.data[i].email << endl;
        cout << "ID Buku: " << riwayat.data[i].buku << endl;
        cout << "Tanggal Pinjam: " << riwayat.data[i].tanggal_pinjam << endl;
        cout << "Batas Pengembalian: " << riwayat.data[i].batas_pengembalian << endl;
        cout << "Hari Pengembalian: " << riwayat.data[i].hari_pengembalian << endl;
        cout << "Denda: " << riwayat.data[i].denda << endl;
        cout << endl;
    }
}

// Transaksi find_id_transaksi(RiwayatTransaksi &riwayat, int id)
// {
//     Transaksi result;
//     for (int i = 0; i < riwayat.top; i++)
//     {
//         if (riwayat.data[i].id == id)
//         {
//             result = riwayat.data[i];
//             cout << "data: " << riwayat.data[i].id << endl;
//             return result;
//         }
//     }

//     return result;
// }

Transaksi find_transaksi_by_id(RiwayatTransaksi &riwayat, int id)
{
    for (int i = riwayat.top; i >= 0; i--)
    {
        if (riwayat.data[i].id == id)
        {
            return riwayat.data[i];
        }
    }

    return {};
}

string getDateAfter7Day(string tanggal_pinjam)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string year = to_string(1900 + ltm->tm_year);
    string month;
    if (1 + ltm->tm_mon < 10)
    {
        month = "0" + to_string(1 + ltm->tm_mon);
    }
    else
    {
        month = to_string(1 + ltm->tm_mon);
    }

    string day = to_string(ltm->tm_mday + 7);

    return year + "-" + month + "-" + day;
}

void pinjam_buku(RiwayatTransaksi &riwayat, Buku data_buku)
{
    Transaksi temp_trans;
    temp_trans.id = generate3RandomNumber();

    cout << "Nama: ";
    cin >> temp_trans.nama;
    cout << "Alamat: ";
    cin >> temp_trans.alamat;
    cout << "No. Telp: ";
    cin >> temp_trans.no_telp;
    cout << "Email: ";
    cin >> temp_trans.email;
    temp_trans.buku = data_buku.id;
    temp_trans.tanggal_pinjam = getCurrentDate();
    temp_trans.batas_pengembalian = getDateAfter7Day(temp_trans.tanggal_pinjam);
    temp_trans.denda = 0;

    clearTerminal();

    // update status buku
    data_buku.status = "Tidak Tersedia";
    updateBukuStatus(data_buku);

    insert_transaksi(riwayat, temp_trans);

    cout << "\nRingkasan transaksi:" << endl;
    cout << "ID peminjaman: " << temp_trans.id << endl;
    cout << "Buku: " << data_buku.judul << endl;
    cout << "tanggal pinjam: " << temp_trans.tanggal_pinjam << endl;
    cout << "tanggal kembali: " << temp_trans.batas_pengembalian << endl;

    cout << "\nBuku " << data_buku.judul << " berhasil dipinjam. Harap kembalikan maksimal tanggal " << temp_trans.batas_pengembalian << endl;

    enterToContinue();
}

void kembalikan_buku(RiwayatTransaksi &riwayat, Transaksi transaksi, treeBuku *pohonBuku)
{
    string current_date = getRegexpDate();

    if (current_date > transaksi.batas_pengembalian)
    {

        int late_days = kalkulasiPerbedaanTanggal(current_date, transaksi.batas_pengembalian);
        int confirm_denda;
        transaksi.denda = late_days * 500;
        cout << "Anda terlambat mengembalikan " << late_days << " hari" << endl;
        cout << "Denda anda sebesar Rp." << transaksi.denda << endl;

        cout << "\nBayar denda? (1: ya, 0: tidak): ";
        cin >> confirm_denda;

        if (confirm_denda == 1)
        {
            Buku returned_buku = find_id_buku(&pohonBuku, transaksi.buku);
            returned_buku.status = "Tersedia";
            updateBukuStatus(returned_buku);

            transaksi.hari_pengembalian = current_date;

            for (int i = riwayat.top; i >= 0; i--)
            {
                if (riwayat.data[i].id == transaksi.id)
                {
                    riwayat.data[i] = transaksi;
                    break;
                }
            }

            // delete transaksi

            cout << "Terima kasih telah mengembalikan buku. Transaksi selesai." << endl;
        }
        else
        {
            cout << "Denda tidak dibayar. Transaksi dibatalkan." << endl;
        }
    }
    else
    {
        transaksi.denda = 0;
        cout << "Buku dikembalikan tepat waktu. Tidak ada denda." << endl;

        Buku returned_buku = find_id_buku(&pohonBuku, transaksi.buku);
        returned_buku.status = "Tersedia";
        updateBukuStatus(returned_buku);

        transaksi.hari_pengembalian = current_date;

        for (int i = riwayat.top; i >= 0; i--)
        {
            if (riwayat.data[i].id == transaksi.id)
            {
                riwayat.data[i] = transaksi;
                break;
            }
        }

        // delete transaksi

        cout << "Terima kasih telah mengembalikan buku. Transaksi selesai." << endl;
    }
}

#endif