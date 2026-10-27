# <h1 align="center">Laporan Praktikum Modul 6 DOUBLY LINKED LIST (BAGIAN PERTAMA) </h1>

<p align="center">Muhammad Farrel Argiyanto - 109082500018</p>

## Dasar Teori

Doubly Linked List merupakan struktur data dinamis yang setiap node-nya memiliki dua pointer, yaitu `next` dan `prev`. Pointer `next` digunakan untuk menunjuk node berikutnya, sedangkan pointer `prev` digunakan untuk menunjuk node sebelumnya. Struktur ini memiliki dua pointer utama, yaitu `first` yang menunjuk node pertama dan `last` yang menunjuk node terakhir. Jika list kosong, pointer `first` dan `last` bernilai `Nil` atau `NULL`. Dengan adanya dua pointer pada setiap node, proses penelusuran data dapat dilakukan dari depan ke belakang maupun dari belakang ke depan.

Operasi dasar pada Doubly Linked List meliputi penyisipan atau *insert* dan penghapusan atau *delete*. Operasi penyisipan terdiri dari `insertFirst()` untuk menambahkan node di awal list, `insertLast()` untuk menambahkan node di akhir list, dan `insertAfter()` untuk menambahkan node setelah node tertentu. Selain itu, terdapat `insertBefore()` untuk menyisipkan node sebelum node tertentu. Dalam proses penyisipan, pointer `next` dan `prev` harus diatur dengan benar agar hubungan antara node baru dan node lainnya tetap terjaga.

Operasi penghapusan pada Doubly Linked List meliputi `deleteFirst()` untuk menghapus node pertama, `deleteLast()` untuk menghapus node terakhir, dan `deleteAfter()` untuk menghapus node setelah node tertentu. Terdapat juga `deleteBefore()` untuk menghapus node sebelum node tertentu. Proses penghapusan dilakukan dengan menghubungkan kembali node yang berada sebelum dan sesudah node yang dihapus. Setelah node dilepaskan dari list, memori yang digunakan dapat dibebaskan melalui proses dealokasi.

Selain operasi penyisipan dan penghapusan, Doubly Linked List juga mendukung operasi pembaruan data (*update*), penampilan data (*view*), dan pencarian (*searching*). Proses tersebut pada dasarnya serupa dengan Singly Linked List, tetapi Doubly Linked List memudahkan akses elemen karena penelusuran dapat dilakukan melalui pointer `next` maupun `prev`. Dengan demikian, proses pencarian dan pengelolaan data dapat dilakukan secara lebih fleksibel.

Dalam implementasinya, Doubly Linked List menggunakan konsep Abstract Data Type (ADT) yang memisahkan deklarasi struktur data dan fungsi dari implementasi operasinya. Setiap node memiliki bagian `info` untuk menyimpan data, `next` untuk menunjuk node berikutnya, dan `prev` untuk menunjuk node sebelumnya. Struktur list menyimpan pointer `first` dan `last` sebagai penanda awal dan akhir list. Pemisahan deklarasi dan implementasi ke dalam file header `.h` dan file sumber `.cpp` membantu membuat program lebih terstruktur dan mudah dikelola.

Melalui materi Doubly Linked List, pemahaman mengenai penggunaan pointer, pengelolaan hubungan antarnode, serta penerapan operasi penyisipan dan penghapusan dapat ditingkatkan. Struktur ini menjadi salah satu cara untuk mengelola data secara dinamis dengan kemampuan penelusuran dua arah menggunakan bahasa pemrograman C++.

## Guided

### 1. Implementasi Doubly Linked List

#### a. File `Doublylist.h`

```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

// Latihan 1
struct infotype {
    std::string nopol; 
    std::string warna; 
    int thnBuat;      
};
typedef struct elmlist *address;
struct elmlist {
    infotype info;  
    address next;   
    address prev;   
};
struct List {
    address First; 
    address Last;  
};


// Latihan 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2

address findElm(List L, std::string nopol);

// Latihan 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```

#### b. File `Doublylist.cpp`

```cpp
#include "Doublylist.h"

// Latihan 1
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; 
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;   
        std::cout << "warna     : " << P->info.warna << std::endl;   
        std::cout << "tahun     : " << P->info.thnBuat << std::endl; 
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;         
        (L.Last)->next = P;     
        L.Last = P;               
    }
}

// Latihan 2
address findElm(List L, std::string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;     
        (L.First)->prev = Nil; 
        P->next = Nil;         
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;      
        (L.Last)->next = Nil; 
        P->prev = Nil;         
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;     
        (P->next)->prev = Prec; 
        P->next = Nil;            
        P->prev = Nil;           
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P); 
        status = true;
    }
}
```

#### c. File `main.cpp`

```cpp
#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "nomor polisi sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    // Latihan 1
    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    // Latihan 2
    string nopolCari;
    cout << "\nMasukkan Nomor Polisi yang dicari : "; 
    cin >> nopolCari; 
    
    P = findElm(L, nopolCari); 
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl; 
        cout << "Warna        : " << P->info.warna << endl; 
        cout << "Tahun        : " << P->info.thnBuat << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3
    string nopolHapus;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteElm(L, nopolHapus, hapusBerhasil); 

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    return 0;
}
```

### 2. Penjelasan Program

Program ini mengimplementasikan Doubly Linked List untuk menyimpan dan mengelola data kendaraan yang terdiri dari nomor polisi, warna, dan tahun pembuatan kendaraan. Pada file `Doublylist.h`, didefinisikan struktur data kendaraan, struktur node yang memiliki pointer `next` dan `prev`, serta deklarasi fungsi yang digunakan dalam program. File `Doublylist.cpp` berisi implementasi fungsi untuk membuat list, mengalokasikan dan membebaskan memori, menampilkan data, menambahkan node, mencari data, dan menghapus node. Sementara itu, file `main.cpp` digunakan untuk menjalankan dan menguji operasi-operasi tersebut.

Pada awal program, fungsi `CreateList()` digunakan untuk membuat list kosong. Selanjutnya, fungsi `inputData()` menerima input berupa nomor polisi, warna, dan tahun pembuatan kendaraan. Sebelum data dimasukkan, fungsi `findElm()` digunakan untuk memeriksa apakah nomor polisi sudah terdaftar. Jika belum terdaftar, data dibuat menjadi node baru menggunakan `alokasi()` dan ditambahkan ke akhir list dengan `insertLast()`. Setelah empat kali input, fungsi `printInfo()` menampilkan data kendaraan dengan menelusuri list dari node terakhir menggunakan pointer `prev`.

Pada latihan kedua, program meminta pengguna memasukkan nomor polisi yang ingin dicari. Fungsi `findElm()` menelusuri node dari awal list menggunakan pointer `next`. Jika nomor polisi ditemukan, program menampilkan nomor polisi, warna, dan tahun kendaraan. Jika tidak ditemukan, program menampilkan pesan bahwa data tidak tersedia. Pada latihan ketiga, pengguna memasukkan nomor polisi kendaraan yang ingin dihapus. Fungsi `deleteElm()` mencari data tersebut dan menentukan operasi penghapusan yang sesuai, yaitu `deleteFirst()` jika node berada di awal, `deleteLast()` jika berada di akhir, atau `deleteAfter()` jika berada di tengah list. Node yang berhasil dihapus kemudian dibebaskan memorinya menggunakan `dealokasi()`. Terakhir, fungsi `printInfo()` dipanggil kembali untuk menampilkan data kendaraan yang masih tersimpan. Melalui program ini, penerapan Doubly Linked List dalam pengelolaan data kendaraan, pencarian berdasarkan nomor polisi, dan penghapusan node dapat dipahami.

## Unguided

### Membuat ADT Doubly Linked List, mencari elemen dengan nomor polisi D001, dan menghapus elemen dengan nomor polisi D003.

##### Doublylist.h

```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

struct infotype {
    std::string nopol;
    std::string warna;
    int thnBuat;
};

typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, std::string nopol);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```

##### Doublylist.cpp

```cpp
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.Last;

    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }

    while (P != Nil) {
        std::cout << "Nomor Polisi : " << P->info.nopol << std::endl;
        std::cout << "Warna        : " << P->info.warna << std::endl;
        std::cout << "Tahun        : " << P->info.thnBuat << std::endl;
        std::cout << std::endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (P == Nil) return;

    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, std::string nopol) {
    address P = L.First;

    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }

    return Nil;
}

void deleteFirst(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
        return;
    }

    P = L.First;

    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;
        L.First->prev = Nil;
    }

    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.Last == Nil) {
        P = Nil;
        return;
    }

    P = L.Last;

    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;
        L.Last->next = Nil;
    }

    P->next = Nil;
    P->prev = Nil;
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }

    P = Prec->next;

    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P == Nil) return;

    if (P == L.First) {
        deleteFirst(L, P);
    } else if (P == L.Last) {
        deleteLast(L, P);
    } else {
        address Prec = P->prev;
        deleteAfter(L, Prec, P);
    }

    dealokasi(P);
    status = true;
}
```

##### main.cpp

```cpp
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

    cout << "--- PENCARIAN NOMOR POLISI ---" << endl;
    address P = findElm(L, "D001");

    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data D001 tidak ditemukan." << endl;
    }

    cout << "\n--- PENGHAPUSAN NOMOR POLISI ---" << endl;
    bool status;
    deleteElm(L, "D003", status);

    if (status) {
        cout << "Data D003 berhasil dihapus." << endl;
    } else {
        cout << "Data D003 tidak ditemukan." << endl;
    }

    cout << "\n--- DATA LIST SETELAH PENGHAPUSAN ---" << endl;
    printInfo(L);

    while (L.First != Nil) {
        address nodeHapus;
        deleteFirst(L, nodeHapus);
        dealokasi(nodeHapus);
    }

    return 0;
}
```

### Output Unguided 1

#### Output 1

![Screenshot Output Unguided 1](https://github.com/Farrel-13/Laporan_Praktikum06/blob/main/foto_output/ouputno1.png?raw=true)
![Screenshot Output Unguided 1](https://github.com/Farrel-13/Laporan_Praktikum06/blob/main/foto_output/ouputno2.png?raw=true)


Program ini menerapkan Doubly Linked List untuk mengelola data kendaraan yang terdiri dari nomor polisi, warna, dan tahun pembuatan. File Doublylist.h berisi deklarasi struktur data dan fungsi, sedangkan Doublylist.cpp berisi implementasi operasi linked list. File main.cpp digunakan untuk menjalankan latihan.

Pada latihan pertama, program menerima empat data kendaraan dan memasukkannya ke akhir list menggunakan insertLast(). Sebelum data ditambahkan, fungsi findElm() memeriksa apakah nomor polisi sudah terdaftar. Fungsi printInfo() menampilkan data kendaraan dengan menelusuri list dari belakang ke depan menggunakan pointer prev.

Pada latihan kedua, fungsi findElm() digunakan untuk mencari kendaraan dengan nomor polisi D001. Jika ditemukan, informasi kendaraan ditampilkan. Pada latihan ketiga, fungsi deleteElm() digunakan untuk menghapus kendaraan dengan nomor polisi D003. Proses penghapusan disesuaikan dengan posisi node, yaitu menggunakan deleteFirst(), deleteLast(), atau deleteAfter(). Setelah penghapusan, program menampilkan data yang tersisa dan membebaskan memori node sebelum berakhir.


## Kesimpulan

Berdasarkan praktikum Modul 6 tentang Doubly Linked List (Bagian Pertama), dapat disimpulkan bahwa Doubly Linked List merupakan struktur data dinamis yang setiap nodenya memiliki pointer next dan prev, sehingga penelusuran data dapat dilakukan ke arah berikutnya maupun sebelumnya. Pada bagian Unguided, Doubly Linked List diterapkan untuk menyimpan data kendaraan yang terdiri dari nomor polisi, warna, dan tahun pembuatan. Operasi yang digunakan meliputi pembuatan list, alokasi dan dealokasi memori, penambahan elemen di akhir list menggunakan insertLast(), pencarian data menggunakan findElm(), serta penghapusan elemen menggunakan deleteFirst(), deleteLast(), dan deleteAfter(). Hasil pengujian menunjukkan bahwa data kendaraan dengan nomor polisi D001 dapat dicari, sedangkan data kendaraan dengan nomor polisi D003 dapat dihapus dari list. Melalui praktikum ini, pemahaman mengenai penggunaan pointer ganda, pengelolaan memori dinamis, dan manipulasi elemen pada Doubly Linked List dapat ditingkatkan.


## Referensi

[1] Tim Praktikum Struktur Data. (t.t.). Modul 6: Doubly Linked List (Bagian Pertama). Modul Praktikum Struktur Data, hlm. 51–58.

[2] Pai, G. A. V. (2023). Linked Lists. Dalam A Textbook of Data Structures and Algorithms 1. Wiley. https://doi.org/10.1002/9781394192076.ch6 
Wiley Online Library

[3] Morin, P. (2013). Open Data Structures: An Introduction. Athabasca University Press. https://opendatastructures.org/
