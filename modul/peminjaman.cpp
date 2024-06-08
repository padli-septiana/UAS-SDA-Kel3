#include <iostream>
#include "../data/transaksi.h"
#include "../data/buku.h"
#include "../utils.h"
using namespace std;

transaksi list_buku_dipinjam[100];
transaksi list_antrian[100];
int jumlah_peminjaman = 0;
int jumlah_antrian = 0;

struct TreeNode
{
    transaksi data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *insertTree(TreeNode *node, transaksi data)
{
    if (node == nullptr)
    {
        TreeNode *temp = new TreeNode;
        temp->data = data;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }

    if (data.id < node->data.id)
    {
        node->left = insertTree(node->left, data);
    }
    else if (data.id > node->data.id)
    {
        node->right = insertTree(node->right, data);
    }

    return node;
}

bool findTree(TreeNode *root, int cari)
{
    int level = 0;
    TreeNode *temp = root;

    while (temp != nullptr)
    {
        level++;
        if (temp->data.buku == cari)
        {
            cout << "Data " << cari << " ditemukan pada level " << level << endl;
            cout << "Nama: " << temp->data.nama << endl;
            cout << "Alamat: " << temp->data.alamat << endl;
            cout << "Nomor Telepon: " << temp->data.no_telp << endl;
            cout << "Email: " << temp->data.email << endl;
            cout << "ID Buku: " << temp->data.buku << endl;
            return true;
        }
        else if (temp->data.buku > cari)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}

void deleteTree(TreeNode *&root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr; 
    }
}

void peminjaman(TreeNode *&root)
{
    string currentDate = getCurrentDate();
    string nama;
    string alamat;
    string nomor_telepon;
    string email;
    int id_buku;

    cout << "Masukkan Nama: ";
    cin >> nama;

    cout << "Masukkan Alamat: ";
    cin >> alamat;

    cout << "Masukkan Nomor Telepon: ";
    cin >> nomor_telepon;

    cout << "Masukkan Email: ";
    cin >> email;

    cout << "Masukkan ID Buku yang ingin dipinjam: ";
    cin >> id_buku;

    // cout << "Nama: " << nama << endl;
    // cout << "Alamat: " << alamat << endl;
    // cout << "Nomor Telepon: " << nomor_telepon << endl;
    // cout << "Email: " << email << endl;
    // cout << "ID Buku: " << id_buku << endl;
    for (int i = 0; i < jumlah_antrian; ++i)
    {
        root = insertTree(root, list_antrian[i]);
    }

    for (int i = 0; i < jumlah_peminjaman; ++i)
    {
        root = insertTree(root, list_buku_dipinjam[i]);
    }

    if (findTree(root, id_buku))
    {
        cout << "\n Masuk ke antrian \n"
             << endl;
        list_antrian[jumlah_antrian].id = jumlah_antrian + 1;
        list_antrian[jumlah_antrian].nama = nama;
        list_antrian[jumlah_antrian].alamat = alamat;
        list_antrian[jumlah_antrian].no_telp = nomor_telepon;
        list_antrian[jumlah_antrian].email = email;
        list_antrian[jumlah_antrian].buku = id_buku;

        cout << "ID: " << list_antrian[jumlah_antrian].id << endl;
        cout << "Nama: " << list_antrian[jumlah_antrian].nama << endl;
        cout << "Alamat: " << list_antrian[jumlah_antrian].alamat << endl;
        cout << "Nomor Telepon: " << list_antrian[jumlah_antrian].no_telp << endl;
        cout << "Email: " << list_antrian[jumlah_antrian].email << endl;
        cout << "ID Buku: " << list_antrian[jumlah_antrian].buku << endl;
        cout << "--------------------------" << endl;


        jumlah_antrian++;
    }
    else
    {
        cout << "\n Masuk ke peminjaman \n"
             << endl;
        list_buku_dipinjam[jumlah_peminjaman].id = jumlah_peminjaman + 1;
        list_buku_dipinjam[jumlah_peminjaman].nama = nama;
        list_buku_dipinjam[jumlah_peminjaman].alamat = alamat;
        list_buku_dipinjam[jumlah_peminjaman].no_telp = nomor_telepon;
        list_buku_dipinjam[jumlah_peminjaman].email = email;
        list_buku_dipinjam[jumlah_peminjaman].buku = id_buku;
        list_buku_dipinjam[jumlah_peminjaman].tanggal_pinjam = currentDate;

        cout << "ID: " << list_buku_dipinjam[jumlah_peminjaman].id << endl;
        cout << "Nama: " << list_buku_dipinjam[jumlah_peminjaman].nama << endl;
        cout << "Alamat: " << list_buku_dipinjam[jumlah_peminjaman].alamat << endl;
        cout << "Nomor Telepon: " << list_buku_dipinjam[jumlah_peminjaman].no_telp << endl;
        cout << "Email: " << list_buku_dipinjam[jumlah_peminjaman].email << endl;
        cout << "ID Buku: " << list_buku_dipinjam[jumlah_peminjaman].buku << endl;
        cout << "Tanggal Peminjaman: " << list_buku_dipinjam[jumlah_peminjaman].tanggal_pinjam << endl;
        cout << "--------------------------" << endl;

        jumlah_peminjaman++;
    }
    deleteTree(root);

}

void printTransaksi(transaksi arr[], int jumlah)
{
    for (int i = 0; i < jumlah; ++i)
    {
        cout << "ID: " << arr[i].id << endl;
        cout << "Nama: " << arr[i].nama << endl;
        cout << "Alamat: " << arr[i].alamat << endl;
        cout << "Nomor Telepon: " << arr[i].no_telp << endl;
        cout << "Email: " << arr[i].email << endl;
        cout << "ID Buku: " << arr[i].buku << endl;
        if (arr[i].tanggal_pinjam != "")
        {
            cout << "Tanggal Peminjaman: " << arr[i].tanggal_pinjam << endl;
        }
        cout << "--------------------------" << endl;
    }


}

void deleteQueue(int id_buku)
{
    bool found = false;

    for (int i = 0; i < jumlah_antrian; ++i)
    {
        if (list_antrian[i].buku == id_buku)
        {
            found = true;
            cout << "Data dengan ID Buku " << id_buku << " dikeluarkan dari antrian." << endl;

            for (int j = i; j < jumlah_antrian - 1; ++j)
            {
                list_antrian[j] = list_antrian[j + 1];
            }
            jumlah_antrian--;
            break;
        }
    }

    if (!found)
    {
        cout << "Data dengan ID Buku " << id_buku << " tidak ditemukan dalam antrian." << endl;
    }
}


// int main()
// {
//     TreeNode *root = nullptr;
//     char choice;

//     do
//     {
//         peminjaman(root);
//         cout << "Apakah Anda ingin memasukkan data lagi? (y/n): ";
//         cin >> choice;
//     } while (choice == 'y' || choice == 'Y');

//     cout << "Data dari list antrian:" << endl;
//     printTransaksi(list_antrian, jumlah_antrian);

//     cout << "Data dari list buku yang sedang dipinjam:" << endl;
//     printTransaksi(list_buku_dipinjam, jumlah_peminjaman);


//     int id_buku_to_delete;
//     cout << "Masukkan ID Buku yang ingin dihapus dari antrian: ";
//     cin >> id_buku_to_delete;

//     deleteQueue(id_buku_to_delete);

//     cout << "Data antrian setelah penghapusan:" << endl;
//     printTransaksi(list_antrian, jumlah_antrian);

//     return 0;
// }

