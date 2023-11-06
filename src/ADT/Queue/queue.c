
#include "boolean.h"
#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueueLagu(QueueLagu *q)
{
  IDX_HEAD(*q) = IDX_UNDEF;
  IDX_TAIL(*q) = IDX_UNDEF;
}        
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IwDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(QueueLagu q)
{
  return (IDX_HEAD(q)== IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(QueueLagu q)
{
  return (length(q) == CAPACITY);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(QueueLagu q)
{ 
  int len;
  if (isEmpty(q)) len = 0;
  else if (IDX_TAIL(q)>= IDX_HEAD(q))
  {
    len = IDX_TAIL(q) - IDX_HEAD(q) + 1;
  }
  else
  {
    len = CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1;
  }

  return len;
}
/* Mengirimkan banyaknya elemen QueueLagu. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueLagu(QueueLagu *q, Kalimat JudulLaguQueue, Kalimat NamaPenyanyiQueue)
{
  if (length(*q) == 0)
  {
    IDX_HEAD(*q) = 0;
    IDX_TAIL(*q) = 0;
    LaguAwal(*q) = JudulLaguQueue;
    PenyanyiAwal(*q) = NamaPenyanyiQueue;
  }
  else
  {
    IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    LaguAkhir(*q) = JudulLaguQueue;
    PenyanyiAkhir(*q) = NamaPenyanyiQueue;
  }

  printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", JudulLaguQueue.TabLine, NamaPenyanyiQueue.TabLine);
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeueLagu(QueueLagu *q, IdQueue id, Kalimat * JudulLaguQueue, Kalimat * NamaPenyanyiQueue) // to do: tambah stack riwayat
{
  if (id-1 > IDX_TAIL(*q)) printf("Lagu dengan urutan %d tidak ada.\n");
  else
  {
    (*JudulLaguQueue) = (*q).JudulLagu[id-1];
    (*NamaPenyanyiQueue) = (*q).NamaPenyanyi[id-1];
    for (int i = id - 1; i < (IDX_TAIL(*q)); i++)
    {
      (*q).JudulLagu[i] = (*q).JudulLagu[i+1];
      (*q).NamaPenyanyi[i] = (*q).NamaPenyanyi[i+1];
    }
    (*q).idxTail -= 1;
  }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display QueueLagu *** */
// void displayQueueLagu(QueueLagu q)
// {
//   if (isEmpty(q)) printf("[]");
//   else
//   { 
//     printf("[");
//     if (IDX_HEAD(q) > IDX_TAIL(q))
//     { 
//       for (int i = IDX_HEAD(q); i < CAPACITY; i++)
//       {
//         printf("%d,", q.buffer[i]);
//       }

//       for (int j = 0; j <= IDX_TAIL(q); j++)
//       {
//         if (j == IDX_TAIL(q)) printf("%d]\n", q.buffer[j]);
//         else printf("%d,", q.buffer[j]);
//       }
//     }
//     else
//     {
//       for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
//       {
//         if (i == IDX_TAIL(q)) printf("%d]\n", q.buffer[i]);
//         else printf("%d,", q.buffer[i]);
//       }
//     }
//   }
// }
/* Proses : Menuliskan isi QueueLagu dengan traversal, QueueLagu ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika QueueLagu kosong : menulis [] */