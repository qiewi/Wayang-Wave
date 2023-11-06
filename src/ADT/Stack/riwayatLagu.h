#ifndef RIWAYAT_LAGU_H
#define RIWAYAT_LAGU_H

#include "../LineMachine/boolean.h"
#include "../Stack/stack.h"
#include "../LineMachine/linemachine.h"

#define Nil -1 
#define MaxEl 100

typedef Kalimat infotypeRiwayat;
typedef int addressRiwayat; 

typedef struct {
    infotypeRiwayat T[MaxEl];
    Kalimat NamaLagu;
    int idAlbum;
    int idPenyanyi;
    int IDXTOP;
} RiwayatLagu;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void PushRiwayatLagu(RiwayatLagu *S, infotypeRiwayat NamaLagu);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru */

void Pop(RiwayatLagu *S, infotypeRiwayat NamaLagu);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif