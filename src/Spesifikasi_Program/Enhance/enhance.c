#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/boolean.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../Playlist/Playlist.h"
#include "../Inisialisasi/inisialisasi.h"

void EnchancePL(ListPenyanyi * LP, ArrayDin * AP)
{
    printf("\n%sDaftar Playlist yang kamu miliki: %s\n", GREEN, WHITE);

    for (int p = 0; p < (*AP).Neff; p++)
    {
        printf("    %d. %s \n", p+1, (*AP).Nama[p].TabLine);
    }

    printf("\nMasukkan nama playlist yang ingin di-enhance: %s", GREEN);
    STARTKALIMATINPUT();

    Kalimat NamaPL = CInput;

    int idPL = idPlaylist(AP, NamaPL);

    if (idPL != -1)
    {
        srand(time(NULL));
        int jumlahLagu = rand() % 4 + 1;
        int count = 0;

        printf("\n%s..\n", CYAN);
        while (count < jumlahLagu)
        {
            int idPenyanyi = rand() % (*LP).NEff;
            int idAlbum = rand() % (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.NEff;
            int idLagu = rand() % (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.Count;

            // printf("%d %d %d\n", idPenyanyi, idAlbum, idLagu);
            // delay(1);

            int Ada = cekLaguPL(AP, (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].NamaAlbum, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[idLagu], idPL);
            // printf("%d", Ada);
            if (Ada != -1)
            {
                printf("%sMenambahkan lagu rekomendasi: %s%s ke dalam playlist.\n", GREEN, WHITE, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[idLagu].TabLine);
                delay(1);
                AddSongToPlaylist(LP, AP, idPenyanyi, idAlbum, idLagu, idPL);
                count++;
            }
        }

        printf("%s..\n", CYAN);
        delay(1);

        printf("\n%sOutput: %sPlaylist \"%s\" berhasil di-enhance!\n",GREEN, WHITE, NamaPL.TabLine);

    }
    else
    {
        printf("%sERROR: %sTidak ada playlist dengan nama \"%s\".\n", RED, WHITE, NamaPL.TabLine);
    }

}