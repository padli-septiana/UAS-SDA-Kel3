#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Buku
{
    int id;
    string judul;
    string pengarang;
    bool tersedia;
};

struct Transaksi
{
    int id_transaksi;
    Buku buku;
    string tanggal_pinjam;
    int batas_pengembalian;
    string hari_pengembalian;
};

struct Antrian
{
    int no_antrian;
    Transaksi transaksi;
};

struct Node
{
    Antrian data;
    Node *next;
};

class AntrianQueue
{
private:
    Node *front;
    Node *rear;

public:
    AntrianQueue();
    ~AntrianQueue();
    void enqueue(const Antrian &data);
    void dequeue();
    bool isEmpty() const;
    void displayQueue() const;
};

AntrianQueue::AntrianQueue()
{
    front = nullptr;
    rear = nullptr;
}

AntrianQueue::~AntrianQueue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

void AntrianQueue::enqueue(const Antrian &data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void AntrianQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    Node *temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr)
    {
        rear = nullptr;
    }
}

bool AntrianQueue::isEmpty() const
{
    return (front == nullptr);
}

void AntrianQueue::displayQueue() const
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Node *temp = front;
    while (temp != nullptr)
    {
        cout << "No Antrian: " << temp->data.no_antrian << ", "
             << "ID Transaksi: " << temp->data.transaksi.id_transaksi << ", "
             << "Judul Buku: " << temp->data.transaksi.buku.judul << ", "
             << "Tanggal Pinjam: " << temp->data.transaksi.tanggal_pinjam << ", "
             << "Batas Pengembalian: " << temp->data.transaksi.batas_pengembalian << ", "
             << "Hari Pengembalian: " << temp->data.transaksi.hari_pengembalian << endl;
        temp = temp->next;
    }
}

vector<Buku> daftarBuku = {
    {1, "Buku A", "Pengarang A", true},
    {2, "Buku B", "Pengarang B", false},
    {3, "Buku C", "Pengarang C", true}};

void tampilkanDaftarBuku()
{
    cout << "Daftar Buku:" << endl;
    for (const auto &buku : daftarBuku)
    {
        cout << "ID: " << buku.id << ", "
             << "Judul: " << buku.judul << ", "
             << "Pengarang: " << buku.pengarang << ", "
             << "Tersedia: " << (buku.tersedia ? "Ya" : "Tidak") << endl;
    }
}

Buku pilihBuku(int id)
{
    for (const auto &buku : daftarBuku)
    {
        if (buku.id == id)
        {
            return buku;
        }
    }
    return {0, "", "", false};
}

int main()
{
    AntrianQueue queue;
    int pilihan;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Pilih Menu Peminjaman\n";
        cout << "2. Tampilkan Antrian\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            tampilkanDaftarBuku();

            int idBuku;
            cout << "Pilih ID Buku: ";
            cin >> idBuku;

            Buku bukuDipilih = pilihBuku(idBuku);

            if (bukuDipilih.id == 0)
            {
                cout << "Buku tidak ditemukan." << endl;
                continue;
            }

            if (bukuDipilih.tersedia)
            {
                cout << "Buku tersedia. Lakukan peminjaman." << endl;
                // Lakukan proses peminjaman
            }
            else
            {
                char masukAntrian;
                cout << "Buku tidak tersedia. Mau masuk antrian? (y/n): ";
                cin >> masukAntrian;

                if (masukAntrian == 'y' || masukAntrian == 'Y')
                {
                    static int noAntrian = 1;
                    Transaksi tempTrans;
                    tempTrans.id_transaksi = noAntrian;
                    tempTrans.buku = bukuDipilih;
                    cout << "Masukkan Tanggal Pinjam: ";
                    cin >> tempTrans.tanggal_pinjam;
                    cout << "Masukkan Batas Pengembalian (hari): ";
                    cin >> tempTrans.batas_pengembalian;
                    cout << "Masukkan Hari Pengembalian: ";
                    cin >> tempTrans.hari_pengembalian;

                    Antrian tempQueue;
                    tempQueue.no_antrian = noAntrian++;
                    tempQueue.transaksi = tempTrans;

                    queue.enqueue(tempQueue);
                    cout << "Anda telah masuk dalam antrian." << endl;
                }
            }
        }
        else if (pilihan == 2)
        {
            queue.displayQueue();
        }
        else if (pilihan == 3)
        {
            break;
        }
        else
        {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
