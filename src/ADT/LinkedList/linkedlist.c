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
            if (Info(p) == X)
            {
                return p;
            } else
            {
                p = Next(p);
            }
        }

        return p;
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
    address p = Search(*L, X);

    if (p != Nil)   // X ada
    {
        if (p == First(*L))
        {
            DelFirst(L, &p);
        } else
        {
            address prev = First(*L);

            while (Next(prev) != p)
            {
                prev = Next(prev);
            }

            //Next(prev) = p
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
            printf("%d", Info(p));
            p = Next(p);
            if (p != Nil)
            {
                printf(",");
            }
        }
    }

    printf("]");
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

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    address p = First(L);
    infotype info_max = Info(p);

    while (p != Nil)
    {
        if (Info(p) > info_max)
        {
            info_max = Info(p);
        }

        p = Next(p);
    }

    return info_max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    address p = First(L);
    infotype max = Max(L);

    while (Info(p) != Max(L))
    {
        p = Next(p);
    }

    return p;
}

infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    address p = First(L);
    infotype info_min = Info(p);

    while (p != Nil)
    {
        if (Info(p) < info_min)
        {
            info_min = Info(p);
        }

        p = Next(p);
    }

    return info_min;
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    address p = First(L);
    infotype min = Min(L);

    while (Info(p) != Min(L))
    {
        p = Next(p);
    }

    return p;
}
float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    address p = First(L);
    float sum = 0;
    float count = 0;

    while (p != Nil)
    {
        sum += Info(p);
        count += 1;
        p = Next(p);
    }

    float avg = sum/count;
    return avg;
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    List inverse;
    CreateEmpty(&inverse);

    address loc;

    while (First(*L) != Nil)
    {
        DelLast(L, &loc);
        InsertLast(&inverse, loc);
    }

    *L = inverse;
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    First(*L3) = First(*L1);

    if (!IsEmpty(*L1))
    {
        address p = First(*L1);

        while (Next(p) != Nil)
        {
            p = Next(p);
        }

        // p = Nil, L1 sudah habis
        Next(p) = First(*L2);
    } else if (IsEmpty(*L1) && !IsEmpty(*L2))
    {
        First(*L3) = First(*L2);
    }

    First(*L1) = Nil;
    First(*L2) = Nil;
}