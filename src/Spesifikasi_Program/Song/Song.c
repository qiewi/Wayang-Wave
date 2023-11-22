/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../Inisialisasi/inisialisasi.h"
#include "../Play/Play.h"
#include "../Queue/Queue.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void SongNext(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS)
{   
    AnimasiSongNext();
    if ((*CS).status == 0)
    {
        if (((*QL).idxHead == IDX_UNDEF || (*QL).idxTail == IDX_UNDEF))
        {
            printf("%sERROR: %sQueue kosong, Current Song juga kosong\n", RED, WHITE);
            printf("%sTidak ada lagu yang dapat diputar.\n", WHITE);
        }
        else
        {
            dequeueLaguNext(QL, CS);

            (*CS).status = 1;

            printf("%sOutput: %sMemutar lagu selanjutnya\n", GREEN, WHITE);
            printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);
        }
    }
    else if ((*QL).idxHead == IDX_UNDEF || (*QL).idxTail == IDX_UNDEF)
    {
        printf("%sOutput: %sQueue kosong, memutar kembali lagu\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);

    }
    else
    {
        PushRiwayatLagu(RL, (*CS).JudulLagu, (*CS).NamaAlbum, (*CS).NamaPenyanyi);
        dequeueLaguNext(QL, CS);

        (*CS).status = 1;

        printf("%sOutput: %sMemutar lagu selanjutnya\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);
    }

}

void SongPrev(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS)
{
    AnimasiSongPrev();
    if ((*RL).IDXTOP == IDX_UNDEF)
    {
        printf("%sOutput: %sRiwayat kosong, memutar kembali lagu\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);
    }
    else
    {
        enqueueLaguFirst(QL, (*CS).JudulLagu, (*CS).NamaAlbum, (*CS).NamaPenyanyi);
        PopRiwayatLagu(RL, CS);

        printf("%sOutput: %sMemutar lagu sebelumnya\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);

    }
}