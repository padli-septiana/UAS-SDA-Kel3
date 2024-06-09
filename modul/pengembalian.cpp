#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "../data/transaksi.h"
#include "peminjaman.cpp"
#include "cek_denda.h"
#include "utils.h"

using namespace std;

// struct TreeNode {
//     transaksi data;
//     TreeNode *left;
//     TreeNode *right;
// };

TreeNode* deleteNode(TreeNode* root, int id) {
    if (root == nullptr) return root;

    if (id < root->data.id)
        root->left = deleteNode(root->left, id);
    else if (id > root->data.id)
        root->right = deleteNode(root->right, id);
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = root->right;
        while (temp && temp->left != nullptr)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.id);
    }
    return root;
}

time_t convertToDate(const string& date) {
    struct tm tm = {};
    sscanf(date.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    return mktime(&tm);
}


void pengembalian(TreeNode *&root, transaksi list_buku_dipinjam[], int &jumlah_peminjaman) {

    string hari_pengembalian = "2024-06-20";
    double harga_denda = 500.0;
    int batas_waktu_pengembalian = 7; // batas waktu 7 hari
    int id_buku;
    cout << "Masukkan ID Buku yang ingin dikembalikan: ";
    cin >> id_buku;

    bool found = false;
    for (int i = 0; i < jumlah_peminjaman; i++) {
        if (list_buku_dipinjam[i].buku == id_buku) {
            found = true;

            cout << "\n Buku dengan ID " << id_buku << " berhasil dikembalikan." << endl;
            cout << "ID: " << list_buku_dipinjam[i].id << endl;
            cout << "Nama: " << list_buku_dipinjam[i].nama << endl;
            cout << "Alamat: " << list_buku_dipinjam[i].alamat << endl;
            cout << "Nomor Telepon: " << list_buku_dipinjam[i].no_telp << endl;
            cout << "Email: " << list_buku_dipinjam[i].email << endl;
            cout << "ID Buku: " << list_buku_dipinjam[i].buku << endl;
            cout << "Tanggal Peminjaman: " << list_buku_dipinjam[i].tanggal_pinjam << endl;
            cout << "--------------------------" << endl;

            // Hitung hari keterlambatan
            time_t tgl_pinjam = convertToDate(list_buku_dipinjam[i].tanggal_pinjam);
            time_t tgl_kembali = convertToDate(hari_pengembalian);

            int hari_terlambat = std::difftime(tgl_kembali, tgl_pinjam) / (60 * 60 * 24) - batas_waktu_pengembalian;

            if (hari_terlambat > 0) {
                double denda = cek_denda(hari_pengembalian, hari_terlambat, harga_denda);
                cout << "Denda untuk peminjaman A/n " << list_buku_dipinjam[i].nama << " adalah: " << denda << endl;
            } else {
                cout << "Tidak ada denda untuk peminjaman A/n " << list_buku_dipinjam[i].nama << "." << endl << endl;
            }

            root = deleteNode(root, list_buku_dipinjam[i].id);

            for (int j = i; j < jumlah_peminjaman - 1; j++) {
                list_buku_dipinjam[j] = list_buku_dipinjam[j + 1];
            }
            jumlah_peminjaman--;

            // Cek apakah ada antrian untuk buku ini
            for (int k = 0; k < jumlah_antrian; k++) {
                if (list_antrian[k].buku == id_buku) {
                    cout << "Ada antrian untuk buku ini. Memindahkan ke daftar peminjaman." << endl;
                    list_buku_dipinjam[jumlah_peminjaman] = list_antrian[k];
                    list_buku_dipinjam[jumlah_peminjaman].tanggal_pinjam = getCurrentDate();
                    jumlah_peminjaman++;

                    // Hapus dari antrian
                    for (int l = k; l < jumlah_antrian - 1; l++) {
                        list_antrian[l] = list_antrian[l + 1];
                    }
                    jumlah_antrian--;

                    break; // Hanya satu orang yang dapat meminjam buku ini berikutnya
                }
            }
            break;
        }
    }

    if (!found) {
        cout << "Buku dengan ID " << id_buku << " tidak ditemukan dalam daftar peminjaman." << endl;
    }
}

// contoh main
int main() {
    TreeNode *root = nullptr;
    char choice;
    int pilihan;

    do {
        cout << "1. Peminjaman Buku\n2. Pengembalian Buku\nPilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            peminjaman(root);
        } else if (pilihan == 2) {
            pengembalian(root, list_buku_dipinjam, jumlah_peminjaman);
        } else {
            cout << "Pilihan tidak valid." << endl;
        }

        cout << "Apakah Anda ingin melakukan transaksi lagi? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}