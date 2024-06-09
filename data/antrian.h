#ifndef ANTRIAN_H
#define ANTRIAN_H

#include <iostream>
#include 'transaksi.h'
#include 'buku.h'

using namespace std;

int MaksAntrian = 5;

struct DataAntrian
{
    int id;
    string nama;
    string alamat;
    string no_telp;
    string email;
    int buku;
}

struct Antrian
{
    int top;
    DataAntrian data[MaksAntrian];
} q;

Antrian.top = 0;

bool isAntrianEmpty()
{
    if (Antrian.top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isAntrianFull()
{
    if (Antrian.top == MaksAntrian)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void tambahAntrian(DataAntrian data)
{
    if (isAntrianFull())
    {
        cout << "Antrian sudah penuh" << endl;
    }
    else
    {
        Antrian.data[Antrian.top] = data;
        Antrian.top++;
    }
}

void hapusAntrian()
{
    if (isAntrianEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        DataAntrian pop = Antrian.data[0];
        int i;
        while (i < Antrian.top)
        {
            Antrian.data[i - 1] = Antrian.data[i];
            i++;
        }
        Antrian.top--;
    }
}

void displayAntrian()
{
    if (!isAntrianEmpty())
    {
        cout << "Antrian" << endl;
        for (int i = 0; i < Antrian.top; i++)
        {
            cout << "Data: " << Antrian.data[i].nama << " - " << Antrian.data[i].buku << endl;
        }
    }
    else
    {
        cout << "Tidak ada data" << enld;
    }
}

// struct Antrian
// {
//     int id;
//     int no_antrian;
//     Transaksi data;
//     int id_buku;
// } q;

// Antrian antrian[100];

// isEmptyAntrian()
// {
//     if (q.id == 0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// isFullAntrian()
// {
//     if (q.id == 100)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void tambahAntrian(Transaksi data)
// {
//     if (isFullAntrian())
//     {
//         cout << "Antrian sudah penuh" << endl;
//     }
//     else
//     {
//         q.id++;
//         q.no_antrian = q.id;
//         q.data = data;
//         antrian[q.id] = q;
//     }
// }

// void hapusAntrian()
// {
//     if (isEmptyAntrian())
//     {
//         cout << "Antrian kosong" << endl;
//     }
//     else
//     {
//         for (int i = 1; i <= q.id; i++)
//         {
//             antrian[i] = antrian[i + 1];
//         }
//         q.id--;
//     }
// }

// void tampilAntrian()
// {
//     if (isEmptyAntrian())
//     {
//         cout << "Antrian kosong" << endl;
//     }
//     else
//     {
//         for (int i = 1; i <= q.id; i++)
//         {
//             cout << "No Antrian : " << antrian[i].no_antrian << endl;
//             cout << "Nama : " << antrian[i].data.nama << endl;
//             cout << "Jenis Transaksi : " << antrian[i].data.jenis_transaksi << endl;
//             cout << "Nominal : " << antrian[i].data.nominal << endl;
//             cout << "Tanggal : " << antrian[i].data.tanggal << endl;
//             cout << "Status : " << antrian[i].data.status << endl;
//             cout << endl;
//         }
//     }
// }

// void cariAntrian(int no_antrian)
// {
//     if (isEmptyAntrian())
//     {
//         cout << "Antrian kosong" << endl;
//     }
//     else
//     {
//         for (int i = 1; i <= q.id; i++)
//         {
//             if (antrian[i].no_antrian == no_antrian)
//             {
//                 cout << "No Antrian : " << antrian[i].no_antrian << endl;
//                 cout << "Nama : " << antrian[i].data.nama << endl;
//                 cout << "Jenis Transaksi : " << antrian[i].data.jenis_transaksi << endl;
//                 cout << "Nominal : " << antrian[i].data.nominal << endl;
//                 cout << "Tanggal : " << antrian[i].data.tanggal << endl;
//                 cout << "Status : " << antrian[i].data.status << endl;
//                 cout << endl;
//             }
//         }
//     }
// }

// void updateAntrian(int no_antrian, Transaksi data)
// {
//     if (isEmptyAntrian())
//     {
//         cout << "Antrian kosong" << endl;
//     }
//     else
//     {
//         for (int i = 1; i <= q.id; i++)
//         {
//             if (antrian[i].no_antrian == no_antrian)
//             {
//                 antrian[i].data = data;
//             }
//         }
//     }
// }

// #endif