/* File : QueueLagu.h */
/* Definisi ADT QueueLagu dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QueueLagu_H
#define QueueLagu_H

#include "boolean.h"
#include "../LineMachine/linemachine.h"

#define IDX_UNDEF -1
#define CAPACITY 20

/* Definisi elemen dan address */
typedef int IdQueue;
typedef struct {
	Kalimat JudulLagu[CAPACITY]; 
        Kalimat NamaAlbum[CAPACITY];
        Kalimat NamaPenyanyi[CAPACITY];
	int idxHead;
	int idxTail;
} QueueLagu;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QueueLagu, maka akses elemen : */
#define     IDX_HEAD(q) (q).idxHead
#define     IDX_TAIL(q) (q).idxTail

#define     LaguAwal(q) (q).JudulLagu[(q).idxHead]
#define     AlbumAwal(q) (q).NamaAlbum[(q).idxHead]
#define     PenyanyiAwal(q) (q).NamaPenyanyi[(q).idxHead]

#define     LaguAkhir(q) (q).JudulLagu[(q).idxTail]
#define     AlbumAkhir(q) (q).NamaAlbum[(q).idxTail]
#define     PenyanyiAkhir(q) (q).NamaPenyanyi[(q).idxTail]

/* *** Kreator *** */
void CreateQueueLagu(QueueLagu *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(QueueLagu q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(QueueLagu q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(QueueLagu q);
/* Mengirimkan banyaknya elemen QueueLagu. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
// void enqueueLagu(QueueLagu *q, Kalimat JudulLaguQueue, Kalimat NamaAlbumQueue, Kalimat NamaPenyanyiQueue);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

// void dequeueLagu(QueueLagu *q, IdQueue id, Kalimat * JudulLaguQueue, Kalimat * NamaAlbumQueue, Kalimat * NamaPenyanyiQueue); // to do list: tambahin stack riwayat lagu
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display QueueLagu *** */
void displayQueueLagu(QueueLagu q);
/* Proses : Menuliskan isi QueueLagu dengan traversal, QueueLagu ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika QueueLagu kosong : menulis [] */


#endif