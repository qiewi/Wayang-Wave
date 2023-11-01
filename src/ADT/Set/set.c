#include <stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    (*S).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    boolean found = false;
    int i = 0;

    while (i < (*S).Count && !found)
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

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    int i = 0;

    while (i < (*S).Count && !found)
    {
        if ((*S).Elements[i] == Elmt)
        {
            found = true;
            // for (i = i; i < (*S).Count - 1; i++)
            // {
            //     (*S).Elements[i] = (*S).Elements[i + 1];
            // }
            // (*S).Count -= 1;
        }
        i += 1;
    }

    if (found)
    {
        for (int j = i - 1; j < (*S).Count - 1; j++)
        {
            (*S).Elements[j] = (*S).Elements[j+1];
        }
        (*S).Count -= 1;
    }
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    for (int i = 0; i < S.Count; i++)
    {
        if (S.Elements[i] == Elmt)
        {
            return true;
        }
    }

    return false;

    // boolean found = false;
    // int i = 0;

    // while (i < S.Count && !found)
    // {
    //     if (S.Elements[i] == Elmt)
    //     {
    //         found = true;
    //     }
    //     i += 1;
    // }

    // return found;
}