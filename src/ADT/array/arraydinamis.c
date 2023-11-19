/* *** Definisi ABSTRACT DATA TYPE POINT *** */
#include <stdio.h>
#include <stdlib.h>
#include "arraydinamis.h"
#include "../LinkedList/linkedlist.h"
#include "../boolean.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
  ArrayDin arr;
  arr.A = (List *) malloc (InitialSize * sizeof(List));
  arr.Nama = (NameType *) malloc (InitialSize * sizeof(NameType));
  arr.Capacity = InitialSize;
  arr.Neff = 0;
  return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
  free((*array).A);
  free((*array).Nama);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArray(ArrayDin array){
  return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArray(ArrayDin array){
  return (array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
List Get(ArrayDin array, IdxType i){
  return array.A[i]; 
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertNama(ArrayDin *array, NameType NamaPlaylist){

  CreateEmpty(&(*array).A[(*array).Neff]);
  (*array).Nama[(*array).Neff] = NamaPlaylist;
  (*array).Neff += 1;

}
