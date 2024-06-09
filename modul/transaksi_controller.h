#ifndef CONTROLLER_TRANSAKSI_H
#define CONTROLLER_TRANSAKSI_H

#include <string>
using namespace std;

#include "../data/transaksi.h"
// #include "../data/antrian.h"
#include "../data/buku.h"
#include "utils.h"
#include "buku_controller.h"

void insert_transaksi(Transaksi *data_transaksi, Transaksi transaksi)
{
    for (int i = 0; i < 100; i++)
    {
        if (data_transaksi[i].id == 0)
        {
            data_transaksi[i] = transaksi;
            break;
        }
    }
}

void show_transaksi(Transaksi *data_transaksi)
{
    for (int i = 0; i < 100; i++)
    {
        if (data_transaksi[i].id != 0)
        {
            cout << "ID: " << data_transaksi[i].id << endl;
            cout << "Nama: " << data_transaksi[i].nama << endl;
            cout << "Alamat: " << data_transaksi[i].alamat << endl;
            cout << "No. Telp: " << data_transaksi[i].no_telp << endl;
            cout << "Email: " << data_transaksi[i].email << endl;
            cout << "ID Buku: " << data_transaksi[i].buku << endl;
            cout << "Tanggal Pinjam: " << data_transaksi[i].tanggal_pinjam << endl;
            cout << "Batas Pengembalian: " << data_transaksi[i].batas_pengembalian << endl;
            cout << "Hari Pengembalian: " << data_transaksi[i].hari_pengembalian << endl;
            cout << "Denda: " << data_transaksi[i].denda << endl;
            cout << endl;
        }
    }
}

Transaksi find_id_transaksi(Transaksi *data_transaksi, int id)
{
    Transaksi result;
    for (int i = 0; i < 100; i++)
    {
        if (data_transaksi[i].id == id)
        {
            result = data_transaksi[i];
            return result;
        }
        else
        {
            result.id = 0;
        }
    }

    return result;
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

void pinjam_buku(Transaksi *data_transaksi, Buku data_buku)
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

    // update status buku
    data_buku.status = "Tidak Tersedia";
    updateBukuStatus(data_buku);
    insert_transaksi(data_transaksi, temp_trans);

    clearTerminal();

    cout << "\nRingkasan transaksi:" << endl;
    cout << "ID peminjaman: " << temp_trans.id << endl;
    cout << "Buku: " << data_buku.judul << endl;
    cout << "tanggal pinjam: " << temp_trans.tanggal_pinjam << endl;
    cout << "tanggal kembali: " << temp_trans.batas_pengembalian << endl;

    cout << "\nBuku " << data_buku.judul << " berhasil dipinjam. Harap kembalikan maksimal tanggal " << temp_trans.batas_pengembalian << endl;

    enterToContinue();
}

void kembalikan_buku(Transaksi *data_transaksi, Transaksi transaksi, treeBuku *pohonBuku)
{
    string current_date = getRegexpDate();

    if (current_date > transaksi.batas_pengembalian)
    {
        int late_days = kalkulasiPerbedaanTanggal(current_date, transaksi.batas_pengembalian);
        int confirm_denda;
        transaksi.denda = late_days * 500;
        cout << "Anda terlambat mengembalikan buku " << current_date << " " << transaksi.batas_pengembalian << ". Denda: Rp. " << transaksi.denda << endl;

        cout << "Bayar denda? (1: ya, 0: tidak): ";
        cin >> confirm_denda;
    }
    else
    {
        transaksi.denda = 0;
        cout << "Buku dikembalikan tepat waktu. Tidak ada denda." << endl;
    }

    Buku returned_buku = find_id_buku(&pohonBuku, transaksi.buku);
    returned_buku.status = "Tersedia";
    updateBukuStatus(returned_buku);

    transaksi.hari_pengembalian = current_date;

    for (int i = 0; i < 100; i++)
    {
        if (data_transaksi[i].id == transaksi.id)
        {
            data_transaksi[i] = transaksi;
            break;
        }
    }

    // delete transaksi

    cout << "Terima kasih telah mengembalikan buku. Transaksi selesai." << endl;
}

#endif