#include <iostream>
#include "data/buku.h"
#include "data/transaksi.h"
#include "modul/utils.h"
#include "modul/pengembalian.cpp"
#include "modul/peminjaman.cpp"
#include "modul/cek_denda.cpp"
#include "modul/show_buku.cpp"

using namespace std;

int main()
{
    // contoh aja mank
    show_buku();
    peminjaman();
    cek_denda();
    pengembalian();
    return 0;
}