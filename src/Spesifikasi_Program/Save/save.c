
#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/array/arraydinamis.h"

static FILE * File;

void SaveFile(ListPenyanyi * LP, ArrayDin * AP, QueueLagu * QL, RiwayatLagu * RL, char filename[])
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
    
    if ((*QL).idxTail != IDX_UNDEF)
    {
        fprintf(File, "%d\n", (*QL).idxTail + 1);
    }

    for (int a = 0; a <= (*QL).idxTail; a++)
    {
        fprintf(File, "%s;%s;%s\n", (*QL).NamaPenyanyi[a].TabLine, (*QL).NamaAlbum[a].TabLine, (*QL).JudulLagu[a].TabLine);
    }

    if ((*RL).IDXTOP > 0)
    {
        fprintf(File, "%d\n", (*RL).IDXTOP + 1);
    }

    for (int b = (*RL).IDXTOP; b >= 0; b--)
    {   
        fprintf(File, "%s;%s;%s\n", (*RL).NamaPenyanyi[b].TabLine, (*RL).NamaAlbum[b].TabLine, (*RL).JudulLagu[b].TabLine);
    }

    if ((*AP).Neff > 0)
    {
        fprintf(File, "%d\n", (*AP).Neff);
    }

    for (int c = 0; c < (*AP).Neff; c++)
    {

        address add = First((*AP).A[c]);
        int count = 0;

        // add = Next(add);

        while (add != Nil)
        {
            count += 1;
            add = Next(add);
        }

        if (count == 0)
        {
            fprintf(File, "%d %s", count, (*AP).Nama[c].TabLine);
        }
        else
        {
            fprintf(File, "%d %s\n", count, (*AP).Nama[c].TabLine);
        }

        address lagu = First((*AP).A[c]);

        for (int d = 0; d < count; d++)
        {
            
            fprintf(File, "%s;%s;%s\n", NamaPenyanyi(lagu).TabLine, NamaAlbum(lagu).TabLine, JudulLagu(lagu).TabLine);

            lagu = Next(lagu);
        }


    }

    fclose(File);
}