#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;

    cout << "Masukkan nomor polisi: ";
    cin >> data.nopol;

    cout << "Masukkan warna kendaraan: ";
    cin >> data.warna;

    cout << "Masukkan tahun kendaraan: ";
    cin >> data.thnBuat;

    if (findElm(L, data.nopol) == Nil) {
        insertLast(L, alokasi(data));
        cout << "Data berhasil ditambahkan." << endl;
    } else {
        cout << "Nomor polisi sudah terdaftar." << endl;
    }

    cout << endl;
}

int main() {
    List L;
    CreateList(L);

    for (int i = 0; i < 4; i++) {
        inputData(L);
    }

    cout << "\n--- DATA LIST 1 ---" << endl;
    printInfo(L);

    // Latihan 2: mencari kendaraan D001
    cout << "--- PENCARIAN NOMOR POLISI D001 ---" << endl;

    address P = findElm(L, "D001");

    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi D001 tidak ditemukan."
             << endl;
    }

    // Latihan 3: menghapus kendaraan D003
    cout << "\n--- PENGHAPUSAN NOMOR POLISI D003 ---" << endl;

    bool status;
    deleteElm(L, "D003", status);

    if (status) {
        cout << "Data dengan nomor polisi D003 berhasil dihapus."
             << endl;
    } else {
        cout << "Data dengan nomor polisi D003 tidak ditemukan."
             << endl;
    }

    cout << "\n--- DATA LIST SETELAH PENGHAPUSAN ---" << endl;
    printInfo(L);

    // Membebaskan seluruh node sebelum program berakhir
    while (L.First != Nil) {
        address nodeHapus;
        deleteFirst(L, nodeHapus);
        dealokasi(nodeHapus);
    }

    return 0;
}