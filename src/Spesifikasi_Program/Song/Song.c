#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../Play/Play.h"
#include "../Queue/Queue.h"

void SongNext(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS)
{   
    if ((*CS).status == 0)
    {
        if (((*QL).idxHead == IDX_UNDEF || (*QL).idxTail == IDX_UNDEF))
        {
            printf("\n%sERROR: %sQueue kosong, Current Song juga kosong\n", RED, WHITE);
            printf("%sTidak ada lagu yang dapat diputar.\n", WHITE);
        }
        else
        {
            dequeueLaguNext(QL, CS);

            (*CS).status = 1;

            printf("\n%sOutput: %sMemutar lagu selanjutnya\n", GREEN, WHITE);
            printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);
        }
    }
    else if ((*QL).idxHead == IDX_UNDEF || (*QL).idxTail == IDX_UNDEF)
    {
        printf("\n%sOutput: %sQueue kosong, memutar kembali lagu\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);

    }
    else
    {
        PushRiwayatLagu(RL, (*CS).JudulLagu, (*CS).NamaAlbum, (*CS).NamaPenyanyi);
        dequeueLaguNext(QL, CS);

        (*CS).status = 1;

        printf("\n%sOutput: %sMemutar lagu selanjutnya\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);
    }

}

void SongPrev(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS)
{
    if ((*RL).IDXTOP == IDX_UNDEF)
    {
        printf("\n%sOutput: %sRiwayat kosong, memutar kembali lagu\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);
    }
    else
    {
        enqueueLaguFirst(QL, (*CS).JudulLagu, (*CS).NamaAlbum, (*CS).NamaPenyanyi);
        PopRiwayatLagu(RL, CS);

        printf("\n%sOutput: %sMemutar lagu sebelumnya\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);

    }
}