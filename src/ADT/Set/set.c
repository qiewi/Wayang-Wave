#include <stdio.h>
#include "set.h"
#include "boolean.h"


/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
{
  (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
{
  return (S).Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S)
{
  return (S).Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
{
  boolean found = false;
  int i = 0;

  while (!found && i < (*S).Count)
  {
    if ((*S).Elements[i] == Elmt)
    {
      found = true;
    }
    i += 1;
  }

  if (!found)
  {
    (*S).Elements[(*S).Count] = Elmt;
    (*S).Count += 1;
  }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt)
{
  boolean found = false;
  int i = 0;

  while (!found && i < (*S).Count)
  {
    if ((*S).Elements[i] == Elmt)
    { 
      found = true;
    }
    i += 1;
  }

  if (found)
  {
    for (int j = i-1; j < (*S).Count; j++)
    {
      (*S).Elements[j] = (*S).Elements[j+1];
    }
    (*S).Count -= 1;
  }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt)
{
  boolean found = false;
  int i = 0;

  while (!found && i < (S).Count)
  {
    if ((S).Elements[i] == Elmt)
    { 
      found = true;
    }
    i += 1;
  }

  return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */

