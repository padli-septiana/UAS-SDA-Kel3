#ifndef LIST_BUKU_H
#define LIST_BUKU_H

#include <iostream>

using namespace std;

struct Buku
{
    int id;
    string judul;
    string penulis;
    string penerbit;
    int tahun_terbit;
    string deskripsi;
    int harga;
    string status;
};

struct treeBuku
{
    Buku data;
    treeBuku *left, *right;
};

treeBuku *pohonBuku, *rootBuku;

Buku data_buku1 = {1, "Bumi Manusia", "Pramoedya Ananta Toer", "Hasta Mitra", 1980, "Bumi Manusia adalah sebuah novel karya Pramoedya Ananta Toer, yang merupakan bagian pertama dari Tetralogi Buru. Novel ini berlatar belakang di Hindia Belanda pada awal abad ke-20 dan mengisahkan kehidupan Minke, seorang pribumi terpelajar yang berusaha menghadapi ketidakadilan kolonial dan menemukan identitasnya. Cerita ini juga menggambarkan hubungannya dengan Nyai Ontosoroh, seorang wanita pribumi yang kuat dan berpengaruh. Melalui 'Bumi Manusia', Pramoedya mengeksplorasi tema-tema sosial, politik, dan budaya, serta kritik terhadap kolonialisme dan perjuangan untuk kebebasan. Novel ini dianggap sebagai salah satu karya sastra Indonesia yang paling penting dan berpengaruh.", 10000, "Tersedia"};
Buku data_buku2 = {2, "The Architecture of Love", "Ika Natassa", "Gramedia Pustaka Utama", 2016, "Architecture of Love adalah sebuah novel karya Ika Natassa, yang mengisahkan perjalanan hidup dan cinta Raia, seorang penulis yang sedang mengalami kebuntuan dalam kariernya. Dalam usahanya mencari inspirasi, Raia melakukan perjalanan ke New York, di mana ia bertemu dengan River, seorang arsitek. Pertemuan ini membuka babak baru dalam hidupnya, di mana keduanya saling berbagi cerita, mimpi, dan luka masa lalu. Melalui interaksi mereka, novel ini mengeksplorasi tema cinta, kehilangan, dan penyembuhan, serta bagaimana dua orang dapat saling mempengaruhi dan menemukan kembali makna hidup. 'The Architecture of Love' menyajikan kisah yang mengharukan dengan latar kota New York yang memukau.", 20000, "Tersedia"};
Buku data_buku3 = {3, "Perahu Kertas", "Dewi Lestari", "Bentang Pustaka", 2009, "Perahu Kertas adalah sebuah novel karya Dewi Dee Lestari yang mengisahkan tentang perjalanan hidup dan cinta dua remaja, Kugy dan Keenan. Kugy adalah seorang gadis yang bercita-cita menjadi penulis dongeng, sementara Keenan adalah seorang pemuda berbakat yang bermimpi menjadi pelukis. Pertemuan mereka membawa petualangan dan tantangan, terutama dalam mengejar impian dan menghadapi realitas kehidupan. Melalui karakter-karakter yang kuat dan alur cerita yang menyentuh, 'Perahu Kertas' mengeksplorasi tema-tema persahabatan, cinta, dan pencarian jati diri. Novel ini telah diadaptasi menjadi film dan mendapatkan banyak apresiasi dari pembaca dan kritikus.", 30000, "Tersedia"};
Buku data_buku4 = {4, "Nanti Kita Cerita Tentang Hari Ini", "Marchella FP", "POP Publisher", 2019, "'NKCTHI' (Nanti Kita Cerita Tentang Hari Ini) adalah sebuah buku karya Marchella FP yang berisi kumpulan pesan, refleksi, dan nasihat yang disusun dalam bentuk cerita pendek dan ilustrasi. Buku ini menyajikan berbagai tema kehidupan sehari-hari, seperti keluarga, persahabatan, cinta, dan self-acceptance, yang ditulis dengan bahasa yang sederhana namun menyentuh. Melalui perspektif yang intim dan personal, 'NKCTHI' mengajak pembaca untuk merenungkan makna dari setiap momen dalam hidup dan menemukan kekuatan dalam menghadapi berbagai tantangan. Buku ini telah menjadi sangat populer di kalangan pembaca muda dan telah diadaptasi menjadi film dengan judul yang sama.", 40000, "Tersedia"};
Buku data_buku5 = {5, "Koala Kumal", "Raditya Dika", "Gagas Media", 2015, "'Koala Kumal' adalah sebuah buku karya Raditya Dika, yang merupakan kumpulan cerita lucu dan refleksi pribadi yang berdasarkan pengalaman hidup penulis. Buku ini menggabungkan humor khas Raditya Dika dengan berbagai kisah tentang cinta, patah hati, dan kejadian sehari-hari yang menggelitik. Setiap cerita disajikan dengan gaya penulisan yang ringan dan menghibur, membuat pembaca tertawa sekaligus merenung. 'Koala Kumal' tidak hanya menawarkan hiburan, tetapi juga pesan-pesan tentang bagaimana menghadapi perubahan dan situasi tidak terduga dalam hidup. Buku ini telah diadaptasi menjadi film yang juga disutradarai oleh Raditya Dika.", 50000, "Tersedia"};
Buku data_buku6 = {6, "The King Bedah Tuntas TPS + B.Inggris SNBT 2023", "Forum Tentor Indonesia", "Forum Edukasi", 2022, "'The King Bedah Tuntas TPS + B.Inggris SNBT 2023' adalah sebuah buku panduan yang dirancang untuk membantu siswa mempersiapkan diri menghadapi Seleksi Nasional Berdasarkan Tes (SNBT) untuk masuk perguruan tinggi di Indonesia. Buku ini menyajikan materi lengkap dan latihan soal yang mencakup Tes Potensi Skolastik (TPS) serta Bahasa Inggris, sesuai dengan format terbaru SNBT 2023. Setiap bagian dilengkapi dengan pembahasan mendetail, strategi pengerjaan soal, dan tips praktis untuk meningkatkan kemampuan serta kepercayaan diri siswa. Dengan pendekatan yang sistematis dan komprehensif, buku ini bertujuan untuk membantu siswa mencapai skor tinggi dalam ujian dan sukses masuk perguruan tinggi impian mereka.", 60000, "Tersedia"};
Buku data_buku7 = {7, "Logika Pemrograman Python", "Abdul Kadir", "Elex Media Komputindo", 2019, "'Logika Pemrograman Python' adalah buku yang ditujukan untuk pemula yang ingin belajar pemrograman menggunakan bahasa Python. Buku ini membahas dasar-dasar logika pemrograman, mulai dari konsep dasar seperti variabel, tipe data, kontrol alur, hingga fungsi dan struktur data. Setiap konsep dijelaskan dengan jelas dan disertai contoh-contoh kode yang mudah dipahami. Buku ini juga menyediakan latihan dan proyek kecil untuk membantu pembaca mempraktikkan apa yang telah mereka pelajari. Dengan pendekatan yang terstruktur dan praktis, 'Logika Pemrograman Python' membantu pembaca membangun fondasi yang kuat dalam pemrograman Python dan mengembangkan keterampilan yang dibutuhkan untuk membuat aplikasi yang efektif.", 70000, "Tersedia"};
Buku data_buku8 = {8, "Pengenalan Machine Leraning dengan Python", "Dios Kurniawan, M.Sc", "Elex Media Komputindo", 2022, "'Pengenalan Machine Learning dengan Python' adalah buku yang ditujukan bagi pemula yang ingin memahami dasar-dasar machine learning menggunakan bahasa pemrograman Python. Buku ini membahas konsep-konsep fundamental machine learning, seperti supervised learning, unsupervised learning, algoritma regresi, klasifikasi, clustering, dan teknik evaluasi model. Selain teori, buku ini juga memberikan contoh implementasi algoritma machine learning menggunakan pustaka Python populer seperti scikit-learn, pandas, dan numpy. Setiap bab dilengkapi dengan latihan praktis dan studi kasus untuk membantu pembaca menerapkan pengetahuan mereka dalam situasi nyata. Dengan pendekatan yang jelas dan aplikatif, buku ini bertujuan untuk membuat pembaca nyaman dengan konsep dan praktik machine learning, sehingga mereka dapat mulai mengembangkan dan menerapkan model machine learning dalam proyek mereka sendiri.", 80000, "Tersedia"};
Buku data_buku9 = {9, "Filosofi Teras", "Henry Manampiring", "Kompas", 2018, "'Filosofi Teras' adalah sebuah buku karya Henry Manampiring yang memperkenalkan dan menguraikan filosofi Stoikisme kepada pembaca modern. Buku ini menjelaskan konsep-konsep utama Stoikisme, seperti ketenangan batin, pengendalian emosi, dan fokus pada hal-hal yang berada dalam kendali kita. Melalui berbagai contoh kehidupan sehari-hari dan refleksi pribadi, Henry Manampiring menunjukkan bagaimana prinsip-prinsip Stoikisme dapat diterapkan untuk menghadapi tantangan hidup, meningkatkan ketahanan mental, dan mencapai kesejahteraan. 'Filosofi Teras' menggabungkan teori filosofis dengan praktik praktis, membuat filosofi kuno ini relevan dan mudah dipahami oleh pembaca masa kini. Buku ini sangat berguna bagi mereka yang mencari panduan untuk hidup yang lebih bijaksana dan tenang.", 90000, "Tersedia"};
Buku data_buku10 = {10, "Filasafat Untuk Pemalas", "Ach. Dhohir Zuhry", "Elex Media Komputindo", 2023, "'Filsafat untuk Pemalas' adalah sebuah buku karya Paul Strathern yang menyajikan konsep-konsep filsafat dalam format yang ringan dan mudah dicerna. Buku ini menggabungkan filsafat klasik dengan humor yang menyegarkan, memperkenalkan pembaca pada berbagai gagasan filosofis dari zaman kuno hingga modern. Melalui narasi yang menghibur, Paul Strathern mengajak pembaca untuk merenungkan pertanyaan-pertanyaan besar tentang kehidupan, kebenaran, dan makna eksistensi manusia. Dengan gaya yang santai namun informatif, 'Filsafat untuk Pemalas' menjadi panduan yang menyenangkan bagi siapa pun yang ingin menjelajahi dunia filsafat tanpa tekanan berlebihan.", 100000, "Tersedia"};

// void show_buku(buku list_buku[], int n, int i)
// {
//     int root = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n)
//     {
//         show_buku(list_buku, n, left);
//     }

//     cout << "ID: " << list_buku[root].id << endl;
//     cout << "Judul: " << list_buku[root].judul << endl;
//     cout << "Penulis: " << list_buku[root].penulis << endl;
//     cout << "Penerbit: " << list_buku[root].penerbit << endl;
//     cout << "Tahun Terbit: " << list_buku[root].tahun_terbit << endl;
//     cout << "Deskripsi: " << list_buku[root].deskripsi << endl;
//     cout << "Harga: " << list_buku[root].harga << endl;
//     cout << endl;

//     if (right < n)
//     {
//         show_buku(list_buku, n, right);
//     }
// }

// void cekDenda(string tanggal_kembali, string tanggal_sekarang)
// {
//     int denda = 0;
//     int hari_keterlambatan = 0;

//     int tahun_kembali = stoi(tanggal_kembali.substr(0, 4));
//     int bulan_kembali = stoi(tanggal_kembali.substr(5, 2));
//     int hari_kembali = stoi(tanggal_kembali.substr(8, 2));

//     int tahun_sekarang = stoi(tanggal_sekarang.substr(0, 4));
//     int bulan_sekarang = stoi(tanggal_sekarang.substr(5, 2));
//     int hari_sekarang = stoi(tanggal_sekarang.substr(8, 2));

//     if (tahun_sekarang > tahun_kembali)
//     {
//         hari_keterlambatan += (tahun_sekarang - tahun_kembali) * 365;
//     }

//     if (bulan_sekarang > bulan_kembali)
//     {
//         hari_keterlambatan += (bulan_sekarang - bulan_kembali) * 30;
//     }

//     if (hari_sekarang > hari_kembali)
//     {
//         hari_keterlambatan += hari_sekarang - hari_kembali;
//     }

//     if (hari_keterlambatan > 7)
//     {
//         denda = (hari_keterlambatan - 7) * 1000;
//     }

//     cout << "Denda: " << denda << endl;
// }

#endif