/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/array/arraydinamis.h"

#include "../MultiUser/MultiUser.h"
#include "../Play/Play.h"

static FILE * File;

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void SaveFile(ListPenyanyi * LP, char filename[], DataUser * DU)
{
    File = fopen(filename, "w");

    // printf("\n%sJumlah Penyanyi: %s%d\n", WHITE, MAGENTA, loop);

    fprintf(File, "%d\n", (*LP).NEff);

    for (int i = 0; i < (*LP).NEff; i++){
        
        // printf("Kalimat %d: %s\n", 1, CLine.TabLine);
        // int album = atoi(CLine.TabLine);

        fprintf(File, "%d %s\n", (*LP).PenyanyiAlbum[i].ListAlbum.NEff, (*LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine);
        
        // delay(1);
        // ADVKALIMAT();
        
        // AddPenyanyi(LP, CLine);
        // NamaPenyanyi = NamaPenyanyiNow(LP);

        // printf("\n%sNama Penyanyi ke-%d: %s%s\n", WHITE, i+1, YELLOW, NamaPenyanyi.TabLine);
        // printf("%s--------------------------------------\n", MAGENTA);
        // printf("%sJumlah Album: %s%d\n", WHITE, MAGENTA, album);
        // printf("--------------------------------------\n");

        // delay(1);

        for (int j = 0; j < (*LP).PenyanyiAlbum[i].ListAlbum.NEff; j++){
            
            fprintf(File, "%d %s\n", (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].IsiLagu.Count, (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].NamaAlbum.TabLine);

        // ADVSATUKATA();
        // int lagu = atoi(CLine.TabLine);

        // ADVKALIMAT();

        // AddAlbum(LP, CLine);
        // NamaAlbum = NamaAlbumNow(LP);

        // printf("%sNama Album: %s%s\n", WHITE, YELLOW, NamaAlbum.TabLine);
        // printf("%s--------------------------------------\n", MAGENTA);
        // delay(1);
            for (int k = 0; k < (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].IsiLagu.Count; k++)
            {
                ADVKALIMAT();
                if (i == (*LP).NEff && j == (*LP).PenyanyiAlbum[i].ListAlbum.NEff && k == (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].IsiLagu.Count)
                {
                    fprintf(File, "%s", (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].IsiLagu.JudulLagu[k].TabLine);
                }
                else
                {
                    fprintf(File, "%s\n", (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].IsiLagu.JudulLagu[k].TabLine);
                }

                // AddLagu(LP, CLine);
                // NamaLagu = NamaLaguNow(LP);

                // printf("%sNama Lagu %d: %s%s\n", WHITE, k+1, MAGENTA, NamaLagu.TabLine);
                // delay(0.5);
            }
        // printf("\n");
        }

    }

    int JumlahUser = (*DU).TotalUser;

    fprintf(File, "%d\n", JumlahUser);

    for (int i = 0; i < JumlahUser; i++)
    {
        fprintf(File, "%s\n", (*DU).NamaUser[i].TabLine);
    }

    for (int idUser = 0; idUser < JumlahUser; idUser++)
    {

        if ((*DU).CS[idUser].status == 1)
        {
            fprintf(File, "%s;%s;%s\n", (*DU).CS[idUser].NamaPenyanyi.TabLine, (*DU).CS[idUser].NamaAlbum.TabLine, (*DU).CS[idUser].JudulLagu.TabLine);
        }
        
        if ((*DU).QL[idUser].idxTail != IDX_UNDEF)
        {
            fprintf(File, "%d\n", (*DU).QL[idUser].idxTail + 1);
        }

        for (int a = 0; a <= (*DU).QL[idUser].idxTail; a++)
        {
            fprintf(File, "%s;%s;%s\n", (*DU).QL[idUser].NamaPenyanyi[a].TabLine, (*DU).QL[idUser].NamaAlbum[a].TabLine, (*DU).QL[idUser].JudulLagu[a].TabLine);
        }

        if ((*DU).RL[idUser].IDXTOP > 0)
        {
            fprintf(File, "%d\n", (*DU).RL[idUser].IDXTOP + 1);
        }

        for (int b = (*DU).RL[idUser].IDXTOP; b >= 0; b--)
        {   
            fprintf(File, "%s;%s;%s\n", (*DU).RL[idUser].NamaPenyanyi[b].TabLine, (*DU).RL[idUser].NamaAlbum[b].TabLine, (*DU).RL[idUser].JudulLagu[b].TabLine);
        }

        if ((*DU).AP[idUser].Neff > 0)
        {
            fprintf(File, "%d\n", (*DU).AP[idUser].Neff);
        }

        for (int c = 0; c < (*DU).AP[idUser].Neff; c++)
        {

            address add = First((*DU).AP[idUser].A[c]);
            int count = 0;

            // add = Next(add);

            while (add != Nil)
            {
                count += 1;
                add = Next(add);
            }

            fprintf(File, "%d %s\n", count, (*DU).AP[idUser].Nama[c].TabLine);

            address lagu = First((*DU).AP[idUser].A[c]);

            for (int d = 0; d < count; d++)
            {
                
                fprintf(File, "%s;%s;%s\n", NamaPenyanyi(lagu).TabLine, NamaAlbum(lagu).TabLine, JudulLagu(lagu).TabLine);

                lagu = Next(lagu);
            }


        }
    }

    fclose(File);
}