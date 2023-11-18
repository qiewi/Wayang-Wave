#include "../../ADT/MapSetList/mapsetlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "Play.h"


void CreateCurrentSong(CurrentSong * CS)
{
    (*CS).status = 0;
    (*CS).statusPL = 0;
}

void CreateCurrentUser(CurrentUser * CU)
{
    (*CU).status = 0;
}

void AddSong(ListPenyanyi * LP, CurrentSong * CS, int idPenyanyi, int idAlbum, int idLagu)
{
    (*CS).status = 1;

    (*CS).NamaPenyanyi = (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi;
    (*CS).NamaAlbum = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].NamaAlbum;
    (*CS).JudulLagu = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[idLagu];
}


void PlaySong(ListPenyanyi * LP, CurrentSong * CS, QueueLagu * QL, RiwayatLagu * RL) // to do list: diconnect ke queue
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

            int idLagu = atoi(CInput.TabLine) - 1;
            if (idLagu < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.Count)
            {
                AddSong(LP, CS, idPenyanyi, idAlbum, idLagu);

                (*QL).idxHead = IDX_UNDEF; (*QL).idxTail = IDX_UNDEF;
                (*RL).IDXTOP = IDX_UNDEF;
                (*CS).statusPL = 0;

                printf("%sMemutar lagu %s\"%s\" %soleh %s\"%s\".\n", GREEN, WHITE, (*CS).JudulLagu.TabLine, GREEN, WHITE, (*CS).NamaPenyanyi.TabLine);    
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

void PopRiwayatLagu(RiwayatLagu *RL, CurrentSong * CS) // untuk song prev
{ 
    (*CS).JudulLagu = InfoLagu(*RL);
    (*CS).NamaAlbum = InfoAlbum(*RL);
    (*CS).NamaPenyanyi = InfoPenyanyi(*RL);
    
	Top(*RL)--;
}