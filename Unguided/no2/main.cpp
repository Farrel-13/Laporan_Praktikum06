#include <iostream>
#include "Buku.h"

using namespace std;

void inputData(List &L) {
    infotype data;

    cout << "masukkan kode buku: ";
    cin >> data.kodeBuku;
    cout << "masukkan judul buku: ";
    cin >> data.judul;
    cout << "masukkan tahun terbit: ";
    cin >> data.thnTerbit;

    if (findElm(L, data) == Nil) {
        insertLast(L, alokasi(data));
    } else {
        cout << "kode buku sudah terdaftar" << endl;
    }

    cout << endl;
}

int main() {
    List L;
    CreateList(L);

    for (int i = 0; i < 4; i++) {
        inputData(L);
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);

    infotype cari;
    cout << "Masukkan Kode Buku yang dicari : ";
    cin >> cari.kodeBuku;

    address P = findElm(L, cari);

    if (P != Nil) {
        cout << "\nKode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "Data buku tidak ditemukan." << endl;
    }

    string kodeHapus;
    bool status;

    cout << "\nMasukkan Kode Buku yang akan dihapus : ";
    cin >> kodeHapus;
    deleteElm(L, kodeHapus, status);

    if (status) {
        cout << "Data dengan kode buku " << kodeHapus
             << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan kode buku " << kodeHapus
             << " tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    while (L.First != Nil) {
        address nodeHapus;
        deleteFirst(L, nodeHapus);
        dealokasi(nodeHapus);
    }

    return 0;
}