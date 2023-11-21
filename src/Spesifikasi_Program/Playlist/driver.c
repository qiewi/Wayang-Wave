#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/boolean.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/array/arraydinamis.h"
#include "../../ADT/pcolor/pcolor.h"
#include "Playlist.h"

int main() {
    ListPenyanyi LP;
    ArrayDin AP;

    // Proses pembuatan playlist
    printf("Membuat Playlist...\n");
    PlaylistCreate(&AP);

    // Menambahkan lagu ke dalam playlist
    printf("Menambahkan Lagu ke Playlist...\n");
    // Misalnya, tentukan idPenyanyi, idAlbum, idLagu, dan idPlaylist
    // AddSongToPlaylist(&LP, &AP, idPenyanyi, idAlbum, idLagu, idPlaylist);

    // Menambahkan album ke dalam playlist
    printf("Menambahkan Album ke Playlist...\n");
    // Misalnya, tentukan idPenyanyi, idAlbum, dan idPlaylist
    // AddAlbumToPlaylist(&LP, &AP, idPenyanyi, idAlbum, idPlaylist);

    // Menghapus lagu dari playlist
    printf("Menghapus Lagu dari Playlist...\n");
    // Misalnya, tentukan idPlaylist dan idLagu
    // PlayListRemoveLagu(&AP, idPlaylist, idLagu);

    // Menghapus playlist
    printf("Menghapus Playlist...\n");
    // deletePlaylist(&AP);

    return 0;
}
