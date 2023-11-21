/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../Queue/Queue.h"
#include "../Play/Play.h"
#include "Status.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void Status(CurrentSong * CS, CurrentUser * CU, QueueLagu * QL, RiwayatLagu * RL)
{
    if ((*CS).status == 0 )
    // Jika tidak ada lagu yang diputar
    {   
        if (((*QL).idxHead != IDX_UNDEF || (*QL).idxTail != IDX_UNDEF))
        // Jika terdapat queue lagu
        {   
            printf("\n%sCurrent User: %s%s\n", GREEN, WHITE, (*CU).NamaUser.TabLine);

            if ((*CS).statusPL == 1)
            // Jika terdapat playlist yang diputar
            {
                printf("\n%sCurrent Playlist: %s%s\n", GREEN, WHITE, (*CS).NamaPlaylist.TabLine);
            }
            
            printf("\n%sNow Playing:\n", GREEN);
            printf("%sNo songs have been played yet. Please search for a song to begin playback.\n", WHITE);

            printf("\n%sQueue:\n", GREEN);
            for (int i = (*QL).idxHead; i <= (*QL).idxTail; i++)
            {
                printf("%s%d. %s - %s - %s\n", WHITE, i+1, (*QL).NamaPenyanyi[i].TabLine, (*QL).JudulLagu[i].TabLine, (*QL).NamaAlbum[i].TabLine);
            }
        }

        else if (((*QL).idxHead == IDX_UNDEF || (*QL).idxTail == IDX_UNDEF))
        // Jika tidak terdapat queue lagu
        {
            printf("\n%sCurrent User: %s%s\n", GREEN, WHITE, (*CU).NamaUser.TabLine);

            printf("\n%sNow Playing:\n", GREEN);
            printf("%sNo songs have been played yet. Please search for a song to begin playback.\n", WHITE);

            printf("\n%sQueue:\n", GREEN);
            printf("%sYour queue is empty.\n", WHITE);
        }

    }
    
    else if ((*CS).status == 1)
    // Jika terdapat lagu yang sedang diputar
    {   
        if ((*QL).idxHead == IDX_UNDEF || (*QL).idxTail == IDX_UNDEF)
        // Jika tidak ada queue lagu
        {
            printf("\n%sCurrent User: %s%s\n", GREEN, WHITE, (*CU).NamaUser.TabLine);

            printf("\n%sNow Playing:\n", GREEN);
            printf("%s%s - %s - %s\n", WHITE, (*CS).NamaPenyanyi.TabLine, (*CS).JudulLagu.TabLine, (*CS).NamaAlbum.TabLine);

            printf("\n%sQueue:\n", GREEN);
            printf("%sYour queue is empty.\n", WHITE);
        }

        else if ((*QL).idxHead != IDX_UNDEF || (*QL).idxTail != IDX_UNDEF)
        // Jika terdapat queue lagu
        {   
            printf("\n%sCurrent User: %s%s\n", GREEN, WHITE, (*CU).NamaUser.TabLine);

            if ((*CS).statusPL == 1)
            // Jika terdapat playlist yang diputar
            {
                printf("\n%sCurrent Playlist: %s%s\n", GREEN, WHITE, (*CS).NamaPlaylist.TabLine);
            }

            printf("\n%sNow Playing:\n", GREEN);
            printf("%s%s - %s - %s\n", WHITE, (*CS).NamaPenyanyi.TabLine, (*CS).JudulLagu.TabLine, (*CS).NamaAlbum.TabLine);

            printf("\n%sQueue:\n", GREEN);
            for (int i = (*QL).idxHead; i <= (*QL).idxTail; i++)
            {
                printf("%s%d. %s - %s - %s\n", WHITE, i+1, (*QL).NamaPenyanyi[i].TabLine, (*QL).JudulLagu[i].TabLine, (*QL).NamaAlbum[i].TabLine);
            }
        }
    }

    if ((*RL).IDXTOP != IDX_UNDEF)
    // Jika terdapat riwayat lagu
    {
        printf("\n%sHistory:\n", GREEN);
        for (int i = 0; i <= (*RL).IDXTOP; i++)
        {
            printf("%s%d. %s - %s - %s\n", WHITE, i+1, (*RL).NamaPenyanyi[i].TabLine, (*RL).JudulLagu[i].TabLine, (*RL).NamaAlbum[i].TabLine);
        }
    }
    
}