#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../Play/Play.h"
#include "../Queue/Queue.h"

void SongNext(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS)
{   
    if ((*CS).status == 0)// Menampilkan pesan kesalahan jika tidak ada lagu yang dapat diputar.
    {
        printf("\n%sERROR: %sQueue kosong, Current Song juga kosong\n", RED, WHITE);
        printf("%sTidak ada lagu yang dapat diputar.\n", WHITE);
    }
    else if ((*QL).idxHead == IDX_UNDEF || (*QL).idxTail == IDX_UNDEF)// Menampilkan pesan jika antrian kosong dan memutar kembali lagu yang sedang diputar.
    {
        printf("\n%sOutput: %sQueue kosong, memutar kembali lagu\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);

    }
    else// Menambahkan lagu yang sedang diputar ke dalam riwayat, dequeue lagu, memutar lagu selanjutnya, dan Menampilkan pesan bahwa lagu selanjutnya diputar.
    {
        PushRiwayatLagu(RL, (*CS).JudulLagu, (*CS).NamaAlbum, (*CS).NamaPenyanyi);
        dequeueLaguNext(QL, CS);

        printf("\n%sOutput: %sMemutar lagu selanjutnya\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);
    }

}

void SongPrev(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS)
{
    if ((*RL).IDXTOP == IDX_UNDEF)// Memeriksa apakah riwayat lagu kosong
    {
        // Menampilkan pesan jika riwayat kosong dan memutar kembali lagu yang sedang diputar.
        printf("\n%sOutput: %sRiwayat kosong, memutar kembali lagu\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);
    }
    else
    {
        // Menambahkan lagu dari riwayat ke antrian, menghapus lagu dari riwayat, dan memutar lagu sebelumnya.
        enqueueLaguFirst(QL, (*CS).JudulLagu, (*CS).NamaAlbum, (*CS).NamaPenyanyi);
        PopRiwayatLagu(RL, CS);

        // Menampilkan pesan bahwa lagu sebelumnya diputar.
        printf("\n%sOutput: %sMemutar lagu sebelumnya\n", GREEN, WHITE);
        printf("\"%s\" oleh \"%s\"\n", (*CS).JudulLagu.TabLine, (*CS).NamaPenyanyi.TabLine);

    }
}