#include "Buku.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
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
        std::cout << "Kode Buku    : " << P->info.kodeBuku << std::endl;
        std::cout << "Judul        : " << P->info.judul << std::endl;
        std::cout << "Tahun Terbit : " << P->info.thnTerbit << std::endl << std::endl;
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

address findElm(List L, infotype x) {
    address P = L.First;

    while (P != Nil) {
        if (P->info.kodeBuku == x.kodeBuku) return P;
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

void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;

    if (P->next != Nil) P->next->prev = Prec;

    P->next = Nil;
    P->prev = Nil;
}

void deleteElm(List &L, std::string kodeBuku, bool &status) {
    address P = L.First;
    status = false;

    while (P != Nil && P->info.kodeBuku != kodeBuku) {
        P = P->next;
    }

    if (P == Nil) return;

    if (P == L.First) {
        deleteFirst(L, P);
    } else if (P == L.Last) {
        deleteLast(L, P);
    } else {
        deleteAfter(P->prev, P);
    }

    dealokasi(P);
    status = true;
}