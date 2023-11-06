#include "../../ADT/MapSetList/mapsetlist.h"
#include <stdio.h>
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "Play.h"

void PlaySong(ListPenyanyi * LP) // to do list: diconnect ke queue
{
    char ViewAlbum;
    char ViewLagu;

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
                printf("%sMemutar lagu %s\"%s\" %soleh %s\"%s\".\n", GREEN, WHITE, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[idLagu].TabLine, GREEN, WHITE, (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi.TabLine);    
            }
            else
            {
                printf("ID Lagu tidak ada\n");
            }
        }
        else
        {
            printf("Album tidak terdaftar\n");
        }
    }
    else
    {
        printf("Penyanyi tidak terdaftar\n");
    }    


}