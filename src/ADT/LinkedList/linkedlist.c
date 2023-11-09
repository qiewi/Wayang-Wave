#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *value = (ElmtList *) malloc(sizeof (ElmtList));

    if (value != Nil)
    {
        Info(value) = X;
        Next(value) = Nil;
        return value;
    } else
    {
        return Nil;
    }
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address p = First(L);

    if (IsEmpty(L))
    {
        return Nil;
    } else
    {
        while (p != Nil)
        {
            if (isKalimatEqual(JudulLagu(p), X.JudulLagu) && isKalimatEqual(NamaAlbum(p), X.NamaAlbum) && isKalimatEqual(NamaPenyanyi(p), X.NamaPenyanyi))
            {
                return true;
            } else
            {
                p = Next(p);
            }
        }

        return false;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
// Bedanya sama yang address : Elemennya harus dialokasi terlebih dahulu
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address p = Alokasi(X);

    if (p != Nil)
    {
        InsertFirst(L, p);
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address p = Alokasi(X);

    if (p != Nil)
    {
        InsertLast(L, p);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p;
    DelFirst(L, &p);
    *X = Info(p);
    Dealokasi(&p);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address p;
    DelLast(L, &p);
    *X = Info(p);
    Dealokasi(&p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address p = First(*L);

    if (IsEmpty(*L))
    {
        InsertFirst(L, P);
    } else
    {
        while (Next(p) != Nil)
        {
            p = Next(p);
        }

        // Next(p) = Nil, artinya p sudah menunjuk ke elemen terakhir list L
        Next(p) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(*P);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address p = First(*L);
    address prev = Nil;

    while (p != Nil && !isKalimatEqual(JudulLagu(p), X.JudulLagu) && !isKalimatEqual(NamaAlbum(p), X.NamaAlbum) && !isKalimatEqual(NamaPenyanyi(p), X.NamaPenyanyi))
    {
        prev = p;
        p = Next(p);
    }

    if (p != Nil)   // X ada
    {
        if (p == First(*L))
        {
            DelFirst(L, &p);
        } else
        {
            DelAfter(L, &p, prev);
        }
    }

    Dealokasi(&p);
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    *P = First(*L);

    if (Next(*P) == Nil)
    {
        First(*L) = Nil;
    } else
    {
        address prev = *P;
        
        while (Next(Next(prev)) != Nil)
        {
            prev = Next(prev);
        }

        // Next(*P) = Nil
        DelAfter(L, P, prev);
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");

    if (!IsEmpty(L))
    {
        address p = First(L);

        while (p != Nil)
        {
            printf("{%s, %s, %s}", NamaPenyanyi(p), NamaAlbum(p), JudulLagu(p));
            p = Next(p);
            if (p != Nil)
            {
                printf(",");
            }
        }
    }

    printf("]\n");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    address p = First(L);

    while (p != Nil)
    {
        count += 1;
        p = Next(p);
    }

    return count;
}