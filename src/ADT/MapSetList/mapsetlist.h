#ifndef MAPSETLIST_H
#define MAPSETLIST_H
#include <stdio.h>
#include "../LineMachine/linemachine.h"
#include "../boolean.h"

/* MODUL MapAlbum
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define AlbumMax 100
#define Undefined -999

// typedef int bool;
typedef int idAlbum;
typedef int address;

// 5
typedef struct
{   
  Kalimat JudulLagu[20];
  address Count;
} SetLagu;

// 4
typedef struct {
	Kalimat NamaAlbum;
	SetLagu IsiLagu; // set Lagu dari suatu album
} MapLagu;

// 3
typedef struct
{
	MapLagu AlbumLagu[10];
	int NEff;
} ListAlbum;

// 2
typedef struct {
	Kalimat NamaPenyanyi;
	ListAlbum ListAlbum; // array of ListAlbum yang dimiliki penyanyi
} MapAlbum;

// 1
typedef struct {
	MapAlbum PenyanyiAlbum[20];
	int NEff;
} ListPenyanyi;


/* Definisi MapAlbum M kosong : M.Count = Nil */
/* M.Count = jumlah element MapAlbum */
/* M.Elements = tempat penyimpanan element MapAlbum */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateListPenyanyi(ListPenyanyi * LP);
// {
// 	(*LP).NEff = 0;
// 	int indeksPenyanyi = (*LP).NEff;
// 	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.Neff = 0;
// 	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.Neff;
// 	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count = 0;
// }

void AddPenyanyi(ListPenyanyi * LP, Kalimat NamaPenyanyi);
// {	
// 	int indeksPenyanyi = (*LP).NEff;
// 	(*LP).PenyanyiAlbum[indeksPenyanyi].NamaPenyanyi = NamaPenyanyi; // Input nama penyanyi pertama
// 	(*LP).NEff += 1; // Jumlah penyanyi nambah satu
// }

Kalimat NamaPenyanyiNow(ListPenyanyi * LP);
// {	
// 	int indeksPenyanyi = LP.NEff - 1;
// 	return LP.PenyanyiAlbum[indeksPenyanyi].NamaPenyanyi.TabLine;
// }

void AddAlbum(ListPenyanyi * LP, Kalimat NamaAlbum);
// {
// 	int indeksPenyanyi = (*LP).NEff; // Penyanyi pertama : 1
// 	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi-1].ListAlbum.Neff // indeksAlbum pertama = 0
// 	(*LP).PenyanyiAlbum[indeksPenyanyi-1].ListAlbum.AlbumLagu[indeksAlbum].NamaAlbum = NamaAlbum; // Nama Album di indeksAlbum
// 	(*LP).PenyanyiAlbum[indeksPenyanyi-1].ListAlbum.Neff += 1; // Jumlah album milik penyanyi tersebut bertambah 1
// }

Kalimat NamaAlbumNow(ListPenyanyi * LP);

void AddLagu(ListPenyanyi * LP, Kalimat NamaLagu);

Kalimat NamaLaguNow(ListPenyanyi * LP);

// {
// 	(*M).Count = Nil;
// }
/* I.S. Sembarang */
/* F.S. Membuat sebuah MapAlbum M kosong berkapasitas MaxEl */
/* Ciri MapAlbum kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
// boolean IsMapAlbumEmpty(MapAlbum M);
/* Mengirim true jika MapAlbum M kosong*/
/* Ciri MapAlbum kosong : count bernilai Nil */

// boolean IsMapAlbumFull(MapAlbum M);
/* Mengirim true jika MapAlbum M penuh */
/* Ciri MapAlbum penuh : count bernilai MaxEl */

// void addPenyanyi(MapAlbum *MA, Kalimat NamaPenyanyi);
// {
// 	(*MapAlbum).AlbumPenyanyi[IdPenyanyi].AlbumOwned.IdAlbum[idAlbum] = idAlbum +1; // masukin idAlbum
// 	(*MapAlbum).AlbumPenyanyi[IdPenyanyi].AlbumOwned.NamaAlbum[idAlbum] = NamaAlbum; // masukin namaAlbum
// 	(*MapAlbum).AlbumPenyanyi[IdPenyanyi].AlbumOwned.NEff += 1; // naikin jumlah Album

// 	(*MapAlbum).AlbumPenyanyi[IdPenyanyi].idPenyanyi = IdPenyanyi + 1; // masukin IdPenyanyi yang punya album
// 	(*MapAlbum).Count += 1; // naikin jumlah album
// }

// /* ********** Operator Dasar MapAlbum ********* */
// valuetype Value(MapAlbum M, keytype k);
// /* Mengembalikan nilai value dengan key k dari M */
// /* Jika tidak ada key k pada M, akan mengembalikan Undefined */

// void Insert(MapAlbum *M, keytype k, valuetype v);
// /* Menambahkan Elmt sebagai elemen MapAlbum M. */
// /* I.S. M mungkin kosong, M tidak penuh
//         M mungkin sudah beranggotakan v dengan key k */
// /* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

// void Delete(MapAlbum *M, keytype k);
// /* Menghapus Elmt dari MapAlbum M. */
// /* I.S. M tidak kosong
//         element dengan key k mungkin anggota / bukan anggota dari M */
// /* F.S. element dengan key k bukan anggota dari M */

// boolean IsMember(MapAlbum M, keytype k);
// /* Mengembalikan true jika k adalah member dari M */

#endif