int isEmptyQueue() {
//     if (list_antrian.top == 0;){
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int deleteQueueByEmail(string buku) {
//     if (isEmpty() == 1) {
//         return 0;
//     } else {
//         bool found = false;
//         for (int i = 0; i < list_antrian.top; i++) {
//             if (list_antrian.email[i].buku == buku) {
//                 string pop = list_antrian.email[i].data;
//                 cout << "Data " << pop << " dari kelompok " << kelompok << " telah keluar dari antrian." << endl;
//                 for (int j = i; j < list_antrian.top - 1; j++) {
//                     list_antrian.isi[j] = list_antrian.isi[j + 1];
//                 }
//                 list_antrian.top--;
//                 found = true;
//                 break;
//             }
//         }
//         if (!found) {
//             cout << "Tidak ada data dari kelompok " << kelompok << " dalam antrian." << endl;
//         }
//     }
// }