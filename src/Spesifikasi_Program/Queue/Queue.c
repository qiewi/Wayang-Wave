
#include <stdio.h>
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../Play/Play.h"

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

// void dequeueLagu(QueueLagu *q, RiwayatLagu * RL, IdQueue id) // to do: tambah stack riwayat
// {
//     PushRiwayatLagu(RL, (*q).JudulLagu[id-1], (*q).NamaAlbum[id-1], (*q).NamaPenyanyi[id-1]);

//     for (int i = id - 1; i < (IDX_TAIL(*q)); i++)
//     {
//       (*q).JudulLagu[i] = (*q).JudulLagu[i+1];
//       (*q).NamaAlbum[i] = (*q).NamaAlbum[i+1];
//       (*q).NamaPenyanyi[i] = (*q).NamaPenyanyi[i+1];
//     }
//     (*q).idxTail -= 1;

// }

// void QueueRemoveLagu(QueueLagu * QL, RiwayatLagu * RL, int idQueue)
// {
//     int id = idQueue - 1;

//     if (id > (*QL).idxTail || id < 0)
//     {
//       printf("\n%sERROR: %sLagu dengan urutan ke %d tidak ada.", RED, WHITE, idQueue);
//     }
//     else
//     {
//       Kalimat NamaLagu = (*QL).JudulLagu[id];
//       Kalimat NamaPenyanyi = (*QL).NamaPenyanyi[id];

//       printf("\n%sLagu %s\"%s\" %soleh %s\"%s\" %stelah dihapus dari queue!", GREEN, WHITE, NamaLagu.TabLine, GREEN, WHITE, NamaPenyanyi.TabLine, GREEN);
//       dequeueLagu(QL, RL, idQueue);
//     }
// }

void QueueAddLagu(ListPenyanyi * LP, QueueLagu * QL)
{
    int id = -1; // kalau -1 dia undefined (ga ada penyanyi / album)

    printf("%sDaftar Penyanyi :\n", GREEN);
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