#ifndef RIWAYAT_LAGU_H
#define RIWAYAT_LAGU_H

#include "../LineMachine/boolean.h"
#include "../../Spesifikasi_Program/Play/Play.h"
#include "../LineMachine/linemachine.h"

typedef Kalimat infotypeRiwayat;
typedef int addressRiwayat; 

typedef struct {
    Kalimat JudulLagu[50];
    Kalimat NamaAlbum[50];
    Kalimat NamaPenyanyi[50];
    int IDXTOP;
} RiwayatLagu;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).IDXTOP
#define InfoLagu(S) (S).JudulLagu[(S).IDXTOP]
#define InfoAlbum(S) (S).NamaAlbum[(S).IDXTOP]
#define InfoPenyanyi(S) (S).NamaPenyanyi[(S).IDXTOP]

boolean IsEmpty(RiwayatLagu RL);

void PushRiwayatLagu(RiwayatLagu *RL, Kalimat JudulLagu, Kalimat NamaAlbum, Kalimat NamaPenyanyi);
// {
//     if ((*RL).IDXTOP == Nil)
//     {
//         Top(*RL) = 0;
//         InfoLagu(*RL) = JudulLagu;
//         InfoAlbum(*RL) = NamaAlbum;
//         InfoPenyanyi(*RL) = NamaPenyanyi;
        
//     }
//     else
//     {
//         if ((*RL).IDXTOP < 50-1) {
//             Top(*RL)++;
//             InfoLagu(*RL) = JudulLagu;
//             InfoAlbum(*RL) = NamaAlbum;
//             InfoPenyanyi(*RL) = NamaPenyanyi;
//         }
//     }
// }
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru */

void Pop(RiwayatLagu *S, CurrentSong * CS);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif