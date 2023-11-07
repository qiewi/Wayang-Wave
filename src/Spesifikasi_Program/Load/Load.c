#include <stdio.h>
#include "../../ADT/WordMachine/wordmachine.h"
#include "../../ADT/CharMachine/charmachine.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../Inisialisasi/inisialisasi.h"
#include "../../ADT/MapSetList/mapsetlist.h"
#include "Load.h"

void LOADFILE(ListPenyanyi * LP, char filename[]){

    STARTKALIMATFILE(filename);

    Kalimat NamaPenyanyi;
    Kalimat NamaAlbum;
    Kalimat NamaLagu;

    int loop = atoi(CLine.TabLine);

    if (loop < 0)
    {
        printf("\n%sERROR: %sSave file tidak ditemukan. %sWayangWave %sgagal dijalankan.\n", RED, WHITE, GREEN, WHITE);
    }
    else
    {
        printf("\n%sJumlah Penyanyi: %s%d\n", WHITE, MAGENTA, loop);


        for (int i = 0; i < loop; i++){
            ADVSATUKATA();
            printf("Kalimat %d: %s\n", 1, CLine.TabLine);
            int album = atoi(CLine.TabLine);
            
            delay(1);

            ADVKALIMAT();
            
            AddPenyanyi(LP, CLine);
            NamaPenyanyi = NamaPenyanyiNow(LP);

            printf("\n%sNama Penyanyi ke-%d: %s%s\n", WHITE, i+1, YELLOW, NamaPenyanyi.TabLine);
            printf("%s--------------------------------------\n", MAGENTA);
            printf("%sJumlah Album: %s%d\n", WHITE, MAGENTA, album);
            printf("--------------------------------------\n");

            delay(1);

            for (int j = 0; j < album; j++){
            ADVSATUKATA();
            int lagu = atoi(CLine.TabLine);

            ADVKALIMAT();

            AddAlbum(LP, CLine);
            NamaAlbum = NamaAlbumNow(LP);

            printf("%sNama Album: %s%s\n", WHITE, YELLOW, NamaAlbum.TabLine);
            printf("%s--------------------------------------\n", MAGENTA);
            delay(1);
            for (int k = 0; k < lagu; k++)
            {
                ADVKALIMAT();

                AddLagu(LP, CLine);
                NamaLagu = NamaLaguNow(LP);

                printf("%sNama Lagu %d: %s%s\n", WHITE, k+1, MAGENTA, NamaLagu.TabLine);
                delay(0.5);
            }
            printf("%s--------------------------------------\n", MAGENTA);
            }


        }

        ADVKALIMAT();
        int loopRecordQ = atoi(CLine.TabLine);

        printf("%sDaftar Record Lagu dalam Queue\n", GREEN);
        for (int i = 0; i < loopRecordQ; i++) // Record Queue
        {   
            ADVRECORD();
            printf("\n%sPenyanyi Lagu %d: %s\n", WHITE, i+1, CLine.TabLine);
            ADVRECORD();
            printf("  Nama Album Lagu %d: %s\n", i+1, CLine.TabLine);
            ADVRECORD();
            printf("    Nama Lagu %d: %s\n", i+1, CLine.TabLine);
        }

        ADVKALIMAT();
        int loopRecordR = atoi(CLine.TabLine);

        printf("\n%sDaftar Record Riwayat\n", GREEN);
        for (int i = 0; i < loopRecordR; i++) // Record Riwayat
        {
            ADVRECORD();
            printf("\n%sPenyanyi Lagu %d: %s\n", WHITE, i+1, CLine.TabLine);
            ADVRECORD();
            printf("  Nama Album Lagu %d: %s\n", i+1, CLine.TabLine);
            ADVRECORD();
            printf("    Nama Lagu %d: %s\n", i+1, CLine.TabLine);
        }

        ADVKALIMAT();
        int loopRecordP = atoi(CLine.TabLine); // Jumlah Playlist
        // printf("%d\n", loopRecordP);

        printf("\n%sDaftar Playlist\n", GREEN);
        for (int i = 0; i < loopRecordP; i++) // Loop Playlist
        {

            ADVSATUKATA();
            int LaguPlaylist = atoi(CLine.TabLine);
            // printf("%d", LaguPlaylist);

            ADVKALIMAT();
            printf("\n%sNama Playlist ke-%d : %s%s\n",YELLOW, i+1, CYAN, CLine.TabLine);
            printf("%s--------------------------------------\n", GREEN);

            for (int j = 0; j < LaguPlaylist; j++)
            {
                ADVRECORD();
                printf("%sPenyanyi ke-%d : %s\n",WHITE, j+1, CLine.TabLine);

                ADVRECORD();
                printf("Album ke-%d : %s\n", j+1, CLine.TabLine);

                ADVRECORD();
                printf("Lagu ke-%d : %s\n\n", j+1, CLine.TabLine);

            }


        }
    }
}

// int main(){
//   LOAD;
// }