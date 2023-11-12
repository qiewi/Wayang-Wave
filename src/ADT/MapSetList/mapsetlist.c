#include <stdio.h>
#include "../boolean.h"
#include "../pcolor/pcolor.h"
#include "../LineMachine/linemachine.h"
#include "mapsetlist.h"

/* *** Konstruktor/Kreator *** */
void CreateListPenyanyi(ListPenyanyi * LP)
{
	(*LP).NEff = 0;
	int indeksPenyanyi = (*LP).NEff;
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff = 0;
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff;
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count = 0;
}

void AddPenyanyi(ListPenyanyi * LP, Kalimat NamaPenyanyi)
{	
	int indeksPenyanyi = (*LP).NEff;
	(*LP).PenyanyiAlbum[indeksPenyanyi].NamaPenyanyi = NamaPenyanyi; // Input nama penyanyi pertama
	(*LP).NEff += 1; // Jumlah penyanyi nambah satu
}

Kalimat NamaPenyanyiNow(ListPenyanyi * LP)
{	
	int indeksPenyanyi = (*LP).NEff - 1;
	return (*LP).PenyanyiAlbum[indeksPenyanyi].NamaPenyanyi;
}

int indeksPenyanyi(ListPenyanyi * LP, Kalimat InputPenyanyi)
{	
	int i = 0;

	while (i < (*LP).NEff)
	{
		if (isKalimatEqual((*LP).PenyanyiAlbum[i].NamaPenyanyi, InputPenyanyi))
		{
			return i;
		}
		else
		{
			i++;
		}
	}
	return -1;
}

void AddAlbum(ListPenyanyi * LP, Kalimat NamaAlbum)
{
	int indeksPenyanyi = (*LP).NEff - 1; // Penyanyi pertama : 1
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff; // indeksAlbum pertama = 0
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].NamaAlbum = NamaAlbum; // Nama Album di indeksAlbum
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff += 1; // Jumlah album milik penyanyi tersebut bertambah 1
}

Kalimat NamaAlbumNow(ListPenyanyi * LP)
{
	int indeksPenyanyi = (*LP).NEff - 1;
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff - 1;
	return (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].NamaAlbum;
}

int indeksAlbum(ListPenyanyi * LP, int indeksPenyanyi, Kalimat InputAlbum)
{	
	int i = 0;

	while (i < (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff)
	{
		if (isKalimatEqual((*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[i].NamaAlbum, InputAlbum))
		{
			return i;
		}
		else
		{
			i++;
		}
	}
	return -1;
}

int indeksLagu(ListPenyanyi * LP, int indeksPenyanyi, int indeksAlbum, Kalimat NamaLagu)
{	
	int i = 0;
	while (i < (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count)
	{
		if (isKalimatEqual((*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.JudulLagu[i], NamaLagu))
		{
			return -1;
		}
		else
		{
			i++;
		}
	}
	return (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count;
}

void AddLagu(ListPenyanyi * LP, Kalimat NamaLagu)
{
	int indeksPenyanyi = (*LP).NEff - 1;
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff - 1;
	int indekSLagu = indeksLagu(LP, indeksPenyanyi, indeksAlbum, NamaLagu);
	
	if (indekSLagu != -1)
	{
		(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.JudulLagu[indekSLagu] = NamaLagu;
		(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count += 1;
	}
	else
	{
		printf("\n%sERROR: %sLagu %s sudah ada di dalam album %s.\n", RED, WHITE, NamaLagu.TabLine, (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].NamaAlbum.TabLine);
	}
}

Kalimat NamaLaguNow(ListPenyanyi * LP)
{
	int indeksPenyanyi = (*LP).NEff - 1;
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff - 1;
	int indekSLagu = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count - 1;

	return (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.JudulLagu[indekSLagu];
}

/* Mengirim true jika MapAlbum M penuh */
/* Ciri MapAlbum penuh : count bernilai MaxEl */

// void addAlbum(IdPenyanyi IdPenyanyi, idAlbum idAlbum, MapAlbum * MapAlbum, Kalimat NamaAlbum)
// {
// 	(*MapAlbum).AlbumPenyanyi[IdPenyanyi].AlbumOwned.IdAlbum[idAlbum] = idAlbum +1; // masukin idAlbum
// 	(*MapAlbum).AlbumPenyanyi[IdPenyanyi].AlbumOwned.NamaAlbum[idAlbum] = NamaAlbum; // masukin namaAlbum
// 	(*MapAlbum).AlbumPenyanyi[IdPenyanyi].AlbumOwned.NEff += 1; // naikin jumlah Album

// 	(*MapAlbum).AlbumPenyanyi[IdPenyanyi].idPenyanyi = IdPenyanyi + 1; // masukin IdPenyanyi yang punya album
// 	(*MapAlbum).Count += 1; // naikin jumlah album
// }

// /* ********** Operator Dasar MapAlbum ********* */
// valuetype Value(MapAlbum M, keytype k)
// {
//     for (int i = 0; i < M.Count; i++)
//     {
//         if (M.Elements[i].Key == k)
//         {
// 			return M.Elements[i].Value;
// 		}
//     }

//     return Undefined;
// }
// /* Mengembalikan nilai value dengan key k dari M */
// /* Jika tidak ada key k pada M, akan mengembalikan Undefined */

// void Insert(MapAlbum *M, keytype k, valuetype v)
// {
//   if (!IsMember((*M), k))
//   {
//     (*M).Elements[(*M).Count].Key = k;
//     (*M).Elements[(*M).Count].Value = v;
//     (*M).Count += 1;
//   }
// }
// /* Menambahkan Elmt sebagai elemen MapAlbum M. */
// /* I.S. M mungkin kosong, M tidak penuh
//         M mungkin sudah beranggotakan v dengan key k */
// /* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

// void Delete(MapAlbum *M, keytype k)
// {
//   int i = 0;
//   boolean found = false;

//   while (i < (*M).Count && !found)
//   {
//     if ((*M).Elements[i].Key == k)
//     {
//       found = true;
//       (*M).Elements[i-1].Value = Undefined;
//       for (i; i < (*M).Count - 1;i++)
//       {
//         (*M).Elements[i] = (*M).Elements[i+1];
//       }
//       (*M).Count -= 1;
//     }
//     i++;
//   }

// }
// /* Menghapus Elmt dari MapAlbum M. */
// /* I.S. M tidak kosong
//         element dengan key k mungkin anggota / bukan anggota dari M */
// /* F.S. element dengan key k bukan anggota dari M */

// boolean IsMember(MapAlbum M, keytype k)
// {
//   int i = 0;
//   boolean found = false;

//   while (i < M.Count && !found)
//   {
//     if (M.Elements[i].Key == k)
//     {
//       found = true;
//     }
//     i++;
//   }

//   return found;

// }
/* Mengembalikan true jika k adalah member dari M */
