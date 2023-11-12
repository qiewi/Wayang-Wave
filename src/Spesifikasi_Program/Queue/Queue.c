
#include <stdio.h>
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../Play/Play.h"

void enqueueLaguFirst(QueueLagu *q, Kalimat JudulLaguQueue, Kalimat NamaAlbumQueue, Kalimat NamaPenyanyiQueue)
{
  if ((*q).idxHead == IDX_UNDEF || (*q).idxTail == IDX_UNDEF)
  {
    IDX_HEAD(*q) = 0;
    IDX_TAIL(*q) = 0;
    LaguAwal(*q) = JudulLaguQueue;
    AlbumAwal(*q) = NamaAlbumQueue;
    PenyanyiAwal(*q) = NamaPenyanyiQueue;
  }
  else
  {
    IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;

    for (int i = IDX_TAIL(*q); i > IDX_HEAD(*q); i--)
    {
      (*q).JudulLagu[i] = (*q).JudulLagu[i-1];
      (*q).NamaAlbum[i] = (*q).NamaAlbum[i-1];
      (*q).NamaPenyanyi[i] = (*q).NamaPenyanyi[i-1];
    }

    LaguAwal(*q) = JudulLaguQueue;
    AlbumAwal(*q) = NamaAlbumQueue;
    PenyanyiAwal(*q) = NamaPenyanyiQueue;
  }

  // printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", JudulLaguQueue.TabLine, NamaPenyanyiQueue.TabLine);
}

void enqueueLagu(QueueLagu *q, Kalimat JudulLaguQueue, Kalimat NamaAlbumQueue, Kalimat NamaPenyanyiQueue)
{
  if ((*q).idxHead == IDX_UNDEF || (*q).idxTail == IDX_UNDEF)
  {
    IDX_HEAD(*q) = 0;
    IDX_TAIL(*q) = 0;
    LaguAwal(*q) = JudulLaguQueue;
    AlbumAwal(*q) = NamaAlbumQueue;
    PenyanyiAwal(*q) = NamaPenyanyiQueue;
  }
  else
  {
    IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    LaguAkhir(*q) = JudulLaguQueue;
    AlbumAkhir(*q) = NamaAlbumQueue;
    PenyanyiAkhir(*q) = NamaPenyanyiQueue;
  }

  // printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", JudulLaguQueue.TabLine, NamaPenyanyiQueue.TabLine);
}

void dequeueLagu(QueueLagu * QL, RiwayatLagu * RL, IdQueue id) // to do: tambah stack riwayat
{
    PushRiwayatLagu(RL, (*QL).JudulLagu[id-1], (*QL).NamaAlbum[id-1], (*QL).NamaPenyanyi[id-1]);

    for (int i = id - 1; i < (IDX_TAIL(*QL)); i++)
    {
      (*QL).JudulLagu[i] = (*QL).JudulLagu[i+1];
      (*QL).NamaAlbum[i] = (*QL).NamaAlbum[i+1];
      (*QL).NamaPenyanyi[i] = (*QL).NamaPenyanyi[i+1];
    }
    (*QL).idxTail -= 1;

}

void dequeueLaguNext(QueueLagu * QL, CurrentSong * CS) // to do: tambah stack riwayat
{ 

    (*CS).JudulLagu = (*QL).JudulLagu[0];
    (*CS).NamaAlbum = (*QL).NamaAlbum[0];
    (*CS).NamaPenyanyi = (*QL).NamaPenyanyi[0];

    for (int i = 0; i < (IDX_TAIL(*QL)) ; i++)
    {
      (*QL).JudulLagu[i] = (*QL).JudulLagu[i+1];
      (*QL).NamaAlbum[i] = (*QL).NamaAlbum[i+1];
      (*QL).NamaPenyanyi[i] = (*QL).NamaPenyanyi[i+1];
    }
    (*QL).idxTail -= 1;

}


void QueueSwap(QueueLagu * QL, IdQueue id1, IdQueue id2)
{   
    if ((id1 > (*QL).idxTail || id1 < 0) && (id2 > (*QL).idxTail || id2 < 0))
    {
      printf("\n%sERROR: %sLagu dengan urutan ke %d dan %d tidak ada.\n", RED, WHITE, id1, id2);
    }
    else if (id1 > (*QL).idxTail || id1 < 0)
    {
      printf("\n%sERROR: %sLagu dengan urutan ke %d tidak ada.\n", RED, WHITE, id1);
    }
    else if (id2 > (*QL).idxTail || id2 < 0)
    {
      printf("\n%sERROR: %sLagu dengan urutan ke %d tidak ada.\n", RED, WHITE, id2);
    }
    else
    {
      CurrentSong temp;

      temp.JudulLagu = (*QL).JudulLagu[id2-1];
      temp.NamaAlbum = (*QL).NamaAlbum[id2-1];
      temp.NamaPenyanyi = (*QL).NamaPenyanyi[id2-1];

      (*QL).JudulLagu[id2-1] = (*QL).JudulLagu[id1-1];
      (*QL).NamaAlbum[id2-1] = (*QL).NamaAlbum[id1-1];
      (*QL).NamaPenyanyi[id2-1] = (*QL).NamaPenyanyi[id1-1];

      (*QL).JudulLagu[id1-1] = temp.JudulLagu;
      (*QL).NamaAlbum[id1-1] = temp.NamaAlbum;
      (*QL).NamaPenyanyi[id1-1] = temp.NamaPenyanyi;

      printf("\n%sLagu %s\"%s\" %sberhasil ditukar dengan %s\"%s\"\n", GREEN, WHITE, (*QL).JudulLagu[id1-1], GREEN, WHITE, (*QL).JudulLagu[id2-1]);
    }
}

void QueueRemoveLagu(QueueLagu * QL, RiwayatLagu * RL, int idQueue)
{
    int id = idQueue - 1;

    if (id > (*QL).idxTail || id < 0)
    {
      printf("\n%sERROR: %sLagu dengan urutan ke %d tidak ada.\n", RED, WHITE, idQueue);
    }
    else
    {
      Kalimat NamaLagu = (*QL).JudulLagu[id];
      Kalimat NamaPenyanyi = (*QL).NamaPenyanyi[id];

      printf("\n%sLagu %s\"%s\" %soleh %s\"%s\" %stelah dihapus dari queue!\n", GREEN, WHITE, NamaLagu.TabLine, GREEN, WHITE, NamaPenyanyi.TabLine, GREEN);
      dequeueLagu(QL, RL, idQueue);
    }
}

void QueueAddLagu(ListPenyanyi * LP, QueueLagu * QL)
{
    int id = -1; // kalau -1 dia undefined (ga ada penyanyi / album)

    printf("\n%sDaftar Penyanyi :\n", GREEN);
    for (int i = 0; i < (*LP).NEff; i++)
    {
        printf("  %s%d. %s \n", WHITE, i+1, (*LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    printf("\nMasukkan Nama Penyanyi yang dipilih : %s", GREEN);
    STARTKALIMATINPUT();
    // printf("%s\n", CInput.TabLine);
    // cek nama penyanyi yang diinput

    int idPenyanyi = indeksPenyanyi(LP, CInput);

    if (idPenyanyi != -1)
    {
        printf("\nDaftar Album oleh %s%s :\n", YELLOW, CInput.TabLine);
        for (int i = 0; i < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.NEff; i++) // print list Album
        {
            printf("  %s%d. %s \n", WHITE, i+1, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[i].NamaAlbum.TabLine);
        }
        
        printf("\nMasukkan Nama Album yang dipilih: %s", GREEN);
        STARTKALIMATINPUT();

        int idAlbum = indeksAlbum(LP, idPenyanyi, CInput);
        // printf("%s\n", CInput.TabLine);

        if (idAlbum != -1)
        {
            printf("\nDaftar Lagu Album %s%s %soleh %s%s:\n", YELLOW, CInput.TabLine, GREEN, YELLOW, (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi.TabLine); // print list Lagu
            for (int i = 0; i < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.Count; i++)
            {
            printf("  %s%d. %s \n",WHITE, i+1, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[i].TabLine);
            }

            printf("\nMasukkan ID Lagu yang dipilih : ");
            STARTKALIMATINPUT();

            int idLagu = CInput.TabLine[0] - 49;
            if (idLagu < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.Count)
            {   
                Kalimat NamaLagu = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[idLagu];
                Kalimat NamaAlbum = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].NamaAlbum;
                Kalimat NamaPenyanyi = (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi;
                enqueueLagu(QL, NamaLagu, NamaAlbum, NamaPenyanyi);
                printf("%sBerhasil menambahkan lagu %s\"%s\" %soleh %s\"%s\" %ske queue.\n", GREEN, WHITE, (*QL).JudulLagu[(*QL).idxTail].TabLine, GREEN, WHITE, (*QL).NamaPenyanyi[(*QL).idxTail].TabLine, GREEN);    
            }
            else
            {
                printf("\n%sERROR: %sID Lagu tidak ada.\n", RED, WHITE);
            }
        }
        else
        {
            printf("\n%sERROR: %sAlbum tidak terdaftar.\n", RED, WHITE);
        }
    }
    else
    {
        printf("\n%sERROR: %sPenyanyi tidak terdaftar.\n", RED, WHITE);
    }    
}

void QueueClear(QueueLagu * QL)
{
  (*QL).idxHead = IDX_UNDEF;
  (*QL).idxTail = IDX_UNDEF;

  printf("\n%sOutput: %sQueue berhasil dikosongkan.\n", GREEN, WHITE);
}