#include "boolean.h"
#include "../WordMachine/wordmachine.h"
#include "../linemachine/linemachine.h"

#ifndef LISTPENYANYI_H
#define LISTPENYANYI_H

/* Kamus Umum */

#define PenyanyiMax 100

/* Definisi elemen dan koleksi objek */
typedef char NamaPenyanyi;
typedef int ElType;
typedef int IdxType;


typedef struct
{
	ElType IdPenyanyi[PenyanyiMax]; 
	Kalimat NamaPenyanyi[PenyanyiMax];
	int NEff;
} ListPenyanyi;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah ListPenyanyi, cara deklarasi dan akses: */
/* Deklarasi : T : ListPenyanyi */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeListPenyanyi (ListPenyanyi *LP);
// {
//     (*LP).NEff = 0;
// }
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */\

void AddPenyanyi (ListPenyanyi * LP, Kalimat Nama);
// {
//     (*LP).IdPenyanyi[(*LP).NEff] = (*LP).NEff + 1;
//     (*LP).NamaPenyanyi[(*LP).NEff] = Nama;
//     (*LP).NEff += 1;
// }

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int JumlahPenyanyi (ListPenyanyi LP);
// {
//     return LP.NEff;
// }
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

Kalimat GetNamaPenyanyi (ListPenyanyi LP, IdxType i);
// {
//     Word NamaPenyanyi;

//     if (IsIdxEff(LP, i))
//     {
//         NamaPenyanyi = LP.NamaPenyanyi[i-1];
//     }

//     return NamaPenyanyi;
// }
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (ListPenyanyi LP, IdxType i);
// {
//     return (i < PenyanyiMax);
// }
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEff (ListPenyanyi LP, IdxType i);
// {
//     return (i >= 0 && i <= LP.NEff);
// }
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (ListPenyanyi LP);
// {
//     return LP.NEff == 0;
// }
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (ListPenyanyi LP);
// {
//     return LP.NEff = PenyanyiMax;
// }
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */


#endif